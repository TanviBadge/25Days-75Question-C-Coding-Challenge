#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return createNode(data);
    
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) return root;
    
    if (key < root->data) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct Node* root = NULL;
    
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");
    
    struct Node* result = search(root, 40);
    if (result != NULL) {
        printf("Element 40 found in BST\n");
    } else {
        printf("Element 40 not found\n");
    }
    
    result = search(root, 100);
    if (result != NULL) {
        printf("Element 100 found in BST\n");
    } else {
        printf("Element 100 not found\n");
    }
    
    return 0;
}
