#include <iostream>
#include <vector>

using namespace std;

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

bool solveNQUtil(int board[100][100], int col, int n, vector<int>& positions, int& count) {
    if (col >= n) {
        //for (int i = 0; i < n; i++) {
        //    cout << positions[i] << " ";
        //}
        cout << endl;
        count++;
        return true; 
    }

    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1;
            positions[col] = i+1; 

            solveNQUtil(board, col + 1, n, positions, count);
            board[i][col] = 0; 
        }
    }
    return false;
}

void solveNQ(int n, int& count) {
    int board[100][100] = {0};
    vector<int> positions(n, -1); 

    solveNQUtil(board, 0, n, positions, count);
}

int main() {
    int n = 6; 
    int count = 0;
    solveNQ(n, count);
    cout << "Number of solutions: " << count << endl;
    return 0; 
}
