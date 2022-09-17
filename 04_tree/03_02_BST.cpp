#include<bits/stdc++.h>
using namespace std;

class Node
{
  public:
  Node* lchild;
   int data;
  Node* rchild;
} *root;


class BST{
  public:
  Node* root;
 void Insert(int key);
 void Inorder(Node *p);
};

void BST::Insert(int key)
{
  Node* t=root;
  Node* r=NULL,*p;
 if(root==NULL)
  {
    p=new Node;
    p->data = key;
    p->lchild=p->rchild=NULL;
    root=p;
    return;
  }

  while(t!=NULL)
  {
    r=t;
    if(key<t->data)
    t=t->lchild;
    else if(key>t->data)
    t=t->rchild;
    else
      return;
  }
  p=new Node;
  p->data=key;
  p->lchild=p->rchild=NULL;

   if(key<r->data) r->lchild=p;
    else r->rchild=p;
}

void BST::Inorder( Node *p)
{
   if(p)
   {
    Inorder(p->lchild);
    printf("%d ",p->data);
    Inorder(p->rchild);
   }
 }

 Node * Search(int key)
{
   Node *t=root;
   while(t!=NULL)
   {
    if(key==t->data)
       return t;
    else if(key<t->data)
      t=t->lchild; 
    else
     t=t->rchild;
  }
  return NULL;
 }

int main()
{
 Node *temp;
 BST t;
t.root=Insert(t.root,50);
t.Insert(t.root,10);
t.Insert(root,40);

t.Insert(root,20);
t.Insert(root,30);
t.Delete(root,30);
t.Inorder(root);
printf("\n");
temp=t.Search(20);

if(temp!=NULL)
  printf("element %d is found\n",temp->data);
else
   printf("element is not found\n");
return 0;
}