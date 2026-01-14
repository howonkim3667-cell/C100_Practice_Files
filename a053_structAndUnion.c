/* 구조체와 공용체를 사용하여 도형의 면적을 계산하기
 * - 공용체는 멤버들이 같은 공간을 공유함
 * - 공용체(union)의 크기는 자료형에서 가장 큰 멤버의 크기와 같음
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <math.h>

#define COUNT 3

// 상수들을 묶어서 관리하기위해 열거형(enum) 선언
enum FigureType { CIRCLE, TRIANGLE, RECTANGLE};

//도형의 타입에 따라 저장 가능한 구조체 선언
struct figure{
    enum FigureType type;   // enum으로 도형 타입 저장
    // 면적계산에 필요한 각 도형의 수치를 저장하기 위한 공용체
    union{  
        int radius;         // 반지름
        int tri_sides[3];   // 세변의 길이
        int rect_sides[2];      // 가로 세로
    };
};


// 구조체 포인터를 전달받아서 면적 계산
float area(struct figure *f)
{
    float area;
    float s;
    switch(f->type)
    {
    //원 면적 계산
    case CIRCLE:
        area = 3.141592 * f-> radius * f->radius;
        break;
    //삼각형 면적 계산 (헤론 공식)
    case TRIANGLE:
        s = (f->tri_sides[0] + f->tri_sides[1] + f->tri_sides[2]) /2;
        area = sqrt(s*(s- f->tri_sides[0])*(s- f->tri_sides[1])*(s- f->tri_sides[2]));
        break;
    // 사각형 면적 계산
    case RECTANGLE:
        area = f->rect_sides[0] *f->rect_sides[1] ;
        break;
    }
    return area;
}

void printFigure(struct figure *f){
    switch(f->type)
    {
    case CIRCLE:
        printf("이 원의 반지름은 %d, 면적은 %.2f입니다.\n", f->radius, area(f));
        break;
    case TRIANGLE:
        printf("이 삼각형 세변의 길이는 %d %d %d 면적은 %.2f입니다.\n", f->tri_sides[0], f->tri_sides[1], f->tri_sides[2], area(f));
        break;
    case RECTANGLE:
        printf("이 사각형의 두 변의 길이는 %d, %d, 면적은 %.2f입니다.\n", f->rect_sides[0], f->rect_sides[1], area(f));
        break;
    }
}

//삼각형 가장 긴 변의 길이는 다른 두 변 길이의 합보다 작은지 검사하는 함수
bool checkTriangle(struct figure fig)
{

    // 가장 긴 변의 길이 인덱스 찾기
    int max =0;
    for(int i = 0; i< 3; i++){
        if(max<fig.tri_sides[i]){
            max=i;
        }
    }

    // 가장 긴 변의 길이 인덱스 제외한 나머지 변의 길이의 합 구하기
    int otherSum = 0;
    for(int i = 0; i <3; i++){
        if(i!=max){
            otherSum +=fig.tri_sides[i];
        }
    }
    // 가장 긴 변의 길이보다 나머지 두 변의 길이가 길다면 false, 짧다면 true 반환
    if(fig.tri_sides[max]< otherSum){
        return true;
    }else{
        return false;
    }
}


int main(void)
{
    struct figure fig[COUNT];

    for(int i = 0; i < COUNT; i++){
        printf("도형의 타입은? (C:원, T:삼각형, R:사각형) : ");
        char Type = _getche();

        switch(Type)
        {
            case 'C':
                fig[i].type = CIRCLE;
                printf("\n반지름을 입력하세요:");
                scanf(" %d", &fig[i].radius);
                break;
            
            case 'T':
                fig[i].type = TRIANGLE;
                printf("\n세 변의 길이를 입력하세요:");
                scanf(" %d %d %d", &fig[i].tri_sides[0], &fig[i].tri_sides[1], &fig[i].tri_sides[2]);
                break;
            
            case 'R':
                fig[i].type = RECTANGLE;
                printf("\n폭과 높이를 입력하세요:");
                scanf(" %d %d", &fig[i].rect_sides[0], &fig[i].rect_sides[1]);
                break;
            //다시 입력받기 위한 default 선언
            default:
                i--;
                break;
        }
    }

    for(int i = 0; i < COUNT; i++){
        printFigure(&fig[i]);
    }

    return 0;
}

