/*
 * qsort 라이브러리 함수 사용하기
 *
 * <stdlib.h>에 정의된 qsort 함수는
 * - 데이터 타입과 정렬 기준을 알 수 없는 범용 정렬 함수이다.
 *
 * 함수 원형
 *  void qsort(
 *      void *base,                     // 배열의 시작 주소
 *      size_t number,                  // 배열 원소 개수
 *      size_t width,                   // 배열 원소 1개의 크기(byte)
 *      int (*compare)(const void *, const void *) // 비교 함수
 *  );
 *
 * qsort는 배열 원소의 타입과 비교 기준을 모르기 때문에
 * 사용자가 직접 비교 함수(compare)를 제공해야 한다.
 *
 * compare 함수는
 * - 두 원소의 주소를 void* 형태로 전달받고
 * - 실제 저장된 자료형으로 형변환한 뒤
 * - 정렬 기준에 따라 음수 / 0 / 양수를 반환해야 한다.
 *
 * 이 예제에서는 구조체 student 배열을 대상으로
 * 1) 학번 오름차순
 * 2) 점수 내림차순
 * 3) 이름 오름차순
 * 정렬을 수행한다.
 */


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




/* -------------------------------------------------
 * 학생 정보 저장 구조체
 * ------------------------------------------------- */
struct student
{
    int id;        // 학번
    char name[20]; // 이름
    int score;     // 점수
};

// id를 오름차순으로 정렬하기 위한 compare1 함수
// 매개변수로 받은 보이드 포인터는 주소만 가지고 있음
// 역참조나 포인터 연산 불가
// 형변환을 통해 타입을 부여해야 올바른 메모리 접근과 주소 계산 가능
int compare1(const void*p, const void* q)
{
    // compare 함수가 qsort로부터 매개변수 p를 받을 때는 void* 상태
    // student 구조체 주소라고 명시해주어야 함
    // 형변환 진행
    const struct student *sp = (const struct student*)p;
    const struct student *sq = (const struct student*)q;
    // 구조체 내부 변수 id 사용
    int a = sp->id;
    int b = sq->id;

    // 두 값을 비교 (오름차순)
    // 음수 리턴 : 앞의 a가 더 작음 -> 유지
    // 0 리턴   : 둘이 같다
    // 양수 리턴 : 앞의 a가 더 크다. -> 자리바꿈
    return a-b;
}



int compare2(const void*p, const void* q)
{
    int a = ((struct student*)p)->score;
    int b = ((struct student*)q)->score;

    //내림차순 
    return b-a; 
}


int compare3(const void*p, const void* q)
{
    //C언어에서 문자열 = 배열이다.
    // 배열의 이름은 포인터(주소)
    // 따라서 주소를 담을 수 있는 포인터 변수에
    // name 배열의 주소를 담는다.
    char *a = ((struct student*)p)->name;
    char *b = ((struct student*)q)->name;

    //문자열 비교
    // strcmp도 앞이 작으면 음수, 크면 양수를 리턴해줌
    //  < 0 : 앞 문자열이 사전순으로 앞
    //  = 0 : 동일
    //  > 0 : 뒤 문자열이 사전순으로 앞
    return strcmp(a, b);
}

/* -------------------------------------------------
 * 구조체 배열 출력 함수
 *
 * - 구조체 변수이므로 '.' 멤버 접근 연산자 사용
 * - '->'는 구조체 포인터에서만 사용 가능
 * ------------------------------------------------- */
void printArr(struct student a[], int n){
    for (int i = 0; i <n; i++){
        printf("%5d %10s %4d\n", a[i].id, a[i].name, a[i].score);
    }
    printf("\n");
}


int main(void)
{
    // 구조체 배열 선언 {int id, char name[], int score}
    struct student a[] = {{1001, "steve", 88},
                        {1003, "tom", 98},
                        {1002, "jane", 76}};

    printf("sort by id(ascending) :\n");
    // qsort 함수 원형
    // * void qsort(
    //  *      void *base,   -> 구조체 배열
    //  *      size_t number -> 구조체 배열의 원소개수
    //  *      size_t width  -> 구조체 크기(byte)
    //  *      int (*compare)(const void *, const void *) -> 비교함수
    //  * )
    // 구조체 배열 a와 a의 원소 개수 3개, 사용하는 구조체 크기, 그리고 아이디 정렬할 기준함수 compare1 매개변수로 줌
    qsort(a, 3, sizeof(struct student), compare1);
    printArr(a, 3);

    printf("sort by score(descending) :\n");
    qsort(a, 3, sizeof(struct student), compare2);
    printArr(a, 3);

    printf("sort by name(descending) :\n");
    qsort(a, 3, sizeof(struct student), compare3);
    printArr(a, 3);
}