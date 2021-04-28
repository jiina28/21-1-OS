## HW3_2

### getuid(), getpid(), getppid()
```c
#include <sys/types.h>
#include <unistd.h>

pid_t getuid();
pid_t getpid();
pid_t getppid();
```
- **getuid()**: 호출한 프로세스의 사용자 ID 알려줌
- **getpid()**: 호출한 프로세스의 ID 알려줌
- **getppid()**: 호출한 프로세스의 부모 프로세스 ID 알려줌

### uname()
```c
#include <sys/utsname.h>

int uname(struct utsname *pn);
```
- 현재 시스템의 운영체제 정보를 utsname(UnixTimeSharing) 형식 변수 주소에 저장

### utsname 구조체
```c
struct utsname {
  char sysname[_SYS_NMLN];    /*현재 운영체제 이름*/
  char nodename[_SYS_NMLN];   /*호스트명*/
  char release[_SYS_NMLN];    /*운영체제 release 번호*/
  char version[_SYS_NMLN];    /*운영체제 버전 번호*/
  char machine[_SYS_NMLN];    /*하드웨어 아키텍처 이름*/
};
```

### sysinfo()
```c
#include <sys/sysinfo.h>

int sysinfo(struct sysinfo *info);
```
- 시스템 전체 정보를 확인할 수 있는 함수
- 커널이 주 대상
- struct sysinfo에 저장

### sysinfo 구조체
```c
struct sysinfo {
  long uptime;              /*부팅 이후 지나간 초단위 시간*/
  unsigned long totalram;   /*사용할 수 있는 총 메모리 크기*/
  unsigned long freeram;    /*이용할 수 있는 메모리 크기*/
  unsigned long sharedram   /*공유 메모리의 양*/
  unsigned long bufferram;  /*버퍼에 의해 사용된 메모리*/
  unsigned long totalswap;  /*총 스왑 공간의 크기*/
  unsigned long freeswap;   /*이용할 수 있는 스왑 공간*/
  unsigned short procs;     /*현재 프로세스 수*/
  char _f[22];              /*구조체를 64bytes로 채움*/
};
```

### access()
```c
#include <unistd.h>

int access(const char *pathname, int mode);
```
- 파일 또는 디렉토리의 사용자 권한을 체크
- **mode**
  * R_OK : 읽기가 가능?
  * W_OK : 쓰기가 가능?
  * X_OK : 실행이 가능?
  * F_OK : 파일이 존재하는가?

### stat()
```c
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int stat(const char *path, struct stat *buf);
```
- 파일의 상태나 정보를 얻음
- struct stat에 저장

### stat 구조체
```c
struct stat {
  dev_t st_dev;           /*장치 파일의 위치 및 여부*/
  ino_t st_ino;           /*파일의 inode 번호*/
  mode_t st_mode;         /*파일의 종류 및 접근 권한*/
  nlink_t st_nlink;       /*hardlink된 횟수*/
  uid_t st_uid;           /*user ID*/
  gid_t st_gid;           /*group ID*/
  dev_t st_rdev;          /*device ID(if special file)*/
  off_t st_size;          /*파일의 크기(bytes)*/
  blksize_t st_blksize;   /*효율적인 I/O 파일 시스템 위한 블럭 사이즈*/
  blkcnt_t st_blocks;     /*파일에 할당한 블럭의 수*/

  time_t st_atime;        /*마지막 접근(access) 시각*/
  time_t st_mtime;        /*마지막 수정(modified) 시각*/
  time_t st_ctime;        /*마지막 상태변경(change) 시각*/
};
```
- **st_mode** : 파일의 종류와 file에 대한 access 권한 정보
  * S_ISREG : 일반 파일 여부
  * S_ISDIR  : 디렉토리 여부
  * S_ISCHR : character device 여부
  * S_ISBLK : block device 여부
  * S_ISFIFO : FIFO 여부
  * S_ISLNK : symbolic link 여부
  * S_ISSOCK : socket 여부
