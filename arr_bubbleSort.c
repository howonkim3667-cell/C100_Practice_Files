/*******************************************
 * 버블정렬 C
 *******************************************/
#include <stdio.h>

void bubbleSort(int arr[], int n)
{
    int i, j, temp; 
    for (i=0; i < n-1; i++){ //버블 정렬 횟수 == n(배열안의 데이터 요소 수) -1 
        for ( j=0; j < n-i-1; j++){ 
            if (arr[j] > arr[j+1]){ // 조건 == 현재 인덱스 번호의 정수가 다음인덱스 번호의 정수보다 크면 정렬 실행
                temp     = arr[j];   // swap 로직 수행
                arr[j]   = arr[j+1];
                arr[j+1] = temp; 
            }
        }
    }
}

int main(void)
{
    int data[]= {1, 3, 5,7, 2, 10};
    int n = sizeof(data)/sizeof(data[0]);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", data[i]);
    }
    bubbleSort(data, n);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", data[i]);
    }    
    return 0;
}