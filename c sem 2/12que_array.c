/*
to create a que usig arrays
inserting element in que (InQue)
deleting element from que(DelQue)
traversing the que 
*/
#include<stdio.h>

int Que[20];
int front=-1,rear=-1,size;

void InQue();
void DelQue();
void traverse();

void main()
{
    printf("enter the size of Que::");
    scanf("%d",&size);
    char ch;
  do{
    InQue();
    printf("do you want to enter more element in que?....(y/n):");
    scanf("%c",&ch);
    scanf("%ch",&ch);
   }while(ch=='y'||ch=='Y');
    traverse();
    printf("\n");
   do
   {
      DelQue();
      printf("do you want to delete more elements from que?...(y/n):");
      scanf("%c",&ch);
      scanf("%c",&ch);  
       traverse(); 
   } while (ch=='y'||ch=='Y');
   
   
}

void InQue()
{
    int new_ele;
    if(rear==size-1)
      printf("que overflow\n");
    else 
    {
       printf("enter element in que:: ");
       scanf("%d",&new_ele);
       if(rear==-1)
       {
           front=rear=0;
           Que[rear]=new_ele;
          rear++;
       }
       else
       {
          Que[rear]=new_ele;
          rear++;
       }
    }
}

void traverse()
{
    int i;
    for(i=front;i<rear;i++)
    {
        printf("%d\n",Que[i]);
    }
}

void DelQue()
{
    if(front==-1)
      printf("que under flow\n");
    else 
    {
        if(front==rear)
          front=rear=-1;
        else
        front++;
    }
}