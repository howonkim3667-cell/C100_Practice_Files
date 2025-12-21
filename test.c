//rand()를 이용해 1~6 사이의 주사위 값 하나를 출력하시오
#include <stdio.h>

int snumsnum(int num);

int main(void){
    int total = 0;

    for(int i =1; i<100; i++){
        total += snumsnum(i);
    }
    printf("%d", total);
}


int snumsnum(int num){
    int sum = 0;
    for(int i = 1; i < num; i++){
        if (num%i == 0){
            sum+=i;}
    }
    return sum;
}