#include "logic.h"

void init_game(Ball *b, Paddle *p1, Paddle *p2) {
    	b->x = WIDTH / 2;
    	b->y = HEIGHT / 2;
    	b->dx = 1;
	b->dy = 1;

    	p1->y = HEIGHT / 2 - 2;
    	p1->score = 0;

    	p2->y = HEIGHT / 2 - 2;
    	p2->score = 0;
}

void move_ball(Ball *b, Paddle *p1, Paddle *p2) {
    	b->x += b->dx;
    	b->y += b->dy;

    	if (b->y <= 0 || b->y >= HEIGHT - 1) {
        	b->dy *= -1;
    	}

    	if (b->x == 2) {
        	if (b->y >= p1->y && b->y <= p1->y + 3) {
            		b->dx *= -1;
        	}
    	}

    	if (b->x == WIDTH - 3) {
        	if (b->y >= p2->y && b->y <= p2->y + 3) {
            		b->dx *= -1;
        	}
    	}
}

void check_goal(Ball *b, Paddle *p1, Paddle *p2) {
    	if (b->x <= 0) {
        	p2->score++;
        	b->x = WIDTH / 2;
        	b->y = HEIGHT / 2;
        	b->dx = 1;
    	} else if (b->x >= WIDTH - 1) {
        	p1->score++;
        	b->x = WIDTH / 2;
        	b->y = HEIGHT / 2;
        	b->dx = -1;
    	}
}

void move_paddle(Paddle *p, int direction) {
    	if (direction == -1 && p->y > 0) {
        	p->y--;
    	} else if (direction == 1 && p->y < HEIGHT - 4) {
        	p->y++;
    	}
}
