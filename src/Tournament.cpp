#include "Tournament.h"

Tournament::Tournament(){
    _tName = "";
    _tSize = 0;
    _tTheme = "";
    _tVenue = "";
}

Tournament::Tournament(string tName, int tSize, string tTheme, string tVenue){
    _tName = tName;
    _tSize = tSize;
    _tTheme = tTheme;
    _tVenue = tVenue;
}

string Tournament::TName(){
    return _tName;
}

int Tournament::TSize(){
    return _tSize;
}

string Tournament::TTheme(){
    return _tTheme;
}

string Tournament::TVenue(){
    return _tVenue;
}

void Tournament::AddTeam(Team * t){
    if (t == NULL || _teams.size() >= _tSize){
        return;
    }
    for (int i = 0; i < _teams.size(); i++){
        if (_teams.at(i) == t || _teams.at(i)->TeamName() == t->TeamName()){
            return;
        }
    }
    _teams.push_back(t);
}

void Tournament::RemoveTeam(string teamName){
    for (int i = 0; i < _teams.size();){
        if(_teams.at(i)->TeamName() == teamName){
            _teams.erase(_teams.begin() + i);
        } else {
            i++;
        }
    }
}

int Tournament::CountTeam(){
    return _teams.size();
}

void Tournament::AddRequest(Team * t){
    if (t == NULL){
        return;
    }
    for (int i = 0; i < _teams.size(); i++){
        if (_teams.at(i) == t || _teams.at(i)->TeamName() == t->TeamName()){
            return;
        }
    }
    for (int i = 0; i < _request.size(); i++){
        if (_request.at(i) == t || _request.at(i)->TeamName() == t->TeamName()){
            return;
        }
    }
    _request.push_back(t);
}

void Tournament::RemoveRequest(string teamName){
    for(int i = 0; i < _request.size();){
        if(_request.at(i)->TeamName() == teamName){
            _request.erase(_request.begin() + i);
        } else {
            i++;
        }
    }
}

int Tournament::CountRequest(){
    return _request.size();
}

void Tournament::SetTournament(string tName, int tSize, string tTheme, string tVenue){
    if (tName != ""){
        _tName = tName;
    } if (tSize != 0){
        _tSize = tSize;
    } if (tTheme != ""){
        _tTheme = tTheme;
    } if (tVenue != ""){
        _tVenue = tVenue;
    }
}

void Tournament::ManageTeam(string teamName, bool add){
    bool found = false;
    for (int i = 0; i < _request.size(); i++){
        if (_request.at(i)->TeamName() == teamName){
            if (add){
                if (_teams.size() >= _tSize){
                    cout << "Tournament is full; the request remains pending." << endl;
                    return;
                }
                AddTeam(_request.at(i));
            }
            _request.erase(_request.begin() + i);
            found = true;
            cout << "Team request managed successfully." << endl;
            break;
        }
    }
    if (!found){
        cout << "Team request is not exist." << endl;
    }
}

void Tournament::PrintTournament(int num){
    cout << "-------------------------" << endl;
    
    if (num > 0){
        cout << "Tournament " << num << endl;
    }

    cout << "Tournament Name:\t" << _tName << endl;
    cout << "Tournament Size:\t" << _tSize << endl;
    cout << "Tournament Theme:\t" << _tTheme << endl;
    cout << "Tournament Venue:\t" << _tVenue << endl;
    
    for(int i = 0; i < _teams.size(); i++){
        _teams.at(i)->PrintTeam(i + 1);
    }
    
    cout << endl;
}

void Tournament::PrintRequest(int num){
    cout << "Request:" << endl;
    
    if (num > 0){
        cout << "Tournament " << num << endl;
    }
    
    for(int i = 0; i < _request.size(); i++){
        _request.at(i)->PrintTeam(i + 1);
    }
}
