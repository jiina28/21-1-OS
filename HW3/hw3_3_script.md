## HW3_3

### 프로세스 관련 함수 정리
### fork()
```c
#include <unistd.h>

pid_t fork();
```
- 프로세스 생성
- 자식 프로세스는 부모 프로세스의 메모리를 그대로 복사해서 가지게 됨
- **return value**
  * 부모 프로세스 : 자식 pid
  * 자식 프로세스 : 0
  * 실패 : -1

### exec() 계열
```c
#include <unistd.h>

int execl(const char *path, const char *arg, ...);
int execv(const char *path, char *const argv[]);
int execlp(const char *file, const char *arg, ...);
int execvp(const char *file, char *const argv[]);
int execle(const char *path, const char *arg,...,char *const envp[]);
int execve(const char *filename, char *const argv[], char *const envp[]);
```
- 현재 프로세스를 새로운 프로그램으로 대체
- **l계열** : 인자 열거 방식이 나열형
- **v계열** : 인자 열거 방식이 배열형
- **p계열** : 환경변수 PATH를 참조하기 때문에 절대경로 입력 필요 x
- **e계열** : 환경변수 지정가능
