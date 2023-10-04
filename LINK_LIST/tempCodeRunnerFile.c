#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

void insertStart (struct Node **head, int data)
{
  struct Node *newNode = (struct Node *) malloc (sizeof (struct Node));
  newNode->data = data;

  // if its the first node being entered
  if (*head == NULL)
    {
      *head = newNode;
      (*head)->next = *head;
      return;
    }

  // if LL already as >=1 node
  struct Node *curr = *head;

  // traverse till last node in LL
  while (curr->next != *head)
    {
      curr = curr->next;
    }
  // assign LL's last node's next as this new node
  curr->next = newNode;

  // assign newNode's next as current head
  newNode->next = *head;

  // change head to this new node
  *head = newNode;
}

void display (struct Node *head)
{
  // if there are no node in LL
  if (head == NULL)
    return;

  struct Node *temp = head;

  //need to take care of circular structure of LL
  do
    {
      printf ("%d ", temp->data);
      temp = temp->next;

    }
  while (temp != head);
  printf ("\n");
}

int main ()
{

  struct Node *head = NULL;

  printf ("Linked List: ");
  insertStart (&head, 1);
  insertStart (&head, 2);
  insertStart (&head, 3);
  insertStart (&head, 4);
  insertStart (&head, 5);
  insertStart (&head, 50);
  display (head);

  return 0;
}