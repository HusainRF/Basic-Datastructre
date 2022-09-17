/*
program to create a linked list 
treversing linked list
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *first=NULL, *last=NULL;
int count=0;

void create();
void treverse();

void main()
{
 create();
 create();
 create();
 treverse();
}

void create()
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

void treverse()
{
    struct node *temp=first;
    while(temp!=NULL)
    {
    printf("%d---->",temp->data);
    temp=temp->link;
    }
}



