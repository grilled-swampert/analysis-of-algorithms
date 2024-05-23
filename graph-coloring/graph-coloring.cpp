#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>>& graph, vector<int>& color, int v, int c) {
    for (int i = 0; i < graph[v].size(); i++) {
        if (graph[v][i] == 1 && color[i] == c) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(vector<vector<int>>& graph, int m, vector<int>& color, int v) {
    if (v == graph.size()) {
        for (int i = 0; i < graph.size(); i++) {
            cout << color[i] << " ";
        }
        cout << endl;
        return true; 
    }
    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, color, v, c)) {
            color[v] = c;

            if (graphColoringUtil(graph, m, color, v + 1)) {
                // Found a valid coloring, continue searching
            }

            color[v] = 0; 
        }
    }
    return false;
}

void graphColoring(vector<vector<int>>& graph, int m) {
    int V = graph.size();
    vector<int> color(V, 0);

    graphColoringUtil(graph, m, color, 0);
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V, 0)); 

    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    int m; 
    cout << "Enter the number of colors: ";
    cin >> m;

    graphColoring(graph, m);
    return 0;
}
