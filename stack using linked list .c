AIM:
To implement a Stack data structure using a Linked List in C, providing operations such as
push (insert), pop (delete), peek (top element), and display, following LIFO (Last In First Out) principle.
ALGORITHM:
1. Algorithm for PUSH (insert element)
Start
Create a new node
If memory allocation fails → print "Overflow" → stop
Set newnode->data = value
Set newnode->next = top
Set top = newnode
End
2. Algorithm for POP (delete element)
Start
If top == NULL → print "Underflow" → stop
Set temp = top
Set top = top->next
Free temp
End
3. Algorithm for PEEK (view top element)
Start
If top == NULL → print "Stack empty" → stop
Else display top->data
End
4. Algorithm for DISPLAY
Start
If top == NULL → print "Stack empty" → stop
Set temp = top
While temp != NULL
Print temp->data
Move temp = temp->next
End
PROGRAM:
#include <stdio.h>
int main()
{
    int size, targetElement, start, mid, end;
    printf("Enter the size of array: ");
    scanf("%d",&size);
    int searchSpace[size];
    //Reading elements into array
    for(int i=0;i<size;i++)
    {
        printf("Enter element %d of %d: ",i, size-1);
        scanf("%d",&searchSpace[i]);
    }
    printf("Enter the element to search ");
    scanf("%d",&targetElement);
    start = 0;
    end = size-1;
    while (start<=end)
    {
        mid = (start + end)/2;
        if(searchSpace[mid] == targetElement)
        {
            printf("Element found at index of %d (i.e. at position %d)", mid, mid+1);
            return 0;
        }
        else if(searchSpace[mid] < targetElement)
        {
            start = mid +1;
        }
        else
        {
            end = mid - 1;
        }
    }
    printf("ELement doesn't exist in the given search set");
   return 0;
}
