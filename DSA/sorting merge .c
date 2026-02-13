AIM:
To write a C program to sort a list of elements using Merge Sort, a recursive Divide and Conquer algorithm that divides the array into halves, sorts each half, and merges them.
ALGORITHM:
Start
If low < high:
Find mid = (low + high)/2
Recursively call mergeSort(low, mid)
Recursively call mergeSort(mid+1, high)
Call merge(low, mid, high)
End
2. Merge Algorithm
Start
Create temporary arrays L[] and R[]
Copy left half elements into L[]
Copy right half elements into R[]
Maintain three indices: i, j, and k
While both arrays have elements:
If L[i] <= R[j] → place L[i] in main array → i++
Else place R[j] in main array → j++
Copy remaining elements of L[] (if any)
Copy remaining elements of R[] (if any)
End
PROGRAM:
#include <stdio.h>
// Merge two sorted subarrays
void merge(int arr[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = 0;
    int temp[right - left + 1];
    // Merge logic
    while (i <= mid && j <= right)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    // Copy left-out elements
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    // Copy temp back to original
    for (i = left, k = 0; i <= right; i++, k++)
        arr[i] = temp[k];
}
// Merge Sort function
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);      // Left part
        mergeSort(arr, mid + 1, right); // Right part
        merge(arr, left, mid, right);   // Merge halves
    }
}
int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    mergeSort(arr, 0, n - 1);
    printf("Sorted array (Merge Sort): ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
