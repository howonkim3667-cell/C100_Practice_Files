#include <stdio.h>

// call by value
// 이 함수는 내부에서 동작할 뿐 main 함수의 값을 바꿔주지 않는다
// 함수 내부의 x, y는 main 함수의 x, y의 값을 복사하여 사용한다
// 즉, swap이라는 함수의 스택프레임 내에서 생성된 지역변수이다.
// 내부에 구현된 swap 로직은 이 함수만의 메모리에서 이루어질 뿐 main함수의 x,y 와 아무런 관계가 없다.
void swap(int x, int y)
{
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
}  
// call by reference
// 엄밀히는 call by value + pointer
void swap2(int *px, int *py)
{
    int tmp;
    tmp = *px;  // tmp를 *px가 가리키는 주소의 값으로 초기화
    *px = *py;  // *px가 가리키는 주소의 값을 *py가 가리키는 주소의 값으로 초기화
    *py = tmp;  // *py가 가리키는 주소의 값을 tmp로 초기화
}

int main(void)
{
    int x = 3;
    int y = 4;

    swap(x, y);    // 값 전달, 복사
    printf("swap()  호출 후 : x = %d, y = %d\n", x, y);
    swap2(&x, &y); // 주소값 전달
    printf("swap2() 호출 후 : x = %d, y = %d", x, y);

    return 0;
}
