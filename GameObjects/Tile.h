//
// Created by amr on 5/14/17.
//

#ifndef PACGL_TILE_H
#define PACGL_TILE_H

#include "IDrawable.h"

enum Type {
    PLAYER,
    PATH,
    WALL,
    GIFT,
    BOMB,
    FINISH
};

class Tile : public IDrawable {
public:
    Tile(Type);

    Tile(Type, int, int);

    void draw(int, int);

protected:
    int x;
    int y;

private:
    Type type;
};


#endif //PACGL_TILE_H
