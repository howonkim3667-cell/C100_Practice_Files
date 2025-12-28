#include <stdio.h>

// 배열의 3개 원소를 더해서 반환
int add3(int *p){
    
    int num = 0;
    
    for(int i=0; i<3;i++){
        // (p + i)  : i번째 요소의 주소
        // *(p + i) : 해당 주소에 저장된 값
        num+= *(p+i);
    }

    return num;
}


int main(void)
{
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int *p;

    // 배열 이름 a는 식에서 &a[0]으로 변환(decay)   
    p = a;
    
    // p, a, &a[0] 는 모두 같은 주소값을 가짐
    printf("%p %p %p\n", p, a, &a[0]);

    // *p == *a == a[0]
    printf("%d %d %d\n", *p, *a, a[0]);
    
    // 배열 a의 모든 원소 출력
    for(int i = 0; i < sizeof(a)/sizeof(a[0]); i++){
        printf("a[%d] %d ",i, a[i]);
    }

    // 포인터를 이용해 배열의 모든 원소 값 변경
    for(int i = 0; i <10; i++){
        *(p+i) = *(p+i)*10;
    }
    printf("\n");
    // 변경된 배열 값 출력
    for(int i = 0; i < sizeof(a)/sizeof(a[0]); i++){
        printf("a[%d] %d ",i, a[i]);
    }

    //  포인터 p 주소에 연산자로 값 주어 값 확인
    printf("\n%d %d %d\n", a[2], *(p+2), *(a+2));

    // 배열을 함수 인자로 전달 (int *)
    printf("Add 3 elements : %d\n", add3(a));

    printf("p address : %p , p value %d\n", p, *p);
    p++;
    /*
     * a++ 이 에러인 이유:
     *  - a는 배열 이름이며 수정 불가능한 lvalue
     *  - 배열 이름은 포인터처럼 보이지만, 실제 포인터 변수가 아니다
     *  - 따라서 주소 자체를 증가/변경할 수 없다
     */
    printf("p address : %p , p value %d\n", p, *p);

    // 포인터를 넘겨도 배열을 넘긴 것과 동일한 효과
    printf("\nAdd 3 elements : %d\n", add3(p)); 

    return 0;

}