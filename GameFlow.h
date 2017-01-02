//
// Created by yarden95c on 08/12/16.
//

#ifndef EX3_MENU_H
#define EX3_MENU_H

#include <iostream>
#include <list>
#include "Status.h"
#include "Map.h"
#include "TaxiCenter.h"
#include "Color.h"
#include "CarType.h"
#include "LuxuryCab.h"
#include "StandardCab.h"
#include "Socket.h"


class GameFlow {
private:
    Map *grid;
    TaxiCenter *taxiCenter;
    Socket *comm;
    int time;
    int portNo;

public:
    GameFlow(Map *map, int portNo);

    void establishCommunication();

    void startGame();

    void recieveDrivers();

    void insertARide();

    void insertAVehicle();

    void printDriverLocation();

    void moveTheClock();

    void sendClientNewLocation();

    void killTheClient();

    ~GameFlow();

};


#endif //EX3_MENU_H
