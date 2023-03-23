#include <iostream>
#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <iomanip>
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

void CommuniTools::printCommunities()
{
    string statement;
    Statement *stmt;
    ResultSet *rs;

    cout << left << setw(25) << "Community Name" << setw(15) << "Community ID" << endl;
    cout << left << setw(25) << "--------------" << setw(15) << "------------" << endl;

    statement = "SELECT comName, comID FROM Communities";
    stmt = DB.conn->createStatement(statement);
    rs = stmt->executeQuery();
    while (rs->next())
    {
        cout << left << setw(25) << rs->getString(1) << setw(15) << rs->getString(2) << endl<<endl;
    }
    stmt->closeResultSet(rs);
    DB.conn->terminateStatement(stmt);

    cout << "-------------------------------------";

    lineBreak();
}

void CommuniTools::printCategories()
{
    string statement;
    Statement *stmt;
    ResultSet *rs;

    cout << left << setw(25) << "Categorie" << setw(15) << "Categorie ID" << endl;
    cout << left << setw(25) << "---------" << setw(15) << "------------" << endl;

    statement = "SELECT catName, catID FROM ToolCategories";
    stmt = DB.conn->createStatement(statement);
    rs = stmt->executeQuery();
    while (rs->next())
    {
        cout << left << setw(25) << rs->getString(1) << setw(15) << rs->getString(2) << endl<<endl;
    }
    stmt->closeResultSet(rs);
    DB.conn->terminateStatement(stmt);

    cout << "-------------------------------------";

    lineBreak();
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
    string statement;
    Statement *stmt;
    ResultSet *rs;

    lineBreak();

    statement = "SELECT memberID FROM CommunityMembers WHERE username = :1 AND password = :2";
    stmt = DB.conn->createStatement(statement);
    stmt->setString(1, user);
    stmt->setString(2, pass);
    rs = stmt->executeQuery();
    if (!rs->next())
    {
        return false;
    }
    stmt->closeResultSet(rs);

    cout << "----------------- Log In Successful -----------------" << endl;
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
    string username;
    string password1;
    string password2;

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

    printCommunities();
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

    cout << "Enter password: " << endl;
    password1 = readPassword();

    cout << "Enter password again: " << endl;
    password2 = readPassword();

    if (password1 != password2)
    {
        cout << "Passwords do not match." << endl;
        return false;
    }

    username = lastName.substr(0, 6) + firstName.substr(0, 1);

    statement = "INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone, username, password)"
        " VALUES (:1, :2, :3, :4, :5, :6, :7, :8)";
    stmt = DB.conn->createStatement(statement);
    stmt->setString(1, communityID);
    stmt->setString(2, firstName);
    stmt->setString(3, lastName);
    stmt->setString(4, address);
    stmt->setString(5, email);
    stmt->setString(6, phone);
    stmt->setString(7, username);
    stmt->setString(8, password1);
    int rowsUpdated = stmt->executeUpdate();

    if (rowsUpdated == 1) // if update was successful, commit changes 
    {
        cout << "Added member " << firstName << " " << lastName << " with user name " << username << " successfully." << endl;
        DB.conn->commit();
    }
    else
    {
        cerr << "Error: Failed to update record" << endl;
    }
    DB.conn->terminateStatement(stmt);
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

void CommuniTools::showTools()
{
    string statement;
    Statement *stmt;
    ResultSet *rs;

    int catID = 0;

    cinClear();
    printCategories();
    cout << "Enter the category ID of what tools you want to see, enter 0 for all tools: ";
    cin >> catID;

    if (!DB.validateID("ToolCategories", catID) || cin.fail() && catID != 0)
    {
        cout << "Invalid tool category." << endl;
        return;
    }

    string memberName;
    string borrowStatus; 

    cout << left << setw(25) << "Tool" << setw(25) << "Owner" << setw(25) << "Community" << setw(20) << "Borrow Status" << setw(25) << "Condition" << endl;
    cout << left << setw(25) << "----" << setw(25) << "-----" << setw(25) << "---------" << setw(20) << "-------------" << setw(25) << "---------" << endl;

    if (catID == 0){
        statement = "SELECT toolName, firstName, lastName, comName, borrowStatus, condition FROM CommunityTools NATURAL JOIN CommunityMembers NATURAL JOIN Communities";
    }
    else {
        statement = "SELECT toolName, firstName, lastName, comName, borrowStatus, condition FROM CommunityTools NATURAL JOIN CommunityMembers NATURAL JOIN Communities WHERE catID = :1";
    }
    stmt = DB.conn->createStatement(statement);
    stmt->setInt(1, catID);
    rs = stmt->executeQuery();
    while (rs->next())
    {
        memberName = rs->getString(2) + " " + rs->getString(3);
        if (rs->getInt(5) == 0)
        {
            borrowStatus = "Available";
        } else {
            borrowStatus = "Not Available";
        }

        cout << left << setw(25) << rs->getString(1) << setw(25) << memberName << setw(25) << rs->getString(4) << setw(20) << borrowStatus << setw(25) << rs->getString(6) << endl;
    }
    stmt->closeResultSet(rs);
    DB.conn->terminateStatement(stmt);

    cout << "-------------------------------------";

    lineBreak();
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

        cout << "---------- Database Connection Successful ----------" << endl<<endl;
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

bool Database::validateID(string table, int ID)
{
    int numCategories;
    string statement;
    Statement *stmt;
    ResultSet *rs;
    cout << table << ID << endl;
    statement = "SELECT COUNT(:2) FROM :1";
    stmt = conn->createStatement(statement);
    stmt->setString(1, table);
    stmt->setID(2, ID);
    rs = stmt->executeQuery();
    numCategories = rs->getInt(1);

    if (ID < 1 || ID > numCategories)
    {
        return false;
    }
    return true;
}