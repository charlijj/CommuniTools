#include <iostream>
#include <occi.h> // Oracle's C++ call level interface library package

  using namespace std;
  using namespace oracle::occi;

class Database {

    private:

    string userName = "";
    string password = "";
    string connectString =  "sunfire.csci.viu.ca";

    public:

    Environment *env;
    Connection *conn;
    Database();
    ~Database();
    bool validateID(string table, int ID);
};

class CommuniTools
{
    private:

    int currentUser;

    Database DB;

    string getCommunities;
    Statement *getCommunitiesStatement;

    string getCommunityOfMember;
    Statement *getCommunityOfMemberStatement;

    string getToolOwner;
    Statement *getToolOwnerStatement;

    string getCategories;
    Statement *getCategoriesStatement;

    string getMemberByName;
    Statement *getMemberByNameStatement;

    string getBorrowStatus;
    Statement *getBorrowStatusStatement;

    string getNumToolsBorrowing;
    Statement *getNumToolsBorrowingStatement;

    string updateNumToolsBorrowing;
    Statement *updateNumToolsBorrowingStatement;

    string updateBorrowStatus;
    Statement *updateBorrowStatusStatement;

    string validateLogin;
    Statement *validateLoginStatement;

    string showAllTools;
    Statement *showAllToolsStatement;

    string showOwnedTools;
    Statement *showOwnedToolsStatement;

    string showCurrentToolBorrows;
    Statement *showCurrentToolBorrowsStatement;

    string showAllAvailableTools;
    Statement *showAllAvailableToolsStatement;

    string showAllToolsOfCategory;
    Statement *showAllToolsOfCategoryStatement;

    string insertNewMember;
    Statement *insertNewMemberStatement;

    string insertNewTool;
    Statement *insertNewToolStatement;

    string insertBorrowRecord;
    Statement *insertBorrowRecordStatement;

    string updateBorrowRecord;
    Statement *updateBorrowRecordStatement;

    string getBorrowRecord;
    Statement *getBorrowRecordStatement;

    string insertBorrower;
    Statement *insertBorrowerStatement;

    string removeTool;
    Statement *removeToolStatement;

    string removeToolFromRecord;
    Statement *removeToolFromRecordStatement;

    int numToIgnore = 256;
    
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
    string readPassword();

    public:

    CommuniTools();
    ~CommuniTools();
    
    void printMenu();
    bool logIn();
    bool getOption(char cmd);
    void lineBreak(){cout<<endl<<endl;};
    void cinClear(){
      cin.clear();
      cin.ignore(numToIgnore, '\n');
    };
};




