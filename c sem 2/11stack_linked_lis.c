/*   program to create a stack with using linked list
   inserting an element in begining of stack (push)
   delteing an element from begining of stack(pop)
   and traversing in stack (display) 
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *link;
};
struct node *top=NULL;  
int count=0,stack_size;   //count indicates the total elements in stack stack_size indicatesmax size of stack

void push();  //(function declaration) inserting a new element
void pop();    //deleting an element
void display();  //traversing the stack

int main()
{   char ch;        //ch for user choice 
    printf("enter the size of stack::");       
    scanf("%d",&stack_size); 
    do{
    push();
    printf("Do ypu want to enter more elements in stack ?..(y/n)::");
    scanf("%c",&ch);
    scanf("%c",&ch);
    }while(ch=='y'||ch=='Y');
   
   display();
    do
    {
        pop();
        printf("do you want to delete more elements in stack?...(y/n)::");
        scanf("%c",&ch);
        scanf("%c",&ch);
        display();
    }while(ch=='y'||ch=='Y');
   
}

void push()
{  int new_ele;      //for taking new element from user in stack
  struct node *new=(struct node *)malloc(sizeof(struct node));
    if (count==stack_size+1)    //condition for stack overflow
       printf("stack overflow\n");
    else 
    {
        count++; 
        printf("enter the element in stack::");
        scanf("%d",&new_ele);
        new->data=new_ele;
        if (top ==NULL)
        {  
             new ->link=NULL;
            top =new;
        }
        else
        {
         new->link=top;
         top=new;
        }    
    }    
}

void pop()
{
   if(count==0)
   printf("underflow stack\n");
   else
   {
       top=top->link; 
   }
   count--;
}

void display()
{
   struct  node *temp=top;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->link;
    }
}