//
// Created by moran on 03/12/16.
//

#ifndef TEST1_TRIP_H
#define TEST1_TRIP_H


#include <list>
#include "Point.h"
#include "Driver.h"
#include "Map.h"
#include "Bfs.h"
#include "Cab.h"
#include <stack>

using namespace std;

/**
 * class trip.
 */
class Trip {
private:
    int tripId;
    Point *start;
    Point *end;
    int passengersNum;
    double tariff;
    Driver *driver;
    bool isPending;
    int startTime;
    stack<Point*> *path;
    //stack<Point*> *pathFromDriver;

    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive &ar, const unsigned int version) {
        ar & tripId;
        ar & start;
        ar & end;
        ar & passengersNum;
        ar & tariff;
        ar & driver;
        ar & isPending;
        ar & startTime;
        ar & path;
    }


public:
    //void setPathFromDriver();

    stack<Point *> *getPath();

    void setPath(Map* map);

    Trip(Map *grid, int id, Point *start1, Point *end1, int numOfPassengers,
             double tariff1, int startTrip1);
    Trip();

    bool getIsPending();

    int getTripId();

    Point *getStartPoint();

    Point *getEndPoint();

    int getPassengersNum();

    double getTariff();

    int getStartTime() const;

    void moveOneStep();
    void setStartTime(int startTime);

    void setDriver(Driver *driver1);

    void setPending(bool pending);

    Driver *getDriver();

    friend bool operator==(Trip trip1, Trip trip2);

    friend bool operator!=(Trip trip1, Trip trip2);

    ~Trip();
};

#endif //TEST1_TRIP_H