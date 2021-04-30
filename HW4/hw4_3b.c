#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include "Console.h"
#include "KeyBuffer.h"

#define SHM_FILE "key_buffer.shm"

int main(int argc, char *argv)
{
	int shmfd = shm_open(SHM_FILE, O_CREAT|O_RDWR, 0666);
	if(shmfd == -1) {
		fprintf(stderr, "shm_open error");
		return -1;
	}

	int buffer_size = sizeof(KeyBuffer);
	KeyBuffer *key_buffer = NULL;
	key_buffer =(KeyBuffer*)mmap(NULL, buffer_size, PROT_WRITE|PROT_READ, MAP_SHARED, shmfd, 0);
	if(key_buffer == MAP_FAILED) {
		fprintf(stderr, "mmap error");
		return -1;
	}
	
	int screen_width = getWindowWidth();
	int screen_height = getWindowHeight() - 3;

	clrscr();

	printf("screen size: %d x %d\n", screen_width, screen_height);
	int x = screen_width / 2;
	int y = screen_height / 2;
	int key = 0;
	char c = '*';
	int repeat = 1;

	gotoxy(x, y);
	putchar('#');

	int flag = 0;
	while(repeat){
		int oldx = x;
		int oldy = y;
		
		gotoxy(screen_width, 1);
		do {
			key = DeleteKey(key_buffer);
		}while(key == 0);

		if(x<1)
			x = 1;
		if(x>screen_width)
			x = screen_width;
		if(y<1)
			y = 1;
		if(y>screen_height)
			y = screen_height;

		switch(key) {
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
					flag = 0;
				}
				break;
		}
		if(key=='q') break;

		gotoxy(oldx, oldy);
		printf("%c", c);

		gotoxy(x,y);
		printf("#");
	}

	clrscr();
	printf("Bye!\n");

	return 0;
}
