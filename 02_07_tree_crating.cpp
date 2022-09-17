#include<bits/stdc++.h>
using namespace std;

struct Node {
   struct Node *lchild;
   int data;
   struct Node *rchild;
};

queue<struct Node*> Q;
struct Node *root;

void create(struct Node* root){
   int x;
   struct Node *p,*t;
   cout<<"Enetr root value: ";
   cin>>x;
   root=new Node;
   root->data=x;
   root->lchild=root->rchild=NULL;
   Q.push(root);
   while(!Q.empty())
   {
   	 p=Q.pop();
    cout<<"Enter the left child: ";
   }
}

int main()
{
   	

  return 0;
}