//
// Created by moran on 03/12/16.
//

#include "Trip.h"
/**
 * constructor.
 * @param id
 * @param currLocationP
 * @param passengersList
 * @param numOfPassengers
 * @return
 */
Trip::Trip(Map *map, int id, Point *start1, Point *end1, int numOfPassengers,
           double tariff1, int startTrip1) {
    tripId = id;
    start = start1;
    end = end1;
    passengersNum = numOfPassengers;
    tariff = tariff1;
    driver = NULL;
    isPending = true;
    startTime = startTrip1;
    this->setPath(map);
    //pathFromDriver = NULL;
}

/**
 * get true if still pending, false if ride done.
 * @return  true if still pending, false if ride done.
 */
bool Trip::getIsPending() {
    return this->isPending;
}

/**
 * get trip id.
 * @return trip id.
 */
int Trip::getTripId() {
    return this->tripId;
}

/**
 * get pointer to the start point of the trip.
 * @return pointer to startPoint.
 */
Point *Trip::getStartPoint() {
    return this->start;
}

/**
 * get pointer to the end point of the trip.
 * @return pointer to endPoint.
 */
Point *Trip::getEndPoint() {
    return this->end;
}

/**
 * get the tariff of the ride.
 * @return the tariff.
 */
double Trip::getTariff() {
    return this->tariff;
}

/**
 * get number of passengers.
 * @return number of passengers.
 */
int Trip::getPassengersNum() {
    return this->passengersNum;
}

/**
 * set a driver to this trip if this trip driver is already set and we want
 * to chnge this trip driver, first we need to initialize the old driver that
 * now is available
 * @param driver1 the driver we want to set
 */
void Trip::setDriver(Driver *driver1) {
    if (driver != NULL) {
        driver->setAvailable(true);
    }
    driver = driver1;
    driver->setAvailable(false);
}

/**
 * get the driver of this trip
 * @return the driver -- maybe NULL
 */
Driver *Trip::getDriver() {
    if (this->driver) {
        return this->driver;
    }
    return NULL;
}

/**
 * set pending.
 * @param pending true if still pending, false if ride done.
 */
void Trip::setPending(bool pending) {
    this->isPending = pending;
}

/**
 * overLoading operator ==
 * @param trip1 the first trip
 * @param trip2 the second trip
 * @return if trip1 is equal to trip2
 */
bool operator==(Trip trip1, Trip trip2) {
    return trip1.getTripId() == trip2.getTripId() &&
           trip1.getStartPoint() == trip2.getStartPoint() &&
           trip1.getEndPoint() == trip2.getEndPoint() &&
           trip1.getPassengersNum() == trip2.getPassengersNum() &&
           trip1.getTariff() == trip2.getTariff();

}

/**
 * overLoading operator !=
 * @param trip1 the first trip
 * @param trip2 the second trip
 * @return if trip1 is not equal to trip2
 */
bool operator!=(Trip trip1, Trip trip2) {
    return !(trip1 == trip2);
}

/**
 * destructor.
 */
Trip::~Trip() {
    delete (start);
    delete (end);
    delete (path);
}

int Trip::getStartTime() const {
    return startTime;
}

void Trip::setStartTime(int startTime) {
    Trip::startTime = startTime;
}

stack<Point *> *Trip::getPath() {
    return path;
}

void Trip::setPath(Map *map) {
    Bfs bfs(map);
    path = bfs.getPath(start, end);
}

void Trip::moveOneStep() {
    int numOfSteps;
    if (driver != NULL) {
        numOfSteps = driver->getCab()->getSpeed();
        while (numOfSteps > 0 && (!path->empty())) {
            driver->setCurrLocation(path->top());
            path->pop();
            numOfSteps--;
        }
    }
}


