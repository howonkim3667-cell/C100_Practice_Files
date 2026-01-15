/* 정렬된 연결리스트
 * 모든 데이터가 정렬된 순서로 유지되는 리스트 만들기
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void insert_list();
void delete_list();
void display();

struct node {
    int value;
    struct node* next;
};


struct node* head = NULL;

int main(){
    int choice;

    while(1){
        printf("==================== MENU ==================\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("0.Exit\n");
        printf("--------------------------------------------\n");
        printf("Enter your choice");


        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert_list();
            display();
            break;
        case 2:
            delete_list();
            display();
            break;
        case 3:
            display();
            break;
        case 0:
            exit(0);
            break;
        }
    }
}



void display(){
    struct node* ptr= head;
    if(ptr == NULL){
        printf("List it empty!\n");
        return;
    }

    else{
        printf("Lise : ");
        while(ptr != NULL){
            printf("%d-> ", ptr->value);
            ptr = ptr->next;
        }
        printf("\n");
    }
}


void insert_list(){
    struct node* ptr;
    struct node* temp;

    int i;
    int value;

    temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL){
        printf("Out of Memory");
        return;
    }

    printf("Enter data : ");
    scanf("%d", &value);
    temp->value = value;
    temp->next  = NULL;

    if(head == NULL){
        head = temp;
    }
    else if(head->value > value){
        temp->next = head;
        head = temp;
    }else{
        for(ptr=head; ptr->next; ptr = ptr->next){
            if(ptr->next->value > value){
                temp->next = ptr->next;
                ptr->next = temp;
                return;
            }
        }
        ptr->next = temp;
    }
    
}

void delete_list(){
    int data;
    struct node* ptr = head;
    struct node* tmp;

    if(head == NULL){
        printf("Empty List. Return without deleting!\n");
        return;
    }
    printf("Enter data to delete:");
    scanf("%d", data);

    if(head->value == data){
        head = head->next;
        free(ptr);
        return;
    }

    for(ptr = head; ptr->next; ptr =ptr->next){
        if(ptr->next->value == data){
            tmp = ptr->next;
            ptr->next = ptr->next->next;
            printf("%d deleted!\n", tmp->value);
            free(tmp);
            return;
        }
    }
    printf("Data not found!\n");
}