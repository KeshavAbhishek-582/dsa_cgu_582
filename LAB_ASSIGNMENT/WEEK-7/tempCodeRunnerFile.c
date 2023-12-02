#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char month[15];
    struct Node *left;
    struct Node *right;
    int height;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct Node *node) {
    if (node == NULL)
        return 0;
    return node->height;
}

struct Node *newNode(char *month) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    strcpy(node->month, month);
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

struct Node *rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct Node *leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(struct Node *node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

struct Node *insert(struct Node *node, char *month) {
    if (node == NULL)
        return newNode(month);

    if (strcmp(month, node->month) < 0)
        node->left = insert(node->left, month);
    else if (strcmp(month, node->month) > 0)
        node->right = insert(node->right, month);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && strcmp(month, node->left->month) < 0)
        return rightRotate(node);

    if (balance < -1 && strcmp(month, node->right->month) > 0)
        return leftRotate(node);

    if (balance > 1 && strcmp(month, node->left->month) > 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && strcmp(month, node->right->month) < 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

struct Node *minValueNode(struct Node *node) {
    struct Node *current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

struct Node *deleteNode(struct Node *root, char *month) {
    if (root == NULL)
        return root;

    if (strcmp(month, root->month) < 0)
        root->left = deleteNode(root->left, month);

    else if (strcmp(month, root->month) > 0)
        root->right = deleteNode(root->right, month);

    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            struct Node *temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;

            free(temp);
        } else {
            struct Node *temp = minValueNode(root->right);

            strcpy(root->month, temp->month);

            root->right = deleteNode(root->right, temp->month);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%s ", root->month);
        inorder(root->right);
    }
}

int main() {
    struct Node *root = NULL;

    root = insert(root, "January");
    root = insert(root, "February");
    root = insert(root, "March");
    root = insert(root, "April");
    root = insert(root, "May");
    root = insert(root, "June");
    root = insert(root, "July");
    root = insert(root, "August");
    root = insert(root, "September");
    root = insert(root, "October");
    root = insert(root, "November");
    root = insert(root, "December");

    printf("Inorder traversal of the AVL tree is: ");
    inorder(root);

    root = deleteNode(root, "March");
    root = deleteNode(root, "May");

    printf("\nInorder traversal of the AVL tree after deleting March and May is:\n ");
    inorder(root);

    return 0;
}