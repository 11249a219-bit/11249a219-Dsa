#include <stdio.h>
// Structure to store item details
struct Item {
    int Weight;   // weight of item
    int Value;    // value of item
    float PPW;    // profit per weight (value/weight)
};
// Function to sort items based on PPW in descending order
void sort(struct Item items[], int n) {
    struct Item temp;
    // bubble sort based on PPW
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].PPW < items[j + 1].PPW) {
                // swap items
                temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
    // display sorted items
    printf("Items sorted by value/weight ratio:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: Weight = %d, Value = %d, Ratio = %.2f\n", 
                i + 1, items[i].Weight, items[i].Value, items[i].PPW);
    }
}
int main() {
    int n;
    float capacity;
    // input number of items
    printf("Enter number of items: ");
    scanf("%d", &n);
    struct Item items[n];
    // input weight and value for each item
    printf("Enter weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].Weight, &items[i].Value);
        // calculate profit per weight
        items[i].PPW = (float)items[i].Value / items[i].Weight;
    }
    // input knapsack capacity
    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);
    // sort items based on ratio
    sort(items, n);
    float totalProfit = 0.0;
    // apply greedy method for fractional knapsack
    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].Weight) {
            // take full item
            totalProfit += items[i].Value;
            capacity -= items[i].Weight;
        } else {
            // take fraction of item
            totalProfit += items[i].PPW * capacity;
            capacity = 0;
            break;
        }
    }
    // print maximum profit
    printf("Maximum profit = %.2f\n", totalProfit);
    return 0;  // end of program
}
