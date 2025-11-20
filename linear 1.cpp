//Aim:To implement Stack operations using Linked List in C, including push, pop and display functions, by dynamically creating and managing nodes as per the given algorithm.
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node* Top = NULL;
struct Node* CreateNewNode(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode != NULL) {
        newNode->data = x;
        newNode->next = NULL;
    }
    return newNode;
}
void push(int x) {
    struct Node* NewNode = CreateNewNode(x);
    if(NewNode == NULL) {
        printf("Stack Overflow\n");
        return;
    }
    NewNode->next = Top;
    Top = NewNode;
    printf("Element pushed onto stack\n");
}
int pop() {
    if(Top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    int popped = Top->data;
    struct Node* temp = Top;
    Top = Top->next;
    free(temp);
    return popped;
}
void display() {
    if(Top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* t = Top;
    printf("Stack elements:\n");
    while(t != NULL) {
        printf("%d\n", t->data);
        t = t->next;
    }
}
int main() {
    int choice, value;
    while(1) {
        printf("\n1 Push\n2 Pop\n3 Display\n4 Exit\n");
        scanf("%d", &choice);
        if(choice == 1) {
            printf("Enter value: ");
            scanf("%d", &value);
            push(value);
        } 
        else if(choice == 2) {
            int v = pop();
            if(v != -1)
                printf("Popped: %d\n", v);
        }
        else if(choice == 3) {
            display();
        }
        else if(choice == 4) {
            break;
        }
        else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}
