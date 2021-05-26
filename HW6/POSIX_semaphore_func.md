## POSIX semaphore functions

### sem_init()
- 익명 세마포어 만듦
```c
int sem_init(sem_t *sem, int pshared, unsigned int value);

sem_init(&sem_name, 0, 1);
```
- **sem** : 초기화할 세마포어 객체
- **pshared** : 0이 아니면 프로세스들 간에 세마포어 공유, 0이면 프로세스 내부에서만 사용
- **value** : 세마포어 초기값

### sem_wait()
- 세마포어를 얻을 때까지 기다림 (잠금)
- 만약 세마포어 값이 0보다 크면 프로세스는 세마포어를 얻고 세마포어 감소 후 즉시 반환
- 세마포어 값이 0이면 세마포어가 0보다 커지거나 시그널이 발생할 때까지 대기
```c
sem_wait(&sem_name);
```

### sem_post()
- 세마포어 되돌려주며 세마포어 값이 하나 증가함 (잠금 해제)
```c
sem_post(&sem_name);
```

### sem_getvalue()
- 세마포어의 정보를 가져오며 현재 세마포어의 값을 sval로 넘겨 알려줌
```c
int sem_getvalue(sem_t *sem, int *sval);

sem_getvalue(&sem_name, &i);
```

### sem_destroy()
- 익명 세마포어 파기
```c
sem_destroy(&sem_name);
```

---
### Mutex 와 semaphore의 차이는?
1) - **세마포어**는 공유 자원에 세마포어의 변수만큼의 프로세스(또는 스레드)가 접근 가능
    - **뮤텍스**는 단 1개의 프로세스(또는 스레드)만 접근 가능
2) - 현재 수행중이 아닌 다른 프로세스가 **세마포어** 해제 가능
    - **뮤텍스**는 lock을 획득한 프로세스가 반드시 그 lock을 해제해야함 
