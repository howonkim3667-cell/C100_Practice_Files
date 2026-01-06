/* 함수 포인터
 * 함수도 변수와 마찬가지로 메모리의 특정영역에 저장되어 있으므로
 * 함수가 저장된 주소를 저장하는 포인터 사용 가능
 */


// 함수 포인터 예시 -----------------
// int add(int a, int b){
//     return a+b;
// }
// 위 함수의 포인터는 아래와 같이 선언
//int (*ptr)(int, int);
// - (*ptr) : 포인터
// - 뒤에 괄호가 나오므로 함수포인터라는 뜻
// - 괄호 안에 두 개의 int가 있으니 ptr은
//   매개변수로 두 개의 정수를 가지고 int를 반환
//
// 만약 (*ptr)를 int ptr(int, int)라 사용하면?
// -> 정수 포인터를 반환하는 함수라는 뜻이 되어버림

// 함수포인터 정의 후에 함수의 주소 할당 가능함
// 함수의 이름은 주소다.
// 따라서 주소 연산자 없이 직접 함수이름 사용 가능
// ptr = &add;
// ptr = add;

// 선언과 동시에 함수의 주소 할당
// int (*ptr)(int, int) = &add;
// int (*ptr)(int, int) = add;

// 매개변수와 반환 값이 없는 함수의 포인터 fptr의 선언은 다음과 같음
// void (*fptr)();

// 실습 ---------------------------------------------------------
#include <stdio.h>

int add(int a, int b){
    return a+b;
}

void hello(){
    printf("Hello\n");
}

int main(void){
    int (*ptr)(int, int) = add;
    void (*fptr)() = hello;

    printf("%d\n", ptr(10, 20));
    fptr();
}



