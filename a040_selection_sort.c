/* 선택정렬
 * - 숫자 중에서 가장 작은 값을 찾아서 맨 앞에 이동시키고
 * - 그 다음 작은 값을 찾아 앞을 이동시키는 과정 반복하여 정렬
 * - 버블 정렬과 시간복잡도는 같지만 가장 작은 수를 먼저 찾아
 * - 한 번씩만 위치를 바꾸어 주므로 버블 정렬보다 효율적
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
/* ----------------------------------------------------------
 * selection_sort
 * - v[left] ~ v[right-1] 구간을 선택 정렬로 오름차순 정렬
 *
 * 동작 과정:
 *  1) 현재 위치 i를 최소값 인덱스로 가정
 *  2) i 이후 구간에서 더 작은 값이 있는지 탐색
 *  3) 최소값 인덱스가 바뀌었으면 한 번만 swap
 * ----------------------------------------------------------
 */
void selection_sort(int v[], int left, int right){
    // 정렬할 시작 인덱스부터 끝-1까지 반복
    for(int i = left; i < right-1; i++){
        // 현재 위치 i를 최소값 인덱스로 가정
        int min=i;
        // i 이후 구간에서 최소값 탐색
        for(int j =i+1; j<right; j++){
            //인덱스 첫 값 최소값으로 설정
            //배열 순회하면서 min값 찾기
            if(v[min]>v[j]){
                // 더 작은 값 발견 시 인덱스 갱신
                min =j;
            }
        }
        // 최소값이 현재 위치가 아니라면 교환
        swap(v,i,min);
    }
}
int main(void){
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
    //선택정렬 진행
    selection_sort(v, 0, MAX);

    // 선택정렬 진행 후 배열 값 출력
    printf("\n..selection_sorting\n");
    for(int i=0; i < MAX ;i++){
        printf("%6d%c",v[i], (i+1)%10==0 ? '\n':' ');
    }
    return 0;

}