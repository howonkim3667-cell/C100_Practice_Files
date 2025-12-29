/* 이중 포인터, 포인터 배열
 * 포인터를 가리키는 포인터도 만들 수 있음
 * 포인터가 변수니 포인터 배열도 가능 
 */

#include <stdio.h>
// 배열 전체 크기 ÷ 원소 하나 크기 식을 자동으로 만들어주는 매크로
#define LEN(arr) (sizeof(arr)/sizeof(arr[0]))
int main(void)
{
    int a[] = {1,2,3,4,5};

    // a[0~5] 원소 주소 담을 포인터 배열 선언
    int *pa[LEN(a)];
    
    // size_t는 메모리 크기와 관련된 값을 표현하기 위한 정수형 타입
    // sizeof(...)  → size_t 반환
    size_t len = LEN(a);
    
    for(int i=0; i < len; i++)
    {
        // 포인터 배열의 주소에 a배열 원소의 주소값 가져오기
        pa[i] = &a[i];
    }

    // 결과 출력
    for(int i=0; i < len; i++){
        printf("[%p] : %d\n", (void*)pa[i], *pa[i]);
    }
    
    // x에 대한 단일, 이중, 삼중 포인터 선언
    int x = 10;
    int *ptr = &x;
    int **pptr = &ptr;
    int ***ppptr = &pptr;

    // 각 포인터의 값 가져오기
    printf("%d %d %d %d\n", x, *ptr, **pptr, ***ppptr);

    // 같은 문자열 내용("abcd")을 사용하더라도
    // 저장 방식에 따라 메모리 영역과 주소는 달라질 수 있다.

    // s : 문자열 리터럴의 내용을 배열에 복사한 것
    //     → 배열 자체가 메모리를 소유함
    //     → 지역 변수이므로 스택(stack)에 저장됨
    //     → 내용 수정 가능
    char s[] = "abcd";

    // t : 문자열 리터럴의 시작 주소를 가리키는 포인터
    //     → 문자열 리터럴은 읽기 전용 메모리 영역(rodata)에 저장됨
    //     → 포인터는 그 주소만 참조함
    //     → 내용 수정 시 미정의 동작(UB)
    char *t = "abcd";

    // s와 t는 같은 문자열을 출력하지만,
    // 서로 다른 메모리 영역을 사용하므로 주소는 다르게 출력된다.
    printf("[%p]=%s, [%p]=%s\n", s, s, t, t);


    // 문자열 리터럴들을 가리키는 포인터들의 배열
    // 각 원소는 하나의 문자열 리터럴의 시작 주소를 저장함
    char *p[] = { "tiger", "lion", "zebra", "giraffe", "dragon" };

    // 포인터 배열을 순회하며 각 문자열 출력
    for (int i = 0; i < 5; i++) {
        printf("%s\n", p[i]);
    }
    return 0;
}
