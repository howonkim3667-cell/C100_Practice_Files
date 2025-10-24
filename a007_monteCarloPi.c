#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

bool isPowerofTen(int x){
    for(int i = 1; i<10; i++){
        if(x==pow(10, i)) return true;
    }
    return false;
}

int main()
{
    int x, y; // 원의 좌표
    int iCnt   = 0;  //원 내부에 있는 점의 수
    int oCnt   = 0; //원 외부에 있는 점의 수
    int radius = 50; //원의 반지름
    double pi;

    for(int i = 1; i <=100000000; i++){
        x = rand()%100; //%100을 하는 이유
        y = rand()%100;
        if((x-radius)*(x-radius) + (y-radius)*(y-radius) <= radius * radius){
            iCnt++;
        }else{
            oCnt++;
        }
        pi = (double)iCnt/(iCnt+oCnt)*4;
        if(isPowerofTen(i)) printf("i = %d, pi = %f\n", i, pi);
    }
    printf("iCnt = %d, oCnt = %d, pi = %f\n", iCnt, oCnt, pi);
}