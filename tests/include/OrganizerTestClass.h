#ifndef ORGANIZERTESTCLASS_H
#define ORGANIZERTESTCLASS_H

#include <cppunit/extensions/HelperMacros.h>

#include "../../include/Organizer.h"
#include "../../include/Leader.h"
#include "../../include/Member.h"

class OrganizerTestClass : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(OrganizerTestClass);

    CPPUNIT_TEST(TestAddUser);
    CPPUNIT_TEST(TestRemoveUser);
    CPPUNIT_TEST(TestCreateTournament);
    CPPUNIT_TEST(TestRemoveTournament);
    CPPUNIT_TEST(TestUpdateTournament);
    CPPUNIT_TEST(TestFormTeam);

    CPPUNIT_TEST_SUITE_END();

private:
    void TestAddUser();
    void TestRemoveUser();
    void TestCreateTournament();
    void TestRemoveTournament();
    void TestUpdateTournament();
    void TestFormTeam();
    
public:
    OrganizerTestClass();
    virtual ~OrganizerTestClass();
    void setUp();
    void tearDown();
};

#endif

