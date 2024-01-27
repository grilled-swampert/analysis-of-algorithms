#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void printArray(long long int array[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void insertionSort(long long int array[], int size) {
    for (int step = 1; step < size; step++) {
        long long int key = array[step];
        int j = step - 1;
        while (key < array[j] && j >= 0) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}

void recursiveBinarySearch(long long int array[], long long int key, int low, int high, int& count) {
    int mid;
    if (low <= high) {
        mid = (low + high) / 2;
        count++;
        if (key == array[mid]) {
            cout << "\nKey found at position: " << mid + 1;
        } else if (key < array[mid]) {
            recursiveBinarySearch(array, key, low, mid - 1, count);
        } else {
            recursiveBinarySearch(array, key, mid + 1, high, count);
        }
    } else {
        cout << "\nKey not found";
    }
}

long long int* generateArray(int size) {
    long long int* data = new long long int[size];
    for (int i = 0; i < size; ++i) {
        data[i] = rand() % 10000;  
    }
    return data;
}

int main() {
    srand(time(0));
    int size = 2000;

    long long int* data = generateArray(size);

    insertionSort(data, size);
    cout << "\nSorted array in ascending order:\n";
    printArray(data, size);

    long long int key = 0;
    cout << "\nEnter element to search: ";
    cin >> key;

    int count = 0;

    recursiveBinarySearch(data, key, 0, size - 1, count);

    cout << "\nNumber of iterations: " << count << endl;  

    ofstream outFile("recursiveBinarySearch.txt", ios::app);
    outFile << "Size: " << size << ", Iterations: " << count << "\n";
    outFile.close();
    delete[] data;

    return 0;
}
