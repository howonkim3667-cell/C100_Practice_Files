#include <stdio.h>


void printArray(int data[], int n); // 함수 전방선언
void quicktSort(int data[], int n); // 함수 전방선언


int main(void)
{
    int data[]= {11, 3, 1,  5 ,7, 2, 10}; 
    int n = sizeof(data)/sizeof(data[0]); // 배열의 요소 수 구하기

    insertSort(data, n);
    printArray(data, n);
    return 0;
}

void printArray(int data[], int n) //배열요소 출력용 함수 
{
    for (int i = 0; i < n; i++)
        {
            printf("%d ", data[i]);
        }   
    printf("\n");
}

void quicktSort(int data[], int n)
{
    
}