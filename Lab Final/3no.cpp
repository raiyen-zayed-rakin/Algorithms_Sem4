#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm> 

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

    vector<char> vertices(numVertices);

    cout << "Enter the labels for the vertices:" << endl;
    for (int i = 0; i < numVertices; ++i) {
        cin >> vertices[i];
    }

    vector<vector<int>> graph(numVertices, vector<int>(numVertices, 0));

    cout << "Enter the adjacency matrix of the graph (0 for no edge, 1 for an edge):" << endl;
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            cin >> graph[i][j];
        }
    }

    // Display adjacency matrix
    cout << "Adjacency Matrix of the Graph:" << endl;
    cout << "  ";
    for (int i = 0; i < numVertices; ++i) {
        cout << vertices[i] << " ";
    }
    cout << endl;

    // Display matrix elements with row labels
    for (int i = 0; i < numVertices; ++i) {
        cout << vertices[i] << " ";
        for (int j = 0; j < numVertices; ++j) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    char sourceVertex, destinationVertex;
    cout << "Enter the source vertex (A to K): ";
    cin >> sourceVertex;
    cout << "Enter the destination vertex (A to K): ";
    cin >> destinationVertex;

    int sourceIndex = -1, destinationIndex = -1;
    for (int i = 0; i < numVertices; ++i) {
        if (vertices[i] == sourceVertex) {
            sourceIndex = i;
        }
        if (vertices[i] == destinationVertex) {
            destinationIndex = i;
        }
    }

    if (sourceIndex == -1 || destinationIndex == -1) {
        cout << "Invalid source or destination vertex entered. Please enter valid vertices." << endl;
        return 1;
    }

    // Find path using BFS
    vector<char> path = findPathBFS(graph, sourceIndex, destinationIndex, vertices);

    // Show path
    cout << "Path from " << sourceVertex << " to " << destinationVertex << ": ";
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
