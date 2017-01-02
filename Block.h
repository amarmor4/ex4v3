//
// Created by moran on 19/11/16.
//

#ifndef TEST1_BLOCK_H
#define TEST1_BLOCK_H

#include "Point.h"

class Block {
private:
    Point *location;
    Block *left;
    Block *up;
    Block *right;
    Block *down;
    Block *parent;
    bool isObstacle;

public:
    Block() {};

    Block(Point c);

    Point * getLocation();

    Block *getCurrBlock();

    Block *getLeft();

    Block *getUp();

    Block *getRight();

    Block *getDown();

    Block *getParent();

    void setLeft(Block *bLeft);

    void setUp(Block *bUp);

    void setRight(Block *bRight);

    void setDown(Block *bDown);

    void setParent(Block *bParent);

    void setLocation(Point *c);


    void setIsObstacle(bool isObst);

    bool getIsObstacle();

    ~Block();
};


#endif //TEST1_BLOCK_H
