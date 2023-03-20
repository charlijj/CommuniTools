#include <iostream>
#include <iostream>
#include <termios.h>
#include <unistd.h>
#include "communiTools_header.hpp"

  using namespace std;

// CommuniTools Class Method Implementation ---------------------------

// Public Methods ------------------------------------------------------

CommuniTools::CommuniTools()
{
    return;
}

CommuniTools::~CommuniTools()
{
    return;
}

void CommuniTools::printMenu()
{
    lineBreak();
    cout << "Enter one of the following commands: " << endl;
    cout << "N: to add a new user." << endl;
    cout << "L: to add a new tool to lend out." << endl;
    cout << "S: to show all tools and their availability." << endl;
    cout << "B: to borrow a tool." << endl;
    cout << "R: to return a tool." << endl;
    cout << "D: to remove a tool from lend out." << endl;
    cout << "Q: to quit program." << endl;
}

void CommuniTools::printCommunitys()
{
    string statement;
    Statement *stmt;
    ResultSet *rs;

    cout << "All communities: " << endl;

    statement = "SELECT comName, comID FROM Communities";
    stmt = DB.conn->createStatement(statement);
    rs = stmt->executeQuery();
    while (rs->next())
    {
        cout << "Community Name: " << rs->getString(1) << "\nCommunity ID: " << rs->getString(2) << endl<<endl;
    }
    stmt->closeResultSet(rs);
}

void CommuniTools::printCategories()
{
    cout << "Printing all categories..." << endl;
}

void CommuniTools::getOption(char cmd)
{
    switch (cmd)
    {
    case 'N':
        cout << "Adding new user..." << endl;
        addMember();
        break;
    case 'L':
        cout << "Adding new tool to lend out..." << endl;
        addTool();
        break;
    case 'S':
        cout << "Showing all tools..." << endl;
        showTools();
        break;
    case 'B':
        cout << "Borrowing tool..." << endl;
        borrowTool();
        break;
    case 'R':
        cout << "Returning tool..." << endl;
        returnTool();
        break;
    case 'D':
        cout << "Removing tool from lend list..." << endl;
        removeTool();
        break;
    
    default:
        cout << "Invalid Option, try again" << endl;
        cin.clear();
        cin.ignore(numToIgnore, '\n');
        break;
    }
}

bool CommuniTools::logIn()
{
    string username;
    string password;
    int trys = 3;
    bool loggedIn = false;

    do
    {
        if (trys == 0)
        {
            cout << "Out of login attempts, quitting program..." << endl;
            return false;
        }
        cout << "Enter user name: ";
        cin >> username;

        cout << endl;

        cout << "Enter password: ";
        cinClear();
        password = readPassword();

        loggedIn = verifyLogIn(username, password);

        if (!loggedIn)
        {
            cout << "Invalid user name or password try again." << endl;
            trys--;
            cout << "Number of try's remaining: " << trys << endl;
        }

    } while(!loggedIn);

    return true;
}

// Private Methods -----------------------------------------------------

string CommuniTools::readPassword()
{
    struct termios settings;
    tcgetattr(STDIN_FILENO, &settings);
    settings.c_lflag = (settings.c_lflag & ~(ECHO));
    tcsetattr(STDIN_FILENO, TCSANOW, &settings);

    string password = "";
    getline(cin, password);

    settings.c_lflag = (settings.c_lflag | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &settings);
    return password;
}

bool CommuniTools::verifyLogIn(string user, string pass)
{
    lineBreak();
    cout << "verifying credentials..." << endl;

    if (user != "user" || pass != "pass")
    {
        return false;
    }

    return true;
}

bool CommuniTools::addMember()
{
    string statement;
    Statement *stmt;
    ResultSet *rs;

    string referralMember;
    string firstName;
    string lastName;
    string communityID;
    string address;
    string phone;
    string email;

    lineBreak();
    cinClear();

    cout << "Enter the required information for the new member: " << endl;

    cout << "Enter member ID of referral member: " << endl;
    getline(cin, referralMember);

    statement = "SELECT memberID FROM CommunityMembers WHERE memberID = :1";
    stmt = DB.conn->createStatement(statement);
    stmt->setString(1, referralMember);
    rs = stmt->executeQuery();
    
    if (!rs->next())
    {
        cout << "No member with ID " << referralMember << " exists." << endl;
        return false;
    }
    stmt->closeResultSet(rs);


    cout << "Enter fist name: " << endl;
    getline(cin, firstName);

    cout << "Enter last name: " << endl;
    getline(cin, lastName);

    statement = "SELECT memberID FROM CommunityMembers WHERE firstName = :1 AND lastName = :2";
    stmt = DB.conn->createStatement(statement);
    stmt->setString(1, firstName);
    stmt->setString(2, lastName);
    rs = stmt->executeQuery();
    if (rs->next())
    {
        cout << firstName << " " << lastName << " is already a member." << endl;
        return false;
    }
    stmt->closeResultSet(rs);


    printCommunitys();
    cout << "Enter community ID: " << endl;
    getline(cin, communityID);

    statement = "SELECT comID FROM Communities WHERE comID = :1";
    stmt = DB.conn->createStatement(statement);
    stmt->setString(1, communityID);
    rs = stmt->executeQuery();
    if (!rs->next())
    {
        cout << "No community with ID " << communityID << " exists." << endl;
        return false;
    }
    stmt->closeResultSet(rs);


    cout << "Enter address: " << endl;
    getline(cin, address);

    cout << "Enter email: " << endl;
    getline(cin, email);

    cout << "Enter phone: " << endl;
    getline(cin, phone);

    statement = "INSERT INTO CommunityMembers (memberID, comID, firstName, lastName, address, email, phone)"
        " VALUES (:1, :2, :3, :4, :5, :6, :7)";
    stmt = DB.conn->createStatement(statement);
    stmt->setString(1, "99999");
    stmt->setString(2, communityID);
    stmt->setString(3, firstName);
    stmt->setString(4, lastName);
    stmt->setString(5, address);
    stmt->setString(6, email);
    stmt->setString(7, phone);
    int rowsUpdated = stmt->executeUpdate();

    if (rowsUpdated == 1) // if update was successful, commit changes 
    {
        cout << "Added member " << firstName << " " << lastName << " successfully" << endl;
        DB.conn->commit();
    }
    else
    {
        cerr << "Error: Failed to update record" << endl;
    }
}

bool CommuniTools::addTool()
{
    string statement;
    string category;
    string name;
    string condition;

    lineBreak();
    cinClear();
    
    printCategories();
    cout << "Enter tool category: " << endl;
    getline(cin, category);

    statement = "SELECT catID from Categories WHERE catID = :1 OR catName = :2";


    cout << "Enter tool name: " << endl;
    getline(cin, name);

    printCommunitys();
    cout << "Enter tool condition: " << endl;
    getline(cin, condition);

    statement = "INSERT INTO Tools (catID, toolName, condition)"
        " VALUES (:1, :2, :3)";


    try
    {
        cout << "New tool successfully added!" << endl;
        return true;
    }
    catch(exception& e)
    {
        std::cerr << e.what() << endl;
        return false;
    }
}

bool CommuniTools::showTools()
{
    cout << "All tools: " << endl;
    return true;
}

bool CommuniTools::borrowTool()
{
    string toolID;

    lineBreak();
    cinClear();

    cout << "All tools available to rent: " << endl;

    cout << "Enter tool ID of tool you would like to borrow: " << endl;
    getline(cin, toolID);
    return true;
}

bool CommuniTools::returnTool()
{
    return true;
}

bool CommuniTools::removeTool()
{
    return true;
}

// --------------------------------------------------------------------

// Database Class Method Implementation -------------------------------

// Public -------------------------------------------------------------

Database::Database()
{
    try
    {
        env = Environment::createEnvironment();
        conn = env->createConnection(userName, password, connectString);

        cout << "----------Database connection succsessfull----------" << endl<<endl;
    }
    catch (SQLException &e)
    {
        cout << e.what();
    }
};

Database::~Database()
{
    env->terminateConnection(conn);
    Environment::terminateEnvironment(env);
};


