/* 퀵 정렬 구현
 * - 여러가지 정렬 알고리즘 중 가장 빠른 수행 속도를 자랑함
 * - 평균 시간복잡도 : O(nlogn)
 * - 이미 정렬된 배열에 적용되면 O(n^2)
 * - <stdlib.h> 라이브러리에 포함 제공
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 30



void swap(int v[], int i, int j){
    int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

void my_qsort(int v[], int left, int right)
{
    int i, last;

    //재귀 탈출 조건
    if(left>=right){
        return;
    }
    //swap??>
    // 첫 인덱스와 중간 인덱스의 값 바꾸기?
    swap(v, left,(left+right)/2);

    //재귀를 위한 설정
    last = left;

    for(i=left+1; i<=right;i++){
        if(v[i]<v[left]){
            swap(v, ++last,i);
        }
    }
    swap(v, left, last);
    my_qsort(v, left, last-1);
    my_qsort(v, last+1, right);
}

int compare(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int main()
{
    int i;
    int v[MAX];

    //랜덤값으로 초기화
    srand(time(0));
    for(int i=0; i < MAX ;i++){
        v[i] = rand();
    }

    //초기화된 배열 출력
    for(int i=0; i < MAX ;i++){
        printf("%6d%c",v[i], (i+1)%10==0 ? '\n':' ');
    }

    qsort(v, MAX, sizeof(int), compare);
    my_qsort(v, 0,MAX-1);


    printf("\n..selection_sorting\n");
    for(int i=0; i < MAX ;i++){
        printf("%6d%c",v[i], (i+1)%10==0 ? '\n':' ');
    }
    return 0;
}