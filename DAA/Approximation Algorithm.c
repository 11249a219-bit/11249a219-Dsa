#include <stdio.h>
#define V 5   // number of vertices in the graph
// Function to find approximate vertex cover
void findVertexCover(int graph[V][V])
{
    int visited[V];
    // Initialize all vertices as not visited
    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
    }
    // Loop through all edges
    for (int u = 0; u < V; u++)
    {
        for (int v = 0; v < V; v++)
        {
            // If there is an edge and both vertices are not selected
            if (graph[u][v] == 1 && !visited[u] && !visited[v])
            {
                // Add both vertices to vertex cover
                visited[u] = 1;
                visited[v] = 1;
            }
        }
    }
    // Print the vertex cover
    printf("Approximate Vertex Cover: ");
    int count = 0;
    for (int i = 0; i < V; i++)
    {
        if (visited[i])
        {
            printf("%d ", i);  // print selected vertex
            count++;
        }
    }
    // Print total count of vertices in cover
    printf("\nTotal vertices in the cover: %d\n", count);
}
int main()
{
    // Adjacency matrix representation of graph
    int graph[V][V] = {
        {0, 1, 0, 0, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };
    printf("Executing Vertex Cover Approximation...\n");
    // Call function
    findVertexCover(graph);
    return 0;  // end of program
}
