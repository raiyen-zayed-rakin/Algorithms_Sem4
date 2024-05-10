/*
Write a program to find MST of a graph using Kruskal's algorithm.
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

// Function to find the MST of a graph using Kruskal's algorithm
vector<pair<int, int>> kruskalMST(vector<Edge>& edges, int n) {
    vector<pair<int, int>> mst;
    // Sorting edges by weight
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    vector<int> parent(n);
    iota(parent.begin(), parent.end(), 0);

    auto find = [&](int u) {
        while (u != parent[u]) {
            parent[u] = parent[parent[u]];
            u = parent[u];
        }
        return u;
    };

    auto unite = [&](int u, int v) {
        int pu = find(u);
        int pv = find(v);
        parent[pv] = pu;
    };

    for (const auto& edge : edges) {
        int u = edge.src;
        int v = edge.dest;
        int pu = find(u);
        int pv = find(v);
        if (pu != pv) {
            mst.push_back({u, v});
            unite(pu, pv);
        }
    }

    return mst;
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

    

    
    // Kruskal's algorithm
    vector<pair<int, int>> kruskalResult = kruskalMST(edges, 9);
    cout << "Minimum Spanning Tree using Kruskal's Algorithm:\n";
    for (const auto& edge : kruskalResult) {
        cout << edge.first << " - " << edge.second << endl;
    }

  
    return 0;
}