#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Graph_Node {
    int data;
    struct Graph_Node* left;
    struct Graph_Node* right;
};

struct Graph_Node* root = NULL;

void insert(struct Graph_Node** root, int num) {
    struct Graph_Node* new_node = (struct Graph_Node*)malloc(sizeof(struct Graph_Node));
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->data = num;

    if (*root == NULL) {
        *root = new_node;
        return;
    }

    struct Graph_Node* current = *root;
    struct Graph_Node* parent = NULL;

    while (current != NULL) {
        parent = current;

        if (current->data > num)
            current = current->left;
        else
            current = current->right;
    }

    if (parent->data > num)
        parent->left = new_node;
    else
        parent->right = new_node;
}

void inorderTraversal(struct Graph_Node* node, FILE* fi) {
    if (node != NULL) {
        inorderTraversal(node->left, fi);
        fprintf(fi, "%d ", node->data);
        inorderTraversal(node->right, fi);
    }
}

void preorderTraversal(struct Graph_Node* node, FILE* fi) {
    if (node != NULL) {
        fprintf(fi, "%d ", node->data);
        preorderTraversal(node->left, fi);
        preorderTraversal(node->right, fi);
    }
}

void postorderTraversal(struct Graph_Node* node, FILE* fi) {
    if (node != NULL) {
        postorderTraversal(node->left, fi);
        postorderTraversal(node->right, fi);
        fprintf(fi, "%d ", node->data);
    }
}

struct Graph_Node* findMax(struct Graph_Node* root) {
    if (root == NULL)
        return NULL;

    while (root->right != NULL)
        root = root->right;

    return root;
}

struct Graph_Node* findMin(struct Graph_Node* root) {
    if (root == NULL)
        return NULL;

    while (root->left != NULL)
        root = root->left;

    return root;
}

struct Graph_Node* search(struct Graph_Node* root, int key) {
    while (root != NULL) {
        if (root->data == key)
            return root;
        else if (root->data > key)
            root = root->left;
        else
            root = root->right;
    }

    return NULL;
}

struct Graph_Node* findPredecessor(struct Graph_Node* root, int key) {
    struct Graph_Node* current = search(root, key);
    if (current == NULL)
        return NULL;

    if (current->left != NULL)
        return findMax(current->left);

    struct Graph_Node* predecessor = NULL;
    while (root != NULL) {
        if (root->data < current->data) {
            predecessor = root;
            root = root->right;
        } else if (root->data > current->data)
            root = root->left;
        else
            break;
    }

    return predecessor;
}

struct Graph_Node* findSuccessor(struct Graph_Node* root, int key) {
    struct Graph_Node* current = search(root, key);
    if (current == NULL)
        return NULL;

    if (current->right != NULL)
        return findMin(current->right);

    struct Graph_Node* successor = NULL;
    while (root != NULL) {
        if (root->data > current->data) {
            successor = root;
            root = root->left;
        } else if (root->data < current->data)
            root = root->right;
        else
            break;
    }

    return successor;
}

int main(int argc, char* argv[]) {
    FILE* fp = fopen(argv[1], "r");
    FILE* fi = fopen("output.txt", "w");

    if (fp == NULL) {
        printf("FILE NOT FOUND");
        exit(1);
    }

    int i;
    char arr[2000];

    while (fscanf(fp, "%s", arr) != EOF) {
        if (!strcmp(arr, "insert")) {
            fscanf(fp, "%d", &i);
            insert(&root, i);
            fprintf(fi, "%d inserted\n", i);
        } else if (!strcmp(arr, "preordertraversal")) {
            preorderTraversal(root, fi);
            fprintf(fi, "\n");
        } else if (!strcmp(arr, "inordertraversal")) {
            inorderTraversal(root, fi);
            fprintf(fi, "\n");
        } else if (!strcmp(arr, "postordertraversal")) {
            postorderTraversal(root, fi);
            fprintf(fi, "\n");
        } else if (!strcmp(arr, "maxvalue")) {
            struct Graph_Node* maxNode = findMax(root);
            if (maxNode != NULL)
                fprintf(fi, "max value in BST is: %d\n", maxNode->data);
            else
                fprintf(fi, "The tree is empty.\n");
        } else if (!strcmp(arr, "minvalue")) {
            struct Graph_Node* minNode = findMin(root);
            if (minNode != NULL)
                fprintf(fi, "min value in BST is: %d\n", minNode->data);
            else
                fprintf(fi, "The tree is empty.\n");
        } else if (!strcmp(arr, "search")) {
            fscanf(fp, "%d", &i);
            struct Graph_Node* result = search(root, i);
            if (result != NULL)
                fprintf(fi, "%d found\n", result->data);
            else
                fprintf(fi, "Element not found\n");
        } else if (!strcmp(arr, "pred")) {
            fscanf(fp, "%d", &i);
            struct Graph_Node* predecessor = findPredecessor(root, i);
            if (predecessor != NULL)
                fprintf(fi, "predecessor: %d\n", predecessor->data);
            else
                fprintf(fi, "There is no predecessor\n");
        } else if (!strcmp(arr, "succ")) {
            fscanf(fp, "%d", &i);
            struct Graph_Node* successor = findSuccessor(root, i);
            if (successor != NULL)
                fprintf(fi, "successor: %d\n", successor->data);
            else
                fprintf(fi, "There is no successor\n");
        }
    }

    fclose(fp);
    fclose(fi);
    return 0;
}
