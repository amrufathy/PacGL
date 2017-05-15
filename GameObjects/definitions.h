//
// Created by amr on 5/14/17.
//

#ifndef PACGL_DEFINITIONS_H
#define PACGL_DEFINITIONS_H

#ifndef GLUT
#define GLUT

#include <GL/glut.h>

#endif

#define MAZEWIDTH 31
#define MAZEHEIGHT 23

#define TILEHEIGHT 20
#define TILEWIDTH 20

#define PACMAN_START_X 1
#define PACMAN_START_Y 1

enum Type {
    PLAYER,
    PATH,
    WALL,
    GIFT,
    BOMB,
    MONSTER
};

#endif //PACGL_DEFINITIONS_H
