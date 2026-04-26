#include <stdio.h>
#define V 5          // number of vertices
#define INF 999999   // representing infinity
// Function to find the vertex with minimum distance
int extractMin(int dist[], int visited[])
{
    int min = INF, min_index = -1;
    // loop through all vertices
    for (int v = 0; v < V; v++)
    {
        // select the unvisited vertex with smallest distance
        if (!visited[v] && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;  // return index of minimum vertex
}
// Dijkstra's algorithm function
void dijkstra(int graph[V][V])
{
    int dist[V], visited[V];
    // initialize distances as infinite and visited as false
    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }
    // distance of source vertex (0) is always 0
    dist[0] = 0;
    // loop for all vertices
    for (int count = 0; count < V; count++)
    {
        int u = extractMin(dist, visited);  // get minimum distance vertex
        if (u == -1)
            break;
        visited[u] = 1;  // mark as visited
        // update distances of adjacent vertices
        for (int j = 0; j < V; j++)
        {
            if (graph[u][j] > 0 && !visited[j])
            {
                // check if shorter path is found
                if (dist[j] > dist[u] + graph[u][j])
                {
                    dist[j] = dist[u] + graph[u][j];
                }
            }
        }
    }
    // print shortest distances
    printf("\nVertex \t Distance from Source (0)\n");
    for (int i = 0; i < V; i++)
    {
        printf("%d --> %d\n", i, dist[i]);
    }
}
int main()
{
    // adjacency matrix representation of graph
    int graph[V][V] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };
    // call dijkstra function
    dijkstra(graph);
    return 0;  // end of program
}
