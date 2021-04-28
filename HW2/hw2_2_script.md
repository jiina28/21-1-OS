## hw2_2

### 디렉토리 함수 정리
### opendir()
```c
#include <sys/types.h>
#include <dirent.h>

DIR * opendir(const char *name);
```
- **return value**: success이면 DIR 구조체 포인터, fail이면 NULL

### readdir()
```c
#include <sys/types.h>
#include <dirent.h>

sturct dirent *readdir(DIR *dir);
```
- **return value**: success이면 디렉토리 포인터 dir이 가리키는 곳, 즉 해당 디렉토리에서 디렉토리의 엔트리에 대한 포인터, fail이거나 읽을 엔트리 없으면  NULL

### closedir()
```c
#include <sys/types.h>
#include <dirent.h>

int closedir(DIR *dir);
```
- **return value**: success이면 0, fail이면 -1

### dirent 구조체
```c
struct dirent {
  ino_t d_ino;                /*inode number*/
  off_t d_off;                /*Not an offset*/
  unsigned short d_reclen;    /*length of this record*/
  unsigned char d_type;       /*type of file*/
  char d_name[256];         /*null-terminated filename*/
}
```
