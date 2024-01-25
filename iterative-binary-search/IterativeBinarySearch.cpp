#include <iostream>
#include <fstream>
#include <chrono>
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

void binarySearch(int array[], int key, int size) {
    int low = 0;
    int high = size - 1;
    int mid;
    int count = 0; 
    cout << "\nBinary Search: ";
    while (low <= high) {
        mid = (low + high) / 2;
        count++;
        if (key == array[mid]) {
            cout << "\nKey found at position: " << mid + 1;
            break;
        }
        else if (key < array[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    cout << "\nNumber of iterations: " << count << endl;

    ofstream outFile("binarySearch.txt", ios::app);
    outFile << "Number of elements: " << size << ", Iterations: " << count << "\n";
    outFile.close();
    if (low > high) {
        cout << "Key not found.";
    }
}

int* generateArray(int size) {
    int* data = new int[size];
    for (int i = 0; i < size; ++i) {
        data[i] = rand() % 10000;
    }
    return data;
}

int main() {
    srand(time(0));
    int size = 10000;

    int* data = generateArray(size);
    cout << "\nUnsorted array:\n";
    printArray(data, size);

    insertionSort(data, size);

    cout << "\nSorted array in ascending order:\n";
    printArray(data, size);

    int key = 0;
    cout << "\nEnter element to search: ";
    cin >> key;

    binarySearch(data, key, size);
    
    delete[] data; 

    return 0;
}
