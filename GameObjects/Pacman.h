//
// Created by amr on 5/14/17.
//

#ifndef PACGL_PACMAN_H
#define PACGL_PACMAN_H

#include <iostream>
#include "IDrawable.h"
#include "Tile.h"

class Pacman : public Tile {
public:
    Pacman();

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
};


#endif //PACGL_PACMAN_H
