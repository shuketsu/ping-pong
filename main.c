#include <ncurses.h>
#include "logic.h"

int main(){

	initscr();
	noecho();
	curs_set(FALSE);

	mvprintw(10, 10, "Ping-Pong");
	refresh();
	getch();

	endwin();

}
