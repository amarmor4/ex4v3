//
// Created by moran on 19/11/16.
//

#include <iostream>
#include "Matrix.h"

using namespace std;

/**
 * constructor of matrix.
 * @param x number of columes.
 * @param y number of rows.
 * @return nothing.
 */
Matrix::Matrix(int x, int y) {
    sizeX = x;
    sizeY = y;
    createMap();
}

/**
 * destructor.
 */
Matrix::~Matrix() {
    for (int y = 0; y < sizeY; y++) {
        for (int x = 0; x < sizeX; x++) {
            delete map[x][y];
        }
    }
}

/**
 * create 2d matrix pointer of Block - the map of the city.
 * Initialized the matrix with blocks, Initialized each one location and
 * neighbors in the scope of map.
 */
void Matrix::createMap() {
    /*
     * create 2d matrix by vector container.
     * at first create one dimension, after create the 2d.
     * note: the matrix Initialized by b variable, all the blocks have the
     * same address.
     */
    vector<Block *> v(sizeY, NULL);
    vector<vector<Block *> > matrix(sizeX, v);

    map = matrix;

    /**
     * Initialized the matrix with block roads and location.
     * create block road in each block at matrix, the location if the [x][y]
     * values of the matrix. we start with y in oreder to create rows > colums.
     */
    for (int y = 0; y < sizeY; y++) {
        for (int x = 0; x < sizeX; x++) {
            map[x][y] = new Block(Point(x, y));
        }
    }


    /**
     * for each block add his neighbors-members (left, up, right, down) in
     * the map/matrix scope.
     */
    for (int y = 0; y < sizeY; y++) {
        for (int x = 0; x < sizeX; x++) {
            if (x - 1 >= 0) {
                map[x][y]->setLeft(map[x - 1][y]);
            }
            if (y + 1 < sizeY) {
                map[x][y]->setUp(map[x][y + 1]);
            }
            if (x + 1 < sizeX) {
                map[x][y]->setRight(map[x + 1][y]);
            }
            if (y - 1 >= 0) {
                map[x][y]->setDown(map[x][y - 1]);
            }
        }
    }
}

/**
 * get number of rows of matrix.
 * @return number of rows of matrix.
 */
int Matrix::getRowsSize() {
    return this->sizeX;
}

/**
 * get number of column of matrix.
 * @return number of column of matrix.
 */
int Matrix::getColumnsSize() {
    return this->sizeY;
}

/**
 * get the map of the city.
 * @return map of the city.
 */
vector<vector<Block *> > Matrix::getMap() {
    return this->map;
}

/**
 * get pointer to block by giving loaction point.
 * @param point point - location point.
 * @return pointer to the block by givig loaction point.
 */
Block *Matrix::getBlock(Point point) {
    return this->map[point.getX()][point.getY()]->getCurrBlock();
}
/**
 * set obstacle in the map
 * @param num the num of obstacle the user asked
 */
void Matrix::setObstacles(int num) {
    int x, y;
    char c;
    while (num > 0) {
        cin >> x >> c >> y;
        // getting a point in the format x,y
        map[x][y]->setIsObstacle(true);
        num--;
    }

}






