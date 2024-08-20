#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
};
// Initializing root equals to NULL as a Global Variable
struct node *root = NULL;

// Function to perform preorder traversal
void preorder(struct node *new, FILE *out)
{
    if (new != NULL)
    {
        fprintf(out, "%d ", new->data);
        preorder(new->left, out);
        preorder(new->right, out);
    }
}

// Function to perform postorder traversal
void postorder(struct node *new, FILE *out)
{
    if (new != NULL)
    {
        postorder(new->left, out);
        postorder(new->right, out);
        fprintf(out, "%d ", new->data);
    }
}

// Function to perform inorder traversal
void inorder(struct node *new, FILE *out)
{
    if (new != NULL)
    {
        inorder(new->left, out);
        fprintf(out, "%d ", new->data);
        inorder(new->right, out);
    }
}

// Function to create a new node
struct node *createnode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// Function to find the minimum value in the tree
void minimum(FILE *out)
{
    if (root == NULL)
    {
        return;
    }
    struct node *current = root;
    struct node *temp;
    while (current != NULL)
    {
        temp = current;
        current = current->left;
    }
    fprintf(out, "%d", temp->data);
}

// Function to find the maximum value in the tree
void maximum(FILE *out)
{
    if (root == NULL)
    {
        return;
    }
    struct node *current = root;
    struct node *temp;
    while (current != NULL)
    {
        temp = current;
        current = current->right;
    }
    fprintf(out, "%d", temp->data);
}

// Function to check if a value exists in the tree
int Isintree(struct node *current, int val)
{
    if (current == NULL)
    {
        return 0;
    }
    if (current->data == val)
    {
        return 1;
    }
    if (current->data < val)
    {
        return Isintree(current->right, val);
    }
    else
    {
        return Isintree(current->left, val);
    }
}

// Function to find the maximum value in the tree, it is called in Successor function
int find_maximum()
{
    struct node *current = root;
    struct node *temp;
    while (current != NULL)
    {
        temp = current;
        current = current->right;
    }
    return temp->data;
}

// Function to find the successor of a value in the tree
void find_successor(FILE *out, int val)
{
    if (root == NULL)
    {
        fprintf(out, "Tree is empty\n");
        return;
    }
    if (!Isintree(root, val))
    {
        fprintf(out, "%d does not exist\n", val);
        return;
    }
    if (val == find_maximum())
    {
        fprintf(out, "Successor of %d does not exist\n", val);
        return;
    }

    struct node *temp = root;
    struct node *successor = NULL;

    while (temp != NULL)
    {
        if (temp->data > val)
        {
            successor = temp;
            temp = temp->left;
        }
        else if (temp->data < val)
        {
            temp = temp->right;
        }
        else
        {
            break;
        }
    }
    if (successor != NULL)
    {
        fprintf(out, "%d\n", successor->data);
    }
}

// Function to find the minimum value in the tree, it is called in predecessor function
int find_minimum()
{
    struct node *current = root;
    struct node *temp;
    while (current != NULL)
    {
        temp = current;
        current = current->left;
    }
    return temp->data;
}

// Function to find the predecessor of a value in the tree
void find_predecessor(FILE *out, int val)
{
    if (root == NULL)
    {
        fprintf(out, "Tree is empty\n");
        return;
    }
    if (val == find_minimum())
    {
        fprintf(out, "Predecessor of %d does not exist\n", val);
        return;
    }
    if (!Isintree(root, val))
    {
        fprintf(out, "%d does not exist\n", val);
        return;
    }

    struct node *temp = root;
    struct node *predecessor = NULL;

    while (temp != NULL)
    {
        if (temp->data < val)
        {
            predecessor = temp;
            temp = temp->right;
        }
        else if (temp->data > val)
        {
            temp = temp->left;
        }
        else
        {
            break;
        }
    }

    if (predecessor != NULL)
    {
        fprintf(out, "%d\n", predecessor->data);
    }
    else
    {
        fprintf(out, "Predecessor of %d does not exist\n", val);
    }
}

// Function to search for a value in the tree
void search(struct node *current, int val, FILE *out)
{
    if (current == NULL)
    {
        fprintf(out, "%d not found\n", val);
        return;
    }

    if (current->data == val)
    {
        fprintf(out, "%d found\n", val);
        return;
    }

    if (current->data < val)
    {
        search(current->right, val, out);
    }
    else
    {
        search(current->left, val, out);
    }
}

// Function to insert a node into the tree
void insertNode(int data, FILE *out)
{
    // When the tree is empty
    if (root == NULL)
    {
        root = createnode(data);
        fprintf(out, "%d inserted\n", data);
        return;
    }
    // When tree is not empty
    struct node *current = root;
    while (current != NULL)
    {
        if (current->data <= data)
        {
            if (current->right == NULL)
            {
                current->right = createnode(data);
                fprintf(out, "%d inserted\n", data);
                break;
            }
            else
            {
                current = current->right;
            }
        }
        else
        {
            if (current->left == NULL)
            {
                current->left = createnode(data);
                fprintf(out, "%d inserted\n", data);
                break;
            }
            else
            {
                current = current->left;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    FILE *in, *out;
    in = fopen(argv[1], "r");
    if (in == NULL)
    {
        fprintf(out, "Error in opening input file");
    }

    out = fopen("output.txt", "w");
    if (out == NULL)
    {
        fprintf(out, "Error in opening output file");
    }

    char command[100];
    int a;

    while (fscanf(in, "%s", command) != EOF)
    {
        if (strcmp(command, "insert") == 0)
        {
            fscanf(in, "%d", &a);
            insertNode(a, out);
        }
        else if (strcmp(command, "inorder") == 0)
        {
            inorder(root, out);
            fprintf(out, "\n");
        }
        else if (strcmp(command, "postorder") == 0)
        {
            postorder(root, out);
            fprintf(out, "\n");
        }
        else if (strcmp(command, "preorder") == 0)
        {
            preorder(root, out);
            fprintf(out, "\n");
        }
        else if (strcmp(command, "minimum") == 0)
        {
            minimum(out);
            fprintf(out, "\n");
        }
        else if (strcmp(command, "maximum") == 0)
        {
            maximum(out);
            fprintf(out, "\n");
        }
        else if (strcmp(command, "search") == 0)
        {
            fscanf(in, "%d", &a);
            search(root, a, out);
        }
        else if (strcmp(command, "successor") == 0)
        {
            fscanf(in, "%d", &a);
            find_successor(out, a);
        }
        else if (strcmp(command, "predecessor") == 0)
        {
            fscanf(in, "%d", &a);
            find_predecessor(out, a);
        }
    }

    fclose(in);
    fclose(out);
    return 0;
}
