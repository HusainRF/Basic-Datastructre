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
void search_in_list();

void main()
{
 create();   //function calling
 create();
 create();
 treverse();
 search_in_list();
 
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

void search_in_list()
{    int searched_element,pos=1,flag=0;
    struct node *temp=first;
    printf("\nenter the value to searched in list\n");
    scanf("%d",&searched_element);
    while(temp!=NULL)
    {     
        
        if(temp->data==searched_element)
         {
             flag=1;
             break;
         }
    temp=temp->link;
        pos++;
    }    
 
 if (flag==1)
  printf("element found at position ::%d",pos);
else 
  printf("the element is not in list");
}


