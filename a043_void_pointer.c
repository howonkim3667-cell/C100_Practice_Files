/* void 포인터
 * - C에서 void는 없다 , 또는 모른다
 * - void 포인터는 주소를 저장할 수 있다.
 * - 하지만, 그 주소에 저장된 데이터가 어떤 형인지 알 수 없으므로
 * - 간접참조(*)와 포인터 연산 불가능
 * - 포인터 형 변환을 통해 포인터 연산 진행
 */
#include <stdio.h>
#define INT     0
#define FLOAT   1
#define DOUBLE  2

void* add(void* a, void* b, void *result, int type)
{
    // 각 케이스 타입에 따라 해당하는 타입으로 형변환
    // 전달받은 주소의 값들 + 연산해서 결과 반환
    switch(type){
        // 타입 INT -> (int*)x 형변환
        case INT:
            int* ptr_a = (int*)a;
            int* ptr_b = (int*)b;
            
            *(int*)result = *ptr_a +  *ptr_b;
            break;
        case FLOAT:
            *(float*)result = *((float*)a) +  *((float*)b);
            break;
        case DOUBLE:
            *(double*)result = *((double*)a) +  *((double*)b);
            break;
    }
    return result;
}

int main(void){
    int x = 10, y = 20, intResult;
    float f1 = 1.3, f2 = 2.4, floatResult;
    double d1 = 2.5, d2 =3.3, doubleResult;

    printf("%d\n", *(int*)add(&x,&y, &intResult, INT));
    printf("%f\n", *(float*)add(&f1,&f2, &intResult, FLOAT));
    printf("%lf\n", *(double*)add(&d1,&d2, &intResult, DOUBLE));
}