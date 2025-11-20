//Aim:To implement a Circular Queue using Linked List  with enqueue, dequeue, and display operations.
#include <stdlib.h>
#include <stdio.h>
struct node {
    int data;
    struct node *next;
};
struct node* create_node(int data) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
void enqueue(struct node **front, struct node **rear, int data) {
    struct node *newnode = create_node(data);
    if (*rear == NULL) {
        *front = *rear = newnode;
    } else {
        (*rear)->next = newnode;
        *rear = newnode;
    }
    printf("Enqueued %d successfully\n", data);
}
void dequeue(struct node **front, struct node **rear) {
    if (*front == NULL) {
        printf("Queue is empty! Dequeue not possible\n");
        return;
    }
    struct node *temp = *front;
    printf("Dequeued %d\n", temp->data);
    *front = (*front)->next;
    if (*front == NULL)
        *rear = NULL;
    free(temp);
}
void peek(struct node *front) {
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        printf("Front element: %d\n", front->data);
    }
}
void display(struct node *front) {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct node *temp = front;
    printf("\nQueue (front to rear): ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    struct node *front = NULL;
    struct node *rear = NULL;
    int choice, data;
    while (1) {
        printf("\n---- Queue using Singly Linked List ----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek (Front Element)\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &data);
                enqueue(&front, &rear, data);
                break;
            case 2:
                dequeue(&front, &rear);
                break;
            case 3:
                peek(front);
                break;
            case 4:
                display(front);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again\n");
        }
    }
    return 0;
}
