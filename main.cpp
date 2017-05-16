#include <thread>
#include <string.h>
#include "GameObjects/Maze.h"
#include "GameObjects/Pacman.h"
#include "GameObjects/Monster.h"

Maze maze;
Pacman pacman;

std::vector<Monster> monsters = {
        Monster(maze.getMap(), &pacman, 1, MAZEWIDTH - 2),
        Monster(maze.getMap(), &pacman, 20, 1),
        Monster(maze.getMap(), &pacman, 15, 15),
        Monster(maze.getMap(), &pacman, 7, 15)
};


void display();

void idle();

void keyboard(unsigned char, int, int);

void special(int, int, int);

void move_monsters();

void text(int, int);

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

    std::thread monsters_thread(move_monsters);
    monsters_thread.detach();

    glutMainLoop();

    return 0;
}

void move_monsters() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
        for (int i = 0; i < monsters.size(); i++) {
            monsters[i].move(maze.getMap());
        }
    }
}

void text(int score, int lives) {
    char string[80];
    sprintf(string, "Score: %d, Lives: %d, 3ayzeen bonus", score, lives);
    int len = (int) strlen(string);

    glColor3f(1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, 600, 0, 600);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glRasterPos2i(10, MAZEWIDTH * TILEWIDTH - 50); // text position

    for (int i = 0; i < len; ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
    }

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    maze.draw(0, 0);
    pacman.draw(0, 0);
    for (int i = 0; i < monsters.size(); i++) {
        monsters[i].draw(0, 0);
    }
    text(pacman.getScore(), pacman.getLives());

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