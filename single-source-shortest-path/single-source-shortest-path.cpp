#include <iostream>
#include <vector>  
using namespace std;

#define INT_MAX 1000000

vector<int> shortestPaths(int v, int n, vector<vector<int>>& cost) {
    vector<bool> S(n, false);
    vector<int> dist(n, INT_MAX);
    dist[v] = 0;
    
    for (int num = 1; num < n; num++) {
        int u = -5;
        for (int i = 0; i < n; i++) {
            if (!S[i] && (u == -5 || dist[i] < dist[u])) {
                u = i;
            }
        }
        //S[u] = true;
        for (int w = 0; w < n; w++) {
            if (dist[w] > dist[u] + cost[u][w]) {
                dist[w] = dist[u] + cost[u][w];
            }
        }
    }
    return dist;
}

int main() {
    int n = 5;
    
    vector<vector<int>> cost = {
        {0,  2,  5,  6, INT_MAX},
        {INT_MAX,  0,  1,  2, INT_MAX},
        {INT_MAX, INT_MAX,  0, INT_MAX,  2},
        {INT_MAX, INT_MAX, INT_MAX,  0,  3},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX,  0}
    };
    
    int v;
    cout << "Enter the source vertex: ";
    cin >> v; 
    
    vector<int> shortestDistances = shortestPaths(v, n, cost);
    
    cout << "Shortest distances from vertex " << v << ": " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i+1 << ": " << shortestDistances[i] << endl;
    }
    return 0;
}
