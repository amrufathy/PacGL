//
// Created by amr on 5/14/17.
//

#ifndef PACGL_IDRAWABLE_H
#define PACGL_IDRAWABLE_H

#include "definitions.h"

// interface
class IDrawable {
    // abstract function
    virtual void draw(int, int) = 0;
};


#endif //PACGL_IDRAWABLE_H
