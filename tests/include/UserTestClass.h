#ifndef USERTESTCLASS_H
#define USERTESTCLASS_H

#include <cppunit/extensions/HelperMacros.h>

#include "../../include/Organizer.h"

class UserTestClass : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(UserTestClass);

    CPPUNIT_TEST(TestUpdateProfile);

    CPPUNIT_TEST_SUITE_END();

private:
    void TestUpdateProfile();

public:
    UserTestClass();
    virtual ~UserTestClass();
    void setUp();
    void tearDown();
};

#endif
