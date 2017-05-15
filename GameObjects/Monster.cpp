//
// Created by amr on 5/15/17.
//

#include "Monster.h"
#include <iostream>

Monster::Monster(Type **maze, int start_x, int start_y) :
        Tile(MONSTER, start_x, start_y) {

    maze[this->x][this->y] = MONSTER;
    last_cell = PATH;
}

void Monster::draw(int x, int y) {
    Tile::draw(this->x, this->y);
}

bool Monster::canGoToCell(Type new_cell) {
    return new_cell == PATH || new_cell == GIFT || new_cell == BOMB || new_cell == PLAYER;
}

void Monster::move(Type **maze) {
    std::uniform_int_distribution<int> distribution(0, 3);
    int random = distribution(generator);

    if (random == 0) {
        this->goUp(maze);
    } else if (random == 1) {
        this->goDown(maze);
    } else if (random == 2) {
        this->goLeft(maze);
    } else {
        this->goRight(maze);
    }
}

bool Monster::canGoUp(Type **maze) {
    if (this->x - 1 < MAZEHEIGHT) {
        Type new_cell = maze[this->x - 1][this->y];
        if (this->canGoToCell(new_cell))
            return true;
    }
    return false;
}

void Monster::goUp(Type **maze) {
    if (this->canGoUp(maze)) {
        going_cell = maze[this->x - 1][this->y];
        maze[this->x][this->y] = last_cell;
        this->x--;
        this->update(maze);
        last_cell = going_cell;
    }
    maze[this->x][this->y] = MONSTER;
}

bool Monster::canGoDown(Type **maze) {
    if (this->x + 1 >= 0) {
        Type new_cell = maze[this->x + 1][this->y];
        if (this->canGoToCell(new_cell))
            return true;
    }
    return false;
}

void Monster::goDown(Type **maze) {
    if (this->canGoDown(maze)) {
        going_cell = maze[this->x + 1][this->y];
        maze[this->x][this->y] = last_cell;
        this->x++;
        this->update(maze);
        last_cell = going_cell;
    }
    maze[this->x][this->y] = MONSTER;
}

bool Monster::canGoLeft(Type **maze) {
    if (this->y - 1 >= 0) {
        Type new_cell = maze[this->x][this->y - 1];
        if (this->canGoToCell(new_cell))
            return true;
    }
    return false;
}

void Monster::goLeft(Type **maze) {
    if (this->canGoLeft(maze)) {
        going_cell = maze[this->x][this->y - 1];
        maze[this->x][this->y] = last_cell;
        this->y--;
        this->update(maze);
        last_cell = going_cell;
    }
    maze[this->x][this->y] = MONSTER;
}

bool Monster::canGoRight(Type **maze) {
    if (this->y + 1 < MAZEWIDTH) {
        Type new_cell = maze[this->x][this->y + 1];
        if (this->canGoToCell(new_cell))
            return true;
    }
    return false;
}

void Monster::goRight(Type **maze) {
    if (this->canGoRight(maze)) {
        going_cell = maze[this->x][this->y + 1];
        maze[this->x][this->y] = last_cell;
        this->y++;
        this->update(maze);
        last_cell = going_cell;
    }
    maze[this->x][this->y] = MONSTER;
}

void Monster::update(Type **) {

}