/* 피보나치 수열과 동적 알고리즘
 * - 첫째와 둘때 항이 1이며 뒤의 모든 항은 두 항의 합인 수열
 * - 재귀알고리즘 표현
 * Fibo(1) = 1;
 * Fibo(2) = 1;
 * Fibo(n) = Fibo(n-1) + Fibo(n-2); n이 2보다 클 때
 * 
 * 방법 1. 배열로 반들기
 * - int 배열 f[] 만든 후 f[1] = f[2] = 1 로 초기화
 * - n이 2보다 클 때는 f[n] = f[n-1] + f[n-2] 로 계산
 * 
 * 방법 2. 재귀적 방법
 * - n번째 피보나치 항을 구하는 Fibo(n) 실행할 때 
 * - Fibo(n-1)과 Fibo(n-2)를 계산해야 함
 * - Fibo(n-1)을 구하기 위해서 Fibo(n-2), Fibo(n-3)을 
 * - 재귀 호출하여 계산하는 방법
 * 방법 3. 동적 프로그래밍 ㅂ아법
 * -  재귀적으로 반복되어 많은 시간이 걸리는 방법 2에서 
 * - 한 번 계산된 값을 배열에 저장해두고 다시 계산하지 않고 
 * - 사용하는 동적 프로그래밍 재귀방법
 * * */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

// 결과 출력용 함수(배열 + 실행 시간)
void printResult (int a[], int n, double t){
    for (int i = 1; i <=n; i++){
        printf("%d ",a[i]);
    }
    printf("\n실행시간 =%lf\n", t);
}

// n항까지의 피보나치 수열 구하는 재귀함수
int RecurFibonacci(int n){
    if(n==1||n==2){
        return 1;
    }else{
        return RecurFibonacci(n-1)+RecurFibonacci(n-2);                  
    }
}


// n항까지의 피보나치 수열 구하는 동적 프로그램
// 재귀함수에 사용될 전역변수 선언
int dp[100];

int DynaFibonacci(int n){
    if(n==1||n==2){
        return 1;
    }
    if(dp[n]!=0){
        return dp[n];
    }else{
        return dp[n] = DynaFibonacci(n-1)+DynaFibonacci(n-2);
    }
}

int main(void){
    // 피보나치 수열 저장할 배열
    int f[100];
    // 구할 n항
    int n;
    // 배열의 요소 수
    int len = sizeof(f)/sizeof(f[0]);
    
    // 실행시간 측정용 변수
    double start, end; 

    printf("n항 까지의 피보나치 수열 계산 \nn을 입력하세요 : ");
    scanf("%d", &n);

    // 방법 1. 반복문 사용
    start = clock()/CLOCKS_PER_SEC;

    
    f[1] =f[2] = 1;
    for (int i = 3; i <=n; i++){
        f[i] = f[i-1]+f[i-2];
    }

    end = clock()/CLOCKS_PER_SEC;
    printResult(f, n, end- start);


    // 방법 2. 재귀함수
    start = clock()/CLOCKS_PER_SEC;

    for (int i =1;i<=n;i++){ // 이거 0으로했다가 Exception has occurred. Segmentation fault 에러 발생
        f[i] = RecurFibonacci(i);
    }

    end = clock()/CLOCKS_PER_SEC;
    printResult(f, n, end- start);
    


    // 방법 2. 동적 프로그래밍 알고리즘 기반 재귀함수
    start = clock()/CLOCKS_PER_SEC;

    for (int i =1;i<=n;i++){
        f[i] = DynaFibonacci(i);
    }

    end = clock()/CLOCKS_PER_SEC;
    printResult(f, n, end- start);

    return 0;
}