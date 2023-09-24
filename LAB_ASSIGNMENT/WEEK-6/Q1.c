#include <stdio.h>
#include <stdlib.h>

// Define a structure for a doubly linked list node
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the list
void insertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// Function to insert a new node at a specific position
void insertAtPosition(struct Node **head, int data, int position)
{
    struct Node *newNode = createNode(data);
    if (position < 1)
    {
        printf("Invalid position!\n");
        return;
    }
    if (position == 1)
    {
        insertAtBeginning(head, data);
        return;
    }

    struct Node *current = *head;
    int currentPosition = 1;

    // while (current->next!=NULL)
    // {
    //     current = current->next;
    //     currentPosition++;
    // }

    if (current == NULL)
    {
        printf("Invalid position!\n");
        return;
    }

    newNode->prev = current;
    newNode->next = current->next;
    if (current->next != NULL)
    {
        current->next->prev = newNode;
    }
    current->next = newNode;
}

// Function to display the doubly linked list
void displayList(struct Node *head)
{
    struct Node *current = head;
    printf("\nNULL<-->");
    while (current != NULL)
    {
        printf("%d<-->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;

    insertAtBeginning(&head, 10);
    insertAtPosition(&head, 20, 2);
    insertAtPosition(&head, 30, 3);
    insertAtPosition(&head, 40, 4);
    insertAtPosition(&head, 50, 3);

    printf("Doubly Linked List after insertions: ");
    displayList(head);

    return 0;
}
