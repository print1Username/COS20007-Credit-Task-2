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
    if (tName == "" || tSize <= 0){
        cout << "Tournament name and size must be valid." << endl;
        return;
    }
    Tournament * t = new Tournament(tName, tSize, tTheme, tVenue);
    AddTournament(t);
    cout << "Tournament created successful." << endl;
}

void Organizer::UpdateTournament(int num, string tName, int tSize, string tTheme, string tVenue){
    if (num < 1 || num > _tournamentList.size()){
        cout << "Tournament is not exist." << endl;
        return;
    }

    if (tSize < 0){
        cout << "Tournament size cannot be negative." << endl;
        return;
    }

    Tournament * tournament = _tournamentList.at(num - 1);
    if (tSize > 0 && tSize < tournament->CountTeam()){
        cout << "Tournament size cannot be smaller than the number of joined teams." << endl;
        return;
    }

    tournament->SetTournament(tName, tSize, tTheme, tVenue);
    cout << "Tournament update successful." << endl;
}

void Organizer::FormTeam(string teamName, string leaderName){
    if (teamName == ""){
        cout << "Team name cannot be empty." << endl;
        return;
    }

    for (int i = 0; i < _userList.size(); i++){
        if (_userList.at(i)->Username() == leaderName){
            Leader * leader = dynamic_cast<Leader *>(_userList.at(i));
            if (leader == NULL){
                cout << "The selected user is not a team leader." << endl;
                return;
            }
            Team * t = new Team(teamName);
            leader->SetTeam(t);
            _teamList.push_back(t);
            return;
        }
    }
    cout << "Team leader is not registered." << endl;
}

void Organizer::ManageTeamRequested(int num, string teamName, bool add){
    if (num < 1 || num > _tournamentList.size()){
        cout << "Tournament is not exist." << endl;
        return;
    }
    _tournamentList.at(num - 1)->ManageTeam(teamName, add);
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
        choose = Int(">>", false);
        
        switch (choose){
            case 0:
                quit = true;
                cout << "Logout successful." << endl;
                break;
            case 1:
                cout << "Update profile." << endl;
                cout << "(Just leave a blank if you don`t want update the profile.)" << endl;
                {
                    string username = String("User Name");
                    string email = String("User Email");
                    string password = String("User Password");
                    UpdateProfile(username, email, password);
                }
                cout << "Profile Update successful." << endl;
                break;
            case 2:
                cout << "View Tournament." << endl;
                PrintTournamentList();
                break;
            case 3:
                cout << "Search Tournament." << endl;
                {
                    Tournament * t = SearchTournament(o, String("Tournament Name"));
                    if (t != NULL){
                        t->PrintTournament(0);
                    } else {
                        cout << "Tournament is not exist." << endl;
                    }
                }
                break;
            case 4:
                cout << "View Team." << endl;
                PrintTeamList();
                break;
            case 5:
                cout << "Create Tournament." << endl;
                {
                    string name = String("Tournament Name");
                    int size = Int("Tournament Size");
                    string theme = String("Tournament Theme");
                    string venue = String("Tournament Venue");
                    CreateTournament(name, size, theme, venue);
                }
                break;
            case 6:
                cout << "Search Tournament." << endl;
                {
                    Tournament * t = SearchTournament(o, String("Tournament Name"));
                    if (t != NULL){
                        t->PrintTournament(0);
                    } else {
                        cout << "Tournament is not exist." << endl;
                    }
                }
                break;
            case 7:
                cout << "Update Tournament." << endl;
                cout << "(Just leave a blank if you don`t want update the information.)" << endl;
                {
                    int number = Int("Tournament number");
                    string name = String("Tournament Name");
                    int size = Int("Tournament Size");
                    string theme = String("Tournament Theme");
                    string venue = String("Tournament Venue");
                    UpdateTournament(number, name, size, theme, venue);
                }
                break;
            case 8:
                cout << "Form Team" << endl;
                {
                    string teamName = String("Team Name");
                    string leaderName = String("Team Leader");
                    FormTeam(teamName, leaderName);
                }
                break;
            case 9:
                cout << "Manage Team request." << endl;
                PrintRequestList();
                {
                    int number = Int("Number of the tournament");
                    string teamName = String("Team Name");
                    bool add = Bool("Add the team to the tournament?");
                    ManageTeamRequested(number, teamName, add);
                }
                break;
            default:
                break;
        }
    }

}
