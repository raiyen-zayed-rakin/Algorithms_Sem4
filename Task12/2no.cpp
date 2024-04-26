/*
Write a program to find the shortest path from a single source to a destination node for a graph using Bellman-Ford algorithm. 
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include<numeric>
#include<limits.h>
using namespace std;

// class to represent an edge in the graph
class Edge {
    public:
    int src, dest, weight;
};


// Function to find the shortest path from a single source to a destination node using Bellman-Ford algorithm
vector<int> bellmanFord(vector<Edge>& edges, int src, int dest, int n) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (const auto& edge : edges) {
            int u = edge.src;
            int v = edge.dest;
            int weight = edge.weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    return dist;
}



int main() {
    // Example usage
    vector<vector<pair<int, int>>> graph = {
        {{1, 4}, {7, 8}},
        {{0, 4}, {2, 8}, {7, 11}},
        {{1, 8}, {3, 7}, {5, 4}, {8, 2}},
        {{2, 7}, {4, 9}, {5, 14}},
        {{3, 9}, {5, 10}},
        {{2, 4}, {3, 14}, {4, 10}, {6, 2}},
        {{5, 2}, {7, 1}, {8, 6}},
        {{0, 8}, {1, 11}, {6, 1}, {8, 7}},
        {{2, 2}, {6, 6}, {7, 7}}
    };

    vector<Edge> edges = {
        {0, 1, 4}, {0, 7, 8}, {1, 0, 4}, {1, 2, 8}, {1, 7, 11},
        {2, 1, 8}, {2, 3, 7}, {2, 5, 4}, {2, 8, 2}, {3, 2, 7},
        {3, 4, 9}, {3, 5, 14}, {4, 3, 9}, {4, 5, 10}, {5, 2, 4},
        {5, 3, 14}, {5, 4, 10}, {5, 6, 2}, {6, 5, 2}, {6, 7, 1},
        {6, 8, 6}, {7, 0, 8}, {7, 1, 11}, {7, 6, 1}, {7, 8, 7},
        {8, 2, 2}, {8, 6, 6}, {8, 7, 7}
    };

    
    // Bellman-Ford algorithm
    vector<int> bellmanDist = bellmanFord(edges, 0, 4, 9);
    cout << "Shortest Path using Bellman-Ford Algorithm: ";
    for (int distance : bellmanDist) {
        cout << distance << " ";
    }
    cout << endl;

    return 0;
}
