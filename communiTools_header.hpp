#include <iostream>

  using namespace std;

class Database {

    private:

        
    public:

    Database();
    ~Database();
};

class CommuniTools
{
    private:

    Database DB;
    
    int numToIgnore = 256;
    bool verifyLogIn(string user, string pass);
    bool addMember();
    bool addTool();
    bool showTools();
    bool borrowTool();
    bool returnTool();
    bool removeTool();
    string readPassword();

    public:

    CommuniTools();
    ~CommuniTools();
    
    void printMenu();
    void printCommunityIDs();
    void printCategories();
    bool logIn();
    void getOption(char cmd);
    void lineBreak(){cout<<endl<<endl;};
    string getString(){
      string str;
      cin.clear();
      cin.ignore(numToIgnore, '\n');
      getline(cin, str);
      return str;
    };
    void cinClear(){
      cin.clear();
      cin.ignore(numToIgnore, '\n');
    };

};




