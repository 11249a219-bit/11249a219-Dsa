//Aim:To perform string reverse using stack operation
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
char pop()
{
    char temp = STACK[top];
    top = top - 1;
    return temp;
}
int main()
{
    printf("Enter the size of string to reverse: ");
    scanf("%d", &size);
    char input[size];
    STACK = (char *)malloc(size * sizeof(char));

    printf("Enter the string of size %d to reverse: ", size);
    scanf("%s", &input);

    for (int i = 0; i <= size - 1; i++)
    {
        push(input[i]);
    }
    printf("Reversed string is - \n");
    for (int i = 0; i <= size - 1; i++)
    {
        printf("%c", pop());
    }
}
}
