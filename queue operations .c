AIM:
To write a C program that implements queue operations using an array (or linked list). The program should perform the basic queue operations:
Enqueue (Insert an element)
Dequeue (Delete an element)
Peek / Front (Access the first element)
Display (Show all elements)
ALGORITHM:
1. Initialization
Step 1:
Start.
Step 2:
Declare an array queue[] with a fixed size.
Step 3:
Set
front = -1  
rear  = -1
2. ENQUEUE (Insert)
Step 1:
If rear == MAX-1, queue is FULL → Overflow. Stop.
Step 2:
If front == -1 and rear == -1 (queue empty):
Set front = rear = 0.
Step 3:
Else:
rear = rear + 1.
Step 4:
Insert the new element at queue[rear].
3. DEQUEUE (Delete)
Step 1:
If front == -1 (queue empty):
Underflow. Stop.
Step 2:
Store the element at queue[front] (for display).
Step 3:
If front == rear:
It means only one element was present.
Set front = rear = -1.
Step 4:
Else:
front = front + 1.
4. PEEK / FRONT (Access first element)
Step 1:
If queue is empty (front == -1):
Display "Queue is empty".
Step 2:
Else:
Display queue[front].
5. DISPLAY
Step 1:
If queue is empty (front == -1):
Print "Queue is empty".
Step 2:
Else:
Print elements from front to rear.
6. stop
PROGRAM:
#include <stdio.h>
#include <stdlib.h>
int front = -1, rear = -1, size;
int *QUEUE; // Dynamic array for queue
void enqueue(int item)
{
    if (rear == size - 1)
    {
        printf("Queue Overflow! Cannot insert.\n");
        return;
    }
    if (front == -1) // First element insertion
        front = 0;
    rear++;
    QUEUE[rear] = item;
    printf("%d inserted into queue.\n", item);
}
void dequeue()
{
    if (front == -1)
    {
        printf("Queue Underflow! Nothing to delete.\n");
        return;
    }
    int temp = QUEUE[front];
    front++;
    printf("Deleted element: %d\n", temp);
    // Reset queue when empty
    if (front > rear)
        front = rear = -1;
}
void display()
{
    if (front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", QUEUE[i]);
    }
    printf("\n");
}
int main()
{
    int choice, data;
    printf("Enter size of Queue: ");
    scanf("%d", &size);
    QUEUE = (int *)malloc(size * sizeof(int));
    if (QUEUE == NULL)
    {
        printf("Memory allocation failed!\n");
        return 0;
    }
    while (1)
    {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            enqueue(data);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...\n");
            free(QUEUE);
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
