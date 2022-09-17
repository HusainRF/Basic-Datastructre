/* to create a stack 
   insert elements in stack (push)
   delete elements from stack (pop)
   traverse stack (display)
*/
#include<stdio.h>
int stack[10],n=10,top=-1;  //stack is array with max size 10,n indicztes the max size,
                           //top isindicates the top most index of array "stack" 
void push();      //function declartion
void pop();
void display();
int main()
{  char ch;
  do
   {
    push();
    printf("do you want to insert more element in stack.... (y/n)");
    scanf("%c",&ch);
   scanf("%c",&ch);
   } while (ch=='y'||ch=='Y');

   display();
    
    do
    {
        pop(); 
        printf("do you want to delete more elements from stack....(y/n)");
        scanf("%c",&ch);
        scanf("%c",&ch);
        display();
    } while (ch=='y'||ch=='Y');

   
}

void push()   //function defination
{
    int new_ele;                                   //to store value of new element in stack
    if (top==n)
      printf("stack overflow\n");
    else
      {
       top++;
      printf("enter the element in the stack::");
       scanf("%d",&new_ele);
       stack[top]=new_ele;
      }
}

void pop()
{
    if(top==-1)
     printf("stack under flow\n");
    else 
     top--;
}

void display()
{
    int i;
    for(i=0;i<=top;i++)
    printf("%d\n",stack[i]);
}