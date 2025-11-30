AIM:
To write a C program that implements a doubly linked list and performs basic operations such as:
Creating nodes
Inserting nodes (beginning/end)
Deleting nodes
Displaying nodes in forward direction
ALGORITHM:
A doubly linked list node contains:
data
prev pointer (points to previous node)
next pointer (points to next node)
A) Algorithm to Create a Node
Step 1:
Allocate memory for a new node.
Step 2:
Read data from the user → store in newnode->data.
Step 3:
Set:
newnode->prev = NULL
newnode->next = NULL
Step 4:
Return the new node.
B) Algorithm to Insert at Beginning
Step 1:
Create a new node.
Step 2:
If head == NULL:
Set head = newnode.
Step 3:
Else:
newnode->next = head
head->prev = newnode
head = newnode
Step 4:
Stop.
C) Algorithm to Insert at End
Step 1:
Create a new node.
Step 2:
If head == NULL:
Set head = newnode
Stop.
Step 3:
Traverse using temp until temp->next == NULL.
Step 4:
Set:
temp->next = newnode
newnode->prev = temp
Step 5:
Stop.
D) Algorithm to Delete a Node
Step 1:
If head == NULL:
List is empty. Stop.
Step 2:
If deleting the first node:
head = head->next
if head != NULL:
    head->prev = NULL
Step 3:
Else traverse until the node to delete is found.
Step 4:
node->prev->next = node->next
if node->next != NULL:
    node->next->prev = node->prev
Step 5:
Free the node.
E) Algorithm to Display (Forward Traversal)
Step 1:
If head == NULL:
Print “List empty”. Stop.
Step 2:
Set temp = head.
Step 3:
While temp != NULL:
Print temp->data
temp = temp->next
Step 4:
Stop.
F) Main Program Flow
Step 1: Start
Step 2: Initialize head = NULL
Step 3: Ask user for operation
Step 4: Perform insert/delete/display
Step 5: Repeat until exit
Step 6: Stop
PROGRAM:
#include <stdio.h>
#include <stdlib.h>
// Create node for linked list
struct Node
{
    int data;
    struct Node *next; // To hold the address of next node
    struct Node *prev; // To hold the address of previous node
};
// To create a node and it returns address of newly created node
struct Node *CreateNode(int data)
{
    // STACK = (char *)malloc(MAX * sizeof(char));
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void InsertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = CreateNode(data);
    newNode->next = *head;
    newNode->prev = NULL; // Optional
    if (*head != NULL)
        (*head)->prev = newNode;
    *head = newNode;
    printf("Node with data %d inserted at beginning successfully  .\n", data);
}
void InsertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = CreateNode(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Node with data %d inserted at the end successfully.\n", data);
}
void InsertAtPosition(struct Node **head, int data, int position)
{
    // Considering that the position starts from 1 (Head at 1)
    if (position < 1)
    {
        printf("Invalid position!\n");
        return;
    }
    if (position == 1)
    {
        InsertAtBeginning(head, data);
        return;
    }
    struct Node *temp = *head;
    for (int k = 1; (k < position - 1 && temp != NULL); k++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Given position is out of range!\n");
        return;
    }
    // Only when given position is valid
    struct Node *newNode = CreateNode(data);
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)         // Only if NOT inserting at the end
        temp->next->prev = newNode; // Correct linking for DLL
    temp->next = newNode;
    printf("Node with data %d inserted at position %d successfully.\n", data, position);
}
// Delete a node by value
void DeleteNode(struct Node **head, int valueToDelete)
{
    if (*head == NULL)
    {
        printf("Linked List is empty, deletion operation can't be performed");
        return;
    }
    struct Node *temp = *head;
    // If head itself holds the value
    if (temp->data == valueToDelete)
    {
        *head = temp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(temp);
        printf("Data %d deleted from list.\n", valueToDelete);
        return;
    }
    // Search for the value
    struct Node *before = *head;
    while (before->next != NULL)
    {
        if (before->next->data == valueToDelete)
        {
            temp = before->next;
            before->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = before;
            free(temp);
            printf("Data %d deleted from list.\n", valueToDelete);
            return;
        }
        before = before->next;
    }
    printf("Element %d not found.\n", valueToDelete);
    return;
}
// Display all elements
void DisplayList(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp;
    temp = head;
    printf("\nLinked List Nodes: ");
    while (temp != NULL)
    {
        printf(" |Prev=%p|%d|Next=%p| -> ", temp->prev, temp->data, temp->next);
        temp = temp->next;
    }
}
// Main function
int main()
{
    struct Node *head = NULL;
    int choice, data, pos;
    while (1)
    {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete by Value\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            InsertAtBeginning(&head, data);
            break;
        case 2:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            InsertAtEnd(&head, data);
            break;
        case 3:
            printf("Enter data and position to insert: ");
            scanf("%d %d", &data, &pos);
            InsertAtPosition(&head, data, pos);
            break;
        case 4:
            printf("Enter value to delete: ");
            scanf("%d", &data);
            DeleteNode(&head, data);
            break;
        case 5:
            DisplayList(head);
            break;
        case 6:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
