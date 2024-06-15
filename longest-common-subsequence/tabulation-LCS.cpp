#include <iostream>
#include <vector>
#include <string>

using namespace std;

pair<int, vector<vector<string>>> LCS_LENGTH(const string& X, const string& Y) {
    int m = X.length();
    int n = Y.length();
    vector<vector<int>> c(m + 1, vector<int>(n + 1, 0));
    vector<vector<string>> b(m + 1, vector<string>(n + 1, ""));

    cout << "  ";
    for (char ch : Y) {
        cout << ch << " ";
    }
    cout << endl;

    for (int i = 1; i <= m; ++i) {
        cout << X[i - 1] << " "; 
        for (int j = 1; j <= n; ++j) {
            if (X[i - 1] == Y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = "o"; 
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = "^"; 
            } else {
                c[i][j] = c[i][j - 1];
                b[i][j] = "<"; 
            }
            cout << c[i][j] << " "; 
        }
        cout << endl;
    }

    cout << "\nMatrix b:" << endl;
    cout << "  ";
    for (char ch : Y) {
        cout << ch << " ";
    }
    cout << endl;
    for (int i = 1; i <= m; ++i) {
        cout << X[i - 1] << " "; 
        for (int j = 1; j <= n; ++j) {
            cout << b[i][j] << " "; 
        }
        cout << endl;
    }

    return make_pair(c[m][n], b);
}

string PRINT_LCS(const vector<vector<string>>& b, const string& X, int i, int j) {
    if (i == 0 || j == 0) {
        return "";
    }
    if (b[i][j] == "o") {
        return PRINT_LCS(b, X, i - 1, j - 1) + X[i - 1];
    } else if (b[i][j] == "^") {
        return PRINT_LCS(b, X, i - 1, j);
    } else {
        return PRINT_LCS(b, X, i, j - 1);
    }
}

int main() {
    string X = "MAVERICK";
    string Y = "TITANIC";

    auto result = LCS_LENGTH(X, Y);
    int length = result.first;
    vector<vector<string>> b_table = result.second;

    cout << "\nLength of Longest Common Subsequence: " << length << endl;
    cout << "Longest Common Subsequence: " << PRINT_LCS(b_table, X, X.length(), Y.length()) << endl;

    return 0;
}
