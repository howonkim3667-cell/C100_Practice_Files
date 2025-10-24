// 열겨형  
//   -  서로 관려있는 상수들의 집합을 정의
//   -  숫자에 특정한 명칭을 붙여주어 의미를 쉽게 이해할 수 있게 하는 용도로 사용 
// 

#include <stdio.h>


enum Size { Short, Tail, Grande, Venti };
// enum Size
//   - int 자료형을 선언한 것 처럼
//     enum Size 라는 새로운 자료형을 정의
//   { Shrot, Tail, Grande, Venti }
//    열거자 목록 (정수 상수들의 목록) 정의
//     순서대로 0 ~3 까지의 정수 값을 가지게 된다


char sizeName[][7] = {"Short", "Tail", "Grande", "Venti" };
int priceAmericano[]={3800,4100,4600,5100};
int priceCapuccino[]={4600,5900,6400,6900};

int main(void){
    printf("커피 가격표 ( 아메리카노)\n");
    for(int i = Short; i < Venti; i++){
        printf("%10s  :  %5d\n", sizeName[i],priceAmericano[i]);
    }
    printf("커피 가격표 ( 카푸치노)\n");
    for(int i = Short; i < Venti; i++){
        printf("%10s  :  %5d\n", sizeName[i],priceCapuccino[i]);
    }
    return 0;

}