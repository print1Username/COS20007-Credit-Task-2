#include "OrganizerTestClass.h"


CPPUNIT_TEST_SUITE_REGISTRATION(OrganizerTestClass);

OrganizerTestClass::OrganizerTestClass() {
}

OrganizerTestClass::~OrganizerTestClass() {
}

void OrganizerTestClass::setUp() {
}

void OrganizerTestClass::tearDown() {
}

void OrganizerTestClass::TestAddUser(){
    Organizer * o = new Organizer();
    Leader * l = new Leader();
    o->AddUser(l);
    CPPUNIT_ASSERT(o->CountUser() == 2);
}

void OrganizerTestClass::TestRemoveUser(){
    Organizer * o = new Organizer();
    Leader * l = new Leader("Leader", "leader@gmail.com", "password");
    o->AddUser(l);
    o->RemoveUser("Leader");
    CPPUNIT_ASSERT(o->CountUser() == 1);
    CPPUNIT_ASSERT(o->Login("Leader", "password") == NULL);
    CPPUNIT_ASSERT(o->Login("", "") == o);
}

void OrganizerTestClass::TestCreateTournament(){
    Organizer * o = new Organizer();
    o->CreateTournament("Tournament 1", 3, "Theme 1", "Venue 1");
    CPPUNIT_ASSERT(o->CountTournament() == 1);
}

void OrganizerTestClass::TestRemoveTournament(){
    Organizer * o = new Organizer();
    o->CreateTournament("Tournament 1", 3, "Theme 1", "Venue 1");
    o->CreateTournament("Tournament 2", 3, "Theme 2", "Venue 2");
    o->RemoveTournament("Tournament 2");
    CPPUNIT_ASSERT(o->CountTournament() == 1);
}

void OrganizerTestClass::TestUpdateTournament(){
    Organizer * o = new Organizer();
    Tournament * t = new Tournament();
    o->AddTournament(t);
    o->UpdateTournament(1, "Name", 0, "", "");
    CPPUNIT_ASSERT(t->TName() == "Name");
}

void OrganizerTestClass::TestFormTeam(){
    Organizer * o = new Organizer();
    Leader * l = new Leader("Leader","Leader@gmail.com","password");
    o->AddUser(l);
    o->FormTeam("Team 1", "Leader");
    CPPUNIT_ASSERT(l->LeaderTeamName() == "Team 1");
}
