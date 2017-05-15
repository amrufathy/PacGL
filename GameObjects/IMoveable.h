//
// Created by amr on 5/15/17.
//

#ifndef PACGL_IMOVEABLE_H
#define PACGL_IMOVEABLE_H

#include "definitions.h"

// abstract class for any moving object
class IMoveable {
    virtual void goUp(Type **) = 0;

    virtual void goDown(Type **) = 0;

    virtual void goLeft(Type **) = 0;

    virtual void goRight(Type **) = 0;

private:
    virtual bool canGoUp(Type **) = 0;

    virtual bool canGoDown(Type **) = 0;

    virtual bool canGoLeft(Type **) = 0;

    virtual bool canGoRight(Type **) = 0;

    virtual void update(Type **) = 0;
};

#endif //PACGL_IMOVEABLE_H
