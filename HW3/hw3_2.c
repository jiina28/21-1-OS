#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <sys/stat.h>
#include <time.h>

#define MAX_SIZE 100

int main(int argc, char *argv[])
{
	char filename[MAX_SIZE];
	struct utsname kerinfo;
	struct sysinfo sys_info;
	int read_per, write_per, exe_per;
	struct stat statbuf;
	struct tm *atime, *mtime, *ctime;

	if (argc == 1)
	{ // no argument
		printf("User and Process info:\n");
		printf("\tgetuid() = %d\n\tgetpid() = %d\n\tgetppid() = %d\n", getuid(), getpid(), getppid());

		if (uname(&kerinfo) == -1)
		{
			perror("uname");
			exit(1);
		}
		printf("Kernel info:\n");
		printf("\tsysname = %s\n\tnodename = %s\n\trelease = %s\n\tversion = %s\n\tmachine = %s\n", kerinfo.sysname, kerinfo.nodename, kerinfo.release, kerinfo.version, kerinfo.machine);

		if (sysinfo(&sys_info) == -1)
		{
			perror("sysinfo");
			exit(1);
		}
		printf("System info:\n");
		printf("\tuptime = %ld\n\ttotalram = %lu\n\tfreeram = %lu\n\tprocs = %d\n", sys_info.uptime, sys_info.totalram, sys_info.freeram, sys_info.procs);
	}

	else
	{ // has argument
		strcpy(filename, argv[1]);
		if (access(filename, F_OK) != 0)
		{
			printf("%s is not existing...\n", filename);
			exit(1);
		}
		if (access(filename, R_OK) == 0)
			read_per = 1;
		else
			read_per = 0;
		if (access(filename, W_OK) == 0)
			write_per = 1;
		else
			write_per = 0;
		if (access(filename, X_OK) == 0)
			exe_per = 1;
		else
			exe_per = 0;
		printf("Permission of file a.out\n");
		printf("\tpermission to read: %d\n\tpermission to write: %d\n\tpermission to execute: %d\n", read_per, write_per, exe_per);

		printf("stat of file %s\n", filename);
		if (stat(filename, &statbuf) == -1)
		{
			perror("stat");
			exit(1);
		}

		printf("\tst_dev = %ld\n\tst_ino = %ld\n\tst_mode = %o (octal)\n\tst_uid = %ld\n\tst_gid = %ld\n\tst_size = %lld\n", statbuf.st_dev, statbuf.st_ino, statbuf.st_mode, (long)statbuf.st_uid, (long)statbuf.st_gid, (long long)statbuf.st_size);

		atime = localtime(&statbuf.st_atime);
		printf("\tst_atime = %d/%d/%d %d:%d:%d\n", atime->tm_year + 1900, atime->tm_mon + 1, atime->tm_mday, atime->tm_hour, atime->tm_min, atime->tm_sec);
		mtime = localtime(&statbuf.st_mtime);
		printf("\tst_mtime = %d/%d/%d %d:%d:%d\n", mtime->tm_year + 1900, mtime->tm_mon + 1, mtime->tm_mday, mtime->tm_hour, mtime->tm_min, mtime->tm_sec);
		ctime = localtime(&statbuf.st_ctime);
		printf("\tst_ctime = %d/%d/%d %d:%d:%d\n", ctime->tm_year + 1900, ctime->tm_mon + 1, ctime->tm_mday, ctime->tm_hour, ctime->tm_min, ctime->tm_sec);
	}

	return 0;
}
