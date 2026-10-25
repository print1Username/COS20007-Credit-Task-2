#include "Organizer.h"
#include "Leader.h"
#include "Member.h"
#include "Tournament.h"
#include "Team.h"
using namespace std;

int main(){
    Organizer * o = new Organizer("organizer", "organizer@gmail.com", "password");
    Leader * l = new Leader("leader", "leader@gmail.com", "password");
    Member * m = new Member("member", "member@gmail.com", "password");
    
    o->AddUser(l);
    o->AddUser(m);
    
    bool quit = false;
    while (!quit){
        Member * mm = NULL;
        int num = 0;
        string username = "";
        string password = "";

        cout << "1. Login" << endl;
        cout << "2. Register new User" << endl;
        cout << "3. End Program" << endl;
        num = o->Int(">>", false);
        
        switch (num){
            case 1:
                cout << "Login." << endl;
                while(o->Login(username, password) == NULL){
                    cout << "Insert User name and Password." << endl;
                    cout << "User name:\t";
                    getline(cin, username);
                    cout << "User password:\t";
                    getline(cin, password);
                    cout << endl;
                }

                o->Login(username, password)->PrintUser(0);
                cout << endl;
                o->Login(username, password)->Menu(o);
                break;
            case 2:
                cout << "Register new user." << endl;
                {
                    string username = o->String("User Name");
                    string email = o->String("User Email");
                    string password = o->String("User Password");
                    mm = new Member(username, email, password);
                }
                o->AddUser(mm);
                cout << "User register successful." << endl;
                break;
            case 3:
                quit = true;
                cout << "End Program." << endl;
                break;
            default:
                num = 0;
                break;
        }
    }
    system("pause");
}
