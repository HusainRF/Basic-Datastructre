#include<stdio.h>
#include<stdlib.h>

struct dnode
{
    int data;
    struct dnode *prev;
    struct dnode *next;
};
int count=0;
struct dnode *first=NULL,*last=NULL;
void dil_traverse();
void dil_creat();
void dil_insert();
void dil_delete();
void dil_search();

int main()
{char choice;
  printf("doubly linked list \n");
  dil_creat();
  dil_creat();
  dil_creat();
 dil_traverse();
 dil_insert();
 dil_traverse();

printf("do you want to delete an elemetn from list....(y/n)..");
scanf("%c",&choice);
scanf("%c",&choice);
switch(choice)
{
  case 'y': dil_delete();
           break;
  case 'n':printf("......program end.....");
         break;
  default:printf("you made wrong choice");
}
 dil_traverse();

}

void dil_creat()
{
    struct dnode *new=(struct dnode *)malloc(sizeof(struct dnode));
    printf("enter the new element\n");
    scanf("%d",&new->data);
    new->prev=NULL;
    new->next=NULL;
    if (first==NULL)
    first =new;
    else
    {
      last->next=new;
      new->prev=last;
    }
     last=new;
     last->next=NULL;
     first->prev=NULL;
     count++;
}

void dil_traverse()
{
struct dnode *temp=first;
if(first==NULL)
  printf("list is empty");
else
{     printf("elements are\n");
    while(temp!=NULL)
   {
       printf("%d\n",temp->data);
       temp=temp->next;
   }
}
}

void dil_insert()

{
  int choice,pos,c=0;
  struct dnode *new= (struct dnode*) malloc(sizeof(struct dnode));
  struct dnode *prev=NULL,*curr=first;
  printf("enter the data ::");
  scanf("%d",&new->data);
  new->next=new->prev=NULL;

  printf("where do you want to enter the element....\n1. at begning \n2.in between \n3.at the end...");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1: if(first==NULL)
          {
            first=new;
          }
          else 
          {
           new->next=first;
           first=new;
          }
          count++;
          break;
   case 3: if(first==NULL)
          {
            first=new;
          }
          else 
          {
           last->next=new;
           new->prev=last;
           last=new;
          }
          count++;
          break;
   case 2: printf("enter the position::");
          scanf("%d",&pos);
          if(pos==1)
          {
            new->next=first;
            first=new;
          }
          else if(pos=count+1)
          { 
            last->next=new;
            new->prev=last;
            last=new;
          }
         else if(pos>count)
         {
           printf("desired positon dose not exist\n");
         }
          else 
          {
            while(c<pos-1&&curr->next!=NULL)
           {
            prev=curr;
            curr=curr->next;
            c++;
           }
           curr->prev=new;
           new->next=curr;
           prev->next=new;
           new->prev=prev;
           }
          count++;
          break;
   default :printf("\nyou made a wrong choice");
         break;
  }
}

void dil_delete()
{ 
  int choice,pos,c=0;
  struct dnode *temp=NULL;
  struct dnode *curr=first;
printf("from where doyou want to delete an element \n1. at begning \n2. in between \n3. from end...::");
scanf("%d",&choice);
switch(choice)
{
  case 1: if (first==NULL){
          printf("\nlist is empty");
          } else
          {
           first=first->next;
           first->prev=NULL;
           count--;
          }
          break;
  case 2: printf("enter the position::");
          scanf("%d",pos);
          if(pos==1)
          {
            first=first->next;
            first->prev=NULL;
            count--;
          }
         else if(pos==count+1)
         {
           while(curr->next!=NULL)
           {
             temp=curr;
             curr=curr->next;
           }
           temp->next=NULL;
           free(curr); 
           count--;
         }
         else if(pos>count+1)
         {
           printf("\n you enter the wrong position \n");
         }
        else
        {
          while(curr->next!=NULL&&c<pos-1)
          {
            temp=curr;
            curr=curr->next;
          }
          temp->next=curr->next;
          curr=curr->next;
          curr->prev=temp;
          count--;    
          c++;   
          }
          break;
  case 3:if(first==NULL)
         printf("\nlist is empty");
         else
         {
           while(curr->next!=NULL)
           {
             temp=curr;
             curr=curr->next;
           }
         temp->next=NULL;
         free(curr);
         count--;
         }
         break;
  default :printf("you made a wrong choice");
         break;
}
}