//
// Created by amr on 5/15/17.
//

#ifndef PACGL_MONSTER_H
#define PACGL_MONSTER_H

#include <time.h>
#include <random>
#include "IMoveable.h"
#include "Tile.h"
#include "Pacman.h"

class Monster : public Tile, public IMoveable {
public:
    Monster(Type **, Pacman *, int, int);

    void move(Type **);

    void goUp(Type **);

    void goDown(Type **);

    void goLeft(Type **);

    void goRight(Type **);

    void draw(int, int);

private:

    bool canGoUp(Type **);

    bool canGoDown(Type **);

    bool canGoLeft(Type **);

    bool canGoRight(Type **);

    bool canGoToCell(Type);

    void update(Type **);

    Type last_cell, going_cell;

    std::default_random_engine generator;

    Pacman *player;
};


#endif //PACGL_MONSTER_H
