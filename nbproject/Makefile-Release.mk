#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Leader.o \
	${OBJECTDIR}/Member.o \
	${OBJECTDIR}/Organizer.o \
	${OBJECTDIR}/Team.o \
	${OBJECTDIR}/Tournament.o \
	${OBJECTDIR}/User.o \
	${OBJECTDIR}/main.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f3 \
	${TESTDIR}/TestFiles/f2 \
	${TESTDIR}/TestFiles/f1

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/tests/LeaderTestClass.o \
	${TESTDIR}/tests/LeaderTestRunner.o \
	${TESTDIR}/tests/OrganizerTestClass.o \
	${TESTDIR}/tests/OrganizerTestRunner.o \
	${TESTDIR}/tests/UserTestClass.o \
	${TESTDIR}/tests/UserTestRunner.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=-Iinclude -Itests/include

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/credittask2.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/credittask2.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/credittask2 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Leader.o: src/Leader.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Leader.o src/Leader.cpp

${OBJECTDIR}/Member.o: src/Member.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Member.o src/Member.cpp

${OBJECTDIR}/Organizer.o: src/Organizer.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Organizer.o src/Organizer.cpp

${OBJECTDIR}/Team.o: src/Team.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Team.o src/Team.cpp

${OBJECTDIR}/Tournament.o: src/Tournament.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Tournament.o src/Tournament.cpp

${OBJECTDIR}/User.o: src/User.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/User.o src/User.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:

${TESTDIR}/TestFiles/f3: ${TESTDIR}/tests/LeaderTestClass.o ${TESTDIR}/tests/LeaderTestRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f3 $^ ${LDLIBSOPTIONS}   `cppunit-config --libs`   

${TESTDIR}/TestFiles/f2: ${TESTDIR}/tests/OrganizerTestClass.o ${TESTDIR}/tests/OrganizerTestRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS}   `cppunit-config --libs`   

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/UserTestClass.o ${TESTDIR}/tests/UserTestRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS}   `cppunit-config --libs`   


${TESTDIR}/tests/LeaderTestClass.o: tests/src/LeaderTestClass.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/LeaderTestClass.o tests/src/LeaderTestClass.cpp


${TESTDIR}/tests/LeaderTestRunner.o: tests/src/LeaderTestRunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/LeaderTestRunner.o tests/src/LeaderTestRunner.cpp


${TESTDIR}/tests/OrganizerTestClass.o: tests/src/OrganizerTestClass.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/OrganizerTestClass.o tests/src/OrganizerTestClass.cpp


${TESTDIR}/tests/OrganizerTestRunner.o: tests/src/OrganizerTestRunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/OrganizerTestRunner.o tests/src/OrganizerTestRunner.cpp


${TESTDIR}/tests/UserTestClass.o: tests/src/UserTestClass.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/UserTestClass.o tests/src/UserTestClass.cpp


${TESTDIR}/tests/UserTestRunner.o: tests/src/UserTestRunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/UserTestRunner.o tests/src/UserTestRunner.cpp


${OBJECTDIR}/Leader_nomain.o: ${OBJECTDIR}/Leader.o src/Leader.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Leader.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Leader_nomain.o src/Leader.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Leader.o ${OBJECTDIR}/Leader_nomain.o;\
	fi

${OBJECTDIR}/Member_nomain.o: ${OBJECTDIR}/Member.o src/Member.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Member.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Member_nomain.o src/Member.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Member.o ${OBJECTDIR}/Member_nomain.o;\
	fi

${OBJECTDIR}/Organizer_nomain.o: ${OBJECTDIR}/Organizer.o src/Organizer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Organizer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Organizer_nomain.o src/Organizer.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Organizer.o ${OBJECTDIR}/Organizer_nomain.o;\
	fi

${OBJECTDIR}/Team_nomain.o: ${OBJECTDIR}/Team.o src/Team.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Team.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Team_nomain.o src/Team.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Team.o ${OBJECTDIR}/Team_nomain.o;\
	fi

${OBJECTDIR}/Tournament_nomain.o: ${OBJECTDIR}/Tournament.o src/Tournament.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Tournament.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Tournament_nomain.o src/Tournament.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Tournament.o ${OBJECTDIR}/Tournament_nomain.o;\
	fi

${OBJECTDIR}/User_nomain.o: ${OBJECTDIR}/User.o src/User.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/User.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/User_nomain.o src/User.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/User.o ${OBJECTDIR}/User_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_nomain.o main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f3 || true; \
	    ${TESTDIR}/TestFiles/f2 || true; \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
