//
// Created by moran on 19/11/16.
//
#include <iostream>
#include "Point.h"

using namespace std;

/**
 * constructor of point - get two int x value and y value.
 * @param currX x value.
 * @param currY y value.
 * @return nothing.
 */
Point::Point(int currX, int currY) {
    x = currX;
    y = currY;
}

/**
 * distance of blocks between two points, current point and the given point.
 * @param other point
 * @return the distance between points.
 */
int Point::distance(Point other) {
    return abs(this->x - other.getX()) + abs(this->y - other.getY());
}

/**
 * getX function.
 * @return x value of point.
 */
int Point::getX() {
    return this->x;
}

/**
 * getY function.
 * @return y value of point.
 */
int Point::getY() {
    return this->y;
}

/**
 * check if the current point and the given point are equals.
 * @param other point.
 * @return true if points equals, otherwise false.
 */
bool Point::equals(Point other) {
    return (this->x == other.getX()) && (this->y == other.getY());
}

/**
 * default destructor.
 */
Point::~Point() {

}

/**
 * operator overloading - print.
 * @param os ostream.
 * @param point point.
 * @return ostream.
 */
ostream &operator<<(ostream &os, Point point) {
    os << "(" << point.getX() << "," << point.getY() << ")";
    return os;
}

/**
 * operator ==
 * @param point1 the first point
 * @param point2 the second point
 * @return if point1 == point2
 */
bool operator==(Point point1, Point point2) {
    return point1.getX() == point2.getX() && point1.getY() == point2.getY();
}

