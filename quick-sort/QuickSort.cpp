#include <iostream>
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

void quickSort(int array[], int left, int right) {
    if (left < right) {
        int pi = partition(array, left, right);
        quickSort(array, left, pi - 1);
        quickSort(array, pi + 1, right);
    }
}

int main() {
    int data[] = {10, 5, 7, 12, 4, 31, 25, 89, -43};
    int n = sizeof(data) / sizeof(data[0]);

    cout << "Unsorted Array: \n";
    printArray(data, n);
    cout << "\n";

    quickSort(data, 0, n - 1);

    cout << "\n";
    cout << "Sorted array in ascending order: \n";
    printArray(data, n);
}