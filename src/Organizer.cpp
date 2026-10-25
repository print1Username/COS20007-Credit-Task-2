#include "Organizer.h"

Organizer::Organizer(){
    _userList.push_back(this);
}

Organizer::Organizer(string username, string email, string password): User(username, email, password){
    _userList.push_back(this);
}

vector<User *> Organizer::UserList(){
    return _userList;
}

vector<Tournament *> Organizer::TournamentList(){
    return _tournamentList;
}

void Organizer::AddUser(User * u){
    _userList.push_back(u);
}

void Organizer::RemoveUser(string username){
    for (int i = 0; i < _userList.size(); i++){
        if (_userList.at(i)->Username() == username){
            _userList.erase(_userList.begin() + i);
            cout << "User remove successfully." << endl;
            break;
        }
    }
}

int Organizer::CountUser(){
    return _userList.size();
}

void Organizer::AddTournament(Tournament * t){
    _tournamentList.push_back(t);
}

void Organizer::RemoveTournament(string tName){
    for (int i = 0; i < _tournamentList.size(); i++){
        if (_tournamentList.at(i)->TName() == tName){
            _tournamentList.erase(_tournamentList.begin() + i);
            cout << "Tournament remove successfully." << endl;
            break;
        }
    }
}

int Organizer::CountTournament(){
    return _tournamentList.size();
}

User * Organizer::Login(string username, string password){
    for (int i = 0; i < _userList.size(); i++){
        if (_userList.at(i)->Username() == username && _userList.at(i)->Password() == password){
            return _userList.at(i);
            break;
        }
    }
    return NULL;
}

void Organizer::CreateTournament(string tName, int tSize, string tTheme, string tVenue){
    Tournament * t = new Tournament(tName, tSize, tTheme, tVenue);
    AddTournament(t);
    cout << "Tournament created successful." << endl;
}

void Organizer::UpdateTournament(int num, string tName, int tSize, string tTheme, string tVenue){
    if (num <= _tournamentList.size()){
        _tournamentList.at(num - 1)->SetTournament(tName, tSize, tTheme, tVenue);
        cout << "Tournament update successful." << endl;
    } else {
        cout << "Tournament is not exist." << endl;
    }
}

void Organizer::FormTeam(string teamName, string leaderName){
    Team * t = new Team(teamName);
    for (int i = 0; i < _userList.size(); i++){
        if (_userList.at(i)->Username() == leaderName){
            _userList.at(i)->SetTeam(t);
            break;
        }
    }
    _teamList.push_back(t);
}

void Organizer::ManageTeamRequested(int num, string teamName, bool add){
    for(int i = 0; i < _tournamentList.size(); i++){
        if (i = num - 1){
            _tournamentList.at(i)->ManageTeam(teamName, add);
            break;
        }
    }
}

void Organizer::PrintUserList(){
    cout << "User List:" << endl;
    for(int i = 0; i < _userList.size(); i++){
        _userList.at(i)->PrintUser(i + 1);
    }
    cout << endl;
}

void Organizer::PrintTournamentList(){
    cout << "Tournament List:" << endl;
    for(int i = 0; i < _tournamentList.size(); i++){
        _tournamentList.at(i)->PrintTournament(i + 1);
    }
    cout << endl;
}

void Organizer::PrintRequestList(){
    cout << "Request List:" << endl;
    for(int i = 0; i < _tournamentList.size(); i++){
        _tournamentList.at(i)->PrintRequest(i + 1);
    }
}

void Organizer::PrintTeamList(){
    cout << "Team List:" << endl;
    for(int i = 0; i < _teamList.size(); i++){
        _teamList.at(i)->PrintTeam(i + 1);
    }
}

void Organizer::Menu(Organizer * o){
    bool quit = false;
    int choose;
    
    while (!quit){
        cout << "Organizer login" << endl;
        cout << "0. Logout" << endl;
        cout << "1. Update User Profile" << endl;
        cout << "2. View Tournament" << endl;
        cout << "3. Search Tournament" << endl;
        cout << "4. View Team" << endl;
        cout << endl;
        cout << "5. Create Tournament" << endl;
        cout << "6. Search Tournament" << endl;
        cout << "7. Update Tournament Information" << endl;
        cout << "8. Form Team" << endl;
        cout << "9. Manage Team request" << endl;
        cout << endl;
        cout << ">>\t";
        cin >> choose;
        
        switch (choose){
            case 0:
                quit = true;
                cout << "Logout successful." << endl;
                break;
            case 1:
                cout << "Update profile." << endl;
                cout << "(Just leave a blank if you don`t want update the profile.)" << endl;
                UpdateProfile(
                        String("User Name"),
                        String("User Email"),
                        String("User Password")
                        );
                cout << "Profile Update successful." << endl;
                break;
            case 2:
                cout << "View Tournament." << endl;
                PrintTournamentList();
                break;
            case 3:
                cout << "Search Tournament." << endl;
                SearchTournament(o,String("Tournament Name"))->PrintTournament(0);
                break;
            case 4:
                cout << "View Team." << endl;
                PrintTeamList();
            case 5:
                cout << "Create Tournament." << endl;
                CreateTournament(
                        String("Tournament Name"),
                        Int("Tournament Size"),
                        String("Tournament Theme"),
                        String("Tournament Venue")
                        );
                cout << "Tournament create successful." << endl;
                break;
            case 6:
                cout << "Search Tournament." << endl;
                SearchTournament(o, String("Tournament Name"));
                break;
            case 7:
                cout << "Update Tournament." << endl;
                cout << "(Just leave a blank if you don`t want update the information.)" << endl;
                UpdateTournament(
                        Int("Tournament number"),
                        String("Tournament Name"),
                        Int("Tournament Size"),
                        String("Tournament Theme"),
                        String("Tournament Venue")
                        );
                cout << "Tournament update successful." << endl;
                break;
            case 8:
                cout << "Form Team" << endl;
                FormTeam(
                        String("Team Name"),
                        String("Team Leader")
                        );
                break;
            case 9:
                cout << "Manage Team request." << endl;
                PrintRequestList();
                ManageTeamRequested(
                        Int("Number of the tournament"),
                        String("Team Name"),
                        Bool("Add the team to the tournament?")
                        );
                cout << "Team manage successful." << endl;
                break;
            default:
                break;
        }
    }

}