#include <stdio.h>
#include <stdbool.h>
// 원주율 계산
// 수학자 라이프니츠의 원주율 공식이 널리 알려져 있음
// Pi를 계산하기 위함
// pi = 4(1/1 - 1/3 + 1/5  - 1/7 + 1/9 .........)
// 항수를 늘릴수록 정확도가 높아짐
// 분모는 1부터 2씩 증가
// 뺄셈, 덧셈 교차 수행하기 때문에 sign이라는 플래그 변수 사용

int main(void)
{
    bool sign = false;
    double pi = 0;
    
    for (int i = 1; i<1000000000; i+=2){
        if (sign == false){
            pi += 1.0/i;
            sign =true;
        }else{
            pi -= 1.0/i;
            sign =false;
        }
        if(i< 20 || i > 999999990){
            printf(" i = %10d. pi = %.18f\n", i, 4*pi); 
        }
    }
}

// 배우고 기억할 것
// 반복문이 실행되면서 연산이 교차되어 실행해야 할 때는 flag를 위한 변수를 선언한다
// if문에 bool 타입검사하고  true, false를 교차변형시키면서 수행 

// #include <stdio.h>
// #include <stdbool.h>
// int main()
// {
//     bool a = true;
//     for (int i = 0; i <10; i ++){
//         if (a){
//             printf("a\n");
//             a = false;
//         }else{
//             printf("not a\n");
//             a = true;
//         }
//     }
// }
//이런식으로 a가 true면 if문 실행
//false면 else문 실행되도록 할 수 있다.