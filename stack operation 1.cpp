/AIM: To find the required element in stack operationt/
#include <stdio.h>
#define MAX 100  // Maximum size of the stack
int stack[MAX];
int top = -1;// Stack is initially empty
void push(int x)
{
    if (top >= MAX - 1)// Check if the stack is full
    {
    printf("Stack overflow\n");
    }
    else
    {
    top++;
     stack[top] = x;// Push the element onto the stack
    }
}
int pop()
{
    if (top < 0)
    {
    printf("Stack underflow\n");
    return -1;// Return -1 to indicate an error
    }
    else
    {
    int value = stack[top];
    top--;
    return value;
    }
}
int peek()
{
    if (top < 0)
    {
     printf("Stack is empty\n"); // If empty, print message
    return -1; // Return -1 to indicate the stack is empty
    }
    else
    {
    return stack[top];
    }
}
int empty()
{
    return top == -1;
}
void display()
{
    if (empty())
    {
     printf("Stack is empty\n");
    }
    else
    {
    printf("Stack elements: ");
    for (int i = top; i >= 0; i--)
    printf("%d ", stack[i]);
    printf("\n");
    }
}
int main()
{
    int choice, value;
    int n;
    printf("Enter total size of stack (max %d): ", MAX);
    scanf("%d", &n);
    if (n > MAX)
    {
     printf("Size exceeds limit\n"); // Print an error message if the size is too large
    return 0;
    }
    while (1)
    {
    printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nEnteryour choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
             case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                value = pop();
                if (value != -1)// Check if the pop was successful
                    printf("Popped value: %d\n", value);
                break;

            case 3:
                value = peek();
                if (value != -1) // Check if the peek was successful
                    printf("Top value: %d\n", value);
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");// Print an error message if the choice is invalid
        }
    }
}
