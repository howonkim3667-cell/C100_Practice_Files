/* string.h
 * - 문자열을 다루기 위한 표준 헤더 파일
 * - strlen : 문자열 길이 반환 ('\0' 제외)
 * - strcmp : 두 문자열을 비교
 *            같으면 0
 *            s < t 이면 음수
 *            s > t 이면 양수
 */
 #include <stdio.h>
 #include <string.h>



 /*
 * my_strlen
 * - 배열 인덱스를 이용한 strlen 구현
 * - 문자열의 끝('\0')을 만날 때까지 카운트
 */
 size_t my_strlen(const char *s)
 {
    // size_t
    // - 메모리 공간의 크기, 배열 인덱스 등에 사용
    // - 부호 없는 정수형 데이터 타입
    size_t i = 0;
    // 문자배열의 끝인 \0에 도달할 때까지 반복
    while(s[i]!='\0'){
        i++; // 문자 하나씩 증가
    }
    // '\0'을 제외한 문자열 길이 반환
    return i;
 }

 /*
 * my_strlen2
 * - 포인터 연산을 이용한 strlen 구현
 */
 size_t my_strlen2(const char* s)
 {
    /*
     * const char *p = s; => warning!
     * - s는 읽기 전용 문자열이므로
     * - 포인터도 반드시 const char *로 받아야 함
     */
    const char *p = s; 

    // '\0'을 만날 때까지 포인터 이동
    while(*p!='\0'){
        p++; 
    }
    /*
     * 포인터 뺄셈
     * - p  : 문자열 끝('\0')을 가리키는 주소
     * - s  : 문자열 시작 주소 (s[0])
     * - p - s : 두 주소 사이의 문자 개수
     */
    return p-s; 
 }

/*
 * my_strcmp
 * - strcmp 직접 구현
 * - 반환값 의미
 *   s < t  -> 음수
 *   s == t -> 0
 *   s > t  -> 양수
 */
int my_strcmp(const char *s, const char *t)
{
    int i;

    
    // 두 문자열 모두 끝('\0')에 도달하지 않는 동안 비교
    for (i = 0; s[i]!='\0'&&t[i]!='\0'; i++){ 
        if (s[i] !=t[i]) 
            break; // 다른 문자 만나면 break
    }
    /*
     * ASCII 코드 값 비교
     * - 'W' < 'w'
     * - 대소문자 차이도 여기서 발생
     */
    
    if(s[i] > t[i])
        return 1;
    else if(s[i] == t[i])
        return 0;
    else
        return -1;
}


int main(void)
{
    char s[] = "Hello World!";
    char t[] = "Hello world!"; // W vs w → ASCII 값 다름

    /*
     * size_t 는 unsigned 타입이므로
     * 출력 시 %zu 사용이 정석
     * 두 문자열의 길이는 같기에 같은 인덱스, 크기 반환됨
     */

    
    printf("strlen(): %zu\n", strlen(s));
    printf("my_strlen(): %zu\n", my_strlen(s));
    printf("my_strlen2(): %zu\n", my_strlen2(s));
    
    
    /*
     * strcmp / my_strcmp
     *
     * - 'W'(87) < 'w'(119)
     * - 따라서 s < t
     * - 음수 값 반환
     */
    printf("strcmp(): %d\n", my_strcmp(s, t));
    printf("my_strcmp(): %d\n", my_strcmp(s, t));

    return 0;
}