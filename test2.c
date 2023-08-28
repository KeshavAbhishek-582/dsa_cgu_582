#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct link {
    int data;
    struct link *next;
};

struct link *head = NULL;

void insert(int data) {
    struct link *new_link = (struct link *)malloc(sizeof(struct link));
    new_link->data = data;
    new_link->next = head;
    head = new_link;
}

void display() {
    struct link *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int data;
    printf("Enter data : ");
    scanf("%d", &data);
    insert(data);
    char opt;
    printf("Any more node you want to create [Y/N] : ");
    opt=getche();
    while(opt=='Y' || opt=='y'){
        printf("\nEnter data : ");
        scanf("%d", &data);
        
        insert(data);

        printf("Any more node you want to create [Y/N] : ");
        opt=getche();
    }

    printf("The linked list is: ");
    display();

    return 0;
}