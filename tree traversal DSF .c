AIM:
To write a C program to perform Depth-First Search (DFS) tree traversals 
Preorder, Inorder, and Postorder — on a binary tree using recursive functions.
ALGORITHM:
Start
Create a new node
Read data for the node
If user enters -1 → return NULL
Recursively create left child
Recursively create right child
Return created node
End
DFS Traversals
2. Algorithm for PREORDER Traversal (Root → Left → Right)
Start
If node is not NULL:
Visit (print) the node’s data
Call preorder(left child)
Call preorder(right child)
End
3. Algorithm for INORDER Traversal (Left → Root → Right)
Start
If node is not NULL:
Call inorder(left child)
Visit (print) the node’s data
Call inorder(right child)
End
4. Algorithm for POSTORDER Traversal (Left → Right → Root)
Start
If node is not NULL:
Call postorder(left child)
Call postorder(right child)
Visit (print) the node’s data
End
PROGRAM:
#include <stdio.h>
#include <stdlib.h>
// Structure for tree node
// Data, Pointer to left child and Pointer to right child
struct Node
{
    int data;
    struct Node *left, *right;
};
// Node creation
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
// Insert the new node and returns root node of the updated tree
struct Node *insert(struct Node *root, int value)
{
    // First node will be root node
    if (root == NULL)
    {
        return createNode(value);
    }
    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}
// Preorder - Root -> Left -> Right
void preorder(struct Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
// Inorder - Left -> Root -> Right
void inorder(struct Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
// Postorder - Left -> Right -> Root
void postorder(struct Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
int main()
{
    int n, value;
    struct Node *root = NULL;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insert(root, value); // Insert dynamically into BST
    }
    printf("Preorder Traversal: ");
    preorder(root);
    printf("\nInorder Traversal: ");
    inorder(root);
    printf("\nPostorder Traversal: ");
    postorder(root);
    return 0;
}
