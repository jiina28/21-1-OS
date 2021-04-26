## HW1_2
---
### linux에서 압축하기
> tar cvfz zip_name.tgz zip_files
### linux에서 압축풀기
> tar xvfz zip_name.tgz

---
### /proc 아래 파일들은 커널 variables를 보여주는 **가상파일**
#### CPU와 관련된 정보
> /proc/cpuinfo
- processor, cpu family, model (name), stepping, cpu MHz, cpu cores 등

#### Memory와 관련된 정보
> /proc/meminfo
- MemTotal, MemFree, MemAvailable, Buffers, Cached, Active, InActive 등

#### 평균 workload와 관련된 정보
> /proc/loadavg
- core 수에 따라서 숫자가 달라지며 각 core가 100% load가 발생할 경우 core1에는 값1, core2에는 값2, ...로 표현됨.  권장하는 average는 70% (0.7) 이하이며, 그 이상일 경우 시스템에 이상이 없는 지 확인 필요.
- 1분, 5분, 15분 동안의 평균 CPU load
