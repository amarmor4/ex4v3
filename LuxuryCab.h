////
//// Created by moran on 03/12/16.
////
//
//#ifndef TEST1_LUXURYCAB_H
//#define TEST1_LUXURYCAB_H
//
//#include <iostream>
//#include "Cab.h"
//
//using namespace std;
//
///**
// * LuxuryCab class.
// */
//class LuxuryCab:public Cab{
//private:
//    int speed;
//    double tariff;
//
//    friend class boost::serialization::access;
//    template<class Archive>
//    void serialize(Archive &ar, const unsigned int version)
//    {
//        ar & boost::serialization::base_object<Cab>(*this);
//        ar & speed;
//    }
//public:
//    LuxuryCab(int id = 0, enum CarType cabType = CarType(0),
//              enum Color color = Color(0), int cabSpeed = 0);
//    int getSpeed();
//    ~LuxuryCab();
//};
//
//
//#endif //TEST1_LUXURYCAB_H
