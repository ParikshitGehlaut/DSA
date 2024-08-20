#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
    
};

struct node* createnode(int data){
    struct node* n;
    n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
}

void preorder(struct node* root){
    if(root != NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

void inorder(struct node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);   
    }
}

int  isBST(struct node* root){
    static struct node *prev = NULL;
    if(root != NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev != NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
        
          
    }else{
        return 1;
    }
}


struct node* search(struct node* root,int key){
    if(root == NULL){
        return NULL;
    }
    if(root->data == key){
        return root;
    }
    if(root->data >= key){
        search(root->left,key);
    }else{
        search(root->right,key);
    }
}

void insert(struct node* root,int key){
    struct node* prev = NULL;
    while(root!= NULL){
        prev = root;
        if(key == root->data){
            printf("cannot insert %d, already in tree\n",key);
            return;
        }
        else if(key< root->data){
            root = root->left;
        }else{
            root = root->right;
        }
    }
    struct node* new = createnode(key);
    if(key<prev->data){
        prev->left = new;
    }else{
        prev->right = new;
    }


}


int main(){
// Constructing the root node - Using Function (Recommended
    struct node* p = createnode(9);
    struct node* p2 = createnode(4);
    struct node* p3 = createnode(11);
    struct node* p4 = createnode(2);
    struct node* p5 = createnode(7);


// linking th nodes 
    p->left = p2;
    p->right = p3;
    p2->left = p4;
    p2->right = p5;
    
    // printf("Preorder Transversal:");
    // preorder(p);
    // printf("\n");
    
    // printf("Postorder Transversal:");
    // postorder(p);
    // printf("\n");

    printf("Inorder Transversal:");
    inorder(p);
    printf("\n");

    // if(isBST(p)){
    //     printf("Given tree is BST\n");
    // }
  
    return 0;
}