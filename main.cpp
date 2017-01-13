#include <curses.h>

#include "Printer.h"

int main()
{
	initscr();

	Snow::Printer pr;


	getch();

	endwin();
	return 0;
}
