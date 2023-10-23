#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a Binary Search Tree node
struct TreeNode {
    char day[10];
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(char* day) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    strcpy(newNode->day, day);
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a day into the Binary Search Tree
struct TreeNode* insert(struct TreeNode* root, char* day) {
    if (root == NULL) {
        return createNode(day);
    }

    int cmp = strcmp(day, root->day);

    if (cmp < 0) {
        root->left = insert(root->left, day);
    } else if (cmp > 0) {
        root->right = insert(root->right, day);
    }

    return root;
}

// Function to do an in-order traversal of the tree
void inOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%s\n", root->day);
        inOrderTraversal(root->right);
    }
}

int main() {
    // Days of the week in the specified order
    char* days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    
    struct TreeNode* root = NULL;

    // Insert the days into the BST
    for (int i = 0; i < 7; i++) {
        root = insert(root, days[i]);
    }

    printf("In-order traversal of the Binary Search Tree:\n");
    inOrderTraversal(root);

    // Free memory by deleting the tree (optional)
    // You can implement a function to delete the tree nodes recursively.

    return 0;
}