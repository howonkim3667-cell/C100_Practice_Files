/* 실행 시간 측정
 * - 프로그램 효율성을 알기 위한 실행 시간 측정
 * - <time.h>의 clock 함수 사용
 * - clock_t clock(void)
 */



#include <stdio.h>
#include <time.h>



int main(){

    double start, end;

    //시작 시간
    // clock() : 프로그램 실행 중 사용된 CPU 시간을 clock_t 단위로 반환
    // CLOCKS_PER_SEC : 1초당 clock tick 수 (시스템마다 다름)
    start = (double)clock() / CLOCKS_PER_SEC; //CLOCKS_PER_SEC == 1000
    int sum = 0;
    // 반복문 1천만 번 반복
    for (int i = 0; i < 10000000; i++){
        sum++;
    }
    
    // 끝 시간
    end = (double)clock() / CLOCKS_PER_SEC; 
    // 시작 시점(start)과 종료 시점(end)의 clock 차이를 이용해 CPU 실행 시간을 계산
    printf("sum = %d, 실행 시간 = %lf초\n", sum, end -start);

    return 0;
}