/* 다른 형의 배열 원소의 함들 하나의 함수로 계산하기
 * - 하나의 함수로 여러 타입을 계산할 수 있게 하는 함수 만들기
 * - void 포인터 활용
 */
#include <stdio.h>
#define INT 0
#define FLOAT 1


 void sum_of_array(void *p, int length, void*result, int type){
    switch (type)
    {
    case INT:
        for (int i= 0; i<length;i++){
            *(int*)result += *((int*)p+i);
        }
        break;
    case FLOAT:
        for (int i= 0; i<length;i++){
            *(float*)result += *((float*)p+i);
        }
        break;
    default:
        break;
    }
 }
//함수가 배열의 합을 반환할 때
 void *sum_of_array2(void *p, int length, void*result, int type){
    switch (type)
    {
    case INT:
        for (int i= 0; i<length;i++){
            *(int*)result += *((int*)p+i);
        }
        break;
    case FLOAT:
        for (int i= 0; i<length;i++){
            *(float*)result += *((float*)p+i);
        }
        break;
    default:
        break;
    }
    return result;
 }


 int main(void)
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    float b[5] = {1.1, 2.2, 3.3, 4.4, 5.5};

    int intSum=0;
    float floatSum=0.0f;

    sum_of_array(a, 10, &intSum, INT);
    printf("%d\n", intSum);
    sum_of_array(b, 10, &floatSum, FLOAT);
    printf("%f\n", floatSum);


    
    intSum=0;
    floatSum=0.0f;
    //반환값이 void 포인터이기 때문에 형변환 필요           
    printf("%d\n", *(int*)sum_of_array2(a, 10, &intSum, INT));
    printf("%f\n", *(float*)sum_of_array2(b, 10, &floatSum, FLOAT));
    



    return 0;

}