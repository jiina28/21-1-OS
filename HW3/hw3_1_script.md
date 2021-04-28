## HW3_1

### 시간 함수 정리
### time()
```c
#include <time.h>

time_t time(time_t *timeptr);
```
- 1970년 1월 1일 0시부터 timeptr까지 흐른 시간 반환 (초단위!)
- 보통 timeptr은 NULL

### localtime()
```c
#include <time.h>

struct tm *localtime(const time_t *timeval)
```
- time 함수로 반환된 초시간을 사용자가 알아보기 쉽게 변환
- time 함수의 return value를 parameter로 넘김
- **return value**: tm structure (static 변수 이므로 연속으로 사용 시 변수 따로 저장해서 사용하기!)

### tm 구조체
```c
struct tm {
  int tm_sec;     //초
  int tm_min;     //분
  int tm_hour;    //시
  int tm_mday;    //일
  int tm_mon;     //월(0부터 시작)
  int tm_year;    //1900년부터 흐른 년(+1900해줘야 현재 연도)
  int tm_wday;    //요일(0부터 일요일)
  int tm_yday;    //현재 년부터 흐른 일수
  int tm_isdst;   //서머타임제를 실시하고 있는지
};
```
### gettimeofday()
```c
#include <sys/time.h>
#include <unistd.h>

int gettimeofday(struct timeval *tv, struct timezone *tz);
```
- 현재 시간 가져옴 (마이크로초까지!)
- 보통 tz는 NULL
---
### usleep()
```c
#include <unistd.h>

void usleep(unsigned long useconds);
```
- 지정한 마이크로초 동안 대기
- usleep 사용으로 1초 대기 하려면 10^6 !!
