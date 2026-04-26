#include <stdio.h>
// Function to implement Best Fit Bin Packing Algorithm
void bestFit(int items[], int n, int capacity) {
    printf("\nBest Fit Algorithm\n");
    int bin[n];      // array to store remaining capacity of bins
    int binCount = 0; // number of bins used
    // initialize all bins with full capacity
    for (int i = 0; i < n; i++)
    {
        bin[i] = capacity;
    }
    // process each item
    for (int i = 0; i < n; i++) 
    {
        int bestIndex = -1;       // index of best bin
        int minSpace = capacity + 1; // minimum remaining space
        // find the best bin for current item
        for (int j = 0; j < binCount; j++)
        {
            // check if item fits and leaves minimum space
            if (bin[j] >= items[i] && (bin[j] - items[i]) < minSpace) 
            {
                bestIndex = j;
                minSpace = bin[j] - items[i];
            }
        }
        // if suitable bin is found
        if (bestIndex != -1) {
            bin[bestIndex] -= items[i]; // reduce remaining space
            printf("Item %d (Weight: %d) placed in Bin %d\n", i + 1, items[i], bestIndex + 1);
        } 
        else 
        {
            // create new bin
            bin[binCount] = capacity - items[i];
            printf("Item %d (Weight: %d) placed in Bin %d\n", i + 1, items[i], binCount + 1);
            binCount++;
        }
    }
    // print total bins used
    printf("Total bins used = %d\n", binCount);
}
int main() 
{
    int n, capacity;
    // input number of items
    printf("Enter number of items: ");
    scanf("%d", &n);
    int items[n];
    // input bin capacity
    printf("Enter bin capacity: ");
    scanf("%d", &capacity);
    // input item sizes
    printf("Enter item sizes:\n");
    for (int i = 0; i < n; i++) 
    {
        int itemSize;
        printf("Item %d: ", i + 1);
        scanf("%d", &itemSize);
        // check if item size is valid
        if (itemSize <= capacity) 
        {
            items[i] = itemSize;
        } 
        else 
        {
            printf("Item size exceeds bin capacity. Please enter a valid size.\n");
            i--; // repeat input for same item
        }
    }
    // call best fit function
    bestFit(items, n, capacity);
    return 0;  // end of program
}
