#include "Leader.h"
#include "Organizer.h"

Leader::Leader() {
    _team = new Team();
}

Leader::Leader(string username, string email, string password): User(username, email, password){
    _team = new Team();
}

string Leader::LeaderTeamName(){
    return _team->TeamName();
}

void Leader::SetTeam(Team * t){
    _team = t;
}

void Leader::UpdateTeam(string teamName){
    _team->SetTeamName(teamName);
    cout << "Team update successfully." << endl;
}

void Leader::AddTeamMember(Organizer * o, string username){
    for (int i = 0; i < o->UserList().size(); i++){
        Member * member = dynamic_cast<Member *>(o->UserList().at(i));
        if (member != NULL && (member->Username() == username || member->Email() == username)){
            _team->AddMember(member);
            cout << "Member added successful" << endl;
            return;
        }
    }
    cout << "Registered member is not exist." << endl;
}

void Leader::JoinTournament(Organizer * o, string tName){
    for (int i = 0; i < o->TournamentList().size(); i++){
        if (o->TournamentList().at(i)->TName() == tName){
            Tournament * tournament = o->TournamentList().at(i);
            int requestCount = tournament->CountRequest();
            tournament->AddRequest(_team);
            if (tournament->CountRequest() > requestCount){
                cout << "Requested to organizer." << endl;
            } else {
                cout << "This team has already requested or joined the tournament." << endl;
            }
            return;
        }
    }
    cout << "Tournament is not exist." << endl;
}

void Leader::Menu(Organizer * o){
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
        cout << "5. Update Team" << endl;
        cout << "6. Add Team Member" << endl;
        cout << "7. Join Tournament" << endl;
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
                o->PrintTournamentList();
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
                o->PrintTeamList();
                break;
            case 5:
                cout << "Update Team." << endl;
                UpdateTeam(String("New team name"));
                break;
            case 6:
                cout << "Add Team Member" << endl;
                AddTeamMember(o,String("Member username or email"));
                break;
            case 7:
                cout << "Join Tournament" << endl;
                JoinTournament(o,String("Tournament Name"));
                break;
            default:
                break;
        }
    }
}
