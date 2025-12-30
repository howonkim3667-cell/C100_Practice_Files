/* 문자열 뒤집기
 * _strrev 함수 원형
 * char* _strrev(char* str);
 * 동일한 함수 만들기
 * char* my_strrev(char* str); -> 내 구현 방식
 *  - 새로운 메모리를 할당하여
 *    뒤집힌 문자열을 생성 (heap 사용)
 *  - 원본 문자열은 변경하지 않음
 * char* my_reverse(char* s) -> 교재 구현 방식
 *  - 원본 문자열을 직접 뒤집음 (in-place)
 *  - 추가 메모리 사용 없음
 */
#include <stdio.h>
#include <string.h>
#include <malloc.h>


/* --------------------------------------------------
 * my_strrev
 *  - 문자열 길이를 구한 뒤
 *    heap에 새로운 문자열을 할당
 *  - 뒤에서부터 문자를 복사하여
 *    새로운 문자열을 생성
 * -------------------------------------------------- */
char* my_strrev(char* str){

    size_t endindex =  strlen(str); // 문자열 길이 ('\0' 제외)

    char *rev = (char*)malloc(endindex+1);  // 뒤집힌 문자열 저장 공간
    
    for(size_t  i = 0; i <endindex ;i++){
        rev[i] = str[endindex-1-i];  // 뒤에서부터 복사
    }
    
    rev[endindex] = '\0'; // 문자열 종료 문자

    return rev;
}



char* my_reverse(char* s){
    char *end = s + strlen(s)-1; // 마지막 문자 주소

    // 초기화 식 : ptr은 s의 시작 주소, 문자열의 앞쪽에서 시작
    // 조건식    : ptr과 end의 주소가 같거나 교차하는 순간
    // 증감식    : ptr 주소 증가, end 주소 감소 
    // - ptr은 앞에서 중앙으로,
    // - end는 뒤에서 중앙으로 접근해야
    // - 중복 없이 정확히 한 번씩 교환됨
    for (char *ptr=s; ptr <end; ptr++, end--){
        char tmp = *ptr; // 앞쪽 문자 임시 저장
        *ptr = *end;     // 앞쪽 ← 뒤쪽
        *end = tmp;      // 뒤쪽 ← 앞쪽
   
    }
    return s;
}


int main(void){

    char s[]= "Hello World!";
    

    char *r = my_strrev(s);
    printf("my func()    : %s\n", my_strrev(s));
    printf("_strrev()    : %s\n", _strrev(s));
    printf("my_reverse() : %s\n", my_reverse(s));
    free(r);
    
    return 0;

    
}
