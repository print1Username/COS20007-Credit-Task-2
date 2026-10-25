#include "UserTestClass.h"


CPPUNIT_TEST_SUITE_REGISTRATION(UserTestClass);

UserTestClass::UserTestClass() {
}

UserTestClass::~UserTestClass() {
}

void UserTestClass::setUp() {
}

void UserTestClass::tearDown() {
}

void UserTestClass::TestUpdateProfile(){
    Organizer * o = new Organizer();
    o->UpdateProfile("Name", "", "");
    CPPUNIT_ASSERT(o->Username() == "Name");
}