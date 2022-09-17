 //bubble sort using function 
 //funtion =>bubble_sort()

#include <stdio.h>
void bubble_sort(long [], long);

int main()
{
  long array[100], n, i;   

  printf("Enter number of elements\n");
  scanf("%ld", &n);

  printf("Enter %ld integers\n", n);

  for (i = 0; i < n; i++)
    scanf("%ld", &array[i]);

  bubble_sort(array, n);

  printf("Sorted list in ascending order:\n");

  for (i= 0; i < n; i++)
     printf("%ld\n", array[i]);

  return 0;
}

void bubble_sort(long list[],long n)
{
    long i, j;
    long temp;
    for( i=0; i<n-1; i++)
    { 
        for(j = 0; j<n-1-i; j++)
        {
            if( list[j] > list[j+1])
            {
                temp=list[j];
                list[j]=list[j+1];
                list[j+1]=temp;
            }
        }
    }
}
