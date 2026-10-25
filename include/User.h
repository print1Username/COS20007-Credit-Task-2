#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Organizer;
class Tournament;
class Team;
class User {
private:
    string _username;
    string _email;
    string _password;
public:
    User();
    User(string username, string email, string password);
    string Username();
    string Email();
    string Password();

    string String(string input);
    int Int(string input);
    bool Bool(string input);
    
    void UpdateProfile(string username, string email, string password);
    void ViewTournament(Organizer * o);
    void ViewTeam(Organizer * o);
    User * SearchUser(Organizer * o, string username);
    Tournament * SearchTournament(Organizer * o, string tName);
    
    virtual void SetTeam(Team * t);
    void PrintUser(int num);
    virtual void Menu(Organizer * o) = 0;
};


#endif

