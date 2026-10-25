#ifndef MEMBER_H
#define MEMBER_H

#include "User.h"
using namespace std;

class Organizer;
class Member: public User{
private:
public:
    Member();
    Member(string username, string email, string password);
    
    void Menu(Organizer * o);
};

#endif