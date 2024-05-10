#include <iostream>
#include <vector>
using namespace std;

const int MAX = 10;

//print-adj-matrix
void printAdjacencyMatrix(int graph[MAX][MAX], int V) {
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

//print-adj-list
void printAdjacencyList(vector<vector<int>>& adjList) {
    cout << "Adjacency List:" << endl;
    for (int i = 0; i < adjList.size(); i++) {
        cout << i << " -> ";
        for (int j = 0; j < adjList[i].size(); j++) {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }
}

//print-weighted-adj-matrix
void printWeightedAdjacencyMatrix(int graph[MAX][MAX], int V) {
    cout << "Weighted Adjacency Matrix:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

//print-weighted-adj-list
void printWeightedAdjacencyList(vector<vector<vector<int>>>& adjList) {
    cout << "Weighted Adjacency List:" << endl;
    for (int i = 0; i < adjList.size(); i++) {
        cout << i << " -> ";
        for (int j = 0; j < adjList[i].size(); j++) {
            cout << adjList[i][j][0] << "(" << adjList[i][j][1] << ") ";
        }
        cout << endl;
    }
}

void Graphs() {
    // Directed graph adjacency matrix
    int graphDirected[MAX][MAX] = {
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 0, 0}
    };

    vector<vector<int>> adjListDirected = {{1}, {2}, {0, 2}, {2, 4}, {0}};

    // Weighted directed graph adjacency matrix
    int graphWeightedDirected[MAX][MAX] = {
        {0, 10, 0, 0, 0},
        {0, 0, 5, 0, 0},
        {0, 0, 0, 10, 0},
        {0, 0, 5, 0, 20},
        {20, 0, 0, 0, 0}
    };

    vector<vector<vector<int>>> adjListWeightedDirected = {{{1, 10}}, {{2, 5}}, {{3, 10}}, {{2, 5}, {4, 20}}, {{0, 20}}};

    // Undirected graph adjacency matrix
    int graphUndirected[MAX][MAX] = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}
    };

    vector<vector<int>> adjListUndirected = {{1, 4}, {0, 2}, {1, 3}, {2, 4}, {0, 3}};

    // Weighted undirected adjacency matrix
    int graphWeightedUndirected[MAX][MAX] = {
        {0, 1, 0, 0, 20},
        {1, 0, 5, 0, 0},
        {0, 5, 0, 10, 0},
        {0, 0, 10, 0, 1},
        {20, 0, 0, 1, 0}
    };

    vector<vector<vector<int>>> adjListWeightedUndirected = {{{1, 1}, {4, 20}}, {{0, 1}, {2, 5}}, {{1, 5}, {3, 10}}, {{2, 10}, {4, 1}}, {{0, 20}, {3, 1}}};

    int V = 5;

    printAdjacencyMatrix(graphDirected, V);
    printAdjacencyList(adjListDirected);
    printWeightedAdjacencyMatrix(graphWeightedDirected, V);
    printWeightedAdjacencyList(adjListWeightedDirected);

    // Print undirected representations
    printAdjacencyMatrix(graphUndirected, V);
    printAdjacencyList(adjListUndirected);
    printWeightedAdjacencyMatrix(graphWeightedUndirected, V);
    printWeightedAdjacencyList(adjListWeightedUndirected);
}

int main() {
    Graphs();
    return 0;
}
