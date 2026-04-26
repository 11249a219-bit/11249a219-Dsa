#include <stdio.h> 
#include <stdlib.h> 
#define V 5   // number of vertices
// Function to find the vertex with minimum key value
int minKey(int key[], int visited[]) {
    int min = 999999; 
    int min_index = 0; 
    // loop through all vertices
    for (int i = 0; i < V; i++) 
    { 
        // select the unvisited vertex with smallest key value
        if (!visited[i] && key[i] < min) 
        { 
            min = key[i]; 
            min_index = i; 
        } 
    } 
    return min_index; 
} 
// Function to print the Minimum Spanning Tree
void printPrimMST(int parent[], int graph[V][V]) {
    printf("\nPrim's MST:\n"); 
    printf("Edge \tWeight\n"); 
    int total = 0; 
    // print edges and calculate total cost
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]); 
        total += graph[i][parent[i]];
    } 
    printf("Total Cost = %d\n", total); 
} 
// Function to implement Prim's Algorithm
void primMST(int graph[V][V]) 
{ 
    int parent[V];   // to store MST
    int key[V];      // minimum edge weight
    int visited[V];  // visited vertices
    // initialize all keys as infinite and visited as false
    for (int i = 0; i < V; i++) {
        key[i] = 999999; 
        visited[i] = 0; 
    } 
    key[0] = 0;     // start from vertex 0
    parent[0] = -1; // root node has no parent
    // loop to construct MST
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, visited);  // get minimum key vertex
        visited[u] = 1;                // mark it as visited
        // update key and parent for adjacent vertices
        for (int v = 0; v < V; v++) 
        { 
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) 
            { 
                parent[v] = u; 
                key[v] = graph[u][v]; 
            } 
        } 
    } 
    // print the resulting MST
    printPrimMST(parent, graph); 
}
// main function
int main() 
{ 
    // adjacency matrix representation of graph
    int graph[V][V] = { 
        {0, 2, 3, 0, 0}, 
        {2, 0, 5, 3, 0}, 
        {3, 5, 0, 0, 4}, 
        {0, 3, 0, 0, 2}, 
        {0, 0, 4, 2, 0}
    }; 
    // call Prim's algorithm
    primMST(graph); 
    return 0;  // end of program
}
