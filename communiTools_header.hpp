#include <iostream>
#include <occi.h> // Oracle's C++ call level interface library package

  using namespace std;
  using namespace oracle::occi;

class Database {

    private:

    string userName = "charlijj";
    string password = "%Magnolia50";
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

    string insertBorrower;
    Statement *insertBorrowerStatement;

    int numToIgnore = 256;
    
    void printCommunities();
    void printCategories();
    void showTools();
    void showAvailableTools();
    bool verifyLogIn(string user, string pass);
    bool addMember();
    bool addTool();
    bool borrowTool();
    bool returnTool();
    bool removeTool();
    string readPassword();

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




