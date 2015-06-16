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
CND_PLATFORM=Arduino-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/1175076252/Button.o \
	${OBJECTDIR}/_ext/1175076252/Logger.o \
	${OBJECTDIR}/_ext/1175076252/Motor.o \
	${OBJECTDIR}/_ext/1175076252/MotorCarriage.o \
	${OBJECTDIR}/_ext/1175076252/MotorSensor.o \
	${OBJECTDIR}/_ext/1175076252/Servo.o \
	${OBJECTDIR}/_ext/1175076252/UltrasonicSensor.o \
	${OBJECTDIR}/_ext/1175076252/UltrasonicSensorCarriage.o \
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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tnev-project.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tnev-project.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	avr-gcc -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tnev-project ${OBJECTFILES} ${LDLIBSOPTIONS} ${FLAGS_LINKER}

${OBJECTDIR}/_ext/1175076252/Button.o: /home/viproz/Programation/TNEV-Project/src/Button.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1175076252
	${RM} "$@.d"
	$(COMPILE.cc) -g -I${INCLUDE} -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1175076252/Button.o /home/viproz/Programation/TNEV-Project/src/Button.cpp

${OBJECTDIR}/_ext/1175076252/Logger.o: /home/viproz/Programation/TNEV-Project/src/Logger.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1175076252
	${RM} "$@.d"
	$(COMPILE.cc) -g -I${INCLUDE} -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1175076252/Logger.o /home/viproz/Programation/TNEV-Project/src/Logger.cpp

${OBJECTDIR}/_ext/1175076252/Motor.o: /home/viproz/Programation/TNEV-Project/src/Motor.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1175076252
	${RM} "$@.d"
	$(COMPILE.cc) -g -I${INCLUDE} -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1175076252/Motor.o /home/viproz/Programation/TNEV-Project/src/Motor.cpp

${OBJECTDIR}/_ext/1175076252/MotorCarriage.o: /home/viproz/Programation/TNEV-Project/src/MotorCarriage.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1175076252
	${RM} "$@.d"
	$(COMPILE.cc) -g -I${INCLUDE} -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1175076252/MotorCarriage.o /home/viproz/Programation/TNEV-Project/src/MotorCarriage.cpp

${OBJECTDIR}/_ext/1175076252/MotorSensor.o: /home/viproz/Programation/TNEV-Project/src/MotorSensor.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1175076252
	${RM} "$@.d"
	$(COMPILE.cc) -g -I${INCLUDE} -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1175076252/MotorSensor.o /home/viproz/Programation/TNEV-Project/src/MotorSensor.cpp

${OBJECTDIR}/_ext/1175076252/Servo.o: /home/viproz/Programation/TNEV-Project/src/Servo.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1175076252
	${RM} "$@.d"
	$(COMPILE.cc) -g -I${INCLUDE} -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1175076252/Servo.o /home/viproz/Programation/TNEV-Project/src/Servo.cpp

${OBJECTDIR}/_ext/1175076252/UltrasonicSensor.o: /home/viproz/Programation/TNEV-Project/src/UltrasonicSensor.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1175076252
	${RM} "$@.d"
	$(COMPILE.cc) -g -I${INCLUDE} -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1175076252/UltrasonicSensor.o /home/viproz/Programation/TNEV-Project/src/UltrasonicSensor.cpp

${OBJECTDIR}/_ext/1175076252/UltrasonicSensorCarriage.o: /home/viproz/Programation/TNEV-Project/src/UltrasonicSensorCarriage.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1175076252
	${RM} "$@.d"
	$(COMPILE.cc) -g -I${INCLUDE} -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1175076252/UltrasonicSensorCarriage.o /home/viproz/Programation/TNEV-Project/src/UltrasonicSensorCarriage.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I${INCLUDE} -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tnev-project.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
