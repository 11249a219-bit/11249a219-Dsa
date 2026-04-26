#include<stdio.h>
// Function to find Fibonacci number using recursion
int fib(int n)
{
    if(n == 0)
    {
        return 0;   // base case: fib(0) = 0
    }
    if(n == 1)
    {
        return 1;   // base case: fib(1) = 1
    }
    // recursive case
    return fib(n-1) + fib(n-2);
}
int main()
{
    int n, result;
    // taking input from user
    printf("Enter the integer number n: ");
    scanf("%d", &n);
    // checking for invalid input
    if (n < 0)
    {
        printf("Invalid number");
        return 0;
    }
    // calling fibonacci function
    result = fib(n);
    // printing the result
    printf("Fibonacci term is %d", result);
    return 0;  // end of program
}
