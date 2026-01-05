#define _CRT_SECURE_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define MAXLINES  1000
#define MAXLEN    1000

// 여러 줄의 문자열을 입력받아 배열에 저장하고 정렬 출력
// 이때 사용하는 배열은 다음과 같이 문자열이 저장된 곳의 
// 주소를 가리키는 포인터 배열
char* lineptr[MAXLINES] = {NULL}; // 포인터 배열 선언


// 포인터 배열 넘기고
void writelines(char* lineptr[]){
    //포인터 배열 가리키는 이중포인터 생성
    char** ptr = lineptr;

    //포인터 배열의 NULL 가리킬 때까지 반복
    while(*ptr){
        // 포인터 배열 순회 문장 출력
        printf("%s\n", *(ptr++));
    }
}

void swap(char *v[], int i, int j){
    char *tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

void my_qsort(char* v[], int left, int right){
    int i, last;

    if(left>=right){
        return;
    }
    swap(v,left, (left+ right)/2);
    last =left;
    for(i=left+1; i<=right; i++){
        if(strcmp(v[i], v[left])<0)
            swap(v,++last, i);
    }

    swap(v,left, last);

    my_qsort(v, left, last-1);
    my_qsort(v, last+1, right);
}

int main(void){
    int nlines = 0;
    char line[MAXLEN];
    printf("문장을 입력하세요(입력을 끝낼 때는[Enter]를 누르세요):\n");
    while (fgets(line,MAXLEN, stdin)!=NULL)
    {
        if(!strcmp(line,"\n"))
            break;
        line[strlen(line)-1] ='\0';
        lineptr[nlines] = (char*)malloc(strlen(line)+1);
        if(lineptr[nlines]!=NULL)
            strcpy(lineptr[nlines], line);
        nlines++;
    }
    my_qsort(lineptr, 0,nlines-1);
    printf("\n..after sorting...\n");
    writelines(lineptr);
    
}