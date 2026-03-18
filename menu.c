#include "menu_h"
#include "logic_h"
#include <ncurses.h>

void the menu(int x, int y){

	int width = WIDTH /2;
	attron(A_BOLD);
	attron(COLOR_PAIR(2));
	mvprintw(width - 2, 1, "MENU");
	mvprintw(width - 5, 5, "PLAY > (p)");
	mvprintw(width - 5, 7, "EXIT > (E)");
	mvpritnw(width - 8, 11, "BUY ME A COFFEE ");

	

}
