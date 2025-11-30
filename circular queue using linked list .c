AIM:
To implement a Circular Queue using a Linked List in C, supporting the operations
enqueue (insert), dequeue (delete), peek (front element), and display, following FIFO (First In First Out) principle.
ALGORITHM:
1. Algorithm for ENQUEUE (Insert Element)
Start
Create a new node
If memory allocation fails → print "Overflow" → stop
Set newnode->data = value
If front == NULL (queue empty):
Set front = newnode
Set rear = newnode
Set rear->next = front (circular link)
Else
Set rear->next = newnode
Set rear = newnode
Set rear->next = front
End
2. Algorithm for DEQUEUE (Delete Element)
Start
If front == NULL → print "Underflow" → stop
If front == rear (only one node):
Store front in temp
Set front = rear = NULL
Free temp
Else
Set temp = front
Set front = front->next
Set rear->next = front
Free temp
End
3. Algorithm for PEEK (View Front Element)
Start
If front == NULL → print "Queue empty"
Else print front->data
End
4. Algorithm for DISPLAY
Start
If front == NULL → print "Queue empty" → stop
Set temp = front
Print temp->data
Move temp = temp->next
While temp != front
End
PROGRAM:
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *front = NULL;
struct Node *rear = NULL;
// Enqueue operation
void enqueue(int item)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    newNode->data = item;
    if (front == NULL && rear == NULL) //Queue empty
    {
        front = rear = newNode;
        newNode->next = front; //Circular link
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
        rear->next = front; // Maintain circular link
    }
    printf("%d inserted into circular queue.\n", item);
}
// Dequeue operation
void dequeue()
{
    if (front == NULL)
    {
        printf("Queue Underflow!\n");
        return;
    }
    struct Node *temp = front;
    if (front == rear) // Only one node
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
        rear->next = front; // Maintain circular link
    }
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}
// Display operation
void display()
{
    if (front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }
    struct Node *temp = front;
    printf("Circular Queue elements: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}
int main()
{
    int choice, data;
    while (1)
    {
        printf("\n--- Queue Using Linked List Menu ---\n");
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
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
