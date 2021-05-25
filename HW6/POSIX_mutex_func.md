## POSIX mutex functions

```c
#include <ptrhead.h>
```

### pthread_mutex_init()
- mutex 초기화
  * 정적 초기화
  ```c
  pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
  ```
  * 동적 초기화
  ```c
  pthread_mutex_t mutex;
  pthread_mutex_init(&mutex, NULL);
  ```

### pthread_mutex_lock()
- critical section(임계구역) 진입시 잠금
```c
pthread_mutex_lock(&mutex);
```

### pthread_mutex_unlock()
- critical section(임계구역) 나올 때 잠금 풀기
```c
pthread_mutex_unlock(&mutex);
```

> 중요한 점은 한 스레드에서 lock을 걸고 critical section에 들어가 있는데 다른 스레드에서 lock을 호출하면 그 스레드는 이전의 스레드가 critical section을 나올 때까지 (unlock할 때까지) 기다려야함

### pthread_mutex_trylock()
- lock을 얻을 수 없을 경우 해당 code에서 block되지 않고 바로 error code를 return (pthread_mutex_lock의 비봉쇄버전)
- EBUSY : mutex가 잠겨있어서 잠금을 얻을 수 없음
- EINVAL : mutex가 잘못 초기화 됨
```c
pthread_mutex_trylock(&mutex);
```

### pthread_mutex_destry()
- 더이상 mutex를 사용할 일이 없다면 반드시 mutex 객체 삭제하고 자원 되돌려줌 (free)
- 만약 mutex 자원을 사용하는 스레드가 하나라도 존재한다면 error
```c
pthread_mutex_destroy(&mutex);
```
