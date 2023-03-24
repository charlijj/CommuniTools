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
    getCommunities = "SELECT comName, comID FROM Communities";
    getCommunitiesStatement = DB.conn->createStatement(getCommunities);

    getCommunityOfMember = "SELECT comID FROM CommunityMembers WHERE memberID = :1";
    getCommunityOfMemberStatement = DB.conn->createStatement(getCommunityOfMember);

    getToolOwner = "SELECT firstName, lastName, memberID, address, toolName FROM CommunityMembers NATURAL JOIN CommunityTools WHERE toolID = :1";
    getToolOwnerStatement = DB.conn->createStatement(getToolOwner);

    getCategories = "SELECT catName, catID, catDescription FROM ToolCategories";
    getCategoriesStatement = DB.conn->createStatement(getCategories);

    getMemberByName = "SELECT memberID FROM CommunityMembers WHERE firstName = :1 AND lastName = :2";
    getMemberByNameStatement = DB.conn->createStatement(getMemberByName);

    getBorrowStatus = "SELECT borrowStatus FROM CommunityTools WHERE toolID = :1";
    getBorrowStatusStatement = DB.conn->createStatement(getBorrowStatus);

    getOwnedTools = "SELECT toolName, toolID FROM CommunityTools WHERE memberID = :1";
    getOwnedToolsStatement = DB.conn->createStatement(getOwnedTools);

    getNumToolsBorrowing = "SELECT numToolsBorrowing FROM Borrowers WHERE memberID = :1";
    getNumToolsBorrowingStatement = DB.conn->createStatement(getNumToolsBorrowing);

    updateNumToolsBorrowing = "UPDATE Borrowers SET numToolsBorrowing = :1 WHERE memberID = :2";
    updateNumToolsBorrowingStatement = DB.conn->createStatement(updateNumToolsBorrowing);

    updateBorrowStatus = "UPDATE CommunityTools SET borrowStatus = :1 WHERE toolID = :2";
    updateBorrowStatusStatement = DB.conn->createStatement(updateBorrowStatus);

    validateLogin = "SELECT memberID FROM CommunityMembers WHERE username = :1 AND password = :2";
    validateLoginStatement  = DB.conn->createStatement(validateLogin);

    showAllTools = "SELECT toolName, firstName, lastName, comName, borrowStatus, condition FROM CommunityTools NATURAL JOIN CommunityMembers NATURAL JOIN Communities";
    showAllToolsStatement = DB.conn->createStatement(showAllTools);

    showCurrentToolBorrows = "SELECT toolName, T.toolID, firstName, lastName, rentDate FROM CommunityTools T JOIN BorrowRecords R ON T.toolID = R.toolID JOIN CommunityMembers M ON T.memberID = M.memberID WHERE R.memberID = :1 AND returnDate IS NULL ORDER BY rentDate DESC";
    showCurrentToolBorrowsStatement = DB.conn->createStatement(showCurrentToolBorrows);

    showAllAvailableTools = "SELECT toolName, toolID, firstName, lastName, comName, condition FROM CommunityTools NATURAL JOIN CommunityMembers NATURAL JOIN Communities WHERE borrowStatus = 0 AND memberID <> :1 AND comID = :2 ORDER BY firstName DESC";
    showAllAvailableToolsStatement = DB.conn->createStatement(showAllAvailableTools);

    showAllToolsOfCategory = "SELECT toolName, firstName, lastName, comName, borrowStatus, condition FROM CommunityTools NATURAL JOIN CommunityMembers NATURAL JOIN Communities WHERE catID = :1";
    showAllToolsOfCategoryStatement = DB.conn->createStatement(showAllToolsOfCategory);

    insertNewMember = "INSERT INTO CommunityMembers (comID, firstName, lastName, address, email, phone, username, password)"
        " VALUES (:1, :2, :3, :4, :5, :6, :7, :8)";
    insertNewMemberStatement = DB.conn->createStatement(insertNewMember);

    insertNewTool = "INSERT INTO CommunityTools (catID, memberID, toolName, condition) VALUES (:1, :2, :3, :4)";
    insertNewToolStatement = DB.conn->createStatement(insertNewTool);

    insertBorrowRecord = "INSERT INTO BorrowRecords (memberID, toolID, rentDate) VALUES (:1, :2, SYSDATE)";
    insertBorrowRecordStatement = DB.conn->createStatement(insertBorrowRecord);

    updateBorrowRecord = "UPDATE BorrowRecords SET returnDate = SYSDATE WHERE toolID = :1 AND memberID = :2";
    updateBorrowRecordStatement = DB.conn->createStatement(updateBorrowRecord);

    getBorrowRecord = "SELECT recordID FROM BorrowRecords WHERE toolID = :1 AND memberID = :2";
    getBorrowRecordStatement = DB.conn->createStatement(getBorrowRecord);

    insertBorrower = "INSERT INTO Borrowers (memberID, numToolsBorrowing) VALUES (:1, :2)";
    insertBorrowerStatement = DB.conn->createStatement(insertBorrower); 

    removeTool = "DELETE FROM CommunityTools WHERE toolID = :1 and memberID = :2";
    removeToolStatement = DB.conn->createStatement(removeTool);

    removeToolFromRecord = "UPDATE BorrowRecords SET toolID = NULL WHERE toolID = :1";
    removeToolFromRecordStatement = DB.conn->createStatement(removeToolFromRecord);
}

CommuniTools::~CommuniTools()
{
    DB.conn->terminateStatement(getCommunitiesStatement);
    DB.conn->terminateStatement(getCommunityOfMemberStatement);
    DB.conn->terminateStatement(getCategoriesStatement);
    DB.conn->terminateStatement(getToolOwnerStatement);
    DB.conn->terminateStatement(getOwnedToolsStatement);
    DB.conn->terminateStatement(getMemberByNameStatement);
    DB.conn->terminateStatement(getBorrowStatusStatement);
    DB.conn->terminateStatement(getNumToolsBorrowingStatement);
    DB.conn->terminateStatement(updateNumToolsBorrowingStatement);
    DB.conn->terminateStatement(updateBorrowStatusStatement);
    DB.conn->terminateStatement(insertNewMemberStatement);
    DB.conn->terminateStatement(insertNewToolStatement);
    DB.conn->terminateStatement(insertBorrowRecordStatement);
    DB.conn->terminateStatement(insertBorrowerStatement);
    DB.conn->terminateStatement(updateBorrowRecordStatement);
    DB.conn->terminateStatement(getBorrowRecordStatement);
    DB.conn->terminateStatement(validateLoginStatement);
    DB.conn->terminateStatement(showAllToolsStatement);
    DB.conn->terminateStatement(showAllAvailableToolsStatement);
    DB.conn->terminateStatement(showAllToolsOfCategoryStatement);
    DB.conn->terminateStatement(showCurrentToolBorrowsStatement);
    DB.conn->terminateStatement(removeToolStatement);
    DB.conn->terminateStatement(removeToolFromRecordStatement);
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

void CommuniTools::printCommunities() // Done
{
    ResultSet *rs;

    cout << left << setw(25) << "Community Name" << setw(15) << "Community ID" << endl;
    cout << left << setw(25) << "--------------" << setw(15) << "------------" << endl;

    rs = getCommunitiesStatement->executeQuery();
    while (rs->next())
    {
        cout << left << setw(25) << rs->getString(1) << setw(15) << rs->getString(2) << endl<<endl;
    }
    getCommunitiesStatement->closeResultSet(rs);

    cout << "-------------------------------------";

    lineBreak();
}

void CommuniTools::printCategories() // Done
{
    string statement;
    Statement *stmt;
    ResultSet *rs;

    cout << left << setw(25) << "Categorie" << setw(15) << "Categorie ID" << setw(50) << "Categorie Description" << endl;
    cout << left << setw(25) << "---------" << setw(15) << "------------" << setw(50) << "---------------------" << endl;

    rs = getCategoriesStatement->executeQuery();
    while (rs->next())
    {
        cout << left << setw(25) << rs->getString(1) << setw(15) << rs->getString(2) << setw(50) << rs->getString(3) << endl<<endl;
    }
    getCategoriesStatement->closeResultSet(rs);

    cout << "--------------------------------------------------------------------------";

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
        unlistTool();
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

string CommuniTools::readPassword() // Done
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

bool CommuniTools::verifyLogIn(string user, string pass) // Done
{
    ResultSet *rs;

    lineBreak();

    validateLoginStatement->setString(1, user);
    validateLoginStatement->setString(2, pass);
    rs = validateLoginStatement->executeQuery();
    if (!rs->next())
    {
        return false;
    }
    currentUser = rs->getInt(1);
    validateLoginStatement->closeResultSet(rs);

    cout << "----------------- Log In Successful -----------------" << endl;
    return true;
}

bool CommuniTools::addMember() // Done
{
    ResultSet *rs;

    int referralMember;
    int comID;
    string firstName;
    string lastName;
    string address;
    string phone;
    string email;
    string username;
    string password1;
    string password2;

    lineBreak();

    cout << "Enter the required information for the new member: " << endl;

    cout << "Enter member ID of referral member: " << endl;
    cin >> referralMember;

    if (cin.fail() || !DB.validateID("CommunityMembers", referralMember))
    {
        cout << "No member with ID " << referralMember << " exists." << endl;
        return false;
    }
    
    cinClear();

    cout << "Enter fist name: " << endl;
    getline(cin, firstName);

    cout << "Enter last name: " << endl;
    getline(cin, lastName);

    getMemberByNameStatement->setString(1, firstName);
    getMemberByNameStatement->setString(2, lastName);
    rs = getMemberByNameStatement->executeQuery();
    if (rs->next())
    {
        cout << firstName << " " << lastName << " is already a member." << endl;
        return false;
    }
    getMemberByNameStatement->closeResultSet(rs);

    printCommunities();
    cout << "Enter community ID: " << endl;
    cin >> comID;

    if (cin.fail() || !DB.validateID("Communities", comID))
    {
        cout << "No community with ID " << comID << " exists." << endl;
        return false;
    }

    cinClear();

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

    insertNewMemberStatement->setInt(1, comID);
    insertNewMemberStatement->setString(2, firstName);
    insertNewMemberStatement->setString(3, lastName);
    insertNewMemberStatement->setString(4, address);
    insertNewMemberStatement->setString(5, email);
    insertNewMemberStatement->setString(6, phone);
    insertNewMemberStatement->setString(7, username);
    insertNewMemberStatement->setString(8, password1);
    int rowsUpdated = insertNewMemberStatement->executeUpdate();

    if (rowsUpdated == 1) // if update was successful, commit changes 
    {
        cout << "Added member " << firstName << " " << lastName << " with user name " << username << " successfully." << endl;
        DB.conn->commit();
        return true;
    }
    else
    {
        cerr << "Error: Failed to update record" << endl;
        return false;
    }
}

bool CommuniTools::addTool() // Done
{
    int catID;
    string name;
    string condition;

    lineBreak();
    cinClear();
    
    printCategories();
    cout << "Enter the tool category: " << endl;
    cin >> catID;

    if (cin.fail())
    {
        cinClear();
        cout << "Invalid tool category ID." << endl;
        return false;
    }
    else if (!DB.validateID("ToolCategories", catID))
    {
        cout << "Invalid tool category ID." << endl;
        return false;
    }
    cinClear();

    cout << "Enter tool name: " << endl;
    getline(cin, name);

    cout << "Enter tool condition: " << endl;
    getline(cin, condition);

    insertNewToolStatement->setInt(1, catID);
    insertNewToolStatement->setInt(2, currentUser);
    insertNewToolStatement->setString(3, name);
    insertNewToolStatement->setString(4, condition);
    int rowsUpdated = insertNewToolStatement->executeUpdate();
    if (rowsUpdated == 1) // if update was successful, commit changes 
    {
        cout << "Added tool " << name << " successfully." << endl;
        DB.conn->commit();
        return true;
    }
    else
    {
        cerr << "Error: Failed to update record" << endl;
        return false;
    }
}

void CommuniTools::showTools() // Done
{
    ResultSet *rs;

    string memberName;
    string borrowStatus; 
    int catID = 0;

    cinClear();
    printCategories();
    cout << "Enter the category ID of what tools you want to see, enter 0 for all tools: ";
    cin >> catID;

    if (cin.fail())
    {
        cinClear();
        cout << "Invalid tool category ID." << endl;
        return;
    }
    else if (catID == 0)
    {
        rs = showAllToolsStatement->executeQuery();
    }
    else if (!DB.validateID("ToolCategories", catID))
    {
        cout << "Invalid tool category." << endl;
        return;
    }
    else
    {
        showAllToolsOfCategoryStatement->setInt(1, catID);
        rs = showAllToolsOfCategoryStatement->executeQuery();
    }

    lineBreak();

    cout << left << setw(25) << "Tool" << setw(25) << "Owner" << setw(25) << "Community" << setw(20) << "Borrow Status" << setw(25) << "Condition" << endl;
    cout << left << setw(25) << "----" << setw(25) << "-----" << setw(25) << "---------" << setw(20) << "-------------" << setw(25) << "---------" << endl;

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

    cout << "-------------------------------------";

    lineBreak();
}

void CommuniTools::showAvailableTools() // Done
{
    ResultSet *rs;
    string memberName;
    int currentUserCom;

    cout << "All tools available to rent: " << endl;
    cout << left << setw(25) << "Tool" << setw(15) << "Tool ID" << setw(25) << "Owner" << setw(25) << "Community" << setw(25) << "Condition" << endl;
    cout << left << setw(25) << "----" << setw(15) << "-------" << setw(25) << "-----" << setw(25) << "---------" <<  setw(25) << "---------" << endl;
    
    getCommunityOfMemberStatement->setInt(1, currentUser);
    rs = getCommunityOfMemberStatement->executeQuery();
    rs->next();
    currentUserCom = rs->getInt(1);
    getCommunityOfMemberStatement->closeResultSet(rs);

    showAllAvailableToolsStatement->setInt(1, currentUser);
    showAllAvailableToolsStatement->setInt(2, currentUserCom);
    rs = showAllAvailableToolsStatement->executeQuery();
    while (rs->next())
    {
        memberName = rs->getString(3) + " " + rs->getString(4);
        cout << left << setw(25) << rs->getString(1) << setw(15) << rs->getInt(2) << setw(25) << memberName << setw(25) << rs->getString(5) << setw(25) << rs->getString(6) << endl;
    }
    showAllAvailableToolsStatement->closeResultSet(rs);
}

bool CommuniTools::borrowTool() // Done
{
    ResultSet *rs;
    int toolID;
    int numToolsBorrowing = 0;
    string memberName;

    lineBreak();
    cinClear();    
    showAvailableTools();
    lineBreak();

    cout << "Enter tool ID of tool you would like to borrow: " << endl;
    cin >> toolID;

    if (cin.fail())
    {
        cinClear();
        cout << "Invalid tool ID." << endl;
        return false;
    }
    else if (!DB.validateID("CommunityTools", toolID))
    {
        cout << "Invalid tool ID." << endl;
        return false;
    }

    getBorrowStatusStatement->setInt(1, toolID);
    rs = getBorrowStatusStatement->executeQuery();
    rs->next();
    if (rs->getInt(1) != 0)
    {
        cout << "Tool " << toolID << " is already being borrowed." << endl;
        return false;
    }
    getBorrowStatusStatement->closeResultSet(rs);


    updateBorrowStatusStatement->setInt(1, 1);
    updateBorrowStatusStatement->setInt(2, toolID);
    int rowsUpdated = updateBorrowStatusStatement->executeUpdate();
    if (rowsUpdated != 1)
    {
        cerr << "Error: Failed to update record" << endl;
        return false;
    }

    insertBorrowRecordStatement->setInt(1, currentUser);
    insertBorrowRecordStatement->setInt(2, toolID);
    rowsUpdated = insertBorrowRecordStatement->executeUpdate();
    if (rowsUpdated != 1)
    {
        cerr << "Error: Failed to update record" << endl;
        return false;
    }

    getNumToolsBorrowingStatement->setInt(1, currentUser);
    rs = getNumToolsBorrowingStatement->executeQuery();
    if (rs->next())
    {
        numToolsBorrowing = rs->getInt(1);
        
        updateNumToolsBorrowingStatement->setInt(1, numToolsBorrowing + 1);
        updateNumToolsBorrowingStatement->setInt(2, currentUser);
        rowsUpdated = updateNumToolsBorrowingStatement->executeUpdate();
        if (rowsUpdated != 1)
        {
            cerr << "Error: Failed to update record" << endl;
            return false;
        }
    }

    else
    {
        insertBorrowerStatement->setInt(1, currentUser);
        insertBorrowerStatement->setInt(2, numToolsBorrowing + 1);
        rowsUpdated = insertBorrowerStatement->executeUpdate();
        if (rowsUpdated != 1)
        {
            cerr << "Error: Failed to update record" << endl;
            return false;
        }
    }
    getNumToolsBorrowingStatement->closeResultSet(rs);


    getToolOwnerStatement->setInt(1, toolID);
    rs = getToolOwnerStatement->executeQuery();
    rs->next();
    memberName = rs->getString(1) + " " + rs->getString(2);
    cout << "You are now borrowing " << rs->getString(5) << " from " << memberName << " ID: " << rs->getInt(3) <<  ", you can pick up your tool at " << rs->getString(4) << "." << endl;
    getToolOwnerStatement->closeResultSet(rs);

    DB.conn->commit();
    return true;
}

bool CommuniTools::returnTool() // Done
{
    ResultSet *rs;
    int toolID;
    int rowsUpdated;
    int numToolsBorrowing = 0;

    lineBreak();
    cinClear();    
    showToolBorrows();
    lineBreak();

    cout << "Enter the tool ID of the tool you would like to return: ";
    cin >> toolID;

    if (cin.fail())
    {
        cinClear();
        cout << "Invalid tool ID." << endl;
        return false;
    }
    else if (!DB.validateID("CommunityTools", toolID))
    {
        cout << "Invalid tool ID." << endl;
        return false;
    }

    getBorrowRecordStatement->setInt(1, toolID);
    getBorrowRecordStatement->setInt(2, currentUser);
    rs = getBorrowRecordStatement->executeQuery();
    if (!rs->next())
    {
        cout << "You are not currently renting the tool with ID " << toolID << "." << endl;
        return false;
    }
    getBorrowRecordStatement->closeResultSet(rs);

    updateBorrowStatusStatement->setInt(1, 0);
    updateBorrowStatusStatement->setInt(2, toolID);
    rowsUpdated = updateBorrowStatusStatement->executeUpdate();
    if (rowsUpdated != 1)
    {
        cerr << "Error: Failed to update record" << endl;
        return false;
    }

    getNumToolsBorrowingStatement->setInt(1, currentUser);
    rs = getNumToolsBorrowingStatement->executeQuery();
    if (rs->next())
    {
        numToolsBorrowing = rs->getInt(1);
        
        updateNumToolsBorrowingStatement->setInt(1, numToolsBorrowing - 1);
        updateNumToolsBorrowingStatement->setInt(2, currentUser);
        rowsUpdated = updateNumToolsBorrowingStatement->executeUpdate();
        if (rowsUpdated != 1)
        {
            cerr << "Error: Failed to update record" << endl;
            return false;
        }
    }
    getNumToolsBorrowingStatement->closeResultSet(rs);

    updateBorrowRecordStatement->setInt(1, toolID);
    updateBorrowRecordStatement->setInt(2, currentUser);
    rowsUpdated = updateBorrowRecordStatement->executeUpdate();
    if (rowsUpdated != 1)
    {
        cerr << "Error: Failed to update record" << endl;
        return false;
    }

    cout << "Tool has been returned." << endl;
    DB.conn->commit();
    return true;
}

void CommuniTools::showToolBorrows() // Done
{
    //SELECT toolName, T.toolID, firstName, lastName, rentDate FROM CommunityTools T JOIN BorrowRecords R ON T.toolID = R.toolID JOIN CommunityMembers M ON T.memberID = M.memberID WHERE R.memberID = :1
    ResultSet *rs;
    string memberName;

    cout << "You are currently borrowing: " << endl;
    cout << left << setw(25) << "Tool" << setw(15) << "Tool ID" << setw(25) << "From" << setw(20) << "Rented On" << endl;
    cout << left << setw(25) << "----" << setw(15) << "-------" << setw(25) << "----" << setw(20) << "--------" << endl;


    showCurrentToolBorrowsStatement->setInt(1, currentUser);
    rs = showCurrentToolBorrowsStatement->executeQuery();
    while(rs->next())
    {
        memberName = rs->getString(3) + " " + rs->getString(4);
        cout << left << setw(25) << rs->getString(1) << setw(15) << rs->getInt(2) << setw(25) << memberName << setw(20) << rs->getString(5) << endl;
    }
    showCurrentToolBorrowsStatement->closeResultSet(rs);
}

bool CommuniTools::unlistTool() 
{
    ResultSet *rs;
    int toolID;
    int rowsUpdated;

    lineBreak();
    cinClear();    
    showUsersTools();
    lineBreak();

    cout << "Enter the ID of the tool you want to remove: ";
    cin >> toolID;

    if (cin.fail())
    {
        cinClear();
        cout << "Invalid tool ID." << endl;
        return false;
    }
    else if (!DB.validateID("CommunityTools", toolID))
    {
        cout << "Invalid tool ID." << endl;
        return false;
    }

    getToolOwnerStatement->setInt(1, toolID);
    rs = getToolOwnerStatement->executeQuery();
    rs->next();

    if (rs->getInt(3) != currentUser)
    {
        cout << "You do not own this tool." << endl;
        return false;
    }
    getToolOwnerStatement->closeResultSet(rs);

    removeToolFromRecordStatement->setInt(1, toolID);
    removeToolFromRecordStatement->executeUpdate();

    removeToolStatement->setInt(1, toolID);
    removeToolStatement->setInt(2, currentUser);
    rowsUpdated = removeToolStatement->executeUpdate();
    if (rowsUpdated != 1)
    {
        cerr << "Error: Failed to update record" << endl;
        return false;
    }

    cout << "Tool has been removed successfully." << endl;
    DB.conn->commit();
    return true;
}

void CommuniTools::showUsersTools()
{
    ResultSet *rs;

    cout << "Your tools: " << endl;
    cout << left << setw(25) << "Tool" << setw(15) << "Tool ID" << endl;
    cout << left << setw(25) << "----" << setw(15) << "-------" << endl;

    getOwnedToolsStatement->setInt(1, currentUser);
    rs = getOwnedToolsStatement->executeQuery();
    while (rs->next())
    {
        cout << left << setw(25) << rs->getString(1) << setw(15) << rs->getInt(2) << endl;
    }
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
    int numTuples;
    ResultSet *rs;
    string getNumTuples;
    Statement *getNumTuplesIDStatement;
    
    getNumTuples = "SELECT COUNT(*) FROM " + table;
    getNumTuplesIDStatement = conn->createStatement(getNumTuples);
    rs = getNumTuplesIDStatement->executeQuery();
    if (!rs->next()) {return false;}
    numTuples = rs->getInt(1);
    if (ID < 1 || ID > numTuples)
    {
        getNumTuplesIDStatement->closeResultSet(rs);
        conn->terminateStatement(getNumTuplesIDStatement);
        return false;
    }
    getNumTuplesIDStatement->closeResultSet(rs);
    conn->terminateStatement(getNumTuplesIDStatement);
    return true;
}