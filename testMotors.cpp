#include "alphabot.h"
#include <ncurses.h>
#include <iostream>

int running = 1;

int main(int, char **)
{
        AlphaBot alphabot;
        initscr();
        noecho();
        raw();
        clear();
        alphabot.start();
        while (running)
        {
                int ch = getch();
                switch (ch)
                {
                case 27:
                        running = 0;
                        break;

                case 'l':
			mvaddstr(0, 0,"Setting left speed");
			refresh();
                        alphabot.setLeftWheelSpeed(0.5);
                        break;

                case 'r':
			mvaddstr(0,0,"Setting right speed");
			refresh();
                        alphabot.setRightWheelSpeed(0.5);
                        break;

                case ' ':
			mvaddstr(0,0,"Stopping");
			refresh();
                        alphabot.setLeftWheelSpeed(0);
                        alphabot.setRightWheelSpeed(0);
                        break;

                default:
                        break;
                }
        }
        alphabot.stop();
        endwin();
}
