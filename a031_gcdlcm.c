#define _CRT_SECURE_NO_WARNING
#include <stdio.h>

// gcd 함수 선언
int gcd(int x, int y);

int main(void)
{
    int a, b, GCD, LCM;

    printf("개의 정수를 입력하세요 :");
    scanf("%d %d", &a, &b);

    GCD = gcd(a,b);  // 최대공약수 
    LCM - (a*b)/GCD; // 최소공배수 : 두 수의 곱(a*b)/ 최대공약수

    printf("GCD(%d, %d) = %d", a, b, GCD);
    printf("LCM(%d, %d) = %d", a, b, LCM);

    return 0;
}
// gcd 함수 정의
// 최대공약수 유클리드 호제법 재귀함수
int gcd(int x, int y){

    if (y ==0){
        return x;
    }else{
        return gcd(y, x%y);
    }
}