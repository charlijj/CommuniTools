#include <iostream>

  using namespace std;

class CommuniTools
{
    private:
    
    int numToIgnore = 256;
    bool verifyLogIn(string user, string pass);

    public:

    CommuniTools();
    ~CommuniTools();
    
    void printMenu();
    bool logIn();
    void getOption(char cmd);
};

class Database {

    private:
        
    public:

    Database();
    ~Database();
};


