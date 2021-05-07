## HW5_3

### POSIX Pthreads function
> #include <pthread.h>
#### create thread
```c
int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void*(*start_routine)(void*), void *arg);
```
- thread : pthread 식별자로 thread가 성공적으로 생성되면 thread 식별값 주어짐.
- attr : pthread 속성(option), 기본적으로 NULL
- void*(함수명) : pthread로 분기할 함수, 반환값이 void* 타입

#### initialized attr by default values
```c
int pthread_attr_init(pthread_attr_t *attr);
```

#### waits for a thread th
: 특정 pthread가 종료될 때까지 기다리다가 특정 pthread 종료시 자원해제 시킴(성공시 return 0)
```c
int pthread_join(pthread_t th, void **thread_return);
```
- th : 어떤 pthread를 기다릴 지 정하는 식별자
- thread_return : pthread의 return 값

#### terminates thread_return
현재 실행 중인 pthread 종료시킬 때 사
```c
void pthread_exit(void *retval);
```
