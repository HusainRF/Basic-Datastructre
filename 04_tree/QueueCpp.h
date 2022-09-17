/* header file for storing address of node in que */

#include<stdio.h>
#ifndef QueueCpp_h
#define QueueCpp_h

class Node {
  public:
   Node *lchild;
   int data ;
   Node *rchild;
};

 //this Que will work on the node of tree so: 
class Queue
{
  private:
   int front;
   int rear;
   int size;
   Node **Q;

  public:
   Queue(){front=rear=-1;size=10;Q=new Node*[size];}
   Queue(int size){front=rear=-1;this->size=size;Q=new Node*[this->size];}
   void enqueue(Node* x);
   Node* dequeue();
   int isEmpty(){return front==rear;}
   void Display();

};

void Queue::enqueue(Node* x)
 {
  if(rear==size-1)
  printf("Queue Full\n");
  else
  {
    rear++;
    Q[rear]=x;
  }
}

Node* Queue::dequeue()
 {
  Node* x=NULL;
  if(front==rear)
   printf("Queue is Empty\n");
   else
   {
     x=Q[front+1];
     front++;
    }
  return x;
 }
void Queue::Display()
{
    for(int i=front+1;i<=rear;i++)
    printf("%d ",Q[i]);
    printf("\n");
}




#endif /*QueueCpp_h  */