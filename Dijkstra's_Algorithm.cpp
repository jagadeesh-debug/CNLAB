#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void dijkstra(int n, vector<vector<int>> &graph, int src)
{
    int dist[n]; 
    bool visited[n];
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    dist[src] = 0; 
    for (int count = 0; count < n - 1; count++)
    {
        int u = -1;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && (u == -1 || dist[i] < dist[u]))
            {
                u = i;
            }
        }
        visited[u] = true;
        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] && !visited[v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    cout << "Vertex\tDistance from Source" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << "\t" << dist[i] << endl;
    }
}

int main()
{
    int n = 5; 
    vector<vector<int>> graph = {
        {0, 10, 0, 0, 5},
        {0, 0, 1, 0, 2},
        {0, 0, 0, 4, 0},
        {7, 0, 6, 0, 0},
        {0, 3, 9, 2, 0}};
    int src = 0; 
    dijkstra(n, graph, src);
    return 0;
}
