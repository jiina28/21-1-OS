#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#define BUFFER_SIZE 1024

int ReadTextLine(int fd, char str[], int max_len);

char buffer[BUFFER_SIZE];
int buffer_size = 0;
int buffer_pos = 0;

int main() {
	int fd, fd2, fd3;
	int ret,fbyte, i;
	int cores, total;
	float loadavg1, loadavg5, loadavg15;
	char name1[10], name2[10], name3[10], name4[10], name5[10], name6[10];

	fd = open("/proc/cpuinfo", O_RDONLY);
	fd2 = open("/proc/meminfo", O_RDONLY);
	fd3 = open("/proc/loadavg", O_RDONLY);

	if(fd == -1||fd2 == -1||fd3 == -1)
		perror("open error");

	//CPU model
	lseek(fd, 80, SEEK_SET);
	ret = ReadTextLine(fd, buffer, sizeof(buffer));
	sscanf(buffer, "%s %s %s %s %s %s", name1, name2, name3, name4, name5, name6);
	printf("CPU model: %s %s %s %s %s %s \n", name1, name2, name3, name4, name5, name6);
	
	//cpu cores
	lseek(fd, 228, SEEK_SET);
	read(fd, buffer, sizeof(buffer));
	sscanf(buffer, "%d", &cores);
	printf("CPU cores: %d\n", cores);
	
	//total memory	
	lseek(fd2, 17, SEEK_SET);
	read(fd2, buffer, sizeof(buffer));
	sscanf(buffer, "%d", &total);
	printf("MemTotal: %d\n", total);

	//loadavg
	ret = ReadTextLine(fd3, buffer, sizeof(buffer));
	sscanf(buffer, "%f %f %f", &loadavg1, &loadavg5, &loadavg15);
	printf("loadavg1 = %f, loadavg5 = %f, loadavg15 = %f\n", loadavg1, loadavg5, loadavg15);

	close(fd);
	close(fd2);
	close(fd3);
	return 0;
}

int ReadTextLine(int fd, char str[], int max_len) {
	int i = 0;
	int j = 0;
	int ret = 0;

	if(lseek(fd, 0, SEEK_CUR) == 0)
		buffer_pos = buffer_size = 0;
	
	while(j < max_len - 1) {
		if(buffer_pos == buffer_size) {
			buffer[0] = 0;
			buffer_size = read(fd, buffer, BUFFER_SIZE);
			buffer_pos = 0;
		}
		if(buffer_size == 0) {
			if(j == 0)
				ret = EOF;
			break;
		}
		while(j < max_len - 2 && buffer_pos < buffer_size) {
			str[j++] = buffer[buffer_pos++];
			if(str[j-1] == '\0' || str[j-1] == 10) {
				j--;
				max_len = j;
				break;
			}
		}
	}
	str[j] = 0;

	return ret;
}
