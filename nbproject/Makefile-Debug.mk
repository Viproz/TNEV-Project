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
CC=avr-gcc
CCC=avr-g++
CXX=avr-g++
FC=gfortran
AS=avr-as

# Macros
CND_PLATFORM=Arduino-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/1628086841/Motor.o \
	${OBJECTDIR}/_ext/1628086841/MotorCarriage.o \
	${OBJECTDIR}/_ext/1628086841/MotorSensor.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=${FLAGS_GCC}

# CC Compiler Flags
CCFLAGS=${FLAGS_GPP}
CXXFLAGS=${FLAGS_GPP}

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tnev-project

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tnev-project: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	avr-gcc -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tnev-project ${OBJECTFILES} ${LDLIBSOPTIONS} ${FLAGS_LINKER}

${OBJECTDIR}/_ext/1628086841/Motor.o: /home/viproz/Programation/TNEV-Project/Motor.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1628086841
	${RM} "$@.d"
	$(COMPILE.cc) -g -I${INCLUDE} -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1628086841/Motor.o /home/viproz/Programation/TNEV-Project/Motor.cpp

${OBJECTDIR}/_ext/1628086841/MotorCarriage.o: /home/viproz/Programation/TNEV-Project/MotorCarriage.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1628086841
	${RM} "$@.d"
	$(COMPILE.cc) -g -I${INCLUDE} -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1628086841/MotorCarriage.o /home/viproz/Programation/TNEV-Project/MotorCarriage.cpp

${OBJECTDIR}/_ext/1628086841/MotorSensor.o: /home/viproz/Programation/TNEV-Project/MotorSensor.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1628086841
	${RM} "$@.d"
	$(COMPILE.cc) -g -I${INCLUDE} -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1628086841/MotorSensor.o /home/viproz/Programation/TNEV-Project/MotorSensor.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I${INCLUDE} -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tnev-project

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
