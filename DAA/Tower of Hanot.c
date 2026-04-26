#include<stdio.h>
// Function for Tower of Hanoi
void TOH(int n, char s, char d, char a)
{
    // Base condition: if only one disk
    if (n == 1)
    {
        printf("\nMove disk %d from %c to %c", n, s, d);
        return;
    }
    // Move n-1 disks from source to auxiliary
    TOH(n-1, s, a, d);
    // Move the largest disk from source to destination
    printf("\nMove disk %d from %c to %c", n, s, d);
    // Move n-1 disks from auxiliary to destination
    TOH(n-1, a, d, s);
}
int main()
{
    int n;
    // Input number of disks
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    // Call TOH function
    TOH(n, 'S', 'D', 'A');
    return 0;  // End of program
}
