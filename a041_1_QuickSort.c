
// 1. 기준요소 선정 및 정렬 대상 분류
// 2. 정렬 대상 분할
// 3. 반복 -> 그룹 크기가 1 이하여서 더 이상 분할할 수 없을 때까지 1과 2의 과정 반복
// 양 끝에 정찰병 2명 1조로 움직임
// 두 정찰병이 접선과정에서 기준 요소보다 작은 값이 있다면 맞교환
//  - 오름차순 정렬 기준
//  - right에 있는 정찰병이 기준요소보다 작은 값을 찾으면
//  - left 정찰병과 맞교환
//  - 서로의 인덱스가 교차하면, right 정찰병과 기준요소 교환
#include <stdio.h>

void Swap(int *A, int *B){
    int Temp = *A;
    *A = *B;
    *B = Temp;
}
// 배열, 정찰병 2명 소환
int Partition (int DataSet[], int Left, int Right){
    // 기준요소 설정 
    // 정렬 1세트 진행 후 가장 왼쪽을 기준요소로 설정
    int First = Left;
    int Pivot = DataSet[First];
    
    //왼쪽 정찰병의 기존 위치 Pivot으로 사용했으니
    //다음 위치부터 이동 시작
    ++Left;
    //반복 진행
    // 종료 조건은 왼쪽 정찰병과 오른쪽 정찰병의 
    // 위치가 같거나 맞교환 되는 시점
    while(Left <= Right){
        // 왼쪽 정찰병 이동 조건
        // - 피벗보다 작은 값에 위치하거나, 오른쪽 정찰병 위치보다 낮을 때까지
        while(DataSet[Left] <= Pivot && Left < Right){
            ++Left;
        }
        // 오른쪽 정찰병 이동 조건
        // - 피벗보다 큰 값에 위치하거나, 왼쪽 정찰병 위치보다 높을 때까지
        while(DataSet[Right] >= Pivot && Left <= Right){
            --Right;
        }
        // 이동 조건 안맞으면,  swap
        if(Left<Right){
            Swap(&DataSet[Left],&DataSet[Right]);
        }else{
            break;
        }

    }
    // 왼쪽, 오른쪽 정찰병 위치 같거나 교차하면
    // 피벗값이랑 오른쪽 정찰병 값 Swap
    Swap(&DataSet[First], &DataSet[Right]);
    // 분할될 인덱스를 위해 Right 반환
    return Right;
}

void QuickSort(int DataSet[], int Left, int Right){

    if (Left<Right)
    {
        int Index = Partition(DataSet, Left, Right);

        //재귀호출
        // 각 세트마다 분할 진행
        // Partition의 종료조건
        QuickSort(DataSet, Left, Index -1);
        QuickSort(DataSet, Index +1, Right);
    }
}

int main(void){
    int DataSet[] = {6, 4, 2, 3, 1, 5};
    int Length = sizeof(DataSet)/sizeof(DataSet[0]);

    QuickSort(DataSet, 0, Length-1);

    for(int i =0; i<Length; i++){
        printf("%2d", DataSet[i]);
    }
    printf("\n");
    return 0;
}
