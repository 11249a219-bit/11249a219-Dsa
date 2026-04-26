#include <stdio.h> 
#define V 5   // number of vertices
#define E 6   // number of edges
int parent[V];  // array to store parent of each vertex
// Function to find leader (root) of a set
int findLeader(int v) {
    while (parent[v] != v) 
        v = parent[v];   // move up until root is found
    return v; 
} 
// Function to merge two sets
void mergeSets(int u, int v) 
{ 
    int a = findLeader(u); 
    int b = findLeader(v); 
    // make one root as parent of another
    parent[a] = b; 
}
// Function to sort edges based on weight (bubble sort)
void sortEdges(int edges[E][3]) 
{ 
    for (int i = 0; i < E - 1; i++) 
    { 
        for (int j = 0; j < E - i - 1; j++) 
        { 
            // compare weights
            if (edges[j][2] > edges[j + 1][2]) 
            { 
                // swap entire edge (u, v, weight)
                for (int k = 0; k < 3; k++) 
                { 
                    int temp = edges[j][k]; 
                    edges[j][k] = edges[j + 1][k]; 
                    edges[j + 1][k] = temp; 
                } 
            } 
        } 
    } 
} 
// Function to implement Kruskal's Algorithm
void kruskal(int edges[E][3]) 
{ 
    sortEdges(edges);  // sort edges by weight
    // initialize each vertex as its own parent
    for (int i = 0; i < V; i++) 
        parent[i] = i; 
    int count = 0, cost = 0; 
    printf("Selected Edges:\n"); 
    // iterate through sorted edges
    for (int i = 0; i < E; i++) 
    { 
        int u = edges[i][0]; 
        int v = edges[i][1]; 
        int w = edges[i][2]; 
        // check if adding edge forms a cycle
        if (findLeader(u) != findLeader(v)) 
        { 
            printf("%d -- %d (Weight: %d)\n", u, v, w); 
            mergeSets(u, v);  // union operation
            cost += w;        // add weight to total cost
            count++; 
        }
        // stop when MST has V-1 edges
        if (count == V - 1) 
            break; 
    } 
    // print total cost of MST
    printf("Total Cost: %d\n", cost); 
} 
// main function
int main() {
    // edge list: (source, destination, weight)
    int edges[E][3] = { 
        {0, 1, 2}, {0, 2, 3}, {1, 2, 5}, 
        {1, 3, 3}, {2, 4, 4}, {3, 4, 2}
    }; 
    // call kruskal function
    kruskal(edges); 
    return 0;  // end of program
}
