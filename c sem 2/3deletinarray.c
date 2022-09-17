//to delete an item from an array at a specific index
#include<stdio.h>

int main()
{
    int arr1[20],size_array,i;
     int index,ele;   //new element
    printf("enter the size of array\n");
    scanf("%d",&size_array);
    printf("enter the value of array\n");
    for(i=0;i<size_array;i++)
     {
        scanf("%d",&arr1[i]);
     }
    printf("enter the index ");
    scanf("%d",&index);
  //  printf("enter the element ");
   // scanf("%d",&ele);
    for(i=0;i<size_array-1;i++)
    {
        if(i==index)
        {
            arr1[i]=arr1[i+1];
        }
        else if(i>=index)
        {
            arr1[i]=arr1[i+1];
        }
    }    
        
    
 printf("new array is\n");
    for(i=0;i<size_array-1;i++)
    {
        
        printf("%d\n",arr1[i]);
    }
}