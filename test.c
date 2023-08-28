#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct link
{
    int info;
    struct link *next;
};

void create(struct link *node);
void display(struct link *node);

int main(){

    struct link *node;
    node = (struct link*)malloc(sizeof(struct link));
    if(node==NULL){
        printf("\nMemory not allocated.");
        exit(0);
    }

    create(node);
    display(node);
    return 0;
}

void create(struct link *node){
    char opt;
    printf("\nEnter the value : ");
    scanf("%d", &node->info);
    node->next=NULL;
    printf("Any more node you want [Y/N] : ");
    opt = getche();printf("\n");

    while(opt=='Y' || opt=='y'){
        node = (struct link*)malloc(sizeof(struct link));
        if(node==NULL){
            printf("Memory not alloted.");
            exit(0);
        }
        else{
            node = node->next;
            printf("Enter the value : ");
            scanf("%d", &node->info);
            node->next = NULL;
        }
        printf("Any more node you want [Y/N] : ");
        opt = getche();
    }
}

void display(struct link *node){
    while(node==NULL){
        printf("%d\n", node->info);
        node = node->next;
    }
}