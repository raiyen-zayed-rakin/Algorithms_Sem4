/*
Write a program to find the shortest path from a single source to a destination node for a graph using dijkstra's algorithm. 
*/
#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>
using namespace std;

// Number of vertices in the graph
#define V 2048 

// The main function that implements Dijkstra's algorithm
int dijkstra(vector<vector<int>> graph,int V, int src, int dest) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    vector<bool> visited(V, false);
    vector<int> parent(V, -1);
    queue<pair<int, int>> pq;
    pq.push(make_pair(0, src));

    while (!pq.empty()) {
        int u = pq.front().second;
        pq.pop();

        if (visited[u])
            continue;

        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 && !visited[v]) {
                if (dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                    pq.push(make_pair(dist[v], v));
                    parent[v] = u;
                }
            }
        }
    }

    return dist[V - 1];
}

int main() {
    int e, i, u, v, w;
    cout << "Enter the number of vertices: ";
    cin >> e;
    vector<vector<int>> graph(e, vector<int>(e, 0));

    cout << "Enter the number of edges: ";
    cin >> e;

    cout << "Enter the edges (u, v, w):\n";
    for (i = 0; i < e; i++) {
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int src = 0;
    int result = dijkstra(graph, src, e);

    cout << "The shortest distance from vertex " << src << " to vertex " << e - 1 << " is: " << result << endl;

    return 0;
}