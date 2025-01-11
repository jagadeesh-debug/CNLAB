#include <bits/stdc++.h>
using namespace std;

void shortestPath(vector<vector<int>> &graph)
{
    vector<vector<int>> dist = graph;
    int n = graph.size();
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == INT_MAX)
            {
                cout << "INFINITY ";
            }
            else
            {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}
int main()
{
    vector<vector<int>> graph = {
        {0, 3, INT_MAX, 5},
        {2, 0, INT_MAX, 4},
        {INT_MAX, 1, 0, INT_MAX},
        {INT_MAX, INT_MAX, 2, 0}};
        shortestPath(graph);
    return 0;
}
