/*
program to create a linked list 
treversing linked list
and deleting an element in list (at begining,in between,at th end)
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
void delete();

void main()
{
 create();   //function calling
 create();
 create();
 treverse();
 delete();
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

void delete() 
{
    int choice,position,c=1,ele_value;                  //c is used for itration in while
    struct node *curr=first,*prev=NULL;   // here curr is reprensting the current node and prev indicates the previous node

    printf("\nenter from where do you  want to delete  the element in lisked list\n");
    printf("1: at begning \n2: in between \n3: at end\n");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
         first =first->link;
        break;
        case 3: 
         while(c<count)
         {
             prev=curr;
             curr=curr->link;
            if(curr==last)
             { prev->link=NULL;
               last =prev;
             } 
             c++;
         }
        break;   
        case 2:
         printf("enter no. to delete from list \n");
         scanf("%d",&ele_value); 
         while((c<count)&&(curr!=NULL))
         {
             c++;
             if(curr->data==ele_value)
              {
                  prev=curr->link;
                  curr=NULL;
                  break;
              }
               prev=curr;
             curr=curr->link;             
         }
         
        break;
        default :printf("you enter the wrong choice");
            
    }
}


