#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *right;
    struct node *left;
}node;
struct node root+NULL;

struct node *create()
{
    struct node *new=(struct node *)malloc(sizeof(struct node));
    printf("enter the data");
    scnaf("%d",&new->data);
    new->left=NULL;
    new->right=NULL;
return new;
}

struct node *insert(struct node *root,struct node* temp)
{
if(temp->data<root->data)
 { if(root->left!=NULL)
      insert(root->left,temp)
    else 
    root->left=temp;
 }
  
else if(root->data<temp->data)
   {
       if(root->right!=NULL)
       insert(root->right,temp)
       else 
       root->right=temp;  
   }
}

void preorder();

int main()
{
    do {
        
    }
}