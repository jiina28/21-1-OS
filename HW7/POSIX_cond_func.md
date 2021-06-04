## POSIX condition variable functions

### pthread_cond_init()
- condition variable 초기화
- PTHREAD_CONT_INITIALIZER 를 이용하여 정적으로 초기화 가능
```c
int pthread_cond_init(pthread_cond_t *restrict cond, const pthread_condattr_t *restrict attr);
```

### pthread_cond_wait()
- 두번째 인수는 조건 변수를 보호하기 위한 뮤텍스
- pthread_cond_wait을 호출하기 전에 전달할 mutex를 이용하여 잠근 후에 이 함수를 호출

```c
int pthread_cond_wait(pthread_cond_t* cond, pthread_mutex_t* mutex );


pthread_cond_wait(&cond, &mutex);
```

### pthread_cond_signal()
- 대기 중인 스레드에게 signal을 보냄
- 현재 pthread_cond_wait으로 대기중인 스레드를 깨우게 되어 다른 스레드가 이후의 작업을 진행할 수 있도록 해줌
```c
int pthread_cond_signal(pthread_cond_t *cond);

pthread_cond_signal(&cond);
```

### pthread_cond_destroy()
- condition variable 파괴
```c
int pthread_cond_destroy(	pthread_cond_t *cond);
```
