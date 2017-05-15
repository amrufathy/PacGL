//
// Created by amr on 5/14/17.
//

#include "Maze.h"

Maze::Maze() {
    Type temp_map[MAZEHEIGHT][MAZEWIDTH] = {
            {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
            {WALL, PATH, PATH, GIFT, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, WALL, PATH, PATH, PATH, PATH, PATH, GIFT, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, WALL},
            {WALL, PATH, PATH, WALL, WALL, WALL, PATH, PATH, PATH, WALL, WALL, WALL, WALL, PATH, PATH, WALL, PATH, PATH, WALL, WALL, WALL, WALL, PATH, PATH, PATH, WALL, WALL, WALL, WALL, PATH, WALL},
            {WALL, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, WALL},
            {WALL, PATH, PATH, WALL, WALL, WALL, PATH, PATH, BOMB, WALL, PATH, PATH, WALL, WALL, WALL, WALL, WALL, WALL, WALL, PATH, PATH, WALL, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, WALL},
            {WALL, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, WALL, PATH, PATH, PATH, PATH, PATH, WALL, PATH, PATH, PATH, PATH, PATH, WALL, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, WALL},
            {WALL, WALL, WALL, WALL, WALL, WALL, PATH, PATH, PATH, WALL, WALL, WALL, WALL, PATH, PATH, WALL, PATH, PATH, WALL, WALL, WALL, WALL, PATH, PATH, PATH, WALL, WALL, WALL, WALL, WALL, WALL},
            {PATH, PATH, PATH, PATH, PATH, WALL, GIFT, PATH, PATH, WALL, PATH, PATH, PATH, PATH, GIFT, PATH, PATH, PATH, PATH, PATH, PATH, WALL, PATH, PATH, PATH, WALL, PATH, PATH, PATH, PATH, PATH},
            {PATH, PATH, PATH, PATH, PATH, WALL, PATH, PATH, PATH, WALL, PATH, BOMB, WALL, WALL, WALL, WALL, WALL, WALL, WALL, PATH, PATH, WALL, PATH, PATH, PATH, WALL, PATH, PATH, PATH, PATH, PATH},
            {WALL, WALL, WALL, WALL, WALL, WALL, PATH, PATH, PATH, PATH, PATH, PATH, WALL, PATH, PATH, BOMB, PATH, PATH, WALL, PATH, PATH, PATH, PATH, PATH, PATH, WALL, WALL, WALL, WALL, WALL, WALL},
            {WALL, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, WALL, PATH, PATH, PATH, PATH, PATH, WALL, PATH, PATH, GIFT, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, WALL},
            {WALL, WALL, WALL, WALL, WALL, WALL, PATH, PATH, PATH, WALL, PATH, PATH, WALL, WALL, WALL, WALL, WALL, WALL, WALL, PATH, PATH, WALL, PATH, PATH, PATH, WALL, WALL, WALL, WALL, WALL, WALL},
            {PATH, PATH, PATH, PATH, PATH, WALL, PATH, PATH, PATH, WALL, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, WALL, PATH, PATH, PATH, WALL, PATH, PATH, PATH, PATH, PATH},
            {PATH, PATH, PATH, PATH, PATH, WALL, PATH, PATH, PATH, WALL, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, WALL, PATH, PATH, PATH, WALL, PATH, PATH, PATH, PATH, PATH},
            {WALL, WALL, WALL, WALL, WALL, WALL, PATH, PATH, PATH, WALL, PATH, PATH, WALL, WALL, WALL, WALL, WALL, WALL, WALL, PATH, PATH, WALL, PATH, PATH, PATH, WALL, WALL, WALL, WALL, WALL, WALL},
            {WALL, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, WALL, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, WALL},
            {WALL, PATH, PATH, WALL, WALL, WALL, PATH, PATH, PATH, WALL, WALL, WALL, WALL, PATH, PATH, WALL, PATH, PATH, WALL, WALL, WALL, WALL, PATH, PATH, PATH, WALL, WALL, WALL, PATH, PATH, WALL},
            {WALL, PATH, PATH, PATH, GIFT, WALL, PATH, PATH, PATH, PATH, PATH, PATH, BOMB, PATH, PATH, GIFT, PATH, PATH, PATH, PATH, PATH, BOMB, PATH, PATH, PATH, WALL, PATH, PATH, PATH, PATH, WALL},
            {WALL, WALL, WALL, PATH, PATH, WALL, PATH, PATH, GIFT, WALL, PATH, PATH, WALL, WALL, WALL, WALL, WALL, WALL, WALL, PATH, PATH, WALL, PATH, PATH, PATH, WALL, PATH, PATH, WALL, WALL, WALL},
            {WALL, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, WALL, PATH, PATH, PATH, PATH, PATH, WALL, PATH, PATH, PATH, PATH, PATH, WALL, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, WALL},
            {WALL, PATH, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, PATH, PATH, WALL, BOMB, PATH, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, PATH, WALL},
            {WALL, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, PATH, WALL},
            {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL}
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