// #include <stdio.h>
// #include <stdlib.h>
// #include <conio.h>

// int value;

// struct node
// {
//     int data;
//     struct node *next;
// };

// void addData(struct node *node){
//     node = node->next;
//     printf("\nEnter data : ");
//     scanf("%d", &value);
//     node->data=value;
//     node->next=NULL;
//     printf("Value added and node linked.\n");
// }

// int main()
// {
//     char opt;
//     struct node *node;
//     node = (struct node*)malloc(sizeof(struct node));
//     addData(node);
//     printf("\nWant to add another data [Y | N]: ");
//     opt = getche();

//     while(opt=='Y' || opt=='y'){
        
//         node = (struct node*)malloc(sizeof(struct node));
//         addData(node);
//         printf("\nWant to add another data [Y | N]: ");
//         opt=getche();
//     }

//     while (node!=NULL)
//     {
//         printf ("%d ", node->data);
//         node = node->next;
//     }
    
//     return 0;

// }

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int data;
    struct node *next;
};

void addData(struct node **head)
{
    int value;
    printf("\nEnter data : ");
    scanf("%d", &value);

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }

    printf("Value added and node linked.\n");
}

int main()
{
    char opt;
    struct node *head = NULL;

    do
    {
        addData(&head);
        printf("\nWant to add another data [Y | N]: ");
        scanf(" %c", &opt);
    } while (opt == 'Y' || opt == 'y');

    struct node *current = head;
    while (current != NULL)
    {
        printf("Data : %d\nCurrent Node Address : %p, Next Node Address : %p\n\n", current->data, current, current->next);
        current = current->next;
    }

    // Free memory
    while (head != NULL)
    {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}