/* 버블 정렬 (Bubble Sort)
 *
 * - 배열의 앞에서부터 인접한 두 원소를 비교하면서
 *   더 큰 값을 오른쪽(뒤쪽)으로 보내는 정렬 방식
 * - 한 번의 패스가 끝날 때마다 가장 큰 값이
 *   배열의 끝에 하나씩 고정됨
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 30


// swap용 함수
void swap(int v[], int i, int j)
{
    int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

// 인덱스 현재 번호와 다음 번호 비교
// 현재 번호의 값이 다음 번호의 값보다 크다면 swap 진행
void bubble_sort(int v[], int left, int right)
{
    // 전체 패스 횟수
    for(int i = left; i < right; i++){
        
        // 인접한 두 원소를 비교하며 큰 값을 뒤로 이동
        for(int j = 0; j< right-1-i; j++){
            if(v[j]> v[j+1]){
                swap(v, j,j+1);
            }
        }
    }
}

//배열 출력 함수
void printArr(int v[], int n){
    for(int i = 0; i<n; i++){
        printf("%6d %c",v[i], (i+1)%10==0? '\n':' ');
    }
}

int main(void){

    int v[MAX];

    // 난수 시드 설정
    srand(time(0));

    // 배열에 난수 값 저장
    for(int i = 0; i < MAX; i++){
        v[i] = rand();}
        
    // 정렬 전 배열 출력
    printArr(v, MAX);

    // 버블 정렬 수행
    bubble_sort(v, 0, MAX);

    // 정렬 후 배열 출력
    printf("\n..bubble sorting\n");
    printArr(v, MAX);

    return 0;
}