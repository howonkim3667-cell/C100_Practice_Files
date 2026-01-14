/* 연결리스트에서의 데이터 추가
 * - 필요한 만큼의 메모리를 필요한 순간에 동적 할당하여 사용할 수 있는 자료구조
 * - 포인터를 사용해서 다음 노드 구조체를 가리키게 하여 이어지게 하는 방식
 * 순서
 * - (1) temp -> next  = ptr->next;
 * - (2) ptr->naxt  - tmp;
 */

#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void append();          // 리스트 맨 뒤에 추가
void insert();          // 리스트 맨 앞에 추가
void insert_pos();      // 특정 위치에 추가
void display();         // 리스트 출력

//node 구조체 정의
struct node
{
    int value;         // 저장되는 데이터
    struct node* next; // 다음 노드를 가리키는 포인터
                       // -> 다음 노드의 데이터 타입이 node 구조체 타입이기 때문에 구조체 타입의 포인터 선언
};

// 연렬리스트의 첫 노드를 가리키는 포인터
struct node* head = NULL;

int main(void){

    int choice;
    while(1){
        printf("==================== MENU ==================\n");
        printf("1.Append\n");
        printf("2.Insert\n");
        printf("3.Insert at position\n");
        printf("4.Display\n");
        printf("0.Exit\n");
        printf("--------------------------------------------\n");
        printf("Enter your choice");


        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            append();
            break;
        case 2:
            insert();
            break;
        case 3:
            insert_pos();
            break;
        case 4:
            display();
            break;
        case 0:
            exit(0);
            break;
        }
    }
}



void append(){
    //메모리 할당을 위한 구조체 포인터
    struct node *temp;
    struct node *ptr;

    //구조체 크기의 메모리 할당
    temp = (struct node*)malloc(sizeof(struct node));

    if(temp==NULL){
        printf("Out Of Memory");
        exit(0);
    }

    printf("\nEnter data :");
    scanf("%d", &temp->value);
    temp->next = NULL;

    //링크드리트스 헤드가 없으면 새로 만든 노드로 헤드 설정
    if(head==NULL){
        head = temp;
    }
    //헤드가 있다면
    else{
        // 헤드부터 시작하여 NULL을 가리키는 노드 탐색
        ptr = head;
        while(ptr->next!=NULL){
            // 노드 이동하며 주소 변경
            ptr = ptr->next;
        }
        // NULL가리키는 노드 만나면 해당 노드의 next 노드를
        // 새로 할당한 노드로 설정
        ptr->next= temp;
    }
}


void insert()
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    
    if(temp==NULL){
        printf("Out Of Memory");
        exit(0);
    }

    printf("\nEnter data :");
    scanf("%d", &temp->value);
    temp->next = NULL;

    if(head==NULL){
        head = temp;
        return;
    }
    else{
        temp->next = head;
        head = temp;
    }
}


void insert_pos()
{
    struct node *ptr;
    struct node *temp;

    int i, pos;
    temp = (struct node*)malloc(sizeof(struct node));

      if(temp==NULL){
        printf("Out Of Memory");
        exit(0);
    }

    //넣을 위치 입력
    printf("\nEnter position to insert :");
    scanf("%d", &pos);
    //노드에 담을 데이터 입력
    printf("\nEnter data :");
    scanf("%d", &temp->value);
    temp->next = NULL;


    
    if(head==NULL){
        head = temp;
        return;
    }else if(pos==0){
        temp->next = head;
        head = temp;
    }else{
        for(i=0 , ptr=head; i<pos-1; i++){
            ptr = ptr->next;
            if(ptr->next==NULL){
                printf("Cannot insert at %d\n",pos);
                return;
            }
        }
        // 로직상 타겟 노드의 뒤에 넣는 방식
        // - 새로운 노드가 가리키는 주소는 타겟 노드의 다음 주소
        temp->next = ptr->next;
        // - 타겟 노드의 다음 주소를 새로운 노드를 가리키게 함으로서 insert pos 끝
        ptr->next = temp;
    }
}

void display()
{
    struct node*ptr = head;
    if(ptr == NULL){
        printf("List is empty!\n");
        return;
    }
    else{
        printf("List : ");
        while(ptr != NULL){
            printf("%d -> ", ptr->value);
            ptr = ptr->next;
        }
        printf("\n");
    }
}



