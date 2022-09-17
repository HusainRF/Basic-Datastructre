/*
     Performs common Traversals on a Binary Tree
     1:preorder
     2:postorder
     3:inorder
*/
 
#include <stdio.h>
#include <stdlib.h>
 

enum Traversal {PREORDER, INORDER, POSTORDER};
 
typedef enum Traversal Traversal;
typedef struct Node Node;
 

struct Node {
    int value;
   
    Node* left, *right;
};
 
 
Node* init_tree(int data) {
 
    Node* root = (Node*) malloc (sizeof(Node));
    root->left = root->right = NULL;
    root->value = data;
    return root;
}
 
Node* create_node(int data) {
    
    Node* node = (Node*) malloc (sizeof(Node));
    node->value = data;
    node->left = node->right = NULL;
    return node;
}

void free_tree(Node* root) {
  
    Node* temp = root;
    if (!temp)
        return;
    free_tree(temp->left);
    free_tree(temp->right);
    if (!temp->left && !temp->right) {
        free(temp);
        return;
    }
}
 
 
void print_tree(Traversal traversal, Node* root) {
  
    if (!root)
        return;
    switch(traversal) {
        case (PREORDER):
           
            printf("%d -> ", root->value);
            print_tree(traversal, root->left);
            print_tree(traversal, root->right);
            break;
 
        case (INORDER):
          
            print_tree(traversal, root->left);
            printf("%d -> ", root->value);
            print_tree(traversal, root->right);
            break;
 
        case (POSTORDER):
            
            print_tree(traversal, root->left);
            print_tree(traversal, root->right);
            printf("%d -> ", root->value);
            break;
    }
}
 
int main() {
   
    Node* root = init_tree(10);

    root->left = create_node(20);
    root->right = create_node(30);
 
    root->left->left = create_node(40);
    root->left->right = create_node(50);
 
    root->right->left = create_node(60);
    root->right->right = create_node(70);
 
    printf("----Preorder Traversal:----\n");
    print_tree(PREORDER, root);
    printf("\n\n");
 
    printf("----Inorder Traversal:----\n");
    print_tree(INORDER, root);
    printf("\n\n");
 
    printf("----Postorder Traversal:----\n");
    print_tree(POSTORDER, root);
    printf("\n\n");
 

    free_tree(root);
    return 0;
}