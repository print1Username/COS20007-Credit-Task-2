#include "Member.h"
#include "Organizer.h"

Member::Member() {
}

Member::Member(string username, string email, string password): User(username, email, password){
}

void Member::Menu(Organizer * o){
    bool quit = false;
    int choose;
    
    while (!quit){
        cout << "Member login" << endl;
        cout << "0. Logout" << endl;
        cout << "1. Update User Profile" << endl;
        cout << "2. View Tournament" << endl;
        cout << "3. Search Tournament" << endl;
        cout << "4. View Team" << endl;
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
            default:
                break;
        }
    }


}
