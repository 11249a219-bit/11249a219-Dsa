#include <stdio.h>
#include <limits.h>
#define MAXN 15          // maximum number of cities
#define INF INT_MAX      // representing infinity
int n;                  // number of cities
int d[MAXN][MAXN];     // cost matrix
int dp[MAXN][1 << MAXN]; // dp table for memoization
// Function to calculate minimum travelling cost
int g(int i, int s) {
    // If no cities left to visit, return cost to go back to starting city
    if (s == 0)
        return d[i][0];
    // If already calculated, return stored value
    if (dp[i][s] != -1)
        return dp[i][s];
    int min_cost = INF;
    // Try visiting all remaining cities
    for (int k = 0; k < n; k++) {
        // Check if city k is in the set s
        if (s & (1 << k))
        {
            // calculate cost of visiting k and remaining cities
            int cost = d[i][k] + g(k, s & ~(1 << k));
            // update minimum cost
            if (cost < min_cost)
                min_cost = cost;
        }
    }
    // store result in dp table and return
    return dp[i][s] = min_cost;
}
int main() {
    // taking number of cities as input
    printf("Enter the number of cities: ");
    scanf("%d", &n);
    // taking cost matrix input
    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &d[i][j]);
        }
    }
    // initialize dp table with -1
    for (int i = 0; i < n; i++)
    {
        for (int s = 0; s < (1 << n); s++)
        {
            dp[i][s] = -1;
        }
    }
    int s = 0;  
    // create set of cities except starting city (0)
    for (int i = 1; i < n; i++) {
        s |= (1 << i);
    }
    printf("S value is: %d\n", s);
    // call function starting from city 0
    int result = g(0, s);
    // print minimum travelling cost
    printf("Minimum travelling cost: %d\n", result);
    return 0;  // end of program
}
