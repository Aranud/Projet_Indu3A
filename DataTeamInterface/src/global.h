#ifndef GLOBAL_H
#define GLOBAL_H

#define DEFAUT_NAME "NAIO01"
#include "QObject"
#include <math.h>
#define PI 3.14159265


typedef enum eIDCommand
{
    eIDCommandNone = -1,
    eIDCommmandAccelero = 0x09,
    eIDCommmandActuator = 0x0C,
    eIDCommmandGPS = 0x04,
    eIDCommandGyro = 0x0A,
    eIDCommmandLidar = 0x07,
    eIDCommmandMagneto = 0x0B,
    eIDCommmandMotors = 0x01,
    eIDCommmandOdo = 0x05,
    eIDCommmandRemote = 0x08

}E_IDCommand;

typedef enum eActuatorTool
{
    eActuatorToolNone = -1,
    eActuatorToolRaise = 0b01,
    eActuatorToolLower = 0b10,
    eActuatorToolFreeze = 0b11,

}E_ActuatorTool;

typedef enum eDirection
{
    eDirectionNone,
    eDirectionLeft,
    eDirectionRight,
    eDirectionFront,
    eDirectionBack,
    eDirectionFrontLeft,
    eDirectionFrontRight,
    eDirectionBackLeft,
    eDirectionBackRight,
    eDirectionTest,
    eIAMotorLevel1

}E_Direction;

typedef enum eActionRobot
{
    eActionRobotNone,
    eActionRobotRigole,
    eActionRobotGrandVirageDroite,
    eActionRobotGrandVirageGauche,
    eActionRobotPetitVirageGauche,
    eActionRobotPetitVirageDroite,
    eActionRobotRigoleExterieure,
}E_ActionRobot;

typedef enum eEtatIAMotor
{
    eEtatIAMotorNone,
    eEtatIAMotorAvant,
    eEtatIAMotorGauche,
    eEtatIAMotorDroite,
    eEtatIAMotorArriere,
    eEtatIAMotorDebutVirage,
    eEtatIAMotorFinVirage,
    eEtatIAMotorSortie,
    eEtatIAMotorSortieExterieur,
    eEtatIAMotorSauteRigole,
    eEtatIAMotorSaute,
    eEtatIAMotorEntree,

}E_EtatIAMotor;

typedef enum eEtatPartVirage
{
    eEtatPartVirage0,
    eEtatPartVirage1,
    eEtatPartVirage2

}E_EtatPartVirage;

typedef struct structDataIA
{
    int iDistanceDroite;
    int iDistanceGauche;
    int iDistanceRef;
    int iDistanceFront;
    int iDegreeDroite;
    int iDegreeGauche;
    int iDegreeRef;
    int iDegreeFront;
    QList<double> lstdLargerRigole;
    double dLargerRigoleMoyenne;

}struct_DataIA;

#endif // GLOBAL_H
