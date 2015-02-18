#ifndef GLOBAL_H
#define GLOBAL_H

#define DEFAUT_NAME "NAIO01"

typedef enum eIDCommand{

    eIDCommmandAccelero = 0x09,
    eIDCommmandActuator = 0x0C,
    eIDCommmandGPS = 0x0A,
    eIDCommmandLidar = 0x07,
    eIDCommmandMotors = 0x01,
    eIDCommmandOdo = 0x05,
    eIDCommmandRemote = 0x08

}E_IDCommand;


#endif // GLOBAL_H
