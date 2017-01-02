////
//// Created by moran on 03/12/16.
////
//
//#include "StandardCab.h"
//
///**
// * constractor.
// * @param id cab id.
// * @param km number of km of cab.
// * @param cabType cab type.
// * @param color cab color.
// * @param cabSpeed cab speed.
// * @param cabTarif cab tarif.
// * @return nothing.
// */
//StandardCab::StandardCab(int id, enum CarType cabType,
//                         enum Color color, int
//                         cabSpeed) :
//        Cab(id, cabType, color, 0, 0) {
//    speed = cabSpeed;
//}
//
///**
// * get speed of cab.
// * @return speed of cab.
// */
//int StandardCab::getSpeed() {
//    return this->speed;
//}
//
///**
// * destructor.
// */
//StandardCab::~StandardCab() {
//
//}
//BOOST_CLASS_EXPORT(StandardCab)