//
// Created by moran on 19/11/16.
//

#ifndef TEST1_MAP_H
#define TEST1_MAP_H

#include <stdlib.h>
#include "Block.h"
#include <vector>


using std::vector;

/**
 * map is abstract class.
 * in order to be able to change the container if we need at work later.
 */
class Map {
private:
public:
    Map() {};

    virtual void createMap() {};

    virtual int getRowsSize() {};

    virtual int getColumnsSize() {};

    virtual vector<vector<Block *> > getMap() {};

    virtual Block *getBlock(Point point) {};

    virtual void setObstacles(int num) {};

    virtual ~Map() {};

};


#endif //TEST1_MAP_H
