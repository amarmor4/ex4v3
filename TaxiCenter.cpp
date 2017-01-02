//
// Created by moran on 03/12/16.
//

#include "TaxiCenter.h"

using namespace std;

/**
 * constructor TaxiCenter doesn't get any argument, the vectors are
 * initialize in the .h file
 */
TaxiCenter::TaxiCenter() {
}

/**
 * destructor.
 */
TaxiCenter::~TaxiCenter() {
    while (!trips.empty()) {
        Trip *t = trips.back();  // get the trip
        trips.pop_back();        // take out the trip from the vector
        delete (t);              // delete the trip
    }

    while (!driversInfo.empty()) {
        Driver *d = driversInfo.back();
        driversInfo.pop_back();
        delete (d);
    }

    while (!cabs.empty()) {
        Cab *c = cabs.back();
        cabs.pop_back();
        delete (c);
    }
}

/**
 * set vector of driversinfo
 * @param driversInfo the vector to set
 */
void TaxiCenter::setDriversInfo(const vector<Driver *> &driversInfo) {
    TaxiCenter::driversInfo = driversInfo;
}

/**
 * set cabs vector.
 * @param cabs the vector to set
 */
void TaxiCenter::setCabs(const vector<Cab *> &cabs) {
    TaxiCenter::cabs = cabs;
}

/**
 * set trips vector.
 * @param trips the vector to set
 */
void TaxiCenter::setTrips(const vector<Trip *> &trips) {
    TaxiCenter::trips = trips;
}

/**
 * access.
 * @return the driversInfo vector
 */
const vector<Driver *> &TaxiCenter::getDriversInfo() const {
    return driversInfo;
}

/**
 * access.
 * @return the cabs vector
 */
const vector<Cab *> &TaxiCenter::getCabs() const {
    return cabs;
}

/**
 * access.
 * @return the trips vector
 */
const vector<Trip *> &TaxiCenter::getTrips() const {
    return trips;
}

/**
 * add one driver to driversInfo vector, each driver get connected to his cab
 * @param driver the new driver
 */
void TaxiCenter::addDriverInfo(Driver *driver) {
    driversInfo.push_back(driver);
    if (!cabs.empty()) {
        for (vector<Cab *>::iterator itCabs = cabs.begin();
             itCabs != cabs.end(); itCabs++) {
            if ((*itCabs)->getCabId() == driver->getCabId()) {
                driver->setCab((*itCabs));
            }
        }
    }
}

/**
 * add one cab to cabs vector
 * @param cab the new cab
 */
void TaxiCenter::addCab(Cab *cab) {
    cabs.push_back(cab);

}

/**
 * add one trip to trips vectoe
 * @param trip the new trip
 */
void TaxiCenter::addTrip(Trip *trip) {
    trips.push_back(trip);

}

/**
 * get the number of the drivers
 * @return the num of drivers
 */
long TaxiCenter::numOfDrivers() {
    return driversInfo.size();
}

/**
 * get the number of the cabs
 * @return the num of cabs
 */
long TaxiCenter::numOfCab() {
    return cabs.size();
}

/**
 * get the number of the trips
 * @return the num of trips
 */
long TaxiCenter::numOfTrips() {
    return trips.size();
}

/**
 * delete the first trip, to do that we need a temp vector, we transfer all
 * the trips from trips vector to temp, getting the last trip from temp (was
 * the first in trips) and returning all the trips to trips vector
 */
void TaxiCenter::popTrip() {
    vector<Trip *> temp;
    while (!trips.empty()) {
        temp.push_back(trips.back());
        trips.pop_back();
    }
    Trip *t = temp.back();
    temp.pop_back();
    t->getDriver()->setAvailable(true);
    delete (t);
    while (!temp.empty()) {
        trips.push_back((temp.back()));
        temp.pop_back();
    }
}

/**
 * delete the first driver, to do that we need a temp vector, we transfer all
 * the drivers from driversInfo vector to temp, getting the last trip from temp
 * (was the first in driversInfo) and returning all the drivers to driversInfo
 * vector
 */

void TaxiCenter::popDriver() {
    vector<Driver *> temp;
    while (!driversInfo.empty()) {
        temp.push_back(driversInfo.back());
        driversInfo.pop_back();
    }
    Driver *d = temp.back();
    temp.pop_back();
    delete (d);
    while (!temp.empty()) {
        driversInfo.push_back((temp.back()));
        temp.pop_back();
    }
}

/**
 * delete the first cab, to do that we need a temp vector, we transfer all
 * the cabs from cabs vector to temp, getting the last cab from temp (was
 * the first in cabs) and returning all the cabs to cabs vector
 */

void TaxiCenter::popCab() {
    vector<Cab *> temp;
    while (!cabs.empty()) {
        temp.push_back(cabs.back());
        cabs.pop_back();
    }
    Cab *c = temp.back();
    temp.pop_back();
    delete (c);
    while (!temp.empty()) {
        cabs.push_back((temp.back()));
        temp.pop_back();
    }
}

/**
 * get the driver
 * @return the first driver in the vector
 */
Driver *TaxiCenter::getDriver() {
    return driversInfo[0];
}
