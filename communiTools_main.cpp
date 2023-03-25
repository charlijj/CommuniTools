// CommuniTool Main Controller

/*
CommunuiTools is a tool-sharing application that aims to facilitate the sharing of tools among members of a community. 
Users are incentivized to join a community through referrals and are encouraged to lend and borrow tools.

The full feature list is:  

  - add a new user, 
    input a referral member ID, the users community, first and last name, address, email, and phone number and be able to log in as that user.

  - add a new tool to lend out.
    input the category of the tool, the tool name, and the condition of the tool.

  - show all tools and their availability.
    lists all tools listed in every community, can by sorted by category

  - borrow a tool in the users community the is available to be borrowed.

  - return a tool that the user is currently borrowing.

  - remove a tool from the database, stop lending.

  - to quit program.

*/

#include <iostream>
#include "communiTools_header.hpp"

  using namespace std;

int main()
{
  bool quit = false; // runs while not quit
  bool fail = false; // gets return of get option
  char cmd; // user command variable
  CommuniTools CT; // Initializing an application object as CT.

  if (CT.logIn()) 
  {
    do
    {
      CT.printMenu();
      CT.cinClear(); // reset cin failbit and ignore buffer
      cin >> cmd;
      cmd = toupper(cmd);
      if (cmd == 'Q')
      {
        CT.lineBreak();
        cout << "Quitting... Bye!" << endl;
        return 1;
      }
      CT.lineBreak();
      CT.getOption(cmd); // getOption is the main method caller, its calls the method associated with the users command

    } while (!quit);

  }

  return 0;
}