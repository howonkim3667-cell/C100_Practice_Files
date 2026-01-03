/* 이진탐색
 * 배열의 원소가 정렬되어 있다면 이진탐색을 통해 값 찾을 수 있음
 * - 배열의 중간 위치의 값과 찾는 값을 비교하여 찾는 값이 더 작다면
 * - 배열 중간 이후의 값은 더 탐색할 필요 없음
 * - 비교횟수는 O(logN)
 * 
 * 배열에 저장된 값을 정렬하는데 드는 비용도 고려해야함
 * 한 번 정렬하고 탐색을 매우 많이 할 때는 적절,
 * 탐색을 몇 번만 할 때는 정렬하는 비용이 더 커지므로 비효율
 * 두 비용을 잘 고려해야 함
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000
#define CNT 1000

int binarySearch(int a[], int n, int v);
void swap(int v[], int i, int j);
void sort(int v[], int left, int right);
void printArr(int a[], int n);

int main(void)
{
    int a[CNT];
    int value, index;
    srand(time(0));

    for(int i = 0; i < CNT; i++){
        a[i] = rand() % MAX;
    }

    sort(a, 0, CNT);
    printArr(a, CNT);

    printf("\n찾고자 하는 값을 입력하세요 : ");
    scanf("%d", &value);

    if((index=binarySearch(a, CNT, value))== -1) {
        printf("%d은(는) 찾고자 하는 배열에 없습니다.", value);
    }else{
        printf("%d은(는) a[%d]에 있습니다.", value, index);
    }
    return 0;
}


// 버블정렬 함수
void sort(int v[], int left, int right){

    for(int i = left; i<right; i++){
        // j는 왜 i가 아니라 0부터 시작하지?
        for(int j= 0; j<right; j++){
    
            if(v[j]>v[j+1]){
                swap(v,j,j+1);
            }
        }
    }
}

void swap(int v[], int i, int j){
    int tmp;

    tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}


 /* 이진 탐색 함수
  *
  * low  : 탐색 범위 시작 인덱스
  * high : 탐색 범위 끝 인덱스 (n-1)
  *
  * 매 반복마다 탐색 범위를 절반으로 줄임
  */
int binarySearch(int a[], int n, int v){
    int low = 0;
    int high = n-1;
    int mid;

    while(low<=high){
        mid = (low+high)/2;
        if(a[mid]==v){
            return mid;
        }else if(v > a[mid]){
            low = mid +1;  // 오른쪽 절반 탐색
        }else{
            high = mid -1;  // 왼쪽 절반 탐색
        }
    }

    return -1;
}

void printArr(int a[], int n){
    for(int i = 0; i < n; i++){
        printf("%c%6d",(i%10==0)?'\n':' ', a[i]);
    }
}