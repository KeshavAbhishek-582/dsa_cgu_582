#include <stdio.h>
// #include <stdlib.h>
struct Node
{
    int data;
    struct Node *pre;
    struct Node *next;
};

void showDLL(struct Node *ptr)
{
    printf("\nNULL <-> ");
    while (ptr != NULL)
    {
        printf("%d <-> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
struct Node *insertatend(struct Node *head)
{
    struct Node *temp = head;

    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter value : ");
    scanf("%d", &new->data);
    new->next = NULL;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new;
    new->pre = temp;
    return head;
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->pre = NULL;
    head->next = NULL;
    printf("Enter value : ");
    scanf("%d", &head->data);
    for (int i = 0; i < 4; i++)
    {
        head = insertatend(head);
    }
    showDLL(head);
    return 0;
}