#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

int ball_start(){
	int num = rand() % 2;
	if (num == 1){
		return -1;
	}
	if (num == 0){
		return 1;
	}
}

int angle(){
	int num = rand() % 3;
	if (num == 0) return 1;
	else return num;
}

void cleaner (int x, int y) {
	mvprintw(y, x-2, "     ");
}

void bord(int zero_x, int zero_y, int max_x, int max_y){

	for(int i = zero_x; i < max_x; i++){

		mvprintw(zero_y, i, "-");
		mvprintw(max_y, i, "-");
	}
	for (int i = zero_y; i < max_y+1; i++){

		mvprintw(i, zero_x, "|");
		mvprintw(i, max_x, "|");
	}

}

void player_bord(int x, int y){

	mvprintw(y, x - 2, "-----");

}

void ball(int x, int y){
	char o = 'o';
	mvaddch(y, x, o);
}

void score(int x, int score_p1, int score_p2){

	mvprintw(1, (x/2) - 4, "%d", score_p1);
	mvprintw(1, (x/2) - 1, "--");
	mvprintw(1, (x/2) + 3, "%d", score_p2);

}

void info(int x, int y){

	mvprintw(y, x - 25, "PLAYER 1");
	mvprintw(y + 1, x - 23, "A - D");
	mvprintw(y, x + 25, "PLAYER 2");
	mvprintw(y + 1, x + 26, "< - >");
}

int main(){

	initscr();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
	cbreak();
	int ch;

	srand(time(NULL));

	int x = 0;
	int y = 0;
	getmaxyx(stdscr, y, x);
	mvprintw(0 , (x/2) - 3, "SCORE:");

	int bord_y_zero = 3;
	int bord_y_max = 37;

	int score_p1 = 0;
	int score_p2 = 0;

	int p1_x = x/2;
	int p1_y = bord_y_zero + 3;
	int p2_x = x/2;
	int p2_y = bord_y_max - 3;

	int ball_x = x/2;
	int ball_y = (bord_y_max+bord_y_zero)/2;
	int mx = ball_start() + angle();
	int my = ball_start();

	timeout(130);
	while(score_p1 < 6 && score_p2 < 6){

		ball(ball_x, ball_y);
		player_bord(p1_x, p1_y);
		player_bord(p2_x, p2_y);
		bord((x/2) - 15, bord_y_zero, (x/2) + 15, bord_y_max);
		score(x, score_p1, score_p2);
		info(x/2, bord_y_max/2);
		refresh();
		ch = getch();
		switch(ch) {
		case KEY_LEFT:
			if(p2_x > (x/2) - 12){
				cleaner(p2_x, p2_y);
				p2_x--;
			}
			break;
		case KEY_RIGHT:
			if(p2_x < (x/2) + 12){
				cleaner(p2_x, p2_y);
				p2_x++;
			}
			break;
		case 'a':
			if(p1_x > (x/2) - 12){
				cleaner(p1_x, p1_y);
				p1_x--;
			}
			break;
		case 'd':
			if(p1_x < (x/2) + 12){
				cleaner(p1_x, p1_y);
				p1_x++;
			}
			break;
		}
		if (ball_x >= (x/2) + 14 || ball_x <= (x/2) - 14){
			mx *= -1;
		}
		if ((ball_y == p1_y + 1 && (ball_x >= p1_x-2 && ball_x <= p1_x+2)) || (ball_y == p2_y - 1 && (ball_x >= p2_x-2 && ball_x <=p2_x + 2))){
			my *= -1;
			mx += angle();
		}
		if (ball_y == bord_y_zero){
			ball_x = x/2;
			ball_y = (bord_y_zero + bord_y_max) / 2;
			cleaner(p1_x, p1_y);
			cleaner(p2_x, p2_y);
			p1_x = x/2;
			p2_x = x/2;
			score_p2++;
		}
		if (ball_y == bord_y_max){
			ball_x = x/2;
			ball_y = (bord_y_zero + bord_y_max) / 2;
			cleaner(p1_x, p1_y);
			cleaner(p2_x, p2_y);
			p1_x = x/2;
			p2_x = x/2;
			score_p1++;
		}
		cleaner(ball_x, ball_y);
		if (mx > 10) mx = 1;
		if (mx < -10) mx = -1;
		if (ball_x + mx > (x/2) + 14) mx = 1;
		if (ball_x + mx < (x/2) - 14) mx = -1;
		ball_x += mx;
		ball_y += my;
	}
	endwin();

}
