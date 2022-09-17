/*
program for insertions sort
*/
#include<stdio.h>

void insertion_sort(int *);
int main()
{
    int arr[10],i;
    for(i=0;i<10;i++)
       scanf("%d",&arr[i]);
 insertion_sort(arr);
 printf("\nthe list is :\n");
 for(i=0;i<10;i++)
 { 
     printf("%d\n",arr[i]);
 }
}

void insertion_sort(int arr[])
{
    int temp,i,j;
    for(i=1;i<10;i++)
    {
        temp=arr[i];
        j=i-1;
      while (j>=0 && arr[j]>temp)
      {
          arr[j+1]=arr[j];
          j--;
      }
      arr[j+1]=temp;
    }
}