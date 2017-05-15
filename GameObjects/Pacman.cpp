//
// Created by amr on 5/14/17.
//

#include "Pacman.h"

Pacman::Pacman() : Tile(PLAYER, PACMAN_START_X, PACMAN_START_Y) {
    score = 0;
    lives = 3;
}

bool Pacman::canGoToCell(Type new_cell) {
    return new_cell == PATH || new_cell == GIFT || new_cell == BOMB;
}

bool Pacman::canGoUp(Type **maze) {
    if (this->x - 1 < MAZEHEIGHT) {
        Type new_cell = maze[this->x - 1][this->y];
        if (this->canGoToCell(new_cell))
            return true;
    }
    return false;
}

void Pacman::goUp(Type **maze) {
    if (this->canGoUp(maze)) {
        maze[this->x][this->y] = PATH;
        this->x--;
        this->update(maze);
    }
    maze[this->x][this->y] = PLAYER;
}

bool Pacman::canGoDown(Type **maze) {
    if (this->x + 1 >= 0) {
        Type new_cell = maze[this->x + 1][this->y];
        if (this->canGoToCell(new_cell))
            return true;
    }
    return false;
}

void Pacman::goDown(Type **maze) {
    if (this->canGoDown(maze)) {
        maze[this->x][this->y] = PATH;
        this->x++;
        this->update(maze);
    }
    maze[this->x][this->y] = PLAYER;
}

bool Pacman::canGoLeft(Type **maze) {
    if (this->y - 1 >= 0) {
        Type new_cell = maze[this->x][this->y - 1];
        if (this->canGoToCell(new_cell))
            return true;
    }
    return false;
}

void Pacman::goLeft(Type **maze) {
    if (this->canGoLeft(maze)) {
        maze[this->x][this->y] = PATH;
        this->y--;
        this->update(maze);
    }
    maze[this->x][this->y] = PLAYER;
}

bool Pacman::canGoRight(Type **maze) {
    if (this->y + 1 < MAZEWIDTH) {
        Type new_cell = maze[this->x][this->y + 1];
        if (this->canGoToCell(new_cell))
            return true;
    }
    return false;
}

void Pacman::goRight(Type **maze) {
    if (this->canGoRight(maze)) {
        maze[this->x][this->y] = PATH;
        this->y++;
        this->update(maze);
    }
    maze[this->x][this->y] = PLAYER;
}

void Pacman::update(Type **maze) {
    if (maze[this->x][this->y] == GIFT) {
        this->score++;
        printf("Lives: %d\n", this->getLives());
        printf("Score: %d\n", this->getScore());
    }
    else if (maze[this->x][this->y] == BOMB) {
        this->lives--;
        printf("Lives: %d\n", this->getLives());
        printf("Score: %d\n", this->getScore());
    }


}

void Pacman::draw(int x, int y) {
    Tile::draw(this->x, this->y);
}

int Pacman::getLives() {
    return this->lives;
}

int Pacman::getScore() {
    return this->score;
}