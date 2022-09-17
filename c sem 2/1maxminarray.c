// to find max min in array
#include<stdio.h>

int main()
{
    int arr[10],i,imax,imin;
    printf("enter the element in array\n");
 for(i=0;i<10;i++)
  scanf("%d",&arr[i]);
imax=arr[0];
 for(i=0;i<10;i++)
 {
     if(arr[i]>imax)
       imax=arr[i];
 }
 imin=arr[0];
 for(i=0;i<10;i++)
 {
     if(arr[i]<imin)
     imin=arr[i];
 }
 printf("maximum=%d \t minimum=%d",imax,imin);
}
