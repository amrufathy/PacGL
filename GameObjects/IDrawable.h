//
// Created by amr on 5/14/17.
//

#ifndef GLUT
#define GLUT

#include <GL/glut.h>

#endif

#include "definitions.h"

#ifndef PACGL_IDRAWABLE_H
#define PACGL_IDRAWABLE_H

// interface
class IDrawable {
    // abstract function
    virtual void draw(int, int) = 0;
};


#endif //PACGL_IDRAWABLE_H
