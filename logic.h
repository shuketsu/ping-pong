#ifndef LOGIC_H
#define LOGIC_H

typedef struct {
	int x, y;
	int dx, dy;
} Ball;

typedef struct {
	int y;
	int score;
} Paddle;

//funzioni!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void init_ball(Ball *b, int start_x, int start_y);
void move_ball(Ball *b);
void reset_paddle(Paddle *p, int start_y);

#endif
