// this one has all functions of BST (final one)
#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
  Node *lchild;
  int data;
  Node *rchild;
};

class BST{
   public:
   Node *root;
    BST(){root=NULL;}  
    void insert_Node(int temp );
    Node* Rinsert(Node * t,int key);
    void preorde(Node *p);
    void inorder(Node *p);
    void postorder(Node *p);
    int Height(Node *p);
    void search(Node *p,int key);
    Node *InPredecessor(Node *p);
    Node *InSuccsesor(Node *p);
    Node *Delete(Node *p, int key);
    void Create_bst_from_pre(int pre[],int n);
   
};

void BST::insert_Node(int temp)
{  Node *t,*p=root,*r=NULL;
   if(root==NULL)
   {
      t=new Node;
      t->lchild=t->rchild=NULL;
      t->data=temp;
      root=t;
      return ;
   }
   while(p!=NULL)
   {    r=p;
       if(p->data > temp)
           p=p->lchild;
       else if(p->data<temp)
          p=p->rchild;
        else if(p->data==temp)
          return ;     
   }
    t=new Node;
    t->lchild=t->rchild=NULL;
    t->data=temp;
   if(r->data > temp)
      r->lchild=t;
    else
      r->rchild=t; 
     
}

Node* BST::Rinsert(Node *t,int key)
{
    if(t==NULL)
    {
        Node* p=new Node;
        p->lchild=p->rchild=NULL;
        p->data=key;
        return p; 
    }
    if(t->data > key)
     t->lchild=Rinsert(t->lchild,key);
    else if(t->data <key)
      t->rchild=Rinsert(t->rchild,key);
    else if(t->data==key)
         return t;
}

void BST::preorde(Node *p)
{
    if(p)
    {   cout<<p->data<<" ";
        preorde(p->lchild);
        preorde(p->rchild);
    }
}

void BST::inorder(Node *p){
    if(p){
        inorder(p->lchild);
        cout<<p->data<<" ";
        inorder(p->rchild);
    }
} 

void BST::postorder(Node *p){
    if(p){
        postorder(p->lchild);
        postorder(p->rchild);
        cout<<p->data<<" ";
    }
} 

int BST::Height(Node *p)
{   int x,y;
   if(p)
   {  
     x=Height(p->lchild);
     y=Height(p->rchild);
     if(x>y)
       return x+1;
     else
       return y+1;
   }
   return 0;
}

Node* BST::InPredecessor(Node *p)
{  //Inorder predeccessor for a particular point  
    while(p && p->rchild!=NULL)
      p=p->rchild;
      return p;
} 

Node* BST::InSuccsesor(Node *p){
  //Inorder successor for a particular point  
    while(p && p->lchild!=NULL)
      p=p->lchild;
      return p;
      
}

void BST::search(Node *p,int key)
{

  if(p==NULL)
   { cout<<"\n--element not found--";return;}

     else if(p->data > key)
       search(p->lchild,key);
      else if(p->data < key)
        search(p->rchild,key);
      else if(p->data==key)
      {cout<<"\n--element found--"; }
      return;
}

Node* BST::Delete(Node *p,int key)
{   Node *t;
    if(p==NULL)
      return NULL;
    if(p->lchild==NULL && p->rchild==NULL)
    {
      if(p==root)
        root=NULL;
        free(p);
      return NULL;
    }
    if(p->data > key)
      p->lchild=Delete(p->lchild,key);
    else if(p->data < key)
      p->rchild=Delete(p->rchild,key);
    else {

      if(Height(p->lchild) >Height(p->rchild) )
       {
         t=InPredecessor(p->lchild);
         p->data =t->data;
         t->lchild=Delete(p->lchild,t->data);
       }
       else{
         t=InSuccsesor(p->rchild);
         p->data =t->data;
         t->rchild=Delete(p->rchild,t->data); 
       }
    }
    return p;
}

void BST::Create_bst_from_pre(int pre[],int n){
    stack<Node *> stk;
    Node *p,*t;
    int i=0;
    
    root=new Node;
    root->data=pre[i++];
    root->lchild=root->rchild=NULL;
    p=root;
    
    while(i<n)
    {
      if(p->data > pre[i])
      { 
        t=new Node;
        t->data=pre[i++];
        t->lchild=t->rchild=NULL;
        p->lchild=t; 
        stk.push(p);
        p=t;
      }
      else{
       if(p->data < pre[i] && pre[i] < stk.top()->data)
       {
         t=new Node;
         t->data=pre[i++];
         t->lchild=t->rchild=NULL;
         p->rchild=t;
         p=t;
       }
       else
         {p=stk.top();
         stk.pop();}
      }
    }
} 

int main(){
   BST B;
   B.insert_Node(10);
   B.insert_Node(20);
   B.insert_Node(5);
   B.root= B.Rinsert(B.root,1);
   B.Rinsert(B.root,25);
   B.Rinsert(B.root,7);  
   B.Rinsert(B.root,15);

   cout<<"\npreorder traversal of BST:  ";
   B.preorde(B.root);

   cout<<"\ninorder traversal of BST:   ";
   B.inorder(B.root);

    cout<<"\npostorder traversal of BST: ";
    B.postorder(B.root);

    cout<<"\n\nHeight of BST: ";
    cout<<B.Height(B.root);
    cout<<"\n searching for element 25 in BST: ";
    B.search(B.root, 25);
    cout<<"\n searching for element 2 in BST: ";
    B.search(B.root, 2);

    cout<<"\n deleting element 25 from BST: ";
    B.Delete(B.root,25);
    cout<<"\ninorder traversal of BST after deletion:   ";
    B.inorder(B.root);

      cout<<"\n deleting element 10 from BST: ";
    B.Delete(B.root,10);
    cout<<"\ninorder traversal of BST after deletion:   ";
    B.inorder(B.root);
  
  //----------------creating a BST using traversal------------------

  // int pre[]={50,25,15,10,20,30,75,60,55,80};
  //  cout<<"/n----------------creating a BST using traversal------------------";
  //   B.Create_bst_from_pre(pre,10);


  //   cout<<"\npreorder traversal of BST :  ";
  //  B.preorde(B.root);

  //  cout<<"\ninorder traversal of BST:   ";
  //  B.inorder(B.root);

  //   cout<<"\npostorder traversal of BST: ";
  //   B.postorder(B.root);

    return 0;
}