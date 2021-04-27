## HW2_1

### system call 정리
### system()
```c
#include <stdlib.h>

int system(const char *string);
```
- **fork() + wait() + exec()**
- 자식 프로세스를 하나 만들어 string의 경로가 지정한 프로세스로 대체한 뒤 이 프로세스가 종료될 때까지 기다림
- **return value**: success이면 0이 아닌 값, fail이면 0

### mkdir(), rmdir()
```c
#include <unistd.h>

int mkdir(const char *path, mode_t mode);
int rmdir(const char *path);
```
- rmdir()은 디렉토리 내에 파일 있으면 실패
- **return value**: success이면 0, fail이면 -1

### chdir()
```c
#include <unistd.h>

int chdir(const char *dirname);
```
- **dirname**: 변경할 디렉토리의 경로
- **return value**: success이면 0, fail이면 -1

### getcwd()
```c
#include <unistd.h>

char *getcwd(char *buf, size_t size);
```
- **buf**: 현재 디렉토리의 절대경로를 저장할 버퍼주소
- **size**: 버퍼의 크기
- **pwd**가 이 함수를 이용해서 현재 디렉토리의 위치를 알려줌
- **return value**: success이면 buf, fail이면 NULL
