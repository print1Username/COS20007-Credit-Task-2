#include "LeaderTestClass.h"


CPPUNIT_TEST_SUITE_REGISTRATION(LeaderTestClass);

LeaderTestClass::LeaderTestClass() {
}

LeaderTestClass::~LeaderTestClass() {
}

void LeaderTestClass::setUp() {
}

void LeaderTestClass::tearDown() {
}

void LeaderTestClass::TestUpdateTeam(){
    Organizer * o = new Organizer();
    Leader * l = new Leader("Leader","Leader@gmail.com","password");
    
    o->AddUser(l);
    o->FormTeam("Team","Leader");
    
    l->UpdateTeam("New Team");
    
    CPPUNIT_ASSERT(l->LeaderTeamName() == "New Team");
}

void LeaderTestClass::TestJoinTournament(){
    Organizer * o = new Organizer();
    Leader * l = new Leader("Leader","Leader@gmail.com","password");
    Tournament * t = new Tournament("Name", 5, "Theme", "Venue");

    o->AddUser(l);
    o->AddTournament(t);
    o->FormTeam("Team","Leader");
    
    l->JoinTournament(o, "Name");
    
    CPPUNIT_ASSERT(t->CountRequest() == 1);
}

void LeaderTestClass::TestAddMember(){
    Organizer * o = new Organizer();
    Leader * l = new Leader("Leader","Leader@gmail.com","password");
    Member * m = new Member("Member", "member@gmail.com","password");
    Team * t = new Team("Team 1");    

    o->AddUser(l);
    o->AddUser(m);
    l->SetTeam(t);
    
    l->AddTeamMember(o, "Member");
    
    CPPUNIT_ASSERT(t->CountMember() == 1);
}