#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include <string>
#include <vector>
#include "Team.h"
using namespace std;

class Tournament{
private:
    string _tName;
    int _tSize;
    string _tTheme;
    string _tVenue;
    vector <Team *> _teams;
    vector <Team *> _request;
public:
    Tournament();
    Tournament(string tName, int tSize, string tTheme, string tVenue);
    string TName();
    int TSize();
    string TTheme();
    string TVenue();
    
    void AddTeam(Team * t);
    void RemoveTeam(string teamName);
    int CountTeam();
    
    void AddRequest(Team * t);
    void RemoveRequest(string teamName);
    int CountRequest();
    
    void SetTournament(string tName, int tSize, string tTheme, string tVenue);
    void ManageTeam(string teamName, bool add);
    void PrintTournament(int num);
    void PrintRequest(int num);
};

#endif
