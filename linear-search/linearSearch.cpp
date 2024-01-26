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

void linearSearch(int array[], int key, int size) {
    int count = 0;
    cout << "\nLinear Search: ";
    for (int i = 0; i < size; ++i) {
        count++;
        if (array[i] == key) {
            cout << "\nKey found at position: " << i + 1;
            break;
        }
    }

    if (count > size) {
        cout << "Key not found.";
    }
    cout << "\nNumber of iterations: " << count << endl;

    ofstream outFile("linearSearch.txt", ios::app);
    outFile << "Number of elements: " << size << ", Iterations: " << count << "\n";
    outFile.close();

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
    int size = 20;

    int* data = generateArray(size);
    cout << "\nUnsorted array:\n";
    printArray(data, size);

    insertionSort(data, size);

    cout << "\nSorted array in ascending order:\n";
    printArray(data, size);

    int key = 0;
    cout << "\nEnter element to search: ";
    cin >> key;

    linearSearch(data, key, size);
    
    delete[] data; 

    return 0;
}
