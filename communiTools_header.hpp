// By: Jasper Charlinski
// CommuniTools and Database Class Definitions 

#include <iostream>
#include <occi.h> // Oracle's C++ call level interface library package

  using namespace std;
  using namespace oracle::occi;


// global read password function, used for database and application login,
string readPassword(); 

class Database {
// Handles the connection to oracle database

    private:

    string connectString =  "sunfire.csci.viu.ca";

    public:

    Environment *env;
    Connection *conn;
    Database();
    ~Database();
    bool validateID(string table, int ID);
};

class CommuniTools {
// Handles all application functionalities 

    private:

    int currentUser; // memberID of current logged in user

    Database DB; // database connection

    // Select querys  -----------------------------

    string getCommunities;
    Statement *getCommunitiesStatement;

    string validateLogin;
    Statement *validateLoginStatement;

    string getCommunityOfMember;
    Statement *getCommunityOfMemberStatement;

    string getMemberByName;
    Statement *getMemberByNameStatement;

    string getToolOwner;
    Statement *getToolOwnerStatement;

    string showAllTools;
    Statement *showAllToolsStatement;

    string showCurrentToolBorrows;
    Statement *showCurrentToolBorrowsStatement;

    string showAllAvailableTools;
    Statement *showAllAvailableToolsStatement;

    string showAllToolsOfCategory;
    Statement *showAllToolsOfCategoryStatement;

    string showOwnedTools;
    Statement *showOwnedToolsStatement;

    string getCategories;
    Statement *getCategoriesStatement;

    string getBorrowStatus;
    Statement *getBorrowStatusStatement;

    string getNumToolsBorrowing;
    Statement *getNumToolsBorrowingStatement;

      string getBorrowRecord;
    Statement *getBorrowRecordStatement;

    // Update querys -----------------------------

    string updateNumToolsBorrowing;
    Statement *updateNumToolsBorrowingStatement;

    string updateBorrowStatus;
    Statement *updateBorrowStatusStatement;

    string updateBorrowRecord;
    Statement *updateBorrowRecordStatement;

    // Insert querys -----------------------------

    string insertNewMember;
    Statement *insertNewMemberStatement;

    string insertNewTool;
    Statement *insertNewToolStatement;

    string insertBorrowRecord;
    Statement *insertBorrowRecordStatement;

    string insertBorrower;
    Statement *insertBorrowerStatement;

    // Remove querys ------------------------------

    string removeTool;
    Statement *removeToolStatement;

    string removeToolFromRecord;
    Statement *removeToolFromRecordStatement;

    int numToIgnore = 256; // number of character to clear from buffer with cin.ignore()
    
    void printCommunities();
    void printCategories();
    void showTools();
    void showUsersTools();
    void showAvailableTools();
    void showToolBorrows();
    bool verifyLogIn(string user, string pass);
    bool addMember();
    bool addTool();
    bool borrowTool();
    bool returnTool();
    bool unlistTool();

    public:

    CommuniTools();
    ~CommuniTools();
    
    void printMenu();
    bool logIn();
    void getOption(char cmd);
    void lineBreak(){cout<<endl<<endl;};
    void cinClear(){
      cin.clear();
      cin.ignore(numToIgnore, '\n');
    };
};
