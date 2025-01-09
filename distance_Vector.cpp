#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Router {
    vector<int> distance;
    vector<int> nextHop;
};

void distanceVectorRouting(vector<vector<int>>& graph, int n) {
    vector<Router> routers(n);

    // Initialize distances and next hops
    for (int i = 0; i < n; i++) {
        routers[i].distance.resize(n, INT_MAX);
        routers[i].nextHop.resize(n, -1);
        for (int j = 0; j < n; j++) {
            if (graph[i][j] != INT_MAX) {
                routers[i].distance[j] = graph[i][j];
                routers[i].nextHop[j] = j;
            }
        }
        routers[i].distance[i] = 0;
        routers[i].nextHop[i] = i;
    }

    bool updated;
    do {
        updated = false;

        for (int i = 0; i < n; i++) { // For each router
            for (int j = 0; j < n; j++) { // For each destination
                for (int k = 0; k < n; k++) { // Check neighbors
                    if (routers[i].distance[k] != INT_MAX && graph[k][j] != INT_MAX) {
                        int newDist = routers[i].distance[k] + graph[k][j];
                        if (newDist < routers[i].distance[j]) {
                            routers[i].distance[j] = newDist;
                            routers[i].nextHop[j] = routers[i].nextHop[k];
                            updated = true;
                        }
                    }
                }
            }
        }
    } while (updated);

    // Display the distance vectors
    for (int i = 0; i < n; i++) {
        cout << "Router " << i << " Distance Vector:\n";
        for (int j = 0; j < n; j++) {
            if (routers[i].distance[j] == INT_MAX) {
                cout << "To " << j << " -> No Path\n";
            } else {
                cout << "To " << j << " -> Distance: " << routers[i].distance[j]
                     << ", Next Hop: " << routers[i].nextHop[j] << "\n";
            }
        }
        cout << "\n";
    }
}

int main() {
    int n;
    cout << "Enter the number of routers: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n, INT_MAX));

    cout << "Enter the cost matrix (use -1 for no direct connection):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cost;
            cin >> cost;
            if (cost >= 0) {
                graph[i][j] = cost;
            }
        }
    }

    distanceVectorRouting(graph, n);

    return 0;
}
