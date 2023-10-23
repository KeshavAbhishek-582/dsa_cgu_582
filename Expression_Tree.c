#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(char value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void INOT(struct TreeNode* root) {
    if (root != NULL) {
        INOT(root->left);
        printf("%c ", root->data);
        INOT(root->right);
    }
}

void preOT(struct TreeNode* root) {
    if (root != NULL) {
        printf("%c ", root->data);
        preOT(root->left);
        preOT(root->right);
    }
}

void postOT(struct TreeNode* root) {
    if (root != NULL) {
        postOT(root->left);
        postOT(root->right);
        printf("%c ", root->data);
    }
}

int main() {
    struct TreeNode* root = NULL;

    root=createNode('+');
    
    root->left=createNode('+');
    root->left->left=createNode('a');
    root->left->right=createNode('*');
    root->left->right->left=createNode('b');
    root->left->right->right=createNode('c');

    root->right=createNode('+');
    root->right->left=createNode('+');
    root->right->right=createNode('g');
    root->right->left->left=createNode('*');
    root->right->left->right=createNode('1');
    root->right->left->left->left=createNode('d');
    root->right->left->left->right=createNode('e');


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