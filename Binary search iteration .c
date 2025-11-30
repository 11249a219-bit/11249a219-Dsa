AIM:
To write a C program that performs binary search using iteration to find the position of a given element in a sorted array.
If the element is present, the program should return its index; otherwise, it should indicate that the element is not found.
ALGORITHM:
Start
Input the size of the array and the sorted array elements.
Input the element (key) to search for.
Initialize:
low = 0
high = n - 1
Repeat while low <= high:
a. Compute mid = (low + high) / 2.
b. If arr[mid] == key,
→ Return mid (element found).
c. Else if arr[mid] < key,
→ Set low = mid + 1.
d. Else
→ Set high = mid - 1.
If the loop ends without finding the key,
→ Return -1 (element not found).
End
PROGRAM:
#include <stdio.h>
int main()
{
    int size, targetElement, start, mid, end;
    printf("Enter the size of array: ");
    scanf("%d",&size);
    int searchSpace[size];
    //Reading elements into array
    for(int i=0;i<size;i++)
    {
        printf("Enter element %d of %d: ",i, size-1);
        scanf("%d",&searchSpace[i]);
    }
    printf("Enter the element to search ");
    scanf("%d",&targetElement);
    start = 0;
    end = size-1;
    while (start<=end)
    {
        mid = (start + end)/2;
        if(searchSpace[mid] == targetElement)
        {
            printf("Element found at index of %d (i.e. at position %d)", mid, mid+1);
            return 0;
        }
        else if(searchSpace[mid] < targetElement)
        {
            start = mid +1;
        }
        else
        {
            end = mid - 1;
        }
    }
    printf("ELement doesn't exist in the given search set");
   return 0;
}
