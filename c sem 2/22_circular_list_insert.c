/**
 * C program to insert a new node in a Circular Linked List
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
}*head;




void create_List(int n);
void display_List();
void insert_At_Beginning(int data);
void insert_At_N(int data, int position);


int main()
{
    int n, data, choice=1;

    head = NULL;
    while(choice != 0)
    {
        
        printf("---circular linked list---\n");
        printf("1. Create List\n");
        printf("2. Display list\n");
        printf("3. Insert at beginning\n");
        printf("4. Insert at any position\n");
        printf("0. Exit\n");
        printf("Enter your choice : ");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter the total number of nodes in list: ");
                scanf("%d", &n);
                create_List(n);
                break;
            case 2:
                display_List();
                break;
            case 3:
                printf("Enter data to be inserted at beginning: ");
                scanf("%d", &data);
                insert_At_Beginning(data);
                break;
            case 4:
                printf("Enter node position: ");
                scanf("%d", &n);
                printf("Enter data you want to insert at %d position: ", n);
                scanf("%d", &data);
                insert_At_N(data, n);
                break;
            case 0:
                break;
            default:
                printf("you made wrong choice ...");
        }

        printf("\n\n");
    }

    return 0;
}



void create_List(int n)
{
    int i, data;
    struct node *prevNode, *newNode;

    if(n >= 1)
    {
        
        head = (struct node *)malloc(sizeof(struct node));

        printf("Enter data of 1 node: ");
        scanf("%d", &data);

        head->data = data;
        head->next = NULL;

        prevNode = head;

        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            printf("Enter data of %d node: ", i);
            scanf("%d", &data);

            newNode->data = data;
            newNode->next = NULL;

            prevNode->next = newNode;
            
            prevNode = newNode;
        }

        prevNode->next = head;

        printf("\nCIRCULAR LINKED LIST CREATED SUCCESSFULLY\n");
    }
}




void display_List()
{
    struct node *current;
    int n = 1;

    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        current = head;
        printf("DATA IN THE LIST:\n");

        do {
            printf("Data %d = %d\n", n, current->data);

            current = current->next;
            n++;
        }while(current != head);
    }
}




void insert_At_Beginning(int data)
{
    struct node *newNode, *current;

    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = head;

        
        current = head;
        while(current->next != head)
        {
            current = current->next;
        }
        current->next = newNode;

        
        head = newNode;

        printf("NODE INSERTED SUCCESSFULLY\n");
    }
}




void insert_At_N(int data, int position)
{
    struct node *newNode, *current;
    int i;

    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else if(position == 1)
    {
        insert_At_Beginning(data);
    }
    else
    {
        
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;

        
        current = head;
        for(i=2; i<=position-1; i++)
        {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;

        printf("NODE INSERTED SUCCESSFULLY.\n");
    }
}