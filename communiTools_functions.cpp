#include <iostream>
#include "communiTools_header.hpp"

  using namespace std;

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
    cout << "Enter one of the following commands: " << endl;
    cout << "N: to add a new user." << endl;
    cout << "L: to add a new tool to lend out." << endl;
    cout << "S: to show all tools and their availability." << endl;
    cout << "B: to borrow a tool." << endl;
    cout << "R: to return a tool." << endl;
    cout << "D: to remove a tool from lend out." << endl;
    cout << "Q: to quit program." << endl;
}

void CommuniTools::getOption(char cmd)
{
    switch (cmd)
    {
    case 'N':
        cout << "Adding new user..." << endl;
        break;
    case 'L':
        cout << "Adding new tool to lend out..." << endl;
        break;
    case 'S':
        cout << "Showing all tools..." << endl;
        break;
    case 'B':
        cout << "Borrowing tool..." << endl;
        break;
    case 'R':
        cout << "Returning tool..." << endl;
        break;
    case 'D':
        cout << "Removing tool from lend list..." << endl;
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
        cin >> password;

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

bool CommuniTools::verifyLogIn(string user, string pass)
{
    cout << "verifying credentials" << endl;

    if (user != "user" || pass != "pass")
    {
        return false;
    }

    return true;
}