#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,first,middle,last,search,n,array[30];

    printf("enter the szie of array (it should be less then 30)::");
    scanf("%d",&n);

    printf("enter the elements in array in ascending order\n");
    for(i=0;i<n;i++)
      scanf("%d",&array[i]);
    first=0;
    last=i;
    middle=(first+last)/2;

  printf("enter the element to be search::");
  scanf("%d",&search);
    while (first <= last) {
    if (array[middle] < search)
      first = middle + 1;
    else if (array[middle] == search) {
      printf("%d found at location %d.\n", search, middle+1);
      break;
    }
    else
      last = middle - 1;

    middle = (first + last)/2;
  }
  if (first > last)
    printf("Not found! %d isn't present in the list.\n", search);

  return 0;
    printf("\nelement is not in array");
}