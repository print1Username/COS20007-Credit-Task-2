#ifndef LEADERTESTCLASS_H
#define LEADERTESTCLASS_H

#include <cppunit/extensions/HelperMacros.h>

#include "../../include/Organizer.h"
#include "../../include/Leader.h"
#include "../../include/Tournament.h"

class LeaderTestClass : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(LeaderTestClass);

    CPPUNIT_TEST(TestUpdateTeam);
    CPPUNIT_TEST(TestJoinTournament);
    CPPUNIT_TEST(TestAddMember);
    
    CPPUNIT_TEST_SUITE_END();

private:
    void TestUpdateTeam();
    void TestJoinTournament();
    void TestAddMember();

public:
    LeaderTestClass();
    virtual ~LeaderTestClass();
    void setUp();
    void tearDown();

};
#endif

