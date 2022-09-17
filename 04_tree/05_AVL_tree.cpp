#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
  Node *lchild;
  int data;
  int height;
  Node *rchild;
};

class AVLTree{
   public:
   Node *root;
   AVLTree(){root=NULL;}
   int NodeHeight(Node *p);
   int BalanceFactor(Node *p );
   Node *LLRotation(Node *p);
   Node *LRRotation(Node *p);
   Node *RRRotation(Node *p);
   Node *RLRotation(Node *p);
   Node *RInsert(Node *p, int key); 
   void RPreorder(Node *p);
   void RInorder(Node *p);
   void RPostorder(Node *p);
};

int AVLTree::NodeHeight(Node *p)
{
   int hl,hr;  //height of left and right sub-tree respectively
   hl=p &&p->lchild ? p->lchild->height:0;
   hr=p &&p->rchild ? p->rchild->height:0;
   return hl>hr ? hl+1 : hr+1;
}

int AVLTree::BalanceFactor(Node *p)
{
    int hl,hr;
    hl=p &&p->lchild?p->lchild->height:0;
    hr=p &&p->rchild?p->rchild->height:0;
    return hl-hr;
}

Node *AVLTree::LLRotation(Node *p)
{  
    Node *pl=p->lchild;
    Node *plr=pl->rchild;
    
    p->lchild=plr;
    pl->rchild=p;

    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);
    if(root==p)
     root=pl;

  return pl;

}

Node *AVLTree::LRRotation(Node *p)
{ 
   Node *pl=p->lchild;
   Node *plr=pl->rchild; 

   pl->rchild=plr->lchild;
   p->lchild=plr->lchild;

   plr->lchild=pl;
   plr->rchild=p;

   pl->height=NodeHeight(pl);
   p->height=NodeHeight(p);
   plr->height=NodeHeight(plr);
    
    if(root==p)
    root=plr;
    
  return plr;  
}

Node *AVLTree::RRRotation(Node *p)
{
    Node *pr=p->rchild;
    Node *prl=pr->lchild;

     p->rchild=prl;
     pr->lchild=p;

    p->height=NodeHeight(p);
    pr->height=NodeHeight(pr);
    if(root==p)
     root=pr;

  return pr;
}

Node *AVLTree::RLRotation(Node *p)
{
   Node *pr=p->rchild;
   Node *prl=pr->lchild; 

   pr->lchild=prl->rchild;
   p->rchild=prl->rchild;

   prl->rchild=pr;
   prl->lchild=p;

   pr->height=NodeHeight(pr);
   p->height=NodeHeight(p);
   prl->height=NodeHeight(prl);
    
    if(root==p)
    root=prl;
    
  return prl;
}

Node* AVLTree::RInsert(Node *p, int key)
{
  Node *t=NULL;
  if(p==NULL)
  {
      t=new Node;
      t->data=key;
      t->height=1;
      t->lchild =t->rchild=NULL;
      return t;
  }
  if(key < p->data)
    p->lchild=RInsert(p->lchild,key);
  else if(key> p->data) 
    p->rchild=RInsert(p->rchild,key);

    p->height=NodeHeight(p);

    if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1)
     return LLRotation(p);
    else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)
     return LRRotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1)
     return RRRotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1)
     return RLRotation(p);
  
     
    return p;
}

void AVLTree::RPreorder(Node *p)
{  
    if(p)
    {
       cout<<p->data<<" ";
       RPreorder(p->lchild);
       RPreorder(p->rchild);
    }
}

void AVLTree::RInorder(Node *p)
{  
    if(p)
    {
       RInorder(p->lchild);
       cout<<p->data<<" ";
       RInorder(p->rchild);
    }
}

void AVLTree::RPostorder(Node *p){
    if(p)
    {
       RPostorder(p->lchild);
       RPostorder(p->rchild);
       cout<<p->data<<" ";
    }
}

int main()
{  
    AVLTree avl;
    avl.root=avl.RInsert(avl.root,10);
    avl.RInsert(avl.root,20);
    avl.RInsert(avl.root,15);
   
   cout<<"\n Preorder traversal:  ";
   avl.RPreorder(avl.root);
    cout<<"\n Inorder traversal:   ";
   avl.RInorder(avl.root);
    cout<<"\n Postorder traversal: ";
   avl.RPostorder(avl.root);

    return 0;
}