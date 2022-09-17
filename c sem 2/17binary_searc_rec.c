#include<stdio.h>

int binary_search(int [],int,int,int);

int main()
{
    int array[30],i,size;
    int first ,search ,last,index;
    
    printf("enter the size of array (max size=30)::");
    scanf("%d",&size);
    printf("enter the elment in ascending order\n");
   for(i=0;i<size;i++)
   scanf("%d",&array[i]);
     first=0;
    last=i;
   printf("enter the element to be searched::");
   scanf("%d",&search);

   index=binary_search(array,first,last,search);
   if(index==-1)
    printf("\nElement not found");
   else 
    printf("elemnt found at index::%d",index);
}
int binary_search(int arr[],int first,int last,int search)
{
    int midd;
    if(first>last)
    return -1;
    midd=(first+last)/2;
   
   if (arr[midd]<search)
    return binary_search(arr,midd+1,last,search);
  else if(arr[midd]==search)
   return midd;
  else
  return  binary_search(arr,first,midd-1,search);
}
