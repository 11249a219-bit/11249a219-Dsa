AIM:
To write a C program that implements basic stack operations—Push, Pop, Peek, and Display—using an array.
The program should demonstrate Last-In-First-Out (LIFO) behavior of a stack.
ALGORITHM:
1. Initialize Stack
Start
Define an array stack[MAX]
Set top = -1 (empty stack)
2. PUSH Operation
If top == MAX - 1
Stack Overflow (cannot insert)
Else
Increase top by 1
Insert the element at stack[top]
End
3. POP Operation
If top == -1
Stack Underflow (no element to delete)
Else
Retrieve element from stack[top]
Decrease top by 1
End
4. PEEK (TOP) Operation
If top == -1
Stack is empty
Else
Return stack[top]
End
5. DISPLAY Operation
If top == -1
Print "Stack is empty"
Else
For i = top down to 0
Display stack[i]
End
6. End Program
program:
#include <stdio.h>
#include <stdlib.h>
int top = -1;
int size;
char *STACK; // Dynamic Array
void push(char item)
{
    if (top == (size - 1))
    {
        printf("Stack is already full, no additional push allowed - Overflow");
    }
    else
    {
        top = top + 1;
        STACK[top] = item;
    }
}
void pop()
{
    if (top == -1)
    {
        printf("Stack is underflow");
    }
    else
    {
        char temp = STACK[top];
        top = top - 1;
        printf("Element popped %c", temp);
    }
}
void DisplayStack()
{
    if (top == -1)
    {
        printf("Stack is underflow");
        return;
    }
    printf("[Top] \n");
    for (int i = top; i >= 0; i--)
    {
        printf("%c \n", STACK[i]);
    }
}
int main()
{
    int choice;
    char data;
    printf("Enter size of stack: ");
    scanf("%d", &size);
    STACK = (char *)malloc(size * sizeof(char));
    while (1)
    {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf(" %c", &data);
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            DisplayStack();
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
