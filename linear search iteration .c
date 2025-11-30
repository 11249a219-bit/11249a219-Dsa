AIM:
To write a C program to search for an element in an array using Linear Search (Iterative method) and determine whether the element is present or not.
ALGORITHM:
Start
Declare an array and variables:
n for number of elements
i for loop index
key for element to be searched
Input the value of n.
Input n elements into the array.
Input the value of key (the element to search).
Set a flag variable found = 0.
Loop from i = 0 to n - 1:
If arr[i] == key
Set found = 1
Break the loop
If found == 1:
Print “Element found at position i+1”.
Else:
Print “Element not found”.
Stop  
PROGRAM:
#include <stdio.h>
int main()
{
    int size, elementToFind, i;
    printf("Enter the size of Data Set for Linear Search:");
    scanf("%d",&size);
    int searchSpace[size];
    for(i=0; i<=size-1; i++)
    {
        printf("Enter the %d out of %d element in data set: ",i+1, size);
        scanf("%d",&searchSpace[i]);
    }
    //printf("Given Dataset for Linear Search is: ");
    for(int i=0; i<size; i++)
    {
        printf("%d - ",searchSpace[i]);
    }
    printf("\nEnter the element to find in the dataset: ");
    scanf("%d",&elementToFind);
    i =0;
    while(i<size)
    {
        if(searchSpace[i] == elementToFind)
        {
            printf("Required element %d is found in the dataset at position %d or index %d",elementToFind, i+1, i);
            return 0;
        }
        i++;
    }
    printf("Required element %d is NOT found in the dataset!!!",elementToFind);
}
