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
                o->PrintTournamentList();
            case 3:
                cout << "Search Tournament." << endl;
                SearchTournament(o,String("Tournament Name"))->PrintTournament(0);
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