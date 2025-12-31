/***************************************
 * 실수를 표시하는 문자열을 숫자로 변환
 * ascii to float 구현
 ****************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>// strcpy 함수
#include <math.h>  // pow 함수
#include <ctype.h> //isdigit 함수

#define MINUS -1
#define PLUS   1

double my_atof(char *s)
{
    int sign =PLUS;         // 부호
    int value = 0;          // 정수부(significand)
    double mantissa = 0;    // 가수부(mantissa)
    double mandigit = 10;   // 가수부의 자릿수
    int exp = 0;            // 지수부 (exponent)
    int expsign = PLUS;      // 지수부 부호
    
    // 마이너스 부호 처리
    if(*s == '-'){
        sign = MINUS;
        s++;
    }else {
        if (*s == '+') // 왜 else if 안쓰고 이렇게 했지?
            s++;
    }

    // 소수점 까지 읽기(정수부)
    while(*s != '.' && *s !='E' && *s !='e' &&  *s !='\0') // *s !='\0' 이거  *s !=NULL 과 차이가 있나 다르게 쓰는 의미가 있나
    {
        if(isdigit(*s)){
            value = value *10 + (*s - '0'); // 정수부 문자열 변환 atoi와 로직 같음
        }
        s++;
    }

    //가수부(mantissa)
    if(*s=='.'){ 
        s++; // 시작이 '.'이니까 다음 주소로 이동
        while(*s !='E' && *s != 'e' && *s!='\0'){
            if(isdigit(*s)){
                mantissa = mantissa + (*s -'0')/mandigit; // 소수점 자리수 0.(mantissa + (*s -'0')) 모양으로 맞추기
                mandigit *=10;                             // 다음 소수점 자리수를 위해 *10
            }
            s++;
        }
    }

    // 지수부(exponent) 부호 처리
    if(*s =='e'|| *s =='E'){
        s++;
        if(*s =='-'){ // 지수부 부호 음수 처리
            expsign = MINUS; 
            s++;
        }else {
            if(*s =='+')
                s++;
        }
    }

    // 지수부 숫자 읽기
    while(*s != '\0'){
        if(isdigit(*s)){
            exp = exp * 10 +(*s - '0');
        }
        s++;
    }

    /* ---------------------------------------
     * 최종 실수 계산
     *
     * 실수 = 부호 *
     *        (정수부 + 가수부) *
     *       pow(10^(지수부 부호 * 지수부))
     * -------------------------------------*/
    return sign * (value+mantissa) * pow(10, expsign * exp);
}

int main(void)
{
    char s[30] = "1.234";
    printf("%f\n", my_atof(s));

    strcpy(s, "1.234e10");
    printf("%e\n", my_atof(s));

    strcpy(s, "-1.234E-10");
    printf("%e\n", my_atof(s));

    return 0;
}

