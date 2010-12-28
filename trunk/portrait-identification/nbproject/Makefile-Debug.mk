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
CND_CONF=Debug
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/D_/Tools/Portrait_identification/portrait-identification/src/domain/CEntity.o \
	${OBJECTDIR}/src/main.o \
	${OBJECTDIR}/src/CImageController.o \
	${OBJECTDIR}/src/CReciever.o

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
LDLIBSOPTIONS=-L../lib/opencv -lcv210 -lcxcore210

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-Debug.mk dist/Debug/Cygwin-Windows/portrait-identification.exe

dist/Debug/Cygwin-Windows/portrait-identification.exe: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/Cygwin-Windows
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/portrait-identification ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/_ext/D_/Tools/Portrait_identification/portrait-identification/src/domain/CEntity.o: nbproject/Makefile-${CND_CONF}.mk /cygdrive/D/Tools/Portrait_identification/portrait-identification/src/domain/CEntity.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/D_/Tools/Portrait_identification/portrait-identification/src/domain
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -I../include/net -I../include/opencv -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/D_/Tools/Portrait_identification/portrait-identification/src/domain/CEntity.o /cygdrive/D/Tools/Portrait_identification/portrait-identification/src/domain/CEntity.cpp

${OBJECTDIR}/src/main.o: nbproject/Makefile-${CND_CONF}.mk src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -I../include/net -I../include/opencv -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/main.o src/main.cpp

${OBJECTDIR}/src/CImageController.o: nbproject/Makefile-${CND_CONF}.mk src/CImageController.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -I../include/net -I../include/opencv -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/CImageController.o src/CImageController.cpp

${OBJECTDIR}/src/CReciever.o: nbproject/Makefile-${CND_CONF}.mk src/CReciever.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -I../include/net -I../include/opencv -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/CReciever.o src/CReciever.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Debug
	${RM} dist/Debug/Cygwin-Windows/portrait-identification.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
