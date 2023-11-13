#include <bits/stdc++.h>
using namespace std;

bool isBipartite(const unordered_map<int, vector<int>>& graph) {
    unordered_set<int> setA, setB;
    unordered_map<int, bool> visited;

    for (const auto& entry : graph) {
        int vertex = entry.first;

        if (!visited.count(vertex) && (setA.empty() || setB.empty())) {
            // Initialize the first vertex in set A
            setA.insert(vertex);
            visited[vertex] = true;
        }

        for (const int neighbor : graph.at(vertex)) {
            if (!visited.count(neighbor)) {
                // If the current vertex is in set A, add the neighbor to set B, and vice versa
                if (setA.count(vertex)) {
                    setB.insert(neighbor);
                } else {
                    setA.insert(neighbor);
                }
                visited[neighbor] = true;
            } else {
                // If the neighbor is in the same set as the current vertex, the graph is not bipartite
                if ((setA.count(vertex) && setA.count(neighbor)) || (setB.count(vertex) && setB.count(neighbor))){
                    return false;
                }
            }
        }
    }

    return true;
}

int main() {
    int v, e;  // Number of vertices and edges
    cout << "Enter the number of vertices: ";
    cin >> v;
    cout << "Enter the number of edges: ";
    cin >> e;

    unordered_map<int, vector<int>> graph;

    for (int i = 0; i < e; ++i) {
        int u, v;  // Edge (u, v)
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);  // Assuming an undirected graph
    }

    if (isBipartite(graph)) {
        cout << "It is a bipartite graph" << endl;
    } else {
        cout << "It is not a bipartite graph" << endl;
    }

    return 0;
}
