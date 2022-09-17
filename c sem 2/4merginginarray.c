// merge two arrays
#include<stdio.h>

int main()
{
    int arr1[20],arr2[10],i,j;
     
    
    printf("enter the value of 1st array\n");
    for(i=0;i<5;i++)
     {
        scanf("%d",&arr1[i]);
     }
    printf("enter the value of 2nd array\n");
    for(i=0;i<5;i++)
    {
       scanf("%d",&arr2[i]);
    }    
    
    j=0;
    for(i=0;i<=10;i++)
    {  
    
        if(i>=5)
        {
          arr1[i]=arr2[j];
          j++;
        }
    }
    printf("the merged array is\n");
    for(i=0;i<10;i++)
    {
        printf("%d\n",arr1[i]);
    }
}