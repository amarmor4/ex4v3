//
// Created by moran on 03/12/16.
//

#include "Passenger.h"

/**
 * constractor of passenger.
 * @param sourceP source point of passenger.
 * @param destinationP destination point of passenger.
 * @return nothing.
 */
Passenger::Passenger(Point* sourceP, Point* destinationP){
    sourcePoint=sourceP;
    destinationPoint=destinationP;
}

/**
 * get pointer to passenger source point.
 * @return pointer to passenger source point.
 */
Point* Passenger::getSourcePoint(){
    return this->sourcePoint;
}

/**
 * get pointer to passenger destination point.
 * @return pointer to passenger destination point.
 */
Point* Passenger::getDestinationPoint(){
    return this->destinationPoint;
}

/**
 * destructor.
 */
Passenger::~Passenger(){

}