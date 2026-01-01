/* ------------------------------------------------------
 * 10진수를 2진수로 변환
 * - 실제 이진수 값이 아닌  10진수 형태로 이진수 모양을 표현하기
 *  ex)
 *   dec   = 5;
 *   실제 이진수 = 101
 *   출력  표현  = 101 (long long)  
 * ------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

long long decimal_to_binary(int dec){
    long long bin = 0; // 이진수 모양 저장용 long long 변수
    int mask = 0x01;   // 0000 0001, 최하위 비트 확인용 마스크
    int bit;           // 확인된 비트 저장용 변수

    for(int i = 0; i<16; i++){ //16자리수의 이진수 표현

        /*
         * AND 연산 결과
         * - dec의 마지막 비트가 1이면 -> 1
         * - dec의 마지막 비트가 0이면 -> 0
         */
        bit = dec&mask; 
                                
        /*
         * bit 값을 10진수 자리수로 변환하여 bin에 누적
         * i = 0 -> 1의자리
         * i = 1 -> 10의자리
         * 
         * bit * 10^1 를 통해 총 반복 횟수인 16자리 2진수까지 표현
         */
                        
        bin += bit *pow(10, i);
        /*
         * dec 오른쪽으로 1 비트 이동
         * >> 1
         * 현재 맨 끝 비트(LSB)를 버리고
         * 다음 비트를 새로운 LSB로 만들기
         * dec = 0011 (3)
         * dec >> 1 -> 0001 (1)
         */
        dec=dec>>1;
    }
    return bin;
}

int main(void){
    long long bin;
    int dec;
    
    printf("Enter decimal number : %d\n", dec);
    
    //scanf("%d", dec ); // 간단한 확인을 위해 scanf 사용 X
    dec = 139;
    bin = decimal_to_binary(dec);
    printf("%d(decimal) = %lld(binary)", dec, bin);
    return 0;
}
