//
// Created by moran on 28/11/16.
//

#ifndef TEST1_DRIVER_H
#define TEST1_DRIVER_H

#include "Cab.h"
#include "Status.h"
#include "Point.h"
#include "Socket.h"

/**
 * driver class.
 */
class Driver {
private:
    int driverId;
    int age;
    int expYears;
    double avgRate;
    int cabId;
    Status status;
    int numOfDrives;
    // why const?
    Point *currentLocation;
    bool available;
    Cab *cab;


    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & driverId;
        ar & age;
        ar & expYears;
        ar & avgRate;
        ar & cabId;
        ar & status;
        ar & numOfDrives;
        ar & currentLocation;
        ar & available;
        ar & cab;

    }
public:
    Cab *getCab() const;

    int getNumOfDrives();

    Driver(int driverId, int age, Status status, int expYears, int cabId);
    Driver();

    int setDataDriver(Socket* udp);

    int getDriverId();

    int getAge();

    Status getStatus();

    int getExpYears();

    int getCabId() const;

    double getAvgRate();

    Point *getCurrentLocation() const;

    bool isAvailable();

    void setCurrLocation(Point *location);

    void setAvailable(bool isAvailable);

    void setDriverId(int driverId);

    void setAge(int age);

    void setStatus(Status status);

    void setExpYears(int expYears);

    void setAvgRate(double avgRate);

    void setNumOfDrives();

    void setCab(Cab *cab);

    friend bool operator==(Driver driver1, Driver driver);

    friend bool operator!=(Driver driver1, Driver driver);

    ~Driver();
};


#endif //TEST1_DRIVER_H
