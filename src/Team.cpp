#include "Team.h"

Team::Team(){
    _teamName = "";
}

Team::Team(string teamName){
    _teamName = teamName;
}

string Team::TeamName(){
    return _teamName;
}

void Team::SetTeamName(string teamName){
    _teamName = teamName;
}

void Team::AddMember(User * u){
    _members.push_back(u);
}

int Team::CountMember(){
    return _members.size();
}

void Team::PrintTeam(int num){
    if (num > 0){
        cout << "Team " << num << endl;    
    }
    
    cout << "Team Name:\t" << _teamName << endl;
    cout << "Team Member:" << endl;
    
    for(int i = 0; i < _members.size(); i++){
        _members.at(i)->PrintUser(i + 1);
    }
    
    cout << endl;
}