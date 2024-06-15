#include <iostream>
using namespace std;

int lcs(string str01, string str02, int m, int n) {
    if (m == 0 || n == 0)
        return 0;
    if (str01[m - 1] == str02[n - 1])
        return 1 + lcs(str01, str02, m - 1, n - 1);
    else
        return max(lcs(str01, str02, m, n - 1), lcs(str01, str02, m - 1, n));
}

int main() {
    string str01 = "MINIMUM";
    string str02 = "MAXIMUM";
    int m = str01.size();
    int n = str02.size();

    cout << "Length of LCS is " << lcs(str01, str02, m, n);	
    return 0;
}
