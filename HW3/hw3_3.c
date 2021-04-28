#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#define BUFFER_SIZE 2048
#define MAX_SIZE 100

char buffer[BUFFER_SIZE];
int buffer_size = 0;
int buffer_pos = 0;

int ReadTextLine(int fd, char str[], int max_len);
void ParseCommand(char *command, int *argc, char *argv[]);

int main(int argc, char *argv[]) {
	char filename[MAX_SIZE];
	int fd, i, status;
	pid_t pid, waitpid;
	int ret;
		
	if(argc != 2) {
		printf("Usage: %s <filename>\n", argv[0]);				
		exit(1);
	}
	strcpy(filename, argv[1]); 		
	fd = open(filename, O_RDONLY);
	if(fd == -1) {
		printf("Cannot open the file %s\n", filename);
		exit(1);
	}
		
	while(1) {
		ret = ReadTextLine(fd, buffer, BUFFER_SIZE);
		if(ret == EOF) break;
		printf("command = [%s]\n", buffer);
			
		ParseCommand(buffer, &argc, argv);
		argv[argc]=NULL;
		
		if(strcmp(argv[0], "cd")==0) {
			chdir(argv[1]);
		}
		else {
			pid = fork();
			if(pid < 0) {
				fprintf(stderr, "fork failed");
				exit(EXIT_FAILURE);
			}
			else if(pid == 0) {
				if(strstr(argv[0], "#") == NULL)
					execvp(argv[0], argv);
				exit(EXIT_SUCCESS);
			}
			else {
				waitpid = wait(&status);
			}
		}
	}
	close(fd);
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

void ParseCommand(char *command, int *argc, char *argv[]) {
	int i = 0;
	int n;
	char *ptr;

	ptr = strtok(command, " ");
	while (ptr != NULL) {
		argv[i] = ptr;
		i++;
		ptr = strtok(NULL, " ");
	}
	*argc = i;
}
