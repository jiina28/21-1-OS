#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include "Console.h"
#include "KeyBuffer.h"

#define SHM_FILE "key_buffer.shm"

int main(int argc, char *argv[])
{
	int shmfd = shm_open(SHM_FILE, O_CREAT|O_RDWR, 0666);
	if(shmfd == -1) {
		fprintf(stderr, "shm_open error");
		return -1;
	}
	int buffer_size = sizeof(KeyBuffer);

	ftruncate(shmfd, buffer_size);
	KeyBuffer *key_buffer = NULL;
	key_buffer = (KeyBuffer*)mmap(NULL, buffer_size, PROT_WRITE|PROT_READ, MAP_SHARED, shmfd, 0);
	if(key_buffer == MAP_FAILED) {
		fprintf(stderr, "mmap error");
		return -1;
	}
	
	InitKeyBuffer(key_buffer);
	clrscr();

	printf("i: up, j: left, k: down, l: right, c: change color, q: quit hw4_3b, ESC: quit both\n");

	while(1){
		gotoxy(1, 2);
		printf("Input a key: ");
		int key = getch();

		if(key == 27) {
			InsertKey(key_buffer, 'q');
			break;
		}
		else {
			InsertKey(key_buffer, key);
		}

		DisplayKeyBuffer(1, 2, key_buffer);
	}

	munmap(key_buffer, buffer_size);
	shm_unlink(SHM_FILE);
	clrscr();
	printf("Bye!\n");

	return 0;
}

