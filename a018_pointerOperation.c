/*
 * 포인터 연산 정리
 *
 * 1. 포인터끼리 더할 수 있는가?
 *    - 불가능
 *    - 포인터는 주소를 저장하며, 두 주소를 더하는 연산은 의미가 없음
 *    - C 언어 문법에서도 허용하지 않음
 *
 * 2. 포인터에서 가능한 연산
 *
 *  (1) 포인터 ± 정수
 *      - 포인터가 배열 원소를 가리킬 때만 의미 있음
 *      - p + 1  → 다음 원소의 주소
 *      - 이동 크기는 sizeof(자료형) 만큼
 *
 *      예) int* p 일 때
 *          p + 1 → 주소 + sizeof(int)
 *
 *  (2) 포인터 - 정수
 *      - 이전 원소의 주소로 이동
 *      - 배열 범위를 벗어나면 Undefined Behavior
 *
 *  (3) 포인터 - 포인터
 *      - 같은 배열 내에서만 가능
 *      - 두 포인터 사이의 "요소 개수"를 반환
 *      - 결과 타입은 ptrdiff_t (보통 int로 출력 가능)
 *
 *      예) pd - pc
 *          → pc부터 pd까지 떨어진 요소 수
 *
 * 3. 주의 사항
 *    - 서로 다른 배열이나 변수의 포인터를 빼는 것은 Undefined Behavior
 *    - 배열을 기준으로 한 포인터 연산만 안전
 */

#include <stdio.h>

int main(void)
{
    int a = 10;
    int b = 20;
    int c[5] = {1,2,3,4,5};

    int *pa = &a;
    int *pb = &b;
    int *pc;

    pc = c+2; // c[2]의 주소 저장, 값은 3
    printf("[%p] %d \n", pc, *pc);

    pc = pc - 1; // pc-1의 주소 pc에 초기화 => c[1]의 주소 저장, 값은 2
    printf("[%p] %d \n", pc, *pc);

    pc = c; // pc에 c의 주소 저장 == &c[0] 값은 1

    int *pd = &c[4];

    // pc에서 pd까지 이동해야 하는 칸 수
    int cnt = pd-pc; // 인덱스 차이
    
    printf("[%p] [%p] %d \n", pc, pd, cnt);
    return 0;

}