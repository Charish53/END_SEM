#include <bits/stdc++.h>
using namespace std;


// Function to find the shortest cycle in the graph
int findShortestCycle(vector<vector<int>>& graph, int V) {
    for (int start = 0; start < V; start++) {
        vector<int> dist(V, -1);
        queue<int> q;
        q.push(start);
        dist[start] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : graph[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                } else if (v != start) {
                    // If v is not the starting vertex and is reachable from u, a cycle is found.
                    return dist[v] + dist[u] + 1;
                }
            }
        }
    }
    return -1; // No cycle found
}

int main() {
    int V, E;
    cin >> V >> E; // Number of vertices (V) and edges (E)

    vector<vector<int>> graph(V);
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        //addEdge(graph, u, v);
    }

    int shortestCycleLength = findShortestCycle(graph, V);
    
    if (shortestCycleLength == -1) {
        cout << "No cycle found in the graph." << endl;
    } else {
        cout << "Length of the shortest cycle: " << shortestCycleLength << endl;
    }

    return 0;
}
