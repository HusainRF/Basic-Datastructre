/* operation on array
insert in array
delete elemenyt in array
merging two array
search in array 
*/

#include<stdio.h>

void inssert_array(int *,int);
void delete_array(int *,int);
void  merging_array(int*,int* ,int,int);
int search_array(int *,int,int);

int main()
{
    int choice,arr1[20],arr2[20],i,size_array,size_array2;
    int index=-1,element;
    printf("enter the size of array\n");
    scanf("%d",&size_array);  
   
    printf("enter the value of array\n");
    for(i=0;i<size_array;i++)
     {
        scanf("%d",&arr1[i]);
     }

   printf("enter 1 for inserting in array\n");
   printf("enter 2 for deleting in in array\n");
   printf("enter 3 for merging of two array in array\n");
    printf("enter 4 for searching in array\n");
   scanf("%d",&choice);

 switch(choice)
  {
    case 1 : inssert_array(arr1,size_array);
            break;

    case 2 : delete_array(arr1,size_array);
            break;

    case 3:printf("enter the size of array\n");
           scanf("%d",&size_array2);
          printf("enter the value of array\n");
          for(i=0;i<size_array2;i++)
          {
            scanf("%d",&arr2[i]);
          }
          merging_array(arr1,arr2,size_array,size_array2);
          break;
    case 4:printf("enter the integer :");
           scanf("%d",&element); 
            index=search_array(arr1,size_array,element);
            if(index==-1)
               printf("element not found ");
            else 
            printf("found at index:%d",index);
           break;
    default :printf("you enter the wrong choice");
             break;
  }

}

void inssert_array(int arr[],int size_array)
{
    int index,element,i;
    printf("enter the index ");
    scanf("%d",&index);

    printf("enter the element ");
    scanf("%d",&element);
    
    for(i=size_array+1;i>=0;i--)
    {
        if(i-1==index)
        {
            arr[i]=arr[i-1]; 
            arr[i-1]=element; 
            break;
        }
        else
        {
            arr[i]=arr[i-1];
        }
    }

  printf("new array is\n");
  for(i=0;i<size_array+1;i++)
    {
        
        printf("%d\n",arr[i]);
    }
}

void delete_array(int arr[],int size_array)
{
    int index,i;
     printf("enter the index ");
    scanf("%d",&index);
  //  printf("enter the element ");
   // scanf("%d",&ele);
    for(i=0;i<size_array-1;i++)
    {
        if(i==index)
        {
            arr[i]=arr[i+1];
        }
        else if(i>=index)
        {
            arr[i]=arr[i+1];
        }
    }    
        
    
 printf("new array is\n");
    for(i=0;i<size_array-1;i++)
    {
        
        printf("%d\n",arr[i]);
    }
}

void merging_array(int arr1[],int arr2[],int size_array1,int size_array2)
{
    int j,i;
    int arr[20];
     j=0;
  for(i=0;i<size_array1;i++)
    {  
           arr[i]=arr1[i] ;
        
    }
  for(i=0;i<size_array2;i++)
    {
        arr[size_array1+i]=arr2[i];
    }
  printf("the merged array is\n");
  for(i=0;i<size_array2+size_array2;i++)
    {
        printf("%d\n",arr[i]);
    }
}

int search_array(int arr[],int size,int element)
{
int i;
for(i=0;i<size;i++)
{
  if(arr[i]==element)
  {
    return i;
  }
} 
}
