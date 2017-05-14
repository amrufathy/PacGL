//
// Created by amr on 5/14/17.
//

#include "Maze.h"

Maze::Maze() {
    Type temp_map[MAZEHEIGHT][MAZEWIDTH] = {
            {WALL, WALL, WALL, WALL, WALL, WALL},
            {WALL, PATH, WALL, PATH, PATH, PATH},
            {WALL, PATH, GIFT, PATH, WALL, PATH},
            {WALL, PATH, WALL, PATH, WALL, PATH},
            {WALL, PATH, PATH, PATH, BOMB, PATH},
            {WALL, WALL, WALL, WALL, WALL, WALL}
    };

    temp_map[PACMAN_START_X][PACMAN_START_Y] = PLAYER;

    // allocate memory
    this->map = new Type *[MAZEHEIGHT];
    for (int j = 0; j < MAZEHEIGHT; j++) {
        this->map[j] = new Type[MAZEWIDTH];
    }

    // copy map
    for (int i = 0; i < MAZEHEIGHT; i++) {
        for (int j = 0; j < MAZEWIDTH; j++) {
            this->map[i][j] = temp_map[i][j];
        }
    }
}

void Maze::draw(int x, int y) {
    for (int i = 0; i < MAZEHEIGHT; i++) {
        for (int j = 0; j < MAZEWIDTH; j++) {
            Tile t(this->map[i][j]);
            t.draw(i, j);
        }
    }
}

Type **Maze::getMap() {
    return this->map;
}