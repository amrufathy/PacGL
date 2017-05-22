//
// Created by amr on 5/14/17.
//

#ifndef PACGL_MAZE_H
#define PACGL_MAZE_H

#include "IDrawable.h"
#include "Tile.h"

class Maze : public IDrawable {
public:
    Maze();

    void draw(int, int);

    Type **getMap();

    int gifts_count();

private:
    Type **map;
};


#endif //PACGL_MAZE_H
