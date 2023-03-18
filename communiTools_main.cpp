#include <iostream>
#include "communiTools_header.hpp"

  using namespace std;

int main()
{
  bool quit = false;
  char cmd;
  CommuniTools CT;

  if (CT.logIn())
  {
    do
    {
      CT.printMenu();
      cin >> cmd;
      cmd = toupper(cmd);
      if (cmd == 'Q')
      {
        CT.lineBreak();
        cout << "Quitting, BYE" << endl;
        break;
      }
      CT.lineBreak();
      CT.getOption(cmd);

    } while (!quit);

  }

  return 0;
}