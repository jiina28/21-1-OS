#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_CMD 2048
#define MAX_ARG 256
#define MAX_SIZE 1024

void ParseCommand(char *command, int *argc, char *argv[]);

int main() {
	char command[MAX_CMD];
	command[0] = command[MAX_CMD-1] = 0;
	int argc = 0;
	char *argv[MAX_ARG] = { NULL };
	char *cur_dir;
	char buf[MAX_SIZE];

	while(1) {
		printf("$");
		fgets(command, MAX_CMD-1, stdin);
		command[strlen(command)-1]=0;

		if(strcmp(command, "quit")==0)
			break;

		ParseCommand(command, &argc, argv);
	
		if(!strcmp(argv[0], "mkdir")) {
			mkdir(argv[1], 0755);
		}
		else if(!strcmp(argv[0], "rmdir")) {
			rmdir(argv[1]);
		}
		else if(!strcmp(argv[0], "cd")) {
			chdir(argv[1]);
		}
		else if(!strcmp(argv[0], "curdir")) {
			cur_dir = getcwd(buf, MAX_SIZE);
			printf("current directory = %s\n", cur_dir);
		}
		else if(!strcmp(argv[0], "ls")) {
			system("ls");
		}
	}
	printf("Bye!\n");
	return 0;
}

void ParseCommand(char *command, int *argc, char *argv[]) {
        int i=0;
        int n;
        char *ptr;

        ptr = strtok(command, " ");
        while(ptr != NULL) {
                argv[i] = ptr;
                i++;
                ptr = strtok(NULL, " ");

        }
        *argc = i;
}

