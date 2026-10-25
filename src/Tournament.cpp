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

void Tournament::AddTeam(Team * t){
    if (_teams.size() < _tSize){
        _teams.push_back(t);
    }
}

void Tournament::RemoveTeam(string teamName){
    for(int i = 0; i < _teams.size(); i++){
        if(_teams.at(i)->TeamName() == teamName){
            _teams.erase(_teams.begin() + i);
        }
    }
}

int Tournament::CountTeam(){
    return _teams.size();
}

void Tournament::AddRequest(Team * t){
    _request.push_back(t);
}

void Tournament::RemoveRequest(string teamName){
    for(int i = 0; i < _request.size(); i++){
        if(_request.at(i)->TeamName() == teamName){
            _request.erase(_request.begin() + i);
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
    for (int i = 0; i < _request.size(); i++){
        if (_request.at(i)->TeamName() == teamName){
            if (add){
                _teams.push_back(_request.at(i));
            }
            _request.erase(_request.begin() + i);
            break;
        }
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