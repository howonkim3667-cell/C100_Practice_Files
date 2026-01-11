/* 구조체를 사용하여 점과 사각형 표현하기
 * 구조체 : 여러 개의 변수를 묶어서 사용자가 만드는 자료형
 * 이차원 평면에서 점은 x좌표와 y좌표로 이루어짐
 * - 좌표가 정수라면 점을 표현하는 구조체를 다음과 같이 선언 가능
 *   struct point{
 *       int x;
 *       int y;
 *   };
 *  선언된 구조체의 사용
 * struct point p1;
 * struct point p12 = {20, 50}; // 초기화
 * 
 * 구조체는 다른 구조체를 포함 가능
 * - 사각형은 두 개의 점으로 표현할 수 있으므로 사각형을 표현하는 구조체는 다음과 같이 선언
 * struct point pnt1 = {10, 20};
 * struct point pnt2 = {30, 40};
 * struct rectangle {
 *      struct point p1;
 *      struct point p2;
 * };
 * struct rectangle r1 = {pnt1, pnt2};
 * struct rectangle r2 = {{10, 20}, {30, 40}};
 * 
 * 구조체를 사용해서 두 점 사이의 거리를 계산, 사각형 면적을 계산하는 프로그램 작성
 */

#include <stdio.h>
#include <math.h>

struct point{
    int x;
    int y;
};

struct  rectangle
{
    struct point p1;
    struct point p2;
};

double distance(struct point p1,struct point p2)
{
    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}

double area(struct rectangle r)
{
    return abs(r.p1.x - r.p2.x) * abs(r.p1.y - r.p2.y);
}

int main(void)
{
    struct point pt1 = {10, 20};
    struct point pt2 = {30, 40};
    struct rectangle rect = {pt1, pt2};

    printf("두 점사이의 거리는 : %f\n", distance(pt1, pt2));
    printf("사각형의 면적은    : %f\n", area(rect));


    return 0;
}
