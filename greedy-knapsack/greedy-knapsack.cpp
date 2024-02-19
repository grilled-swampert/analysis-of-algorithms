#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Object {
    int profit;
    int weight;
    double ratio;

    bool operator<(const Object& other) const {
        return ratio > other.ratio; // Algorithm: Objects ordered by p[i] / w[i] in non-increasing order
    }
};

void greedyKnapsack(int m, std::vector<Object>& objects) {
    sort(objects.begin(), objects.end()); // Algorithm: Objects ordered by p[i] / w[i] in non-increasing order
    cout << "Sorted objects:\n";
    for (size_t i = 0; i < objects.size(); ++i) {
        cout << "Object " << i + 1 << ": " << objects[i].profit << " " << objects[i].weight << " " << objects[i].ratio << endl;
    }

    vector<double> x(objects.size(), 0.0); // Algorithm: Initialize solution vector x
    int U = m;
    cout << endl;

    for (size_t i = 0; i < objects.size(); ++i) {
        if (objects[i].weight > U && U > 0 && !objects.empty()) {
            x[i] = (double)U / objects[i].weight; // Algorithm: Set x[i] = U / w[i] if i < n
            break; // Algorithm: Exit loop if w(i) > U
        }
        x[i] = 1.0;
        U -= objects[i].weight;
    }

    // Output the solution vector
    cout << "Solution vector:\n";
    for (size_t i = 0; i < objects.size(); ++i) {
        cout << "Object " << i + 1 << ": " << objects[i].profit << " " << objects[i].weight << " " << objects[i].ratio << " ---> " << x[i] << endl;
    }

    cout << endl;
    double totalProfit = 0.0;
    for (size_t i = 0; i < objects.size(); ++i) {
        totalProfit += x[i] * objects[i].profit; // Algorithm: Calculate total profit
    }
    cout << "Total profit: " << totalProfit << endl << "\n";
}

int main() {
    int m = 70; // Knapsack size
    vector<Object> objects = {{100, 20, 0.0}, {50, 10, 0.0}, {120, 30, 0.0}, {70, 15, 0.0}, {90, 40, 0.0}}; // Example objects

    for (auto& obj : objects) {
        obj.ratio = (double)obj.profit / obj.weight; // Calculate profit-to-weight ratio
    }

    greedyKnapsack(m, objects);

    return 0;
}
