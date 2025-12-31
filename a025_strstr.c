/***************************************
 * 문자열 안에서 다른 문자열 찾기
 * <string.h>에 있는 strstr 함수는 
 * 문자열안에서 특정 문자열을 찾는 함수
 * 
 * 함수 원형
 * - char*strstr(const char *str, const char *strSearch);
 * 
 * t* == NULL : 포인터 값 0 -> 문자열에서 배열에서 벗어났는지 확인
 ****************************************/

#include <stdio.h>
#include <string.h>

char str[] = "ababacabcaab"; // 전역 변수 배열 선언
char sub[] = "abc";          // 전역 변수 배열 선언

/*
 * 문자열 str에서 sub 문자열이 처음 시작되는 위치를 반환
 * - 찾으면: str 내부의 해당 시작 주소
 * - 못 찾으면: NULL
 */
char* my_strstr(const char *str, const char *sub)
{
    int len1 = strlen(str);// 배열이니까 &없이 그대로 전달
    int len2 = strlen(sub);
    // 빈 문자열은 항상 시작 위치로 간주
    if (len2 ==0)
        return (char*)str; 

    while(len1>=len2)//str의 남은 길이가 sub보다 작다면 비교할 필요 없음
    {
        char *s = (char*)str; //상수 const 제거 캐스팅
        char *t = (char*)sub; //상수 const 제거 캐스팅

        /* ---------------------------------------------------------------------
         * while문
         * 1. s와 t가 같은 문자면 비교 시작
         * 2. 다음 문자열이 같은지 확인하기 위해 주소 이동
         *  - 만약 다음 문자열이 같다면 계속 진행
         *  - 아니라면 빠져나와서 line 42로 이동하여 **str**의 다음 주소부터 다시 바교 시작
         * ----------------------------------------------------------------------*/
        while(*s==*t && *t !='\0'){ //포인터 s의 문자가 포인터 t의 문자와 같거나 t의 값이 NULL이 아닐 때까지 반복
            s++; // s 주소 이동
            t++; // t 주소 이동
        }
        if(*t =='\0') //만약 t가 NULL이라면 같은 문자열 없다는 것 -> 근데 왜 str 현재 주소값을 던지지?
            return (char*)str;
        str++; //주소 이동, while문 돌아가서 다음 위치부터 비교 시작
        len1 --; // str 길이 줄여가며 반복횟수 맞추기
    }
    return NULL;
}

int main()
{
    printf("strstr()    : %s\n", strstr(str, sub));
    printf("my_strstr() : %s\n", my_strstr(str, sub));
    return 0;
}
