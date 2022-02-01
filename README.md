# 21-1학기 Operating System
## HW1
### hw1_2.c
Write a program that prints the following information.
1. Numbers of CPU cores
2. CPU model name
3. Total memory
4. Average workload for previous 1min, 5min, and 15min

### hw1_3.c
Write function *ParseCommand()* that parses command into arguments.

## HW2
### hw2_1.c
Write a simple command line interpreter that handles directory manipulation commands.
> ex) mkdir, rmdir, cd, curdir, ls, quit

### hw2_2.c
Write a program that displays the content of the current directory.

## HW3
### hw3_1.c
Write a C program that executes the following instructions.
1. Read delay as a float number from command line arguments.
2. Read arguments.c on the next page to learn how to access command line arguments.
3. Use *atof()* to convert a string into the corresponding float number.
4. Display current date and time
  * Use *time()* and *localtime()* system calls and struct tm type.
  * Read current time using *gettimeofday()* system call and store it in a variable of struct timeval type, start_time and end_time.
5. Wait for delay using *usleep()*
6. Display start_time and end_time in (sec usec) and hour:min:sec format
7. Use *localtime()* system call
8. Display the difference between start_time and end_time in seconds (including decimal parts)

### hw3_2.c
Write a C program that prints the display.
1. When executed without argument, display the following information
* User and process info
* User id, process id, parent’s process id
* Kernel info
* Sysname (OS name), nodename (hostname), release, version,machine
* System info
* Uptime, total ram, free ram, number of processes

2. When executed with a filename, display the following information
* Permission of the file
* Permission to read, write, and execute
* Stat of the file
* Device id, inode number, mode (display as an octal number), user id, group id, access time, modification time, creation time

### hw3_3.c
Write a C program that reads commands from a text file and run.
1. Read the name of command file from command line arguments.
2. Open the command file.
3. Repeat.
* Read a text line from the file using *ReadTextLine()* 
* If *ReadTextLine()* returns EOF, break the loop
* Display the command
* Parse command using *ParseCommand()*
* Run the commend
* If the commend is ‘cd’ change the current directory using *chdir()*
* If the first character of the command is ‘#’, ignore the command
* Otherwise, run the command on a child process using *fork()* and *execvp()*. Meanwhile, the parent process waits the child.
4. Close the command file.

## HW4
### hw4_1.c
Write a program that draws or erases shape using the keyboard.
* ‘i’: move up, ‘j’: move left, ‘k’: move down, ‘l’: move right 
* ‘c’: change color (‘*’ <-> ‘ ’)
* ‘q’: quit
 

### hw4_3a.c, hw4_3b.c
Write two programs hw4_3a.c and hw4_3b.c extending hw4_1.c and hw4_2.c.
* hw4_3a read keys from the user and put them into a key buffer in a shared memory block
* hw4_3b draws or erases shapes according to the keys retrieved from the key buffer in the shared memory block
* hw4_3a and hw4_3b should communication through a key buffer implemented by POSIX shared memory system calls
> ex) shm_open(), shm_unlink(), mmap(), munmap() functions


## HW5
### hw5_1.c, hw5_2.c, hw5_3.c
Practice Pointer and Dynamic allocation & deallocation.


## HW6
### hw6_1.c
Write a program that moves balls using multiple threads.
* Complete the skeleton code so that only one ball can enter in the critical region at a time.

### hw6_2.c
Write the solution of the Dining Philosophers Problem
* Complete the skeleton code by synchronizing the philosophers and display function.
* Extend the solution to prevent deadlock by not allowing the ‘circular wait’ condition.

## HW7
### hw7_1.c
Write the solution of the Dining Philosophers Problem with Monitors.

### hw7_2.c
Implement the address translation algorithm of a paging system.
* Address translation algorithm
1. Separate page number and offset from logical address.
2. With the page number, look up the page table to find the corresponding frame number.
3. Combine frame number and offset to make physical address.
