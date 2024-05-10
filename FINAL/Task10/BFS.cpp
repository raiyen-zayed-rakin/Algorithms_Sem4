#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm> // Include the algorithm header for reverse

using namespace std;

// Function to perform BFS traversal and find the path from source to destination
vector<char> findPathBFS(vector<vector<int>>& graph, int source, int destination, const vector<char>& vertices) {
    int V = graph.size();
    vector<bool> visited(V, false);
    vector<int> parent(V, -1);
    queue<int> q;
    vector<char> path;

    visited[source] = true;
    q.push(source);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == destination) {
            // Build path from destination to source
            while (parent[u] != -1) {
                path.push_back(vertices[u]);
                u = parent[u];
            }
            path.push_back(vertices[source]); // Add source to path
            reverse(path.begin(), path.end()); // Reverse path to get source to destination
            return path;
        }

        for (int v = 0; v < V; ++v) {
            if (graph[u][v] && !visited[v]) {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    return path; // If no path is found
}

int main() {
    int numVertices;
    cout << "Enter the number of vertices in the graph: ";
    cin >> numVertices;

    // Vector to store vertex labels
    vector<char> vertices(numVertices);

    // Input vertex labels
    cout << "Enter the labels for the vertices (A to K):" << endl;
    for (int i = 0; i < numVertices; ++i) {
        cin >> vertices[i];
    }

    // Create a 2D vector to represent the graph
    vector<vector<int>> graph(numVertices, vector<int>(numVertices, 0));

    // Input the adjacency matrix of the graph
    cout << "Enter the adjacency matrix of the graph (0 for no edge, 1 for an edge):" << endl;
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            cin >> graph[i][j];
        }
    }

    // Display adjacency matrix
    cout << "Adjacency Matrix of the Graph:" << endl;
    for (const auto& row : graph) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Find path from vertex A to vertex J
    vector<char> path = findPathBFS(graph, 0, numVertices - 1, vertices);

    // Display path
    cout << "Path from A to J: ";
    if (!path.empty()) {
        for (char vertex : path) {
            cout << vertex << " ";
        }
    } else {
        cout << "No path found.";
    }
    cout << endl;

    return 0;
}
