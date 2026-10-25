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
    if (u == NULL){
        return;
    }
    for (int i = 0; i < _members.size(); i++){
        if (_members.at(i) == u){
            return;
        }
    }
    _members.push_back(u);
}

void Team::RemoveMember(string member){
    for (int i = 0; i < _members.size(); i++){
        if (_members.at(i)->Username() == member || _members.at(i)->Email() == member){
            _members.erase(_members.begin() + i);
            break;
        }
    }
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
