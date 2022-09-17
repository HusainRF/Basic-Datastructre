/*
program for selection sort
*/
#include<stdio.h>

int main()
{
    int arr[10],i,j,MIN,loca,temp;
    for(i=0;i<=9;i++)
       scanf("%d",&arr[i]);
    
    for(i=0;i<9;i++)
    {
        MIN=arr[i];
        loca=i;
        for(j=i+1;j<=9;j++)
        {
            if(MIN>arr[j])
            {
                MIN=arr[j];
                loca=j;
            }
        }
      temp=arr[i];
      arr[i]=arr[loca];
      arr[loca]=temp;
    }
    
  printf("\n the list is\n");
  for(i=0;i<10;i++)
  {
      printf("%d\n",arr[i]);
  }
 return 0; 
}