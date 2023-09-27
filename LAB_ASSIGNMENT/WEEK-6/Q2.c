#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *insertAtEnd(struct Node *head)
{
    struct Node *new;
    new = (struct Node *)malloc(sizeof(struct Node));
    new->prev = NULL;
    printf("Enter Data : ");
    scanf("%d", &new->data);
    new->next = NULL;

    if (head == NULL)
    {
        return new;
    }

    struct Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new;
    new->prev = temp;

    return head;
}

void showLinkList(struct Node *ptr)
{
    if (ptr == NULL)
    {
        printf("\n\nLinked list is Empty.");
    }
    else
    {
        printf("\nDouble-Link List contains : \nNULL");
        while (ptr != NULL)
        {
            printf("<->%d", ptr->data);
            ptr = ptr->next;
        }
        printf("<->NULL");
    }
}

struct Node *delete(struct Node *head)
{
    struct Node *temp = head;
    
    while (temp != NULL)
    {
        if (temp->data == 30)
        {
            if (temp->prev == NULL)
            {
                head = temp->next;
                if (head != NULL)
                {
                    head->prev = NULL;
                }
                free(temp);
                temp = head;
                // return head;
            }

            else
            {
                struct Node *prevNode = temp->prev;
                struct Node *nextNode = temp->next;
                prevNode->next = nextNode;
                if (nextNode != NULL)
                {
                    nextNode->prev = prevNode;
                }
                temp = temp->next;
            }
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}

int main()
{
    struct Node *head = NULL;

    for (int i = 0; i < 6; i++)
    {
        head = insertAtEnd(head);
    }

    head = delete(head);
    showLinkList(head);

    return 0;
}