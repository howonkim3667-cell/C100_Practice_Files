/* 함수 포인터의 배열을 사용한 계산기
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 함수 포인터의 배열에 사용될 계산 함수들
float add(float a, float b){
    return a+b;
}

float subtract(float a, float b){
    return a - b;
}

float multiply(float a, float b){
    return a * b;
}

float divide(float a, float b){
    return a / b;
}

int main(void)
{
    float a, b;
    //함수포인터배열 인덱스용 정수
    int choice;
    //함수포인터 배열 선언 및 함수들로 요소들 초기화
    float(*funcptr[4])(float, float)={add, subtract, multiply, divide};
    printf("Enter to numbers : ");
    scanf("%f %f",&a, &b);
    printf("Enter choice[0:add 1:subtract 2:multiply 3:divide]: ");
    scanf("%d", &choice);
    // choice 인덱스 번호 기반 계산 진행
    printf("result = %f\n", funcptr[choice](a, b));

}