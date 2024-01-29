#include <iostream>
#include <ctime>
#include <iomanip>
#include <ctime>
#include <fstream>
using namespace std;

void printArray(long int array[], long int size) {
    for (long int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

long int* generateArray(long int size) {
    long int* data = new long int[size];
    for (long int i = 0; i < size; ++i) {
        data[i] = rand() % 50000;
    }
    return data;
}

void straightMaxMin(long int array[], long int size, long int& max, long int& min) {
    max = min = array[0];
    long int count = 0;
    for (long int i = 1; i < size; ++i) {
        count++;
        if (array[i] > max) max = array[i];
        else if (array[i] < min) min = array[i];
    }
    cout << "\nMax: " << max << "\nMin: " << min << endl;
    cout << "\nNumber of iterations: " << count << endl;

    ofstream outFile("straightMaxMin.txt", ios::app);
    outFile << "Number of elements: " << size << ", Iterations: " << count << "\n";
    outFile.close();
}

int main() {
    clock_t start = clock();
    srand(time(0));
    long int size = 150;
    long int max, min = 0;

    long int* data = generateArray(size);
    straightMaxMin(data, size, max, min);
    delete[] data;

    return 0;
}


