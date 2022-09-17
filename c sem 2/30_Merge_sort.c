/*
 C Program to Perform Merge Sort 
*/
#include <stdio.h>

#define max 10

int a[11] = { 111, 22, 99, 88, 33, 44, 77, 55, 66, 101, 00 };
int b[10];

void Merging_to_Sort(int , int , int );
void Sort(int , int );


int main() { 
   int i;

   printf("List before Sorting\n");
   
   for(i = 0; i <= max; i++)
      printf("%d ", a[i]);

   Sort(0, max);

   printf("\nList after Sorting\n");
   
   for(i = 0; i <= max; i++)
      printf("%d ", a[i]);
}

void Merging_to_Sort(int low, int mid, int high) {
   int l1, l2, i;

   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
      if(a[l1] <= a[l2])
         b[i] = a[l1++];
      else
         b[i] = a[l2++];
   }
   
   while(l1 <= mid)    
      b[i++] = a[l1++];

   while(l2 <= high)   
      b[i++] = a[l2++];

   for(i = low; i <= high; i++)
      a[i] = b[i];
}

void Sort(int low, int high) {
   int mid;
   
   if(low < high) {
      mid = (low + high) / 2;
      Sort(low, mid);
      Sort(mid+1, high);
      Merging_to_Sort(low, mid, high);
   } else { 
      return;
   }   
}