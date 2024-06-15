#include <iostream>
using namespace std;

const int maximum = 1000;

void printDP(int dp[][maximum], int m, int n) {
    cout << "DP Array:\n";
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
}

int lcs(string str01, string str02, int m, int n, int dp[][maximum]) {
    if (m == 0 || n == 0)
        return 0;

    if (dp[m - 1][n - 1] != 0)
        return dp[m - 1][n - 1];

    if (str01[m - 1] == str02[n - 1]) {
        dp[m - 1][n - 1] = 1 + lcs(str01, str02, m - 1, n - 1, dp);
        return dp[m - 1][n - 1];
    } else {
        dp[m - 1][n - 1] = max(lcs(str01, str02, m, n - 1, dp),
                               lcs(str01, str02, m - 1, n, dp));
        return dp[m - 1][n - 1];
    }
}

int main() {
    string str01 = "MINIMUM";
    string str02 = "MAXIMUM";
    int m = str01.length();
    int n = str02.length();

    int dp[m][maximum];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = 0;

    cout << "Length of LCS: " << lcs(str01, str02, m, n, dp) << "\n";

    printDP(dp, m, n);
    return 0;
}
