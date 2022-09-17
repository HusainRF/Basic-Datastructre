#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
  Node *rchild;
  int data;
  Node *lchild;
};

class Tree{
 public:
  Node *root;
  Tree(){root=NULL;}
  void CreateTree();  
  void Preorder(Node *temp);
  void IPreoder(Node *temp);
  void Inorder_traversal(Node *temp);
  void IInorder_traversal(Node *t);
  void Postorder(Node *temp); 
  void IPostorder(Node *p);
  int count(Node *t);
  int Height(Node *t);
  int NoLeafNode(Node *temp);
  int EnternalNode(Node *temp);
 };
 
void Tree::CreateTree(){

  Node *t,*p;
  int x;
  cout<<"Enter the root Node: ";
  cin>>x;
  queue <Node *> Q;
  root=new Node;
  root->rchild = root->lchild = NULL;
  root->data=x;
  Q.push(root);
  while(!Q.empty())
  {   p=Q.front();
       Q.pop();
     cout<<"enter the left child of "<<p->data<<" ";
     cin>>x;
     if(x!=-1)
     {
        t=new Node;
        t->rchild =t->lchild=NULL;
        t->data=x;
        p->lchild=t;
        Q.push(t);
     }
     cout<<"enter the right child of "<<p->data<<" ";
     cin>>x;
     if(x!=-1)
     {
         t=new Node;
          t->rchild=t->lchild=NULL;
          t->data=x;
          p->rchild=t;
          Q.push(t);
     }
  }
 }

 void Tree::Preorder(Node *temp)
 {
  if(temp)
  {
    cout<<temp->data<<" ";
    Preorder(temp->lchild);
    Preorder(temp->rchild);
  }
 }

void Tree::IPreoder(Node *temp)
{
  stack<Node *> st;
   st.emplace(temp);
    while(!st.empty()||!temp)
    {
      if(temp!=NULL)
      {
         st.push(temp);
         cout<<temp->data<<" ";
         temp=temp->lchild;      
      }
      else
      {
        temp=st.top();
        st.pop();
        temp=temp->rchild;
      }
    }
}

void Tree::Inorder_traversal(Node *temp)
{   //left,visit,right
    if(temp){
         Inorder_traversal(temp->lchild);
         cout<<temp->data<<" ";
         Inorder_traversal(temp->rchild);
    }
}

void Tree::IInorder_traversal(Node* t){
  stack<Node *> st;
  while(!st.empty() || t!=NULL)
   { 
     if(t!=NULL)
     {
       st.push(t);
       t=t->lchild;
     }
     else 
     {
       t=st.top();
       st.pop();
       cout<<t->data<<" ";
       t=t->rchild;
     }
   }  
}

void Tree::Postorder(Node *temp){
 if(temp)
 {
   Postorder(temp->lchild);
   Postorder(temp->rchild);
   cout<<temp->data<<" ";
 }

}

void Tree::IPostorder(Node *p){
  stack<Node *> st;
  Node *q=p; 
  while(1)
  {   while(p->lchild!=NULL)
    {
        st.push(p);
        p=p->lchild;
    }
    
    while(p->rchild==NULL|| p->rchild==q)
    { 
        cout<<p->data<<" ";
        q=p;
        if(st.empty())
        return;
        p=st.top();
        st.pop();
    }
      st.push(p); 
      p=p->rchild;      
  }
}

int Tree::count(Node *t)
{  int x,y;
   if(t)
   {
     x=count(t->lchild);
     y=count(t->rchild);
     return x+y+1;
   }
   return 0;
}

int Tree::Height(Node *t)
{  int x,y;
  if (t){
     x=Height(t->lchild);
     y=Height(t->rchild);
     if(x>y)
     return x+1;
     else 
       return y+1;
   }
   return 0;
}

int Tree::NoLeafNode(Node *temp)
int Tree::NoLeafNode(Node *temp)
{  int x,y;
  if(temp)
  {
    x=NoLeafNode(temp->lchild);
    y=NoLeafNode(temp->rchild);
    if(x==0 &&y==0)
     return x+y+1;
     else 
     return x+y;
  }
  return 0;

}

int Tree::EnternalNode(Node *temp)
{ int x,y;
  if(temp)
  {
   x=EnternalNode(temp->lchild);
   y=EnternalNode(temp->rchild);
   if(temp->lchild && temp->rchild)
     return x+y+1;
     else return x+y;
  }
  else 
  return 0;
}

int main()
{
  Tree t ;

  t.CreateTree();
  
  cout<<"\n\nPreoder Traversal(Recrussive):  ";
  t.Preorder(t.root);
  cout<<"\nPreoder Traversal(Iterative):     ";
  t.IPreoder(t.root);

  cout<<"\n\nInoder Traversal(Recrussive):   ";
  t.Inorder_traversal(t.root);
  cout<<"\nInoder Traversal(Iterative):      ";
  t.IInorder_traversal(t.root);

 cout<<"\n\nPostorder Traversal(Recrussive): ";
  t.Postorder(t.root);
 cout<<"\nPostorder Traversal(Iterative):   ";
 t.IPostorder(t.root);

  cout<<"\n\nNo. of nodes in Tree:      "<<t.count(t.root);

  cout<<"\nmaximum height  of Tree:   "<<t.Height(t.root);

  cout<<"\nNo. of Leaf nodes in Tree: "<<t.NoLeafNode(t.root);

  cout<<"\nNo. of nodes with deg(2) in Tree: "<<t.EnternalNode(t.root);

  
  return 0;
}