#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	float delay;
	double diff;
	struct tm *curr, *end;
	const time_t curr_t = time(NULL);
	struct timeval start_time, end_time;
	int hour, min, sec;

	delay = atof(argv[1]);
	curr = localtime(&curr_t);
	hour = curr->tm_hour;
	min = curr->tm_min;
	sec = curr->tm_sec;

	printf("current date = %d/%d/%d\ncurrent time = %d:%d:%d\n\n", curr->tm_year+1900, curr->tm_mon+1, curr->tm_mday, hour, min, sec);
	
	gettimeofday(&start_time, NULL);

	usleep(delay*1000000);
	
	gettimeofday(&end_time, NULL);
	const time_t end_t = time(NULL);
	end = localtime(&end_t);

	printf("waiting for %f sec using usleep()\n\n", delay);
	printf("start_time = (%ld %ld), %d:%d:%d\n", start_time.tv_sec, start_time.tv_usec, hour, min, sec);
	printf("end_time = (%ld %ld), %d:%d:%d\n", end_time.tv_sec, end_time.tv_usec, end->tm_hour,end->tm_min, end->tm_sec);

	diff = (end_time.tv_sec - start_time.tv_sec) + ((end_time.tv_usec - start_time.tv_usec)/1000000.0);
	printf("elapsed time = %f sec\n", diff);
	return 0;
}
