//
// Created by amr on 5/14/17.
//

#include "Tile.h"

Tile::Tile(Type type) {
    this->type = type;
}

Tile::Tile(Type type, int x, int y) {
    this->type = type;
    this->x = x;
    this->y = y;
}

void Tile::draw(int x, int y) {
    //    glColor3f(r, g, b);

    if (this->type == PATH) {
        glColor3f(0.0, 0.0, 0.0); // black
    } else if (this->type == WALL) {
        glColor3f(1.0, 1.0, 1.0); // white
    } else if (this->type == BOMB) {
        glColor3f(1.0, 0.0, 0.0); // red
    } else if (this->type == GIFT) {
        glColor3f(0.0, 1.0, 0.0); // green
    } else if (this->type == PLAYER) {
        glColor3f(0.0, 0.0, 1.0); // blue
    }

    int x_to_draw = y * TILEWIDTH;
    int y_to_draw = TILEHEIGHT * (-1 + MAZEHEIGHT - x);

    glBegin(GL_QUADS);

    glVertex2i(x_to_draw, y_to_draw);
    glVertex2i(x_to_draw, y_to_draw + TILEHEIGHT);
    glVertex2i(x_to_draw + TILEWIDTH, y_to_draw + TILEHEIGHT);
    glVertex2i(x_to_draw + TILEWIDTH, y_to_draw);

    glEnd();
}