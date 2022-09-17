/*
program to create a linked list 
treversing linked list
and inserting element in list (at begining,in between,at th end)
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *first=NULL, *last=NULL;
int count=1;

void create();    //function declaration
void treverse();
void insert();

void main()
{
 create();   //function calling
 create();
 create();
 treverse();
 insert();
 treverse();
}
//function defination 
void create() // creates a new node
{
 struct node *new;
 new=(struct node *)malloc(sizeof(struct node));
 printf("enter the data \n"); 
 scanf("%d",&new->data);
 new->link=NULL;
 if(first==NULL)
    first = new;
 else 
 last->link=new;
 last =new;
 count++;
}

void treverse()   //treversing linked list
{
    struct node *temp=first; //temproray pointer for trevering
    while(temp!=NULL)
    {
    printf("%d---->",temp->data);
    temp=temp->link;
    }
}

void insert() 
{
    int choice,position,c=1;                  //c is used for itration in while
    struct node *new=(struct node *)malloc(sizeof(struct node));
    struct node *curr=first,*prev=NULL;   // here curr is reprensting the current node and prev indicates the previous node

    printf("\nenter where do you  want enter the element in lisked list\n");
    printf("1: at begning \n2: in between \n3: at end\n");
    scanf("%d",&choice);

    printf("enter the data :");
    scanf("%d",& new->data);
    new->link=NULL;
    switch(choice)
    {
        case 1:
         new->link =first;
         first =new;
        break;
        case 3: 
         last->link=new;
         last=new;
        break;   
        case 2:
         printf("enter the position\n");
         scanf("%d",&position); 
         while((c<position)&&(curr!=NULL))
         {
             prev=curr;
             curr=curr->link;
             c++;
         }
         new->link=curr;
         prev->link=new;
        break;
        default :printf("you enter the wrong choice");
    }
}


