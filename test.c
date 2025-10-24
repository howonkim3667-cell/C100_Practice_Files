//rand()를 이용해 1~6 사이의 주사위 값 하나를 출력하시오
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    //랜덤시드 설정 srand(). RAND_MAX 랜덤 최대값
    int max = 6; //주사위 최대값
    int min = 1; //주사위 최소값
    int result;
    srand(time(0));// 난수 생성 시드 시간으로 설정

    result = (int)rand()/RAND_MAX *(max -min + 1) + min;
    // result = rand()%max + min;
    printf("%d", result);

    return 0;
}