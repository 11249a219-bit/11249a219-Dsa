#include <stdio.h>   // for input and output functions
#include <stdlib.h>  // for rand() and srand()
#include <time.h>    // for time() function
// Function to swap two numbers
void swap(int *a, int *b)
{
    int temp = *a;   // store value of a in temp
    *a = *b;         // assign value of b to a
    *b = temp;       // assign temp to b
}
// Function to partition the array
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];  // choosing last element as pivot
    int i = (low - 1);      // index of smaller element
    // loop through array and compare elements with pivot
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)   // if element is smaller than pivot
        {
            i++;
            swap(&arr[i], &arr[j]); // swap smaller element to left
        }
    }
    // place pivot at correct position
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);  // return pivot index
}
// QuickSort function using recursion
void quickSort(int arr[], int low, int high)
{
    if (low < high)  // condition for recursion
    {
        // choosing random pivot to improve performance
        int randomIndex = low + rand() % (high - low + 1);
        swap(&arr[randomIndex], &arr[high]);
        // partition the array
        int pi = partition(arr, low, high);
        // recursively sort left part
        quickSort(arr, low, pi - 1);
        // recursively sort right part
        quickSort(arr, pi + 1, high);
    }
}
int main()
{
    int n;
    srand(time(NULL));  // seed for random number generator
    // taking input size of array
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }
    int numbersToSort[n];  // array declaration
    // taking array elements as input
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &numbersToSort[i]);
    }
    // calling quicksort function
    quickSort(numbersToSort, 0, n - 1);
    // printing sorted array
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", numbersToSort[i]);
    }
    return 0;  // end of program
}
