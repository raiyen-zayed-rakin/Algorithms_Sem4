#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm> 

using namespace std;

vector<char> findPathBFS(vector<vector<int>>& graph, int source, int destination, const vector<char>& vertices) {
    int V = graph.size();
    vector<bool> visited(V, false);
    vector<int> parent(V, -1);
    queue<int> q;
    vector<char> path;

    visited[source] = true;
    q.push(source);
    
    cout << "Visited vertices: ";
    while (!q.empty()) {
        queue<int> temp = q;
        while (!temp.empty()) {
            cout << vertices[temp.front()] << " ";
            temp.pop();
        }
        cout << endl;

        int u = q.front();
        q.pop();

        if (u == destination) {
            while (parent[u] != -1) {
                path.push_back(vertices[u]);
                u = parent[u];
            }
            path.push_back(vertices[source]); 
            reverse(path.begin(), path.end()); 
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

    return path; 
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

    cout << "Adjacency Matrix of the Graph:" << endl;
    for (const auto& row : graph) {
        for (int val : row) {
            cout << val << " ";
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
    // Display adjacency matrix with row and column labels
    cout << "Adjacency Matrix of the Graph:" << endl;
    // Display column labels
    cout << "  ";
    for (int i = 0; i < numVertices; ++i) {
        cout << vertices[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < numVertices; ++i) {
        cout << vertices[i] << " ";
        for (int j = 0; j < numVertices; ++j) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    //PATH
    vector<char> path = findPathBFS(graph, sourceIndex, destinationIndex, vertices);

    //show
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
