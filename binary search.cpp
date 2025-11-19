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
