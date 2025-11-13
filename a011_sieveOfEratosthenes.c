# include <stdio.h>
# include <stdbool.h>

#define N 1000 //N = 1000 매크로
int main(void){
    bool a[N+1]; //boolean값을 저장할 배열 선언

    a[0] = false;
    a[1] = false;
    int primes = 0;
    for (int i = 2; i <= N; i ++){  //소수는 1보다 큰 자연수 중 자신과 1만이 약수이기 때문에 2부터 시작
        a[i] = true;                // 배열 전체 true값으로 초기화,
    }

    for (int i =2; i<=N/2; i++){     // N번째 수의 N/2 이상의 수는 몫이 정수로 나오지 않기 때문에 절반만 반복문 진행
        for(int j=2; j <= N/i; j++){  // 소수를 판별하기 위한 반복은 판별 기준 수 i의 N/i 만큼만 반복하면 가능
            a[i*j] = false;          // 만약 기준수 i와 j를 곱하였을 때 수의 해당 인덱스는 소수가 아니므로 false로 변경
        }
    }
    // 소수로 판별된 true 값을 출력하기 위해 1~1000까지의 배열 인덱스를 기준으로 해당 배열 인덱스 출력
    for(int i=1; i<=N; i++){
        if(a[i]==true){
            primes++;   
            printf("%4d%c", i,primes % 15 == 0 ? '\n' : ' ');
        }
    }
    printf("\n2부터 1000 사이 소수의 개수 : %d", primes);
}



# include <stdio.h>    
# include <stdbool.h> 

#define N 1000 // 소수를 찾을 최대 범위 매크로 상수로 정의
int main(void){
    // a[i]의 i가 소수인지 아닌지를 판별하기 위한 boolean 배열
    // a[i]가 true이면 i는 소수 후보, false이면 i는 소수가 아님
    bool a[N+1];

    // 0과 1은 소수가 아니므로 false
    a[0] = false;
    a[1] = false;
    
    // 찾은 소수의 개수를 저장할 변수
    int primes = 0;
    
    
    // 로직 진행 전 1, 2를 제외한 전체 true로 초기화
    for (int i = 2; i <= N; i ++){
        a[i] = true;
    }

    /*

     * 2부터 시작하여, 아직 지워지지 않은 수(소수)를 찾고,
     * 그 수의 배수들을 모두 소수가 아닌 것(false)으로 처리(지우기)합니다.
     * 예: 2는 소수이므로, 2의 배수인 a[4], a[6], a[8], ... 을 모두 false로 초기화 
     
     * 이 과정을 반복하여 소수만 남깁니다.
     */
    // 바깥쪽 루프: i는 배수를 지우기 위한 기준 수
    // N/2보다 큰 수 n의 가장 작은 배수(2*k)N을 초과, i는 2부터 N/2까지만 확인.  
    for (int i = 2; i<=N/2; i++){
        // 안쪽 루프: i의 배수들을 찾아 소수가 아니라고 표시
        // j는 2부터 시작하여 a[i*j]가 인덱스 번호 최대인 N을 넘지 않는 범위까지만 반복
        for(int j=2; j <= N/i; j++){
            // i의 배수인 a[i*j]는 소수가 아니므로 false로 초기화
            a[i*j] = false;
        }
    }
    
    
   // 소수로 판별된 true 값을 출력하기 위해 1~1000까지의 배열 인덱스를 기준으로 해당 배열 인덱스 출력
    for(int i=1; i<=N; i++){
        if(a[i]==true){
            primes++; 
            printf("%4d%c", i,primes % 15 == 0 ? '\n' : ' ');
        }
    }
    
    // 2부터 1000 사이에서 찾은 소수의 총 개수를 출력
    printf("\n2부터 1000 사이 소수의 개수 : %d", primes);
}