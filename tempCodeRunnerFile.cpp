#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void dijkstra(int n, vector<vector<int>>& graph, int s) {
    vector<int> smallestdistance(n, INT_MAX);
    vector<bool> visited(n, false);

    smallestdistance[s] = 0;

    for (int row = 0; row < n; row++) {
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && (u == -1 || smallestdistance[i] < smallestdistance[u])) {
                u = i;
            }
        }

        if (u == -1) break; // All reachable vertices are visited.

        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !visited[v] && smallestdistance[u] != INT_MAX 
                && smallestdistance[u] + graph[u][v] < smallestdistance[v]) {
                smallestdistance[v] = smallestdistance[u] + graph[u][v];
            }
        }
    }

    cout << "Vertex\tDistance from Source" << endl;
    for (int i = 0; i < n; i++) {
        cout << i << "\t" << smallestdistance[i] << endl;
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n)); // Initialize 2D vector correctly.

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    int src = 0;
    dijkstra(n, v, src);

    return 0;
}
