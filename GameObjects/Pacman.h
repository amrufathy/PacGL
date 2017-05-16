//
// Created by amr on 5/14/17.
//

#ifndef PACGL_PACMAN_H
#define PACGL_PACMAN_H

#include <iostream>
#include "IMoveable.h"
#include "Tile.h"

class Pacman : public Tile, public IMoveable {
public:
    Pacman();

    void goUp(Type **);

    void goDown(Type **);

    void goLeft(Type **);

    void goRight(Type **);

    void draw(int, int);

    int getLives();

    int getScore();

    int getX();

    int getY();

    void setLives(int);

private:
    bool canGoUp(Type **);

    bool canGoDown(Type **);

    bool canGoLeft(Type **);

    bool canGoRight(Type **);

    bool canGoToCell(Type);

    void update(Type **);

    int score;
    int lives;
};


#endif //PACGL_PACMAN_H
