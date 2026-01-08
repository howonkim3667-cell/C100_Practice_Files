#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXOP  100
#define MAXVAL 100
#define NUMBER '0'

float stack[MAXVAL];
int sp = 0;

int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getchar()) == ' ' || c =='\t')
    ;

    s[1] = '\0';
    if(!isdigit(c) && c!='.'){
        return c;
    }
    i = 0;
    if(isdigit(c)){
        while (isdigit(s[++i]= c= getchar()))
        ;
    }
    if(c=='.')
        while (isdigit(s[++i]= c= getchar()))
        ;
    s[i] ='\0';
    if(c!=EOF)
        ungetc(c,stdin);
    return NUMBER;
}

void push(float f){
    if(sp <MAXVAL)
        stack[sp++] = f;
    else
        printf("Stack full\n");
}

float pop()
{
    if(sp>0)
        return stack[--sp];
    else{
        printf("error: stack empty\n");
        return 0;
    }
}

int main(){
    int type;
    double op2;
    char s[MAXOP];

    while ((type =getop(s))!=EOF){
        switch(type){
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop()+pop());
            break;
        case '-':
            push(-(pop()-pop()));
            break;           
        case '*':
            push((pop()*pop()));
            break;           
        case '/':
            push(1/(pop()/pop()));
            break;           
        case '\n':
            printf("%.8g\n",pop());
            break;           
        default:
            printf("Unknow %s \n",s);
            break;
        }
    }
}

