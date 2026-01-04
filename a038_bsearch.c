/* 이진탐색 라이브러리 함수 bsearch 사용하기
 * <stdlib.h> ->  이진탐색을 위한 bsearch 함수 제공
 * void *bsearch(
 *      const void *key,
 *      const void *base,
 *      size_t num,
 *      size_t width,
 *      int (*compare) (const void* key, const void *datum)
 * );
 * 
 * 이진탐색이므로 배열은 오름차순 정렬되어야 함
 * bsearch함수의 반환값은 배열에서 key가 저장된 곳의 포인터 -> 반환값 포인터로 받아야 함
 * 배열안에 key가 없으면 NULL반환
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* p, const void* q){
    return *(int*)p - *(int*)q;
}

int main(void){
    int a[] = {10,20,30, 40, 50, 60, 70, 80, 90, 100};
    int *ptr; // bsearch 반환값 받을 정수 포인터
    int key;

    printf("찾고자 하는 값을 입력하세요 : ");
    scanf("%d", &key);
//  * void *bsearch(
//  *      const void *key,
//  *      const void *base,
//  *      size_t num,
//  *      size_t width,
//  *      int (*compare) (const void* key, const void *datum)
//  * );
    // 반환값 void 포인터이므로 정수형 포인터로 형 변환
    ptr =(int*)bsearch(&key, a, 10, sizeof(int), compare); 

    if(ptr !=NULL){
    /*
     * 포인터 뺄셈 연산 (ptr - a)
     *
     * - 같은 배열 내의 두 포인터를 빼면 "주소 차이"가 아니라
     *   포인터 타입 크기(sizeof(int)) 기준으로 나눈
     *   "원소 개수 차이"가 계산된다.
     *   ptr - a
     *   = (1012 - 1000) / sizeof(int)
     *   = 12 / 4
     *   = 3 -> 배열 시작(a[0]) 기준으로 ptr이 가리키는 원소의 인덱스
     */
        printf("%d은(는) a[%d]에 있습니다.", *ptr, ptr-a);
    }else{
        printf("%d은(는) 배열 안에 없습니다.", key);
    }
    return 0;
}
