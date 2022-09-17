#include<stdio.h>
int main()
{
    long int n,d,i,j;
    
    
    scanf("%ld %ld",&n,&d);
    long int arr[n];
    long int temp[d];
    for(i=0;i<n;i++)
    {
        scanf("%ld",&arr[i]);
    }
   for(i=0;i<d;i++)
   {
      temp[i]=arr[i]; 
   }
       for(j=0;j<n;j++)
       {
           arr[j]=arr[j+d];
       }
      for(i=n-d,j=0; i<n ,j<d;i++,j++)
      {
          arr[i]=temp[j];
      }
    
    for(i=0;i<n;i++)
printf("%ld ",arr[i]);
return 0;
}
