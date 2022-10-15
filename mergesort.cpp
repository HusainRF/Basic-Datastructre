#include <iostream>
using namespace std;
int comparisons=0;
int partitions=0;
void merge(int arr[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];
    int i, j, k;
    i = 0;
    j = 0;
    k = p;
    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}
void mergeSort(int array[], int const begin, int const end)
{
	if (begin >= end)
		return;
    partitions++;
	auto mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
}

void printArray(int A[], int size)
{
	for (auto i = 0; i < size; i++)
		cout << A[i] << " ";
}

int main()
{
    cout<<"Enter array size: "<<endl;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
	cout << "Given array is \n";
	printArray(arr, n);

	mergeSort(arr, 0, n - 1);

	cout << "\nSorted array is \n";
	printArray(arr, n);
	return 0;
}