/* 정수와 문자열 변환
 * 숫자 1234와 문자열 "1234"는 완전히 다른 데이터
 * <stdlib.h>에는 문자열 변환을 위한 함수가 있음
 * atoi  : ASCII to integer
 * - 문자열 정수로 변환
 * - 문자열 앞뒤의 공백 자동 무시
 * - 부호(+/-) 처리 가능
 * - 숫자가 아닌 문자 만나면 변환 중단
 * _itoa : integer to ASCII
 * - 정수를 문자열로 변환
 * - 변환 결과를 저장할 char 배열이 필요
 * - 진법(base) 지정 가능 : 10진수, 16진수, .. 
 */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int my_atoi(const char *s) //문자열 읽기 전용으로 받음
{
    int value = 0;

    while(*s){ // 0 의미하는 문자열 마지막 '\0' 까지 반복
        if(*s>='0'&& *s<='9'){ //아스키 코드 값 0~9사이라면
            value =  (value*10) + *s - '0';
            /* 
            * *s - '0'
            *  : 문자 '0'의 ASCII 값을 빼서
            *    문자 형태의 숫자를 실제 정수 값으로 변환
            *
            * value * 10
            *  : 기존 값의 자릿수를 한 칸 왼쪽으로 이동
            *    (새로운 숫자를 추가할 공간을 만들기 위함)
            *
            * 결과
            *  : 기존 숫자를 한 자리 올린 뒤,
            *    새로 읽은 문자 숫자를 더해 누적
            */
            s++; //s 주소 다음 배열 요소의 주소로 이동
        }else{
            //숫자 아닌 문자 만나면 예외처리
            printf("non-number found!"); 
            return -1; 
        }
    }
    return value;
}

char* my_itoa(int v){
    // 1. 문자열이 들어갈 메모리 만들기
    //  - 숫자 자릿수를 먼저 알아야 함
    int len = 0;
    int t = v;

    while(t){                 // t가 0이 될 때까지 반복
        len++;                // 숫자 자릿수 증가
        t /= 10;              // 정수 / 정수 연산 → 소수점 버림
                               // 한 자리씩 제거되며 마지막에 0이 됨
    }

    // 2. 구한 자릿수로 문자열을 담을 메모리 크기 할당
    //  - 자릿수 + 문자열 종료 문자('\0') 공간 필요
    char *number = (char*)malloc(len + 1);
    number[len] = '\0';        // 문자열의 끝을 알리는 NULL 문자

    // 3. 배열에 문자 담기
    //  - 나머지 연산을 이용해 뒤자리 숫자부터 추출
    //  - 뒤에서부터 채우기 위해 len을 감소시키며 저장
    while(len != 0){
        number[--len] = v % 10 + '0';  // 숫자 → 문자 변환하여 저장
        v /= 10;                       // 다음 자리수 처리를 위한 나누기
    }

    return number;             // 변환된 문자열의 시작 주소 반환
}


int main(void)
{
    char buffer[30];

    printf("atoi(   ) : %d\n", atoi("1234567"));
    printf("my_atoi() : %d\n", my_atoi("1234567"));

    _itoa_s(1234567, buffer,_countof(buffer), 10);
    // _itoa 보안 강화 함수  : _itoa_s
    //   errno_t _itoa_s(
    //   int value,         - 문자열 변환 정수 값
    //   char *buffer,      - 변환된 문자열 저장될 배열 * 할당된 메모리 있어야 함
    //   size_t bufferSize, - buffer의 전체 크기
    //   int radix          - 진법
    //    );

    //#define _countof(arr) (sizeof(arr) / sizeof(arr[0]))
    // - 배열의 전체 원소 개수 매크로
    // - <sal.h> 에 정의되어 있으나 <stdio.h> 내부적으로 <sal.h>가 포함
    printf("_itoa_s() : %s\n", buffer);
    printf("my_itoa() : %s\n", my_itoa(1234567));
}