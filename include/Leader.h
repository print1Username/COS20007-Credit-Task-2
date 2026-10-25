#ifndef LEADER_H
#define LEADER_H

#include "User.h"
#include "Team.h"
using namespace std;

class Organizer;
class Leader: public User{
private:
    Team * _team;
public:
    Leader();
    Leader(string username, string email, string password);
    string LeaderTeamName();
        
    void SetTeam(Team * t);
    void UpdateTeam(string teamName);
    void AddTeamMember(Organizer * o, string username);
    void JoinTournament(Organizer * o, string tName);
    
    void Menu(Organizer * o);
};

#endif