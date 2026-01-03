/* 선형 탐색
 * 배열에 저장된 값 중에서 원하는 특정 값을 찾기
 * - 찾은 값이 배열에 있으면 배열의 인덱스 반환
 * - 없으면 -1 반환
 * - 시간복잡도는 O(N)
 * 배열의 max, min 값을 찾는 경우도 선형탐색 사용
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000
#define CNT 1000


int search(int a[], int v);
void printArr(int a[], int n);
void find_min_max(int a[], int n);

int main(void)
{
    int a[CNT];
    int value, index;

    srand(time(0));

    for (int i = 0; i<CNT;i++){
        a[i] = rand() % MAX;
    }

    printArr(a, CNT);
    find_min_max(a, CNT);
    printf("\n찾고자 하는 값을 입력하세요 : ");
    scanf("%d", &value);

    if((index=search(a,value))==-1){
        printf("%d은(는) 배열 안에 없습니다.", value);
    }else{
        printf("%d은(는) a[%d]에 있습니다.", value, index);
    }

    return 0;
}

int search(int a[], int v){
    // 배열 순차적으로 탐색하면서 타겟값 있는지 확인
    for (int i = 0; i<CNT; i++){
        // 있으면 인덱스 반환
        if(a[i]==v){
            return i;
        }
    }
    //없으면 -1 반환
    return -1;
}

void find_min_max(int a[], int n){
    int max = a[0];
    int min = a[0];

    for(int i = 1; i < n; i++){
        if (a[i]>max){
            max = a[i];
        }
        if (a[i]<min){
            min = a[i];
        }
    }

    printf("\nmin = %d, max = %d", min, max);
}

void printArr(int a[], int n){
    for(int i =0; i < n; i++){
        printf("%c%6d",(i %10 == 0)? '\n': ' ', a[i]);
    }
}