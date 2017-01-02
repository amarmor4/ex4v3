//
// Created by moran on 03/12/16.
//

#ifndef TEST1_PASSENGER_H
#define TEST1_PASSENGER_H

#include "Point.h"

/**
 * Passenger class.
 */
class Passenger {
private:
    Point* sourcePoint;
    Point* destinationPoint;
public:
    Passenger(Point* sourceP, Point* destinationP);
    Point* getSourcePoint();
    Point* getDestinationPoint();
    ~Passenger();
};


#endif //TEST1_PASSENGER_H
