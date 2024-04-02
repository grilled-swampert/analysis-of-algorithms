#include <iostream>
#include <vector>

using namespace std;

vector<int> x(100, 0); 

bool isSafe(int board[100][100], int row, int col, int n) {
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (int i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQUtil(int board[100][100], int col, int n) {
    if (col >= n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
        cout << "-----------------" << endl; 
        return true; 
    }

    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1;
            solveNQUtil(board, col + 1, n);

            board[i][col] = 0; 
        }
    }

    return false; 
}

void solveNQ(int n) {
    int board[100][100] = {0};

    solveNQUtil(board, 0, n);
}

int main() {
    int n = 12; 
    solveNQ(n);
    return 0;
}
