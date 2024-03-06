#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct MatrixChainResult {
    vector<vector<int>> minimum_cost;
    vector<vector<int>> optimal_solution;
    vector<vector<int>> partition;
};

MatrixChainResult matrix_chain_order(const vector<int>& p) {
    int n = p.size() - 1;
    vector<vector<int>> minimum_cost(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> optimal_solution(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> partition(n + 1, vector<int>(n + 1, 0));

    for (int l = 2; l <= n; ++l) {
        for (int i = 1; i <= n - l + 1; ++i) {
            int j = i + l - 1;
            minimum_cost[i][j] = numeric_limits<int>::max();
            for (int x = i; x < j; ++x) {
                int q = minimum_cost[i][x] + minimum_cost[x + 1][j] + p[i - 1] * p[x] * p[j];
                if (q < minimum_cost[i][j]) {
                    minimum_cost[i][j] = q;
                    optimal_solution[i][j] = x;
                    partition[i][j] = x;
                }
            }
        }
    }

    return {minimum_cost, optimal_solution, partition};
}

void print_optimal_parenthesization(const vector<vector<int>>& minimum_cost, int i, int j) {
    if (i == j) {
        cout << "A" << i;
    } else {
        cout << "(";
        print_optimal_parenthesization(minimum_cost, i, minimum_cost[i][j]);
        print_optimal_parenthesization(minimum_cost, minimum_cost[i][j] + 1, j);
        cout << ")";
    }
}

int main() {
    vector<int> matrix_sizes = {4, 10, 3, 12, 20};
    MatrixChainResult result = matrix_chain_order(matrix_sizes);
    vector<vector<int>> minimum_cost = result.minimum_cost;
    vector<vector<int>> optimal_solution = result.optimal_solution;
    vector<vector<int>> partition = result.partition;

    cout << "Optimal parenthesization: ";
    print_optimal_parenthesization(partition, 1, matrix_sizes.size() - 1);
    cout << endl << endl;

    cout << "Partition Matrix:" << endl;
    for (int i = 1; i < partition.size(); ++i) {
        for (int j = 1; j < partition[i].size(); ++j) {
            cout << partition[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    cout << "Minimum Cost Matrix:" << endl;
    for (int i = 1; i < minimum_cost.size(); ++i) {
        for (int j = 1; j < minimum_cost[i].size(); ++j) {
            cout << minimum_cost[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

