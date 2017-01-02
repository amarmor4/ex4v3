//
// Created by moran on 24/11/16.
//

#include <iostream>
#include "Bfs.h"


using namespace std;

/**
 * constructor of bfs.
 * @param map1 the map of the city.
 * @param startX x value of source block.
 * @param startY y value of source block.
 * @param endX x value of destination block.
 * @param endY y value of destination block.
 * @return
 */
//Bfs::Bfs(Map *map1, int startX, int startY, int endX, int endY) {
Bfs::Bfs(Map *map1) {
    map = map1;
}

/**
 * destructor
 */
Bfs::~Bfs() {

}

/**
 * find the shortest path from source block to destination block.
 * @return block.
 */
Block *Bfs::findPath(Point *start, Point *end) {
    /**
     * create boolean vector 2d with map size in order to flag block that was
     * visited. Initialized with false - no one was visited yet.
     */
    vector<bool> v(map->getColumnsSize(), false);
    vector<vector<bool> > visited(map->getRowsSize(), v);

    // Initialized parent filed with null, in each block at map.
    for (int y = 0; y < map->getColumnsSize(); y++) {
        for (int x = 0; x < map->getRowsSize(); x++) {
            map->getBlock(Point(x, y))->setParent(NULL);
        }
    }

    queue<Block *> path;
    path.push(map->getBlock(*start));
    visited[start->getX()][start->getY()] = true;

    while (!path.empty()) {
        Block *currBlock = path.front();
        path.pop();
        if (currBlock->getLocation()->equals(*end)) {
            queue<Block *> empty;
            swap(path, empty);
            vector<vector<bool> > visited();
            return currBlock;
        }
        /**
         * pass over all the neighbors. in order: left(0), up(1), right(2),
         * down(3).
         */
        for (int i = 0; i < 4; i++) {
            // save pointer to block neighbor.
            Block *neighbor = getNeighborSide(currBlock, i);
            // if neighbor is not null.
            if (neighbor) {
                // if block neighbor wasn't visited yet.
                if (visited[neighbor->getLocation()->getX()
                    ][neighbor->getLocation()->getY()] == false) {
                    // flag block neighbor has visited.
                    visited[neighbor->getLocation()->getX()
                    ][neighbor->getLocation()->getY()] = true;
                    // set pointer to parent in "child" block.
                    neighbor->setParent(currBlock);
                    path.push(neighbor);
                }
            }
        }
    }
}

/**
 * print the points from source block to destination block.
 * @param currBlock that return from findPath().
 */
stack<Point *>  *Bfs::getPath(Point *start, Point *end) {
    Block *currBlock = this->findPath(start, end);
    // create stack and push all the parents from destination block to source.
    stack<Point *> *path = new stack<Point*>;

    path->push(currBlock->getLocation());
    while (!currBlock->getLocation()->equals(*start)) {
        path->push(currBlock->getParent()->getLocation());
        currBlock = currBlock->getParent();
    }
    path->pop();
    return path;
}

/**
 * find num of steps from start point to end point
 * @param start point
 * @param end point
 * @return num of steps from start point to end point.
 */
int Bfs::findNumOfSteps(Point *start, Point *end) {
    int counter = 0;
    Block *block = this->findPath(start, end);
    // create stack and push all the parents from destination block to source.
    stack<Block *> path;
    path.push(block);
    while (!block->getLocation()->equals(*start)) {
        path.push(block->getParent());
        block = block->getParent();
    }
    // pop and count
    while (!path.empty()) {
        block = path.top();
        path.pop();
        counter++;
    }
    return counter;
}


/**
 * get pointer to the neighbor at the side that was get.
 * @param currBlock block that want to get his neighbor.
 * @param side of the neighbor - left (0), up(1), right(2), down(3).
 * @return pointer to the neighbor at the side that was get.
 */
Block *Bfs::getNeighborSide(Block *currBlock, int side) {
    Block *block = NULL;
    switch (side) {
        case 0:
            block = currBlock->getLeft();
            break;
        case 1:
            block = currBlock->getUp();
            break;
        case 2:
            block = currBlock->getRight();
            break;
        case 3:
            block = currBlock->getDown();
            break;
        default:
            break;
    }
    if (block != NULL) {
        if (!block->getIsObstacle()) {
            return block;
        }
    }
    return NULL;
}

