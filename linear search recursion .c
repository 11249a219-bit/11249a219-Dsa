AIM:
To write a C program that uses recursion to perform a linear search on an array, and determines whether a given element is present in the array. If present, the program should return the index of the element; otherwise, it should indicate that the element is not found.
ALGORITHM:
Start
Input the size of the array and the array elements.
Input the element (key) to search for.
Define a recursive function
int linearSearch(int arr[], int index, int key, int n)
where:
arr[] = given array
index = current index to check
key = element to search
n = size of array
Base Case 1 (Not found):
If index == n, return -1.
Base Case 2 (Found):
If arr[index] == key, return index.
Recursive Step:
Call the function again with index + 1:
return linearSearch(arr, index + 1, key, n);
In the main function, call the recursive function starting from index 0.
If the returned value is -1, display “Element not found”.
Otherwise, display the index where the element is found.
End  
PROGRAM:
 #include <stdio.h>
#include <stdbool.h>
int LinearSearch(int dataSet[], int size, int elementToFind, int index)
{
    if (index >= size)
    {
        return -1;
    }
    if (dataSet[index] == elementToFind)
    {
        return index;
    }
    return LinearSearch(dataSet, size, elementToFind, index + 1);
}
int main()
{
    int size, elementToFind, i;
    printf("Enter the size of Data Set for Linear Search:");
    scanf("%d", &size);
    int searchSpace[size];
    for (i = 0; i < size; i++)
    {
        printf("Enter the %d out of %d element in data set: ", i + 1, size);
        scanf("%d", &searchSpace[i]);
    }
    printf("Given Dataset for Linear Search is: ");
    for (i = 0; i < size; i++)
    {
        printf("%d - ", searchSpace[i]);
    }
    printf("\nEnter the element to find in the dataset: ");
    scanf("%d", &elementToFind);
    int foundAt = LinearSearch(searchSpace, size, elementToFind, i = 0);
    if (foundAt >= 0)
        printf("Required element %d is found in the dataset at position %d or index %d", elementToFind, foundAt + 1, foundAt);
    else
        printf("Required element %d is NOT found in the dataset!!!", elementToFind); 
