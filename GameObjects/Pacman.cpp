//
// Created by amr on 5/14/17.
//

#include "Pacman.h"

Pacman::Pacman() : Tile(PLAYER, PACMAN_START_X, PACMAN_START_Y) {
}

bool Pacman::canGoUp(Type **maze) {
    if (this->x - 1 < MAZEHEIGHT) {
        if (maze[this->x - 1][this->y] == PATH)
            return true;
    }
    return false;
}

void Pacman::goUp(Type **maze) {
    if (this->canGoUp(maze)) {
        maze[this->x][this->y] = PATH;
        this->x--;
    }
    maze[this->x + 1][this->y] = PATH;
    maze[this->x][this->y] = PLAYER;
}

bool Pacman::canGoDown(Type **maze) {
    if (this->x + 1 >= 0) {
        if (maze[this->x + 1][this->y] == PATH)
            return true;
    }
    return false;
}

void Pacman::goDown(Type **maze) {
    if (this->canGoDown(maze)) {
        maze[this->x][this->y] = PATH;
        this->x++;
    }
    maze[this->x][this->y] = PLAYER;
}

bool Pacman::canGoLeft(Type **maze) {
    if (this->y - 1 >= 0) {
        if (maze[this->x][this->y - 1] == PATH)
            return true;
    }
    return false;
}

void Pacman::goLeft(Type **maze) {
    if (this->canGoLeft(maze)) {
        maze[this->x][this->y] = PATH;
        this->y--;
    }
    maze[this->x][this->y] = PLAYER;
}

bool Pacman::canGoRight(Type **maze) {
    if (this->y + 1 < MAZEWIDTH) {
        if (maze[this->x][this->y + 1] == PATH)
            return true;
    }
    return false;
}

void Pacman::goRight(Type **maze) {
    if (this->canGoRight(maze)) {
        maze[this->x][this->y] = PATH;
        this->y++;
    }
    maze[this->x][this->y] = PLAYER;
}


void Pacman::draw(int x, int y) {
    Tile::draw(this->x, this->y);
}