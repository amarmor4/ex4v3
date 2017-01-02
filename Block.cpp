//
// Created by moran on 19/11/16.
//

#include "Block.h"

/**
 * constractor block get point, the location of the block at the city
 * map. block also contain his neighbours (left, up, right, down)
 * @param c point of the location at the city
 * @return nothing.
 */
Block::Block(Point c) {
    location = new Point(c.getX(), c.getY());
    left = NULL;
    up = NULL;
    right = NULL;
    down = NULL;
    parent = NULL;
    isObstacle = false;
}

/**
 * destructor
 */
Block::~Block() {
    delete location;
}

/**
 * get the location point of the block at the city.
 * @return location point.
 */
Point * Block::getLocation() {
    return location;
}

/**
 * get pointer to the current block.
 * @return pointer to the current block.
 */
Block *Block::getCurrBlock() {
    return this;
}

/**
 *  get pointer to his left neighbour.
 * @return pointer to his left neighbour of the current block.
 */
Block *Block::getLeft() {
    return left;
}

/**
 * get pointer to his up neighbour.
 * @return pointer to his up neighbour of the current block.
 */
Block *Block::getUp() {
    return up;
}

/**
 * get pointer to his right neighbour.
 * @return pointer to his right neighbour of the current block.
 */
Block *Block::getRight() {
    return right;
}

/**
 * get pointer to his down neighbour.
 * @return pointer to his down neighbour of the current block.
 */
Block *Block::getDown() {
    return down;
}

/**
 * get pointer to his parent at bfs.
 * @return pointer to his parent at bfs.
 */
Block *Block::getParent() {
    return parent;
}

/**
 * set the pointer to his left neighbour.
 * @param bLeft pointer of his left neighbour.
 */
void Block::setLeft(Block *bLeft) {
    left = bLeft;
}

/**
 * set the pointer to his up neighbour.
 * @param bUp pointer of his up neighbour.
 */
void Block::setUp(Block *bUp) {
    up = bUp;
}

/**
 * set the pointer to his right neighbour.
 * @param bRight pointer of his right neighbour.
 */
void Block::setRight(Block *bRight) {
    right = bRight;
}

/**
 * set the pointer to his down neighbour.
 * @param bDown pointer of his down neighbour.
 */
void Block::setDown(Block *bDown) {
    down = bDown;
}

/**
 * set the location point of the current block.
 * @param c location point of the current block.
 */
void Block::setLocation(Point *c) {
    location = c;
}

/**
 * set pointer to his parent at bfs.
 * @param bParent pointer of the parent at bfs.
 */
void Block::setParent(Block *bParent) {
    parent = bParent;
}
/**
 * if the user put an obstacle in this location
 * @param isObst will set if this location is obstacle
 */
void Block::setIsObstacle(bool isObst) {
    isObstacle = isObst;
}
/**
 * access.
 * @return if this block is obstacle
 */
bool Block::getIsObstacle() {
    return isObstacle;
}