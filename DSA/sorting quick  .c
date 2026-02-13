AIM:
To write a C program to sort a list of elements using the Quick Sort technique, which follows the Divide and Conquer approach by selecting a pivot and partitioning the array.
ALGORITHM:
1. Partition Algorithm
Start
Choose the last element as pivot
Set i = low - 1
For j = low to high - 1:
If array[j] < pivot:
Increment i
Swap array[i] and array[j]
Swap array[i + 1] with array[high]
Return i + 1 as pivot index
End
2. Quick Sort Algorithm
Start
If low < high:
Find pivot index using partition()
Recursively quick sort left part: quickSort(low, pivot-1)
Recursively quick sort right part: quickSort(pivot+1, high)
End
PROGRAM:
#include <stdio.h>
//Swap the numbers / Call by referene to persist changes
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
// Partition 
int partition(int list[], int low, int high)
{
    int pivot = list[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (list[j] < pivot)
        {
            i++;
            swap(&list[i], &list[j]);
        }
    }
    swap(&list[i + 1], &list[high]);
    return i + 1;
}
// Quick Sort function
void quickSort(int list[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(list, low, high);
        quickSort(list, low, pi - 1);
        quickSort(list, pi + 1, high);
    }
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int list[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &list[i]);
    quickSort(list, 0, n - 1);
    printf("Sorted array (Quick Sort): ");
    for (int i = 0; i < n; i++)
        printf("%d ", list[i]);
    return 0;
}
