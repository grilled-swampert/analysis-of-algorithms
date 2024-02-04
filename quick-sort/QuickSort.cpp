#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
using namespace std;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void printArray(int array[], int size) {
    int i;
    for (i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

int partition(int array[], int left, int right) {
    int pivot = array[left];
    int low = left + 1;
    int high = right;

    while (low <= high) {
        while (array[high] > pivot) high--;
        while (low <= high && array[low] <= pivot) low++;
        if (low <= high) swap(&array[low], &array[high]);
    }
    swap(&array[left], &array[high]);
    cout << "Partion at: " << high << endl;
    return high;
}

int* generateArray(int size) {
    int* data = new int[size];
    for (int i = 0; i < size; ++i) {
        data[i] = rand() % 1000;
    }
    return data;
}

void quickSort(int array[], int left, int right) {
    if (left < right) {
        int pi = partition(array, left, right);
        quickSort(array, left, pi - 1);
        quickSort(array, pi + 1, right);
    }
}

int main() {
    srand(time(0)) ;
    int size = 200;
    cout << "Size of the array: " << size << endl; 

    int* data = generateArray(size);

    cout << "Unsorted Array: \n";
    printArray(data, size);
    cout << "\n";

    clock_t start = clock();
    quickSort(data, 0, size - 1);
    clock_t end = clock();
    double timeTaken = double(end - start) / CLOCKS_PER_SEC;
    cout << "Time taken by the program: " << timeTaken << " seconds" << endl;

    ofstream outFile("quickSort.txt", ios::app);
    outFile << fixed << setprecision(10);
    outFile << "Size: " << size << ", Time: " << timeTaken << " seconds\n";
    outFile.close();

    cout << "\n";
    cout << "Sorted array in ascending order: \n";
    printArray(data, size);
}