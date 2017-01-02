//
// Created by moran on 03/12/16.
//

#ifndef TEST1_CAB_H
#define TEST1_CAB_H

#include <iostream>
#include <boost/serialization/access.hpp>
#include "Color.h"
#include "CarType.h"
#include "Point.h"
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/export.hpp>
using namespace std;

/**
 * cab class.
 */
class Cab {
private:
    int cabId;
    double numOfKm;
    CarType carType;
    Color cabColor;
    int speed;
public:
    int getSpeed() const;

private:
    double tarrif;
public:
    void setSpeed(int speed);

    double getTarrif() const;

    void setTarrif(double tarrif);

private:


    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive &ar, const unsigned int version) {
        ar & cabId;
        ar & carType;
        ar & cabColor;
        ar & speed;
        ar & tarrif;

    }

public:
    Cab(int id , CarType cabType, Color color, int speed, double tarrif);
    Cab();

    int getCabId();

    double getNumOfKm();

    CarType getCarType();

    Color getColor();


    //friend bool operator==(Cab cab1, Cab cab2);

     ~Cab();

};

//BOOST_SERIALIZATION_ASSUME_ABSTRACT(Cab)
#endif //TEST1_CAB_H
