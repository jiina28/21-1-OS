#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include <unistd.h>
#include <pthread.h>

#include "Console.h"
#include "hw7_1.h"

#define DEFAULT_NO_PHIL 5

typedef struct {
	int phil_idx;
	int no_phil;

	Philosophers *dp;
	int screen_width;
	int screen_height;
} ThreadParam;

int thread_cont = TRUE;
void* ThreadFn(void *vParam);

int main(int argc, char *argv[])
{
	int no_phil = 0;
	if(argc > 1)
		no_phil = atoi(argv[1]);
	if(no_phil <= 0)
		no_phil = DEFAULT_NO_PHIL;

	srand(time(NULL));
	clrscr();

	int screen_width = getWindowWidth();
	int screen_height = getWindowHeight() - 3;

	pthread_t tid[MAX_PHIL];
	ThreadParam param[MAX_PHIL];

	Philosophers dp;
	Philosophers_Init(&dp, no_phil);
	Philosophers_Display(&dp, screen_width, screen_height);

	for(int i = 0; i < no_phil; i++){
		param[i].phil_idx = i;
		param[i].no_phil = no_phil;

		param[i].dp = &dp;
		param[i].screen_width = screen_width;
		param[i].screen_height = screen_height;

		pthread_create(&tid[i], NULL, ThreadFn, &param[i]);
	}

	PrintXY(1, 1, "Press 'q' to quit!\n");
	
	while(1){
		gotoxy(1, 1);
		if(kbhit() && getch() == 'q')
			break;

		Philosophers_Check(&dp);

		usleep(100000);
	}

	thread_cont = FALSE;

	for(int i=0;i<no_phil;i++)
		pthread_join(tid[i], NULL);

	Philosophers_Destroy(&dp);

	clrscr();
	printf("Bye!\n");

	return 0;
}

void* ThreadFn(void *vParam)
{
	ThreadParam *param = (ThreadParam*)vParam;

	Philosophers *dp = param->dp;
	int idx = param->phil_idx;

	while(thread_cont){
		// picking up
		Philosophers_PickUp(dp, idx);

		Philosophers_Check(dp);

		// eating
		Philosophers_Display(dp, param->screen_width, param->screen_height);
		usleep((rand() % 500 + 500) * 1000);

		// putting down
		Philosophers_PutDown(dp, idx);

		// thinking
		Philosophers_Display(dp, param->screen_width, param->screen_height);
		usleep((rand() % 500 + 1000) * 1000);
	}

	return NULL;
}

