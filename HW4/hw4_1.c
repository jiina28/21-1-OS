#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Console.h"

int main(int argc, char *argv)
{
	clrscr();			// clear screen

	// retrieve the size of window
	int screen_width = getWindowWidth();
	int screen_height = getWindowHeight() - 3;

	printf("i: up, j: left, k: down, l: right, c: change color, q: quit\n");
	printf("screen size: %d x %d\n", screen_width, screen_height);

	int x = screen_width / 2;	// horizontal coordinate
	int y = screen_height / 2;	// vertical coordinate
	int key = 0;
	int repeat = 1;
	char c = '*';		// initial color

	gotoxy(x, y);		// move the cursor to (x, y)
	putchar('#');

	int oldx = 0, oldy = 0;
	int flag=0;

	while(repeat){
		oldx = x;
		oldy = y;

		gotoxy(1, 3);
		printf("x = %3d, y = %3d", x, y);

		gotoxy(screen_width, 1);	// move cursor to upper right corner
		key = getch();		// read a key not waiting for ENTER


		if(x<1)
			x = 1;
		if(x>screen_width)
			x = screen_width;
		if(y<1)
			y = 1;
		if(y>screen_height)
			y = screen_height;

		switch(key){
			case 'i':
				y--;
				break;
			case 'j':
				x--;
				break;
			case 'k':
				y++;
				break;
			case 'l':
				x++;
				break;
			case 'c':	
				if(flag==0) {
					c=' ';
					flag = 1;
				}
				else if(flag==1) {
					c='*';
					flag=0;
				}
				break;
		}
		if(key=='q') break;

		gotoxy(oldx,oldy);
		printf("%c",c);

		gotoxy(x,y);
		printf("#");
	}

	clrscr();
	printf("Bye!\n");

	return 0;
}

