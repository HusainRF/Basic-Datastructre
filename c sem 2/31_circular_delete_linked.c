#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *last=NULL;
void create();
void insert();
void delete();
void traverse();
void main()
{
    create();
    create();
    create();
    insert();
    delete();
    traverse();
}
void create()
{
    struct node *new=(struct node *)malloc(sizeof(struct node));
    printf("enter a data");
    scanf("%d",&new->data);
    new->link=NULL;
    if(last==NULL)
    {
    last=new;
    last->link=new;
    }
    else
    {
    new->link=last->link;
    last->link=new;
    last=new;
    }
}
void traverse()
{
    struct node*temp;
    if(last==NULL)
    {
        printf("linked list is empty");
    }
    else
    {
        temp=last->link;
        while(temp->link!=last->link)
        {
        printf("%d--->",temp->data);
        temp=temp->link;
        }
    printf("%d",temp->data);
    }
}
void insert()
{
  int ch,pos,c=1;
  struct node *new,*temp;
  new=(struct node*)malloc(sizeof(struct node));
    printf("enter a data");
    scanf("%d",&new->data);
    new->link=NULL;
    printf("1.insert at beginning\n");
    printf("2.insert at last\n");
    printf("3.insert in between\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        new->link=last->link;
        last->link=new;
        break;
        case 2:
        new->link=last->link;
        last->link=new;
        last=new;
        break;
        case 3:
        printf("enter the position");
        scanf("%d",&pos);
        temp=last->link;
        while(c<pos-1)
        {
           temp=temp->link;
           c++;
        }
        new->link=temp->link;
        temp->link=new;
        break;
        default:
        printf("invalid position");
    }      
}
void delete()
{
    int ch,pos,c=1;
    struct node* temp;
    struct node*cur,*prev;
    printf("1.delete first node\n");
    printf("2.delete last node\n");
    printf("3.delete node based on position\n");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
    temp=last->link;
    last->link=temp->link;
    break;
    case 2:
    cur=last->link;
    while(cur->link!=last->link)
    {
      prev=cur;
      cur=cur->link;
    }
    prev->link=cur->link;
    last=prev;
    break;
    case 3:
    cur=last->link;
    printf("enter a position of node you have to delete\n");
    scanf("%d",&pos);
    while(c<pos-1)
        {
          cur=cur->link;
          c++;
        }
    prev=cur->link;
    cur->link=prev->link;
    break;
    default:
    printf("invalid choice");
    }
}