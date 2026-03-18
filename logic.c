#include "logic.h"

void init_ball(Ball *b, int x, int y){

	b->x = x;
	b->y = y;
	//speed
	b->dx = 1;
	b->dy = 1;

}

//move trigger
void move_ball(Ball *b, int max_x, int max_y){

	//move
	b->x += b->dx;
	b->y += b->dy;
	//colision(y)
	if(b->y <= 0 || b -> y >= max-y){
		b->dy *=  -1;
	}

}

void reset_paddle(Paddle *p, int start_y){

	

}
