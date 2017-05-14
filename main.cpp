#include <iostream>

#include "GameObjects/Maze.h"
#include "GameObjects/Pacman.h"

Maze maze;
Pacman pacman;

void display();

void idle();

void keyboard(unsigned char key, int x, int y);

void special(int key, int x, int y);

int main(int argc, char *argv[]) {

    int width = MAZEWIDTH * TILEWIDTH;
    int height = MAZEHEIGHT * TILEHEIGHT;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(width, height);

    glutCreateWindow("PacGL");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, width, 0.0, height + 50);
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutSpecialFunc(special);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    maze.draw(0, 0);
    pacman.draw(0, 0);

    glFlush();
}

void idle() {
    display();
}

void special(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP: // move pacman up
            pacman.goUp(maze.getMap());
            break;
        case GLUT_KEY_DOWN: // move pacman down
            pacman.goDown(maze.getMap());
            break;
        case GLUT_KEY_RIGHT: // move pacman right
            pacman.goRight(maze.getMap());
            break;
        case GLUT_KEY_LEFT: //move pacman left
            pacman.goLeft(maze.getMap());
            break;
    }
}

void keyboard(unsigned char key, int x, int y) {

}