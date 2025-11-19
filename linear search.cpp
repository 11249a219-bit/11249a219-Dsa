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
