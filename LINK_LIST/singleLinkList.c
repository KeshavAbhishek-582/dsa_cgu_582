#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data=7;
    head->next=second;

    second->data=11;
    second->next=third;

    third->data=66;
    third->next=NULL;

    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }

    return 0;
}