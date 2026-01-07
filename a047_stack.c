/* 스택 구현
 * 후입선출 (Last -In First-Out, LIFO) 형태의 자료 다룰 때는 스택 사용함
 * 보통 배열로 구현
 * 1. 스택에 값 넣는 push 함수
 * 2. 스택에 값 꺼내는 pop 함수
 * 3. 스택을 배열로 구현 시 오버플로 방지 필요
 * 스택의 마지막 인덱스를 스택 포인터라 함
 * -> sp라는 int 변수로 지정
 * -> 0으로 시작 push 할 때마다 stack[sp++]=v로 sp 위치값 저장
 * -> sp는 하나 증가
 * -> pop은 return stack[--sp]; 하여 sp를 먼자 하나 줄이고 그 위치값 반환
 */


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#define MAXVAL 100

// 스택과 스택포인터 전역변수로 지정
int stack[MAXVAL];
int sp  = 0;

void push(int v){
    if(sp<MAXVAL){
        stack[sp++]=v;
    }else{
        printf("stack full\n");
    }
}

int pop(){
    if(sp>0){
        return stack[--sp];
    }else{
        printf("error:stack empty\n");
        return 0;
    }
}

void printStack(){
    printf("Stack : ");
    for(int i = 0; i < sp; i++){
        printf("%8d", stack[i]);
    }
    printf("\n");
}


int main(void){
    int c, v;
    while(1){
        printf("Operatrion : i(insert), d(Delete), q(Quit) : ");
        c = getche();
        printf("\n");

        switch (c)
        {
        case 'i':
            printf("Enter a number : ");
            scanf("%d", &v);
            push(v);
            break;
        case 'd':
            printf("%d removed\n", pop());
            break;
        case 'q':
            return 0;
        }
        printStack();
    }
}