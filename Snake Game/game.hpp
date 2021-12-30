#ifndef game_hpp
#define game_hpp

#define UP 1
#define DOWN -1
#define RIGHT 2
#define LEFT -2

#define MAX 60

void initGrid(int, int);
void drawGrid();
void unit(int, int);
void drawFood();
void drawSnake();
void random(int&, int&);

#endif
