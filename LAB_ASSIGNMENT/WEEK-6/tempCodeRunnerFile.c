#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* prev;
    int data;
    struct Node* next;
};

struct Node* insertAtEnd(struct Node* head) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    new_node->prev = NULL;
    printf("Enter Data: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;

    if (head == NULL) {
        return new_node;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
    new_node->prev = temp;

    return head;
}

void showLinkList(struct Node* ptr) {
    if (ptr == NULL) {
        printf("\n\nLinked list is Empty.");
    } else {
        printf("\nDouble-Link List contains: \nNULL");
        while (ptr != NULL) {
            printf("<->%d", ptr->data);
            ptr = ptr->next;
        }
        printf("<->NULL\n");
    }
}

struct Node* deleteNode(struct Node* head, int target) {
    struct Node* current = head;

    while (current != NULL) {
        if (current->data == target) {
            if (current->prev == NULL) {
                // If the target node is the head
                head = current->next;
                if (head != NULL) {
                    head->prev = NULL;
                }
                free(current);
                current = head;
            } else {
                struct Node* prevNode = current->prev;
                struct Node* nextNode = current->next;
                prevNode->next = nextNode;
                if (nextNode != NULL) {
                    nextNode->prev = prevNode;
                }
                struct Node* temp = current;
                current = current->next;
                free(temp);
            }
        } else {
            current = current->next;
        }
    }

    return head;
}

int main() {
    struct Node* head = NULL;

    for (int i = 0; i < 6; i++) {
        head = insertAtEnd(head);
    }

    int target;
    printf("Enter the target value to delete: ");
    scanf("%d", &target);

    head = deleteNode(head, target);
    showLinkList(head);

    // Free the memory allocated for the linked list nodes
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
