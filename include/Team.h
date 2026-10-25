#ifndef TEAM_H
#define TEAM_H

#include <string>
#include <vector>

#include "Member.h"
using namespace std;

class Team {
private:
    string _teamName;
    vector <User *> _members;
public:
    Team();
    Team(string teamName);
    
    string TeamName();
    
    void SetTeamName(string teamName);
    void AddMember(User * u);
    void RemoveMember(string member);
    int CountMember();
    
    void PrintTeam(int num);
};

#endif