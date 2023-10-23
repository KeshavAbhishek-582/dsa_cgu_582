#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void INOT(struct TreeNode* root) {
    if (root != NULL) {
        INOT(root->left);
        printf("%d ", root->data);
        INOT(root->right);
    }
}

void preOT(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOT(root->left);
        preOT(root->right);
    }
}

void postOT(struct TreeNode* root) {
    if (root != NULL) {
        postOT(root->left);
        postOT(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct TreeNode* root = NULL;

    root = createNode(100);
    root->left=createNode(20);
    root->right=createNode(200);
    root->left->left=createNode(10);
    root->left->right=createNode(30);
    root->right->left=createNode(150);
    root->right->right=createNode(300);


    printf("In-order traversal sequence: ");
    INOT(root);
    printf("\n");

    printf("Pre-order traversal sequence: ");
    preOT(root);
    printf("\n");

    printf("Post-order traversal sequence: ");
    postOT(root);
    printf("\n");

    return 0;
}