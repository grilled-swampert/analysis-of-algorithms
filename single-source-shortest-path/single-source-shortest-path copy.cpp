#include <iostream>
#include <vector>
#include <chrono> 
#include <fstream> 
using namespace std;
using namespace std::chrono;

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
        S[u] = true;
        for (int w = 0; w < n; w++) {
            if (dist[w] > dist[u] + cost[u][w]) {
                dist[w] = dist[u] + cost[u][w];
            }
        }
    }
    return dist;
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;
    
    vector<vector<int>> cost(n, vector<int>(n, INT_MAX));

    for (int i = 0; i < n; i++) {
        cost[i][i] = 0;
    }

    cout << "NOTE: IF YOU WISH TO INPUT INFINITY, ENTER '-1'" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Enter the costs for row " << i + 1 << ": ";
        for (int j = 0; j < n; j++) {
            int c;
            cin >> c;
            if (c == -1) {
                c = INT_MAX;
            }
            cost[i][j] = c;
        }
    }

    cout << "Cost matrix: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << cost[i][j] << " ";
        }
        cout << endl;
    }

    int v;
    cout << "Enter the source vertex: ";
    cin >> v;

    clock_t start = clock();
    vector<int> shortestDistances = shortestPaths(v, n, cost);

    cout << "Shortest distances from vertex " << v + 1 << ": " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i + 1 << ": " << shortestDistances[i] << endl;
    }

    clock_t end = clock();
    double timeTaken = double(end - start) / CLOCKS_PER_SEC;

    cout << "Time taken by the algorithm: " << timeTaken << " milliseconds" << endl;

    ofstream outputFile("time_taken.txt", ios::app);
    if (outputFile.is_open()) {
        outputFile << "Vertices: " << n << ", Time taken: " << timeTaken << " milliseconds" << endl;
        outputFile.close();
    } else {
        cout << "Unable to open file." << endl;
    }

    return 0;
}
