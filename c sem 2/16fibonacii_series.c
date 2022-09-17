#include<stdio.h>
 
int Fibonacci_series(int);
 
int main()
{
   int a,i=0,c;
 
   scanf("%d",&a);
 
   printf("Fibonacci series\n");
 
   for (c=1;c<=a;c++)
   {
      printf("%d\n",Fibonacci_series(i));
      i++; 
   }
 
   return 0;
}
 
int Fibonacci_series(int n)
{
   if (n==0)
      return 0;
   else if (n==1)
      return 1;
   else
      return (Fibonacci(n-1) + Fibonacci(n-2));
}