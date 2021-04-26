## HW1_3
### system call 정리
### open()
~~~c
#include <sys/stat.h>
#include <fcntl.h>

int open(const char *pathname, int flags);
~~~
- **flags** : O_RDONLY, O_WRONLY, ...
- **return value** : success이면 0, fail이면 -1

### close()
~~~c
#include <unistd.h>
int close(int fd);
~~~
- **return value** : success이면 0, fail이면 -1

### read()
~~~c
#include <unistd.h>
ssize_t read(int fd, void *buf, size_t count);
~~~
- **return value** : success이면 읽어들인 byte 수 (파일 끝은 0), fail이면 -1

### write()
~~~c
#include <unistd.h>
ssize_t write(const void *buf, size_t count);
~~~
- **return value** : success이면 기록한 byte 수, fail이면 -1
