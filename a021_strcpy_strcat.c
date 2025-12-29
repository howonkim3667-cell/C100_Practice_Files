/*  strcpy, strcat 함수 직접 구현
 *  strcpy : 문자열 복사하는 함수
 *  strcat : 문자와 문자 이어붙이기
 */

#include <stdio.h>
#include <string.h>
#include <malloc.h> // 힙 메모리 할당 사용


// ------------------------------------------------------------
// source(src): 원본 데이터가 있는 곳 (읽기 전용)
// dest(dst)  : 복사해서 넣을 곳 (쓰기 대상)
//
// 메모리 관점
// - source : "참조"만 함 (값을 바꾸지 않음)
// - dest   : 실제로 문자를 써야 하는 메모리 공간
// ------------------------------------------------------------

char *my_strcpy(char * dest, char * source){
    /*
     * main 함수에서 t는
     *     char *t = NULL;
     * 즉, 아무 메모리도 가리키고 있지 않음
     *
     * -> 복사할 공간이 없으므로
     * -> 함수 내부에서 source 길이만큼
     *    힙 메모리를 새로 만들어줘야 함
     */
    dest = (char *)malloc(strlen(source) +1);// '\0' 저장하기 위해 메모리 할당 크기 + 1
    if (dest==NULL){
        // malloc 실패 시 NULL 반환
        return NULL;
    }

    int i = 0;

    /*
     * while (dest[i] = source[i])
     * - 대입식의 결과값은 "대입된 값"
     * - 문자열의 끝 문자는 '\0' (값 0)
     *
     *  source[i] != '\0' → 값이 0이 아님 → while 계속
     *  source[i] == '\0' → 값이 0       → while 종료
     *
     * -> 복사 + 종료 조건을 동시에 처리하는 C 스타일 기법
     */
    while(dest[i] = source[i]) 
        i++;
    dest[i] = '\0'; //마지막 문자배열에 문자열종료 문자인 '\0' 넣기
    return dest;
}

// str1에 str2 문자열 결합

char* my_strcat(char *str1, const char* str2) //왜 하나만 상수선언? str1에 붙이기만 하니까 수정 안하려고?
{   
    /*
     * - str1 + str2 결과는 새로운 문자열
     * - 기존 변수(s, u)에 덮어쓰지 않음
     * - 따라서 결과를 담을 새 메모리가 필요
     */
    char *result = (char*)malloc(strlen(str1) + strlen(str2)+1);
    int i = 0;

    while(str1[i]!='\0'){
        result[i] = str1[i];
        i++;
    }
    /*
     * ptr은 result + strlen(str1)를 통해 result의 "끝 지점"을 가리키게 된다.
     * 이후 여기에 str2를 이어 붙임
     */
    char * ptr = result + strlen(str1);

    /* 1. *ptr = *str2  -> 문자 복사
     * 2. ptr++         -> 다음 위치로 이동
     * 3. str2++        -> 다음 문자로 이동
     */
    while( *str2 !='\0'){ // str2의 주소의 값이 '\0'이면 종료
        *ptr++ = *str2++; //
    }
    *ptr = '\0'; // 마지막 주소의 값에 '\0' 넣기

    return result;
}

int main()
{
    char s[] = "Hello World!";
    char *t = NULL;
    char u[] = "C programming language!";

    // NULL을 %s로 바로 출력하면
    // 정의되지 않은 동작(UB)
    // 삼항 연산자로 안전하게 조건 처리
    printf("original t : %s\n", t ? t : "(null)");

    //문자열 복사, 새 매모리 할당
    t = my_strcpy(t, s);
    // 결과 확인
    printf("my_strcpy() : %s->%s\n", s, t);
    printf("after t : %s\n", t);

    // 문자열 결함
    char *joined = my_strcat(s, u);
    // 함수 내부에서 메모리 할당 실패 조건문 만들기
    if(joined == NULL){
        printf("malloc Failed\n");
        free(t); //위에서 메모리 할당한 t 메모리 해제
        return 1; 
    }
    // 결과 확인
    printf("my_strcat() : %s\n", joined);

    // malloc으로 할당한 메모리 해제
    free(t);
    free(joined);

    return 0;

}
