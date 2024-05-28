#include <iostream>
#include <vector>
using namespace std;

void sum_of_subsets(int s, int k, int r, int m, vector<int> &w, vector<int> &x) { 
    // s: current sum, k: current index, r: remaining sum, m: target sum, w: weights, x: solution vector
    x[k] = 1;
    cout << "Current k: " << k << ", Current s: " << s << ", Current r: " << r << endl; // Debugging line
    if(s + w[k] == m) {
        cout << "Solution: ";
        for(int i = 0; i <= k; ++i) {
            if(x[i] == 1) {
                cout << w[i] << " ";
            }
        }
        cout << endl;
    } else if(s + w[k] + w[k+1] <= m) {
        sum_of_subsets(s + w[k], k + 1, r - w[k], m, w, x);
    }
    x[k] = 0;
    if(s + r - w[k] >= m) {
        sum_of_subsets(s, k + 1, r - w[k], m, w, x);
    }
}

int main() {
    vector<int> w = {3, 34, 4, 1, 5, 2};
    int m = 9;
    int r = 0; // sum of all elements in w
    for(int i = 0; i < w.size(); i++) r += w[i];
    vector<int> x(w.size(), 0); // solution vector
    sum_of_subsets(0, 0, r, m, w, x);
    return 0;
}

