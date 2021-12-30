#ifdef __APPLE_CC__
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>
#include "game.hpp"

#define COLUMNS 40
#define ROWS 40
#define FPS 10

extern short sDirection;
bool gameOver = false;

void init() {
  glClearColor(0.0, 0.0, 0.0, 1.0);
  initGrid(COLUMNS, ROWS);
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  drawGrid();
  drawSnake();
  drawFood();
  glutSwapBuffers();
  if (gameOver) {
    exit(0);
  }
}

void reshape(int w, int h) {
  glViewport(0, 0, static_cast<GLsizei>(w), static_cast<GLsizei>(h));
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, COLUMNS, 0.0, ROWS, -1.0, 1.0);
  glMatrixMode(GL_MODELVIEW);
}

void timer(int v) {
  glutPostRedisplay();
  glutTimerFunc(500/FPS, timer, 0);
}

void special(int key, int, int) {
  switch (key) {
    case GLUT_KEY_UP:
      if (sDirection != DOWN) {
        sDirection = UP;
      }
      break;
    case GLUT_KEY_DOWN:
      if (sDirection != UP) {
        sDirection = DOWN;
      }
      break;
    case GLUT_KEY_RIGHT:
      if (sDirection != LEFT) {
        sDirection = RIGHT;
      }
      break;
    case GLUT_KEY_LEFT:
      if (sDirection != RIGHT) {
        sDirection = LEFT;
      }
      break;
  }
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutCreateWindow("Snake");
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutTimerFunc(0, timer, 0);
  glutSpecialFunc(special);
  init();
  glutMainLoop();
}
