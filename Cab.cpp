//
// Created by moran on 03/12/16.
//

#include "Cab.h"

/**
 * constractor.
 * @param id cab id.
 * @param km number of km.
 * @param cabType cab type.
 * @param color color of cab.
 * @return
 */
Cab::Cab(int id, CarType cabType, Color color, int speed1, double tarrif1) {
    cabId = id;
    carType = cabType;
    cabColor = color;
    speed = speed1;
    tarrif = tarrif1;

}
Cab::Cab() {

}
/**
 * get cab id.
 * @return cab id.
 */
int Cab::getCabId() {
    return this->cabId;
}

/**
 * get number of km of cab.
 * @return number of km of cab.
 */
double Cab::getNumOfKm() {
    return this->numOfKm;
}

/**
 * get car type.
 * @return car type.
 */
CarType Cab::getCarType() {
    return this->carType;
}

/**
 * get color of cab.
 * @return color of cab.
 */
Color Cab::getColor() {
    return this->cabColor;
}

/**
 * destructor.
 */
Cab::~Cab() {

}

void Cab::setSpeed(int speed) {
    Cab::speed = speed;
}

double Cab::getTarrif() const {
    return tarrif;
}

void Cab::setTarrif(double tarrif) {
    Cab::tarrif = tarrif;
}

int Cab::getSpeed() const {
    return speed;
}
//bool operator==(Cab cab1, Cab cab2){
//    return cab1.getCabId() == cab2.getCabId()&&
//            cab1.getNumOfKm() == cab2.getNumOfKm()&&
//           cab1.getCarType()==cab2.getCarType() &&
//           cab1.getColor() == cab2.getColor();
//
//}