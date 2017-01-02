#include <iostream>
//#include "gtest/gtest.h"
#include "Matrix.h"
#include "Map.h"
#include "Bfs.h"
#include "GameFlow.h"
#include "Udp.h"
#include <unistd.h>

using namespace std;

int main(int args, char **argv) {
    /**
     * get input from user.
     * width of map >> height of map >> x value of start point >>
     * y value of start point >> x value of end point >> y value of end point.
     * format: 4_4,3_2,1_2
     */
    int sizeX, sizeY, numOfObstacles;
    cin >> sizeX >> sizeY;

    // create matrix.
    Matrix matrix(sizeX, sizeY);
    //Matrix matrix(6, 6);
    // save matrix address at map object.
    Map *map = &matrix;
    Bfs bfs(map);
    //set obstacles
    cin >> numOfObstacles;
    if (numOfObstacles > 0) {
        map->setObstacles(numOfObstacles);
    }
    GameFlow *g = new GameFlow(map, atoi(argv[1]));
    g->startGame();

    delete (g);

    return 0;
}
