//Creating binary search tree

#include<bits/stdc++.h>
using namespace std;

class Node 
{
 public:
 Node *lchild;
 int data;
 Node *rchild;
};

class BST{
public:

 Node *root;
 BST(){root=NULL;}
 void Create(); 
 void Inorder(Node *temp);
 void Search(Node *p,int key);
};

void BST::Create()
{     Node *q=NULL;
      Node *p=root;
      Node *t;
      int key; char c;
    cout<<"enter the key value: ";
      cin>>key;

    if(root==NULL)
   {
       t=new Node;
       t->data=key;
       t->lchlid=t->rchild=NULL;
       root=t;
   }
   
    do{
        q=NULL;
        int f=0;
        p=root;
        cout<<"enter the key value: ";
        cin>>key;
      while(p!=NULL)
        {   q=p;
            if(p->data > key)
               p=p->lchlid;
            else if(p->data<key)
             p=p->rchild;     
             else 
            {f=1; break;}
        }
   if(!f){      t=new Node;
            t->rchild=t->lchlid=NULL;
            t->data=key;
        if(q->data>key) 
          q->lchlid=t;
            else  
            q->rchild=t;
   }
        cout<<"do you want to continue (y/n): ";
        cin>>c;    
    }while(c=='Y'||c=='y');
    
}

void BST::Inorder(Node *temp)
{   
    // cout<<1<<endl;
    if(temp!=NULL){
         Inorder(temp->lchlid);
         cout<<temp->data<<" ";
         Inorder(temp->rchild);
    }
    return;
}

void Search(Node *p,int key)
{
  if(p->data >key)
    p=p->lchild;
  else if(p->data < key)
   p=p->rchild;
  else if(p->data==key)
 {cout<<"\nx--- key found ---x";return;}
  if(p==NULL)
   {cout<<"key not found "; return;}
  
}

int main()
{
     BST t;
     t.Create();

   // cout<<"Inorder traversal: "<<
   t.Inorder(t.root);
   t.Search(t.root ,20);
    
    return 0;    
}