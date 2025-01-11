#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int tsp(vector<vector<int>> &graph, int pos, int visited, vector<vector<int>> &dp)
{
    int n = graph.size();
    if (visited == (1 << n) - 1)
        return graph[pos][0]; // Return to starting point
    if (dp[pos][visited] != -1)
        return dp[pos][visited];
    int minCost = INT_MAX;
    for (int city = 0; city < n; city++)
    {
        if (!(visited & (1 << city)))
        {
            int cost = graph[pos][city] + tsp(graph, city, visited | (1 << city), dp);
            minCost = min(minCost, cost);
        }
    }
    return dp[pos][visited] = minCost;
}
int main()
{
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}};
    int n = graph.size();
    vector<vector<int>> dp(n, vector<int>(1 << n, -1));
    cout << "Minimum cost of TSP: " << tsp(graph, 0, 1, dp) << endl;
    return 0;
}