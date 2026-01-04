/* qsort를 이용한 재귀 이진탐색
 * 이진 탐색을 위해서는 배열의 내용이 정렬되어 있어야 함
 * qsort를 사용해서 배열 내용 정렬 후 이진탐색으로 원하는 값 찾기
 * 이진탐색을 재귀로도 구현 가능
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10000
#define CNT 1000

void printArr(int a[], int n){
    for (int i = 0; i<n; i++){
        printf("%c%6d", (i %10 == 0)? '\n':' ', a[i]);
    }
}

// qsort 사용하기 위해 양수, 음수, 0값 리턴
int compare(const void*p, const void*q){
    // int *ptr_p = (int*)p;
    // int *ptr_q = (int*)q;
    // return *ptr_p - *ptr_q;
    
    // 위 비교 로직을 한 줄로 축약
    return *(int*)p - *(int*)q;
}

// 이진 탐색에서 low, high 값을 줄여가며 탐색하던 로직을
// 재귀 함수 형태로 구현
// low ~ high 범위에서 key를 탐색
int bSearch(int a[], int low, int high, int key){
    if(low<=high){
        int mid = (low+high) /2;
        if(key==a[mid]){
            return mid;
        }else if(key>a[mid]){
            return bSearch(a, mid+1, high, key);
        }else {
            return bSearch(a, low, mid-1, key);
        }
    }
    return -1;
}

int main(void){
    int a[CNT];
    int value, index;

    //random seed 설정
    srand(time(0));

    for(int i=0; i<CNT; i++){
        a[i] = rand() % MAX;
    }

    // 배열 배열원소 수, 원소 크기, compare 함수
    qsort(a, CNT, sizeof(int), compare);
    printArr(a, CNT);

    printf("\n 찾고자 하는 값을 입력하세요. >");
    scanf("%d", &value);

    if(index=(bSearch(a, 0, CNT-1, value))==-1){
        printf("%d은(는) 배열 안에 없습니다", value);
    }else{
        printf("%d은(는) a[%d]에 있습니다", value, index);
    }
    return 0;
}