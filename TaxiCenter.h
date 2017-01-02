//
// Created by moran on 03/12/16.
//

#ifndef TEST1_TAXICENTER_H
#define TEST1_TAXICENTER_H

#include <list>
#include <algorithm>
#include "Driver.h"
#include "Point.h"
#include "Cab.h"
#include "Trip.h"


class TaxiCenter {
private:
    vector<Driver *> driversInfo;
    vector<Cab *> cabs;
    vector<Trip *> trips;
public:
    TaxiCenter();

    void addDriverInfo(Driver *driver);

    void addCab(Cab *cab);

    void addTrip(Trip *trip);

    void popTrip();

    void popDriver();

    void popCab();

    long numOfDrivers();

    long numOfCab();

    long numOfTrips();

    ~TaxiCenter();

    Driver * getDriver();

    void setDriversInfo(const vector<Driver *> &driversInfo);

    void setCabs(const vector<Cab *> &cabs);

    void setTrips(const vector<Trip *> &trips);

    const vector<Driver *> &getDriversInfo() const;

    const vector<Cab *> &getCabs() const;

    const vector<Trip *> &getTrips() const;
};


#endif //TEST1_TAXICENTER_H
