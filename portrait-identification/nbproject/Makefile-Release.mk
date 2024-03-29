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
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=
AS=as

# Macros
CND_PLATFORM=Cygwin-Windows
CND_CONF=Release
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/domain/CPoint.o \
	${OBJECTDIR}/_ext/D_/Tools/Portrait_identification/portrait-identification/src/CEntityManager.o \
	${OBJECTDIR}/src/domain/CEntity.o \
	${OBJECTDIR}/src/CReciever.o \
	${OBJECTDIR}/src/domain/CPerson.o \
	${OBJECTDIR}/src/CNormalizer.o \
	${OBJECTDIR}/_ext/D_/Tools/Portrait_identification/portrait-identification/src/dao/CGenericDAO.o \
	${OBJECTDIR}/src/main.o \
	${OBJECTDIR}/_ext/D_/Tools/Portrait_identification/portrait-identification/src/dao/CPersonDAO.o \
	${OBJECTDIR}/src/dao/CPointDAO.o \
	${OBJECTDIR}/src/CImageController.o \
	${OBJECTDIR}/src/CIdentifier.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-Release.mk dist/Release/Cygwin-Windows/portrait-identification.exe

dist/Release/Cygwin-Windows/portrait-identification.exe: ${OBJECTFILES}
	${MKDIR} -p dist/Release/Cygwin-Windows
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/portrait-identification ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/src/domain/CPoint.o: nbproject/Makefile-${CND_CONF}.mk src/domain/CPoint.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/domain
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/domain/CPoint.o src/domain/CPoint.cpp

${OBJECTDIR}/_ext/D_/Tools/Portrait_identification/portrait-identification/src/CEntityManager.o: nbproject/Makefile-${CND_CONF}.mk /cygdrive/D/Tools/Portrait_identification/portrait-identification/src/CEntityManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/D_/Tools/Portrait_identification/portrait-identification/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/D_/Tools/Portrait_identification/portrait-identification/src/CEntityManager.o /cygdrive/D/Tools/Portrait_identification/portrait-identification/src/CEntityManager.cpp

${OBJECTDIR}/src/domain/CEntity.o: nbproject/Makefile-${CND_CONF}.mk src/domain/CEntity.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/domain
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/domain/CEntity.o src/domain/CEntity.cpp

${OBJECTDIR}/src/CReciever.o: nbproject/Makefile-${CND_CONF}.mk src/CReciever.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/CReciever.o src/CReciever.cpp

${OBJECTDIR}/src/domain/CPerson.o: nbproject/Makefile-${CND_CONF}.mk src/domain/CPerson.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/domain
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/domain/CPerson.o src/domain/CPerson.cpp

${OBJECTDIR}/src/CNormalizer.o: nbproject/Makefile-${CND_CONF}.mk src/CNormalizer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/CNormalizer.o src/CNormalizer.cpp

${OBJECTDIR}/_ext/D_/Tools/Portrait_identification/portrait-identification/src/dao/CGenericDAO.o: nbproject/Makefile-${CND_CONF}.mk /cygdrive/D/Tools/Portrait_identification/portrait-identification/src/dao/CGenericDAO.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/D_/Tools/Portrait_identification/portrait-identification/src/dao
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/D_/Tools/Portrait_identification/portrait-identification/src/dao/CGenericDAO.o /cygdrive/D/Tools/Portrait_identification/portrait-identification/src/dao/CGenericDAO.cpp

${OBJECTDIR}/src/main.o: nbproject/Makefile-${CND_CONF}.mk src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/main.o src/main.cpp

${OBJECTDIR}/_ext/D_/Tools/Portrait_identification/portrait-identification/src/dao/CPersonDAO.o: nbproject/Makefile-${CND_CONF}.mk /cygdrive/D/Tools/Portrait_identification/portrait-identification/src/dao/CPersonDAO.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/D_/Tools/Portrait_identification/portrait-identification/src/dao
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/D_/Tools/Portrait_identification/portrait-identification/src/dao/CPersonDAO.o /cygdrive/D/Tools/Portrait_identification/portrait-identification/src/dao/CPersonDAO.cpp

${OBJECTDIR}/src/dao/CPointDAO.o: nbproject/Makefile-${CND_CONF}.mk src/dao/CPointDAO.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/dao
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/dao/CPointDAO.o src/dao/CPointDAO.cpp

${OBJECTDIR}/src/CImageController.o: nbproject/Makefile-${CND_CONF}.mk src/CImageController.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/CImageController.o src/CImageController.cpp

${OBJECTDIR}/src/CIdentifier.o: nbproject/Makefile-${CND_CONF}.mk src/CIdentifier.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/CIdentifier.o src/CIdentifier.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Release
	${RM} dist/Release/Cygwin-Windows/portrait-identification.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
