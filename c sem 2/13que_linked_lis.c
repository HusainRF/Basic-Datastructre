/*
program to create a que using linked list
inserting an element in que(InQue)
deleting an element from (DelQue)
traversing through que
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};
struct node *front=NULL,*rear=NULL;
int count =1,Que_size;

void InQue();
void DelQue();
void traverse();

int main()
{ 
  char ch;
    printf("Enter the size of  Que::");
    scanf("%d",&Que_size);
   do{
    InQue();
    printf("do you want toenter more elements?....(y/n):");
    scanf("%c",&ch);
    scanf("%ch",&ch);
   }while(ch=='y'||ch=='Y');
  traverse();
   do
   {
      DelQue();
      printf("do you want to delete miore from que?...(y/n):");
      scanf("%c",&ch);
      scanf("%c",&ch);   
   } while (ch=='y'||ch=='Y');
    traverse();
}
void InQue()
{
    struct node *new=(struct node *)malloc(sizeof( struct node));
    if(count==Que_size)
      printf("que overflow \n");
    else
    {
        printf("Enter the value in Que::");
        scanf("%d",&new->data);
        new->link=NULL;
     if(front==NULL)
       front=new;
     else
       rear->link=new;
     rear=new;
     count++;  
    }
}

void traverse()
{  struct node *temp=front;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
       temp=temp->link;
    }
}

void DelQue()
{
 
  
    if(front ==rear)
     { front =rear =NULL;
      printf("que underflow\n");   
     }
     else
    {
    front=front->link;

    
    }
}