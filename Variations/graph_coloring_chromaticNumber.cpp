#include <iostream>
#include <vector>

using namespace std;

// Safety check: Are any adjacent nodes sharing color 'c'?
bool isSafe(int v, const vector<vector<int>>& graph, const vector<int>& color, int c) {
    for (int i = 0; i < graph.size(); i++) {
        if (graph[v][i] == 1 && c == color[i]) {
            return false;
        }
    }
    return true;
}

// Backtracking utility
bool graphColoringUtil(const vector<vector<int>>& graph, int m, vector<int>& color, int v) {
    if (v == graph.size()) {
        return true;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c; 

            if (graphColoringUtil(graph, m, color, v + 1)) {
                return true;
            }

            color[v] = 0; // Backtrack
        }
    }
    return false;
}

int main() {
    // Adjacency matrix representation
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };
    
    int V = graph.size();
    vector<int> color(V, 0);
    
    cout << "--- Graph Colouring: Chromatic Number ---\n";

    int m = 1; // Start by trying to color it with just 1 color
    
    // Increment 'm' until the graph can be successfully colored
    while (!graphColoringUtil(graph, m, color, 0)) {
        m++; 
        fill(color.begin(), color.end(), 0); // Reset color array for the next attempt
    }

    cout << "The Chromatic Number is: " << m << "\n";
    cout << "Color assignments for minimum colors:\n";
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << " -> Color " << color[i] << "\n";
    }

    return 0;
}