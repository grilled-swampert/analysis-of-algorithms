#include <iostream>
#include <chrono>
#include <iomanip>
#include <fstream>
using namespace std;
using namespace std::chrono;

long int* globalArray; // Declare the global array

void printArray(long int array[], long int size) {
    for (long int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

long int* generateArray(long int size) {
    globalArray = new long int[size]; // Use the global array
    for (long int i = 0; i < size; ++i) {
        globalArray[i] = rand() % 50000;
    }
    return globalArray;
}

void recursiveMaxMin(int i, int j, long int& max, long int& min, int& count) {
    if (i == j) {
        max = min = globalArray[i];
    } else if (i == j - 1) {
        if (globalArray[i] < globalArray[j]) {
            max = globalArray[j];
            min = globalArray[i];
        } else {
            max = globalArray[i];
            min = globalArray[j];
        }
    } else {
        long int max1, min1;
        int mid = (i + j) / 2;
        count++;
        recursiveMaxMin(i, mid, max, min, count);
        recursiveMaxMin(mid + 1, j, max1, min1, count);

        if (max < max1) max = max1;
        if (min > min1) min = min1;
    }
}

int main() {
    srand(time(0));
    long int size = 100;
    long int max, min = 0;

    auto start = high_resolution_clock::now();

    long int* data = generateArray(size);
    int count = 0;
    recursiveMaxMin(0, size - 1, max, min, count);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cout << "Max: " << max << "\nMin: " << min << endl;
    cout << "Iterations taken by the algorithm: " << count << endl;

    cout << "\nTime taken by the program: " << duration.count() / 1000.0 << " microseconds" << endl;

    ofstream outFile("recursiveMaxMin.txt", ios::app);
    outFile << fixed << setprecision(10);
    outFile << "Size: " << size << ", Time: " << duration.count() / 1000.0 << " microseconds\n";
    outFile.close();

    delete[] data; // The array is deleted in the main function now

    return 0;
}
