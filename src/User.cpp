#include "User.h"
#include "Tournament.h"
#include "Organizer.h"

User::User(){
    _username = "";
    _email = "";
    _password = "";
}

User::User(string username, string email, string password){
    _username = username;
    _email = email;
    _password = password;
}

string User::Username(){
    return _username;
}

string User::Email(){
    return _email;
}

string User::Password(){
    return _password;
}

string User::String(string input){
    string output = "";
    cout << input << ":\t";
    getline(cin, output);
    return output;
}

int User::Int(string input){
    string o;
    cout << input << ":\t";
    getline(cin, o);
    int output = stoi(o);
    return output;
}

bool User::Bool(string input){
    string o;
    bool output;
    cout << "(1 means true, 0 means false)" << endl;
    cout << input << ":\t";
    getline(cin, o);
    
    if (o == "1"){
        output = true;
    } else {
        output = false;
    }
    return output;
}

void User::UpdateProfile(string username, string email, string password){
    if (username != ""){
        _username = username;
    } if (email != ""){
        _email = email;
    } if (password != ""){
        _password = password;
    }
}

User * User::SearchUser(Organizer * o, string username){
    for (int i = 0; i < o->UserList().size(); i++){
        if (o->UserList().at(i)->Username() == username){
            return o->UserList().at(i);
            break;
        }
    }
    return NULL;
}

Tournament * User::SearchTournament(Organizer * o, string tName){
    for (int i = 0; i < o->TournamentList().size(); i++){
        if (o->TournamentList().at(i)->TName() == tName){
            return o->TournamentList().at(i);
        }
    }
    
    return NULL;
}

void User::SetTeam(Team * t){
    cout << "The user cannot set team." << endl;
}

void User::PrintUser(int num){
    cout << "--------------------" << endl;

    if (num > 0){
        cout << "User " << num << endl;
    }
    
    cout << "User Name:\t" << _username << endl;
    cout << "User Email:\t" << _email << endl;
}