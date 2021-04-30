## HW4_3

- **hw4_3a**에서는 사용자로부터 key를 읽어들이고, 그것들을 공유 메모리 블럭 안의 key buffer에 넣음.
- **hw4_3b**에서는 공유 메모리 블럭 안의 key buffer의 key를 읽어서 그것에 따라 screen에 그림을 그리고 지움.

### 공유 메모리 사용 시 컴파일 옵션
> -lrt

- **example**       
gcc hw4_3a KeyBuffer.c Console.c **-lrt**

---
### 공유 메모리 관련 함수 (POSIX)
- system V 함수와는 달리 메모리 사용량 조절이 가능함. **because 파일을 다루기 때문!**
- **메모리 상에 존재하는 file을 통해 communication.**

#### shm_open()
```c
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>           /* For O_* constants */

int shm_open(const char *name, int oflag, mode_t mode);
```
- 공유 메모리 세그먼트를 생성하고 오픈
- **oflag** 대표 매크로
  * O_CREAT : 존재하지 않으면 생성
  * O_RDWR : 읽기/쓰기를 위해 오픈
- **return value : file descriptor**

#### shm_unlink()
```c
#include <sys/mman.h>

int shm_unlink(const char *name);
```
- 공유 메모리의 링크를 끊음.

#### ftruncate()
```c
#include <unistd.h>

int ftruncate(int fildes, off_t length);
```
- 파일을 특정 크기로 설정

#### mmap()
```c
#include <sys/mman.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);
```
- shmat 함수와 유사, **memory mapping을 만듦**  
- **return value : mapping이 시작하는 실제 mapping 주소**
- **addr** : kernel에게 mapping 시작 주소 제안 (보통 0)
- **length** : mapping 시킬 메모리 영역 길이
- **prot** : 메모리 보호 모드
    * PROT_READ : 읽기 가능
    * PROT_WRITE : 쓰기 가능
    * PROT_EXEC : 실행 가능
    * PROT_NONE : 접근 불가
- **flags** : mapping 유형 및 동작 구성 요소
  * MAP_SHARED : mapping 한 프로세스들끼리 데이터 (변경) 내용 공
  * MAP_FIXED :  mapping 주소를 정확히 지정. 헤당 메모리 영역에 mapping된 파일이 있다면, mapping이 해제되고 새 파일이 mapping됨. (사용 권장 x)
  * MAP_PRIVATE : mapping을 공유하지 않아 데이터 (변경) 내용 공유 x, mapping된 메모리의 사본을 생성하고 mapping 주소는 이 사본을 가리킴.
- **fd** : file descriptor
- **offset** : 시작점

#### munmap()
```c
#include <sys/mman.h>

int munmap(void *addr, size_t length);
```
- shmdt 함수와 유사, **memory mapping을 끊음**
---
### 예제 (producer-consumer)
#### producer.c
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

int main() {
  /* the size (in bytes) of shared memory object */
  const int SIZE = 4096;

  /* name of the shared memory object */
  const char *name = "OS";

  /* strings written to shared memory */
  const char *message_0 = "Hello";
  const char *message_1 = "World!";

  int shm_fd; /* shared memory file descriptor */
  void *ptr;  /* pointer to shared memory obect */`

  /* create the shared memory object */
  shm_fd = shm_open(name, O_CREAT|O_RDWR, 0666);

  /* configure the size of the shared memory object */
  ftruncate(shm_fd, SIZE);

  /* memory map the shared memory object */
  ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);

  /* write to the shared memory object */
  sprintf(ptr,"%s",message_0);
  ptr += strlen(message_0);
  sprintf(ptr,"%s",message_1);
  ptr += strlen(message_1);

  return 0;
}
```

#### consumer.c
```c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
int main() {
  /* the size (in bytes) of shared memory object */
  const int SIZE = 4096;

  /* name of the shared memory object */
  const char *name = "OS";

  int shm_fd; /* shared memory file descriptor */
  void *ptr;  /* pointer to shared memory obect */`

  /* open the shared memory object */
  shm_fd = shm_open(name, O_RDONLY, 0666);

  /* memory map the shared memory object */
  ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);

  /* read from the shared memory object */
  printf("%s", (char *) ptr);

  /* remove the shared memory object */
  shm_unlink(name);

  return 0;
}
```
