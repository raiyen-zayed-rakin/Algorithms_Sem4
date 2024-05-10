#include <iostream>
#include <vector>
#include <algorithm>
#include<numeric>
#include<limits.h>
using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Function to find the shortest path from a single source to a destination node using Dijkstra's algorithm
vector<int> dijkstra(vector<vector<pair<int, int>>>& graph, int src, int dest) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);
    dist[src] = 0;

    for (int i = 0; i < n - 1; ++i) {
        int u = -1;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u]))
                u = j;
        }
        if (dist[u] == INT_MAX)
            break;
        visited[u] = true;
        for (auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (!visited[v] && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }
    return dist;
}

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

// Function to find the MST of a graph using Prim's algorithm
vector<pair<int, int>> primMST(vector<vector<pair<int, int>>>& graph) {
    int n = graph.size();
    vector<pair<int, int>> mst;
    vector<bool> visited(n, false);
    vector<int> key(n, INT_MAX);
    vector<int> parent(n, -1);

    key[0] = 0;

    for (int i = 0; i < n - 1; ++i) {
        int u = -1;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && (u == -1 || key[j] < key[u]))
                u = j;
        }

        visited[u] = true;

        for (auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (!visited[v] && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
            }
        }
    }

    for (int i = 1; i < n; ++i) {
        mst.push_back({parent[i], i});
    }

    return mst;
}

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

// Function to implement the concept of 0/1 Knapsack
int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
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

    // Dijkstra's algorithm
    vector<int> shortestPath = dijkstra(graph, 0, 4);
    cout << "Shortest Path using Dijkstra's Algorithm: ";
    for (int distance : shortestPath) {
        cout << distance << " ";
    }
    cout << endl;

    // Bellman-Ford algorithm
    vector<int> bellmanDist = bellmanFord(edges, 0, 4, 9);
    cout << "Shortest Path using Bellman-Ford Algorithm: ";
    for (int distance : bellmanDist) {
        cout << distance << " ";
    }
    cout << endl;

    // Prim's algorithm
    vector<pair<int, int>> primResult = primMST(graph);
    cout << "Minimum Spanning Tree using Prim's Algorithm:\n";
    for (const auto& edge : primResult) {
        cout << edge.first << " - " << edge.second << endl;
    }

    // Kruskal's algorithm
    vector<pair<int, int>> kruskalResult = kruskalMST(edges, 9);
    cout << "Minimum Spanning Tree using Kruskal's Algorithm:\n";
    for (const auto& edge : kruskalResult) {
        cout << edge.first << " - " << edge.second << endl;
    }

    // 0/1 Knapsack
    int knapWeight = 10;
    vector<int> knapValues = {60, 100, 120};
    vector<int> knapWeights = {10, 20, 30};
    int knapsackValue = knapsack(knapWeight, knapWeights, knapValues, 3);
    cout << "Maximum value for 0/1 Knapsack with weight " << knapWeight << ": " << knapsackValue << endl;

    return 0;
}
