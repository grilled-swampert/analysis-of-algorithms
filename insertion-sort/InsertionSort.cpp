#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
using namespace std;

void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void insertionSort(int array[], int size) {
    for (int step = 1; step < size; step++) {
        int key = array[step];
        int j = step - 1;
        while (key < array[j] && j >= 0) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}

int* generateArray(int size) {
    int* data = new int[size];
    for (int i = 0; i < size; ++i) {
        data[i] = rand() % 1000;
    }
    return data;
}

int main() {
    srand(time(0));
    int size = rand() % 1000;
    cout << "Size of the array: " << size;

    clock_t start = clock();

    int* data = generateArray(size);
    insertionSort(data, size);
    cout << "\nSorted array in ascending order:\n";
    printArray(data, size);
    delete[] data; 

    clock_t end = clock();
    double timeTaken = double(end - start) / CLOCKS_PER_SEC;

    cout << fixed << setprecision(10); 
    cout << "\nTime taken by the program: " << timeTaken << " seconds" << endl;

    ofstream outFile("output.txt", ios::app);
    outFile << fixed << setprecision(10);
    outFile << "Size: " << size << ", Time: " << timeTaken << " seconds\n";
    outFile.close();

    return 0;
}
