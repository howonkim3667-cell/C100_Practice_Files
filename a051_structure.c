/* 구조체를 함수로 전달하기
 * 방법 1. 구조체 자체를 전달하는 방법
 *  - 구조체의 모든 멤버의 값을 그대로 복사해야 하므로 시간이 많이 소요되며 메모리 차지 많이
 * 방법 2. 구조체의 주소만 전달하여 포인터로 처리
 *  - 주소만 전달하므로 좋음
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct student
{
    char dept[20];
    int year;
    int id;
    char name[20];
    char phone[20];
};

void print_info(struct student *s)
{
    printf("\n학과    : %s\n", s->dept);
    printf("학년    : %d\n", s->year);
    printf("학번    : %d\n", s->id);
    printf("이름    : %s\n", s->name);
    printf("전화번호 : %s\n", s->phone);
}

int main(void){
    struct student s;
    char c;
    printf("학과 : ");
    scanf("%s", s.dept);
    c =getchar();
    printf("학년 : ");
    scanf("%d", &s.year);
    c =getchar();
    printf("학번 : ");
    scanf("%d", &s.id);
    c =getchar();
    printf("이름 : ");
    scanf("%s", s.name);
    c =getchar();
    printf("전화번호 : ");
    scanf("%s", s.phone);
    c =getchar();

    print_info(&s);
}
