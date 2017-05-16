//
// Created by amr on 5/15/17.
//

#include "Monster.h"
#include <string>

Monster::Monster(Type **maze, Pacman *player, int start_x, int start_y) :
        Tile(MONSTER, start_x, start_y) {

    maze[this->x][this->y] = MONSTER;
    last_cell = PATH;
    this->player = player;
}

void Monster::draw(int x, int y) {
    Tile::draw(this->x, this->y);
}

bool Monster::canGoToCell(Type new_cell) {
    return new_cell == PATH || new_cell == GIFT || new_cell == BOMB || new_cell == PLAYER;
}


void Monster::moveToClosestCell(Type **maze) {
    int min_distance = numeric_limits<int>::max();
    Direction min_direction;
    int distance;
    //get minimum direction
    int current_x = this->x;
    int current_y = this->y;
    //left
    distance = this->getDistance(this->player->getX(), this->player->getY(), current_x, --current_y);
    if (min_distance > distance) {
        min_distance = distance;
        min_direction = LEFT;
    }
    //right
    distance = this->getDistance(this->player->getX(), this->player->getY(), current_x, ++current_y);
    if (min_distance > distance) {
        min_distance = distance;
        min_direction = RIGHT;
    }
    //down
    distance = this->getDistance(this->player->getX(), this->player->getY(), ++current_x, current_y);
    if (min_distance > distance) {
        min_distance = distance;

        min_direction = DOWN;
    }
    //up
    distance = this->getDistance(this->player->getX(), this->player->getY(), --current_x, current_y);
    if (min_distance > distance) {
        min_direction = UP;
    }

    //make move
    if (min_direction == LEFT && this->canGoLeft(maze)) {
        this->goLeft(maze);
    } else if (min_direction == RIGHT && this->canGoRight(maze)) {
        this->goRight(maze);
    } else if (min_direction == UP && this->canGoUp(maze)) {
        this->goUp(maze);
    } else if (min_direction == DOWN && this->canGoDown(maze)) {
        this->goDown(maze);
    } else {
        this->moveRandomly(maze);
    }

};

int Monster::getDistance(int from_x, int from_y, int to_x, int to_y) {
    return (int) sqrt(pow(from_x - to_x, 2) + pow(from_y - to_y, 2));
}

void Monster::move(Type **maze) {
    this->moveToClosestCell(maze);
}

void Monster::moveRandomly(Type **maze) {
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

void Monster::update(Type **maze) {
    if (maze[this->x][this->y] == PLAYER) {
        this->player->setLives(this->player->getLives() - 1);
    }
}