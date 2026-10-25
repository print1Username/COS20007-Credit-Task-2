#ifndef ORGANIZER_H
#define ORGANIZER_H

#include "User.h"
#include "Leader.h"
#include "Tournament.h"
using namespace std;

class Organizer: public User {
private:
    vector<User *> _userList;
    vector<Tournament *> _tournamentList;
    vector<Team *> _teamList;
public:
    Organizer();
    Organizer(string username, string email, string password);
    
    vector<User *> UserList();
    vector<Tournament *> TournamentList();
    
    void AddUser(User * u);
    void RemoveUser(string username);
    int CountUser();
    
    void AddTournament(Tournament * t);
    void RemoveTournament(string tName);
    int CountTournament();
    
    User * Login(string username, string password);
    
    void CreateTournament(string tName, int tSize, string tTheme, string tVenue);
    void UpdateTournament(int num, string tName, int tSize, string tTheme, string tVenue);
    void FormTeam(string teamName, string leaderName);
    void ManageTeamRequested(int num, string teamName, bool add);

    void PrintUserList();
    void PrintTournamentList();
    void PrintRequestList();
    void PrintTeamList();
    
    void Menu(Organizer * o);
};
#endif