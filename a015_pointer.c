#include <stdio.h>
int main(void){
    int x = 10;
    int y = 20;
    int z[3] = {1, 2, 3};

    int *p;      // 정수형 포인터
    p = &x;      // 포인터 p는 x의 주소값 저장 : &x
    y = *p;      // y는 포인터 p가 가리키는 주소의 값을 가짐 : *p
    *p = *p+y;   // p가 가리키는 값을 p가 가리키는 값 + y 값으로 만듦 : x = x+y = *p = *p+y
    p = &z[0];   // p는 z[0]의 주소를 가리킴
                 // *p는 z[0]의 값 (1)
                 // p = z 와 동일한 효과
    *p = 30;     // p가 가리키는 주소의 값을 30으로 초기화, z[0] = 30;

    printf("[%p] : %d\n", p, *p);       // 주소,   값 출력
    printf("[%p] : %d\n", p, *p+1);     // 주소, 값에+1 출력
    printf("[%p] : %d\n", p+1, *(p+1)); // 주소+1 : z[1]의 주소 출력,   주소 +1 값, 즉 z[1]의 값 출력

    int a[3] = {10, 20 ,30};
    int *q = a;
    printf("\n[%p] : %d",   q, *q);     // a의 주소, a[0]의 값 출력
    q = q + 1;                          // q가 가리키는 주소 + sizeof(int) 
    printf("\n[%p] : %d\n", q, *q);     // a[1]의 주소, a[1]의 값 출력

    int *ip;
    char *cp;
    double *dp;

    // 모든 포인터의 크기는 4 바이트로 같음, 주소에 어떤 값이 저장되어 있던 주소는 4바이트로 표현하기 때문
    // 시스템(32/64비트)에 따라 주소 크기는 달라짐
    printf("sizeof(int*)=%d, sizeof(char*)=%d,, sizeof(double*)=%d, \n", sizeof(ip), sizeof(cp), sizeof(dp));
    return 0;
}