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

    Database DB;
  
    int numToIgnore = 256;
    
    void printCommunities();
    void printCategories();
    void showTools();
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




