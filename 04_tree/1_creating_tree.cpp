#include<bits/stdc++.h>
#include "QueueCpp.h"
#include "StackCpp.h"
#include "stackforIpost.h"

using namespace std;

class Tree
{
   public:
   Node *root;
   Tree(){root=NULL;}
   void Create_tree();
   void Preorder_traversal(Node *p);
   void IPreorder_traversal(Node *p);//I stand for itrative l
   void Postorder_traversal(Node *p);
   void IPostorder_traversal(Node *p);
   void Inorder_traversal(Node *p);
   void IInorder_traversal(Node *p);
   void Levelorder_traversal(Node *p);
   int Height( Node *root);
   int count(Node *p);
   int InternalNodes(Node *root);
   int LeafNode(Node *root);
};

// creating a tree level by level
void Tree::Create_tree()
{
  Node *p,*t;
  Queue q(100);
  int x;

  cout<<"enter the value of root node: ";
  cin>>x;
  root=new Node;
  root->data=x;
  root->lchild=root->rchild=NULL;
  q.enqueue(root);

  while(!q.isEmpty())
  {
    p=q.dequeue();
    cout<<"eneter the left child of "<<p->data<<": ";
    cin>>x;
    if(x!=-1)
    {
        t=new Node;
        t->lchild=t->rchild=NULL;
        t->data=x;
        p->lchild=t;
        q.enqueue(t);
    }
    cout<<"eneter the right child of "<<p->data<<": ";
    cin>>x;
    if(x!=-1)
    {
        t=new Node;
        t->lchild=t->rchild=NULL;
        t->data=x;
        p->rchild=t;
        q.enqueue(t);
    }
  }
}

void Tree::Preorder_traversal(Node *temp)
{ //visit,left,right
    if(temp){
      cout<<temp->data<<" ";
       Preorder_traversal(temp->lchild);
       Preorder_traversal(temp->rchild); 
    }
}

void Tree::Postorder_traversal(Node *temp)
{   //left,right,visit
    if(temp){
    Postorder_traversal(temp->lchild);
    Postorder_traversal(temp->rchild);
    cout<<temp->data<<" ";
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

void Tree::Levelorder_traversal(Node *root)
{
 // traversing level by level (left to right)
    Queue q(100);
    
    cout<<root->data<<" ";
    q.enqueue(root);

    while(!q.isEmpty())
    {
     root=q.dequeue();
     if(root->lchild)
     {
         cout<<root->lchild<<" ";
         q.enqueue(root->lchild);
     }
     if(root->rchild)
      {
         cout<<root->rchild<<" ";
         q.enqueue(root->rchild);
      }
    }
}

void Tree::IPreorder_traversal(Node *p)
 {
    Stack<Node *> St(100);
    while( p!=NULL ||!St.isEmpty())
    {
     if(p!=NULL)
      {
     
        St.push(p);
        cout<<p->data<<" ";
        p=p->lchild;
      }
      else 
      {
        p=St.pop();
        p=p->rchild;
      }
    }  
 }

 void Tree::IInorder_traversal(Node *p)
 {
    Stack<Node *> St(100);
    while( p!=NULL ||!St.isEmpty())
    {
     if(p!=NULL)
      {
     
        St.push(p);
        p=p->lchild;
      }
      else 
      {
        p=St.pop();
        cout<<p->data<<" ";
        p=p->rchild;
      }
    }  
 }


  void Tree::IPostorder_traversal(Node *p)
 {  
     Node *q=p;    
     Stack<Node *> st(100);
     if(p==NULL)
     { cout<<"Tree is empty";return;}

     while(1)
     {
       while(p->lchild!=NULL)
       {
         st.push(p);
         p=p->lchild;
       }
       while(p->rchild==NULL || q==p->rchild)
       {
         cout<<p->data<<" ";
         q=p;
         if(st.isEmpty())
           return;
         p=st.pop();
       }       
      st.push(p);
      p=p->rchild;
     }
      
 } 

int Tree::Height(Node * root)
{
  int x,y;
    if(root)
    {
      x=Height(root->lchild);
      y=Height(root->rchild);
      if(x>y)
        return x+1;
      else 
        return y+1;
    }
   return 0;
}
//1st way for counting no. of nodes  
// int Tree::count(Node *root)
// {
//   int x,y;
//   if(root)
//   {
//      x=count(root->lchild);
//      y=count(root->rchild);
//       return x+y+1;
//   }
//   return 0;
// }

//2nd way for counting no. nodes both are same just slite change is done 
int Tree::count(Node *root)
{
  int x,y;
  if(root)
      return count(root->lchild)+ count(root->rchild)+1;
  return 0;
}

int Tree:: InternalNodes(Node *root){
   int x,y;
   if(root)
   {
     x=InternalNodes(root->lchild);
     y =InternalNodes( root->rchild);
    if(root->rchild &&root->lchild)
       return x+y+1;
    else
      return x+y;
  }
  return 0;
}

int Tree::LeafNode(Node *root)
{
    return InternalNodes(root)+1;
}

int main()
{   
     Tree t;
     t.Create_tree(); 

     cout<<"\nPreoder traversal(Recurssive): ";
     t.Preorder_traversal(t.root);

     cout<<endl<<"Preoder traversal(iterative): ";
     t.IPreorder_traversal(t.root);
         
     cout<<"\ntotal nodes are: "<<t.count(t.root);
     
     cout<<"\nno. of internal node(deg(2)) are: "<< t.InternalNodes(t.root);

     cout<<"\nno. of leaf/external node(deg(0)) are: "<< t.LeafNode(t.root);

     cout<<"\nHeight of tree: "<<t.Height(t.root);

     cout<<"\nInorder traversal: ";
     t.Inorder_traversal(t.root);

     cout<<"\nInorder traversal: ";
     t.IInorder_traversal(t.root);
    
     cout<<"\nPostoder traversal(recursive): ";
     t.Postorder_traversal(t.root);
  
     cout<<"\nPostoder traversal(iterative): ";
    t.IPostorder_traversal(t.root);

    cout<<"\nLeveloder traversal: ";
    t.Levelorder_traversal(t.root);
    
    cout<<"\nHeight of tree: "<<t.Height(t.root)<<endl;
    
    return 0;
}