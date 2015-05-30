#ifndef GLOBAL_H
#define GLOBAL_H

#include <QObject>
#include <math.h>

#define DEFAUT_NAME "NAIO01"
#define PI 3.14159265
#define PI_180 (PI / 180.0)

#define LARGEUR_OZ 420
#define LONGUEUR_OZ 1000

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

typedef enum ePositionRobot
{
    ePositionRobotNone,
    ePositionRobotRigole,
    ePositionRobotGrandVirageDroite,
    ePositionRobotGrandVirageGauche,
    ePositionRobotPetitVirageGauche,
    ePositionRobotPetitVirageDroite,
    ePositionRobotRigoleExterieure

}E_ActionRobot;

typedef enum eEtatIAMotor
{
    eEtatIAMotorNone,
    eEtatIAMotorAvant,
    eEtatIAMotorGauche,
    eEtatIAMotorDroite,
    eEtatIAMotorReculeVirage,
    eEtatIAMotorDebutVirage,
    eEtatIAMotorFinVirage,
    eEtatIAMotorSortieRigole,
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

typedef struct structVirageData
{
    bool bInverse;
    int iDistanceSide;
    int iDistanceOpposite;
    int iDegreeSide;
    int iDegreeOpposite;

}struct_VirageData;

typedef struct structNuagePoint
{
    bool bInverse;
    int iDistanceSide;
    int iDistanceOpposite;
    int iDegreeSide;
    int iDegreeOpposite;

}struct_NuagePoint;

#endif // GLOBAL_H
