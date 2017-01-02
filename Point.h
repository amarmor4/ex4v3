//
// Created by moran on 19/11/16.
//

#ifndef TEST1_POINT_H
#define TEST1_POINT_H

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/assign/list_of.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/iostreams/device/back_inserter.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>

using namespace std;

/**
 * point.
 */
class Point {
private:
    int x;
    int y;


    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive &ar, const unsigned int version) {
        ar & x;
        ar & y;
    }
public:
    Point(int x = 0, int y = 0);

    int distance(Point other);

    int getX();

    int getY();

    bool equals(Point other);

    friend ostream &operator<<(ostream &os, Point point);

    friend bool operator==(Point point1, Point point2);
    ~Point();
};


#endif //TEST1_POINT_H
