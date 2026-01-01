/* 재귀함수를 사용해서 10진수 2진수 변환
 * 10진수를 계속 2로 나누어가며 나머지를 역순으로 출력하면 2진수
 * 처음 계산한 나머지가 제일 나중에 출력되어야 하므로 나머지 값을 배열에저장,
 * 계산 끝난뒤 배열 뒤에서 부터 출력
 * 
 * 
 * 이번 구현에서는 INT_MAX의 값인 2,147,483,647 보다 큰 값을 입력 받았는지 검사하는
 * checkOverflow함수 함께 구현
 * 따라서 _itoa 함수 사용해 만들어진 입력 정수가 자리수를 초과하는지 검사
 */

#define _CRT_SECURE_NO_WARNINGS
#define SIZE 32     // int 타입이 가질 수 있는 최대 비트 수
#include <stdio.h>  // 표준 입출력
#include <stdlib.h> // atoi, _itoa
#include <limits.h> // INT_MAX
#include <string.h> // strlen

int checkOverflow(char buffer[]){
    char intmax[11]; // INT_MAX = 2147483647 -> 총 10자리 + '\0'
    
    // 1. INT_MAX 값을 문자열로 변환
    //    숫자 비교를 문자열로 비교
    _itoa(INT_MAX, intmax, 10); 

    // 2. 입력받은 문자열(buffer)의 길이가
    //    INT_MAX 자리수보다 길면 -> 무조건 overflow
    if(strlen(buffer) > strlen(intmax)){
        return 1;
    }
     // 3. 자리수가 같은 경우 -> 각 자릿수 문자 비교
    else if (strlen(buffer) == strlen(intmax)){
        // 가장 높은 자리부터 비교
        // buffer가 한 자리라도 더 크면 overflow
        for (int i = 0; i<11; i++)
            if(buffer[i]>intmax[i])
                return 1;
    }
    // 4. 모두 문제가 없다면 int 범위 내에 해당
    //    0 반환
    return 0;
}

void array_d2b(int n)// decimal to binary
{   
    int arr[SIZE] = {0}; //int최대 비트 SIZE 32
    int i;
    int length = 0;   // 실제 저장된 비트 개수 == 배열 길이

    // 1. 10진수를 2로 나누면서 나머지를 배열에 저장
    //    LSB(최하위 비트)부터 저장
    for(i = 0; n>0; i++){
        // 1-1 현재 비트 저장
        arr[i] = n%2;
        // 1-2 다음 비트를 계산하기 위해 2로 나눔
        n/=2;
        // 저장된 비트 수 증가
        length++;
    }
    // length는 개수, index는 0부터 시작
    // index Max == length -1
    length--;

    // 뒤에서 부터 출력
    while(length>=0){ 
        printf("%d", arr[length]);
        length--;
    }
}

void recursive_d2b(int n) // 재귀함수로 decimal to binary 구현
{
     // 1. n이 2 이상이면 n / 2를 먼저 재귀 호출
    if(n>=2){
        recursive_d2b(n/2);
    }
    // 2. 재귀가 끝나고 돌아오면서 나머지 출력
    printf("%d", n % 2);
}

int main(void)
{
    int n;
    char number[11] = "27"; //10자리 +'\n'
    
    printf("10진수 정수를 입력하세요");
    //scanf("%s", number); // 간단한 확인을 위해 scanf 사용 X

    

    if(checkOverflow(number)==1){
        printf("입력한 숫자가 정수의 범위를 넘어섭니다.\n");
        exit(0); //프로그램 종료
    }
    n = atoi(number); // 문자열 정수로 변환
    
    //배열
    printf("\n 10진수 %d의 2진수는 : ", n);
    array_d2b(n);

    //재귀
    printf("\n 10진수 %d의 2진수는 : ", n);
    recursive_d2b(n);
}
