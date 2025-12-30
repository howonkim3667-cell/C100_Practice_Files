/* 대문자와 소문자의 변환
 * <ctype.h> 헤더 파일에는 문자 검사와 문자 변환과 관련된 함수들 포함하고 있음
 * 대소문자와 소문자 변환하는 함수는 다음과 같은 원형 가짐
 * int tolower(int c); : 문자 'c' 소문자 변환
 * int toupper(int c); : 문자 'c' 대문자 변환
 * 
 * 문자열 단위로 변환해주는 함수를 만들어보자
 * char to_upper(char* str);
 * char* to_lower(char* str);
 */
#include <stdio.h>


char* to_upper(char* str)
{
//  * 포인터를 사용하면 배열 인덱스 없이 문자열을 순회하며
//  * 원본 의 문자를 직접 수정할 수 있다 (in-place 변환)문자열
    char *ptr = str;

    while(*ptr){ // '\0' 까지 반복
        /* 소문자 범위 ('a' ~ 'z') 인 경우 */
        if (*ptr >= 'a' && *ptr <= 'z') {
            /* 문자 상수를 이용해 대소문자 변환
             * ASCII 코드에서 소문자와 대문자의 차이를
             * 숫자(32)가 아닌 문자 기준으로 계산하여
             * 가독성과 의미를 명확히 한다
             */
            *ptr = *ptr - 'a' + 'A';
        }   
        ptr++;
    }
    /* 변환된 문자열의 시작 주소 반환 */
    return str;
}


char* to_lower(char* str)
{
    char *ptr = str;

    while(*ptr){ // '\0' 까지 반복
        /* 대문자 범위 ('A' ~ 'Z') 인 경우 */
        if(*ptr >='A'&& *ptr <='Z')
            *ptr = *ptr - 'A'+'a';
        ptr++; // 포인터 주소 다음 배열로 이동
    }
    return str;
}

int main(void)
{
    char s[] = "Hello Wolrd!";
    printf("to_upper() : %s\n", to_upper(s));
    printf("to_lower() : %s\n", to_lower(s));

    return 0;
}


