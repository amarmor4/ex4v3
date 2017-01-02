//
// Created by moran on 24/11/16.
//

#ifndef TEST1_BFS_H
#define TEST1_BFS_H

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include "Block.h"
#include "Map.h"
#include "Point.h"


/**
 * bfs algorithm to find the shortest path from source point to
 * destination and print the path - locations points of blocks.
 */
class Bfs {
private:
    Map *map;
public:
    Bfs(Map *map);

    Block *findPath(Point *start, Point *end);

    int findNumOfSteps(Point *start, Point *end);

    stack<Point*> *getPath(Point *start, Point *end);

    Block *getNeighborSide(Block *curr, int side);

    ~Bfs();
};


#endif //TEST1_BFS_H
