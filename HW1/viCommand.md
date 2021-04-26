## VI Command 정리

### Insert
- **i** 현재 위치에서 insert
- **I** 현재 위치 line의 첫 번째에서 insert
- **a** 현재 위치 다음 커서부터 insert
- **A** 현재 위치 line의 끝에서 insert
- **o** 현재 위치 다음 line에서 insert
- **O** 현재 위치 이전 line에서 insert

### Substitute
- **r** 한 문자 대체
- **R** 대체모드

### copy & paste
- **dd** 한 줄 삭제 (ndd: n줄 삭제)
- **yy** 한 줄 복사 (nyy: n줄 복사)
- **p** 현재 위치 다음 line에 붙여넣기
- **P** 현재 위치 이전 line에 붙여넣기

### search
- **/string** string 검색

### more
- **u** 이전으로 돌아가기
- **:n** n번째 line으로 커서 옮기기
- **:$** 파일의 끝으로 커서 옮기기 
	* **$** 현재 line의 끝으로 커서 옮기기 (A와 비슷하지만 insert가 아님)
	* **^** 현재 line의 맨 앞으로 커서 옮기기 (I와 비슷하지만 insert가 아님)
- **:n1,n2:s/string1/string2** n1 line부터 n2 line까지 있는 string1을 string2로 바꿔라!
- **ctrl+f** 보이는 화면의 다음 장
- **ctrl+b** 보이는 화면의 이전 장
