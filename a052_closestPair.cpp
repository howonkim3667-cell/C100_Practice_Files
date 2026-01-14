/* 구조체의 구조체 - 최근접 점의 쌍 찾기
 * 2차원 평면상의 n개의 점이 입력으로 주어질 때,
 * 거리가 가장 가까운 한 쌍의 점을 찾는 문제
 * - 점의 위치 랜덤
 * - 점의 개수가 n개라면 두 점 사이의 거리를 계산하는 횟수는 n(n-1)/2회
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// 텍스트 대치 메모리를 차지하지 않음
// 코드 여기저기에 숫자 100을 직접 쓰면, 
// 나중에 200개로 고칠 때 100을 일일이 다 찾아야 함 
// 이렇게 이름을 지어주면 맨 위 한 줄만 고치면 됨
#define POINTS 100  // 점의 개수
#define MAXPOS 1000 // 최대 좌표



//x, y 좌표 구조체 선언
// point라는 새로운 자료형(틀) 만드는 것
typedef struct point
{
    int x;
    int y;
}point; // typedef로 구조체 별칭 선언


// 좌표 구조체와 계산된 거리 담는 구조체 선언
// pointPair 변수를 만든 후 메모리상 공간
// [ dist (8바이트) ] [ p1.x (4) | p1.y (4) ] [ p2.x (4) | p2.y (4) ]
typedef struct pointPair
{
    double dist; // 두 점 사이의 거리
    point p1;    // 첫 번째 점(구조체 변수)
    point p2;    // 두 번째 점(구조체 변수)
}pointPair; 

// 좌표 담는 구조체 배열 전역 변수
// 
point p[POINTS]; 

// 두 점 사이의 거리를 계산하는 함수
double dist(point p1, point p2)
{   
    // 피타고라스 정리로 두 점 사이의 거리 계산
    // 왜 pow() 함수를 사용하지 않았나?
    // pow 함수 대신 곱셈을 두 번 쓰는 것이 
    // 성능상 더 빠를 수 있어 자주 쓰이는 방식
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// 두 점을 매개변수로 전달받아 구조체 pointPair 반환 하는 함수
pointPair makePair(point p1, point p2)
{   
    // 완성된 정보를 담는 구조체 변수인 pointPair 에 결과 저장하기 위한 
    // 구조체 지역변수 선언
    pointPair pp; 
    
    // 두 점 사이의 거리 저장
    pp.dist = dist(p1, p2); 
    pp.p1 = p1; // 점 정보 복사
    pp.p2 = p2; // 점 정보 복사
    return pp;  // 완성된 구조체를 반환 (값 복사)
}


pointPair closestPair()
{
    double min = MAXPOS*MAXPOS; //초기 최솟값을 매우 큰 값으로 설정
    double d;

    pointPair minPair;

    for(int i = 0; i<POINTS-1; i++){
        for(int j=i+1; j<POINTS; j++){
            if((d=dist(p[i], p[j]))<min){
                min = d;
                minPair = makePair(p[i], p[j]);
            }
        }
    }
    return minPair;
}

int main(void){
    srand(time(0));


    for(int i = 0; i<POINTS;i++){
        p[i].x = rand() % MAXPOS;
        p[i].y = rand() % MAXPOS;
    }

    pointPair pp = closestPair();
    printf("closest pair : (%d, %d) - (%d, %d) distance = %f\n", pp.p1.x, pp.p1.y, pp.p2.x, pp.p2.y, pp.dist);

}


