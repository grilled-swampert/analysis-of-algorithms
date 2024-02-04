#include <iostream> 
#include <fstream>
#include <ctime>
#include <iomanip>
using namespace std; 
  
void merge(int array[], int const left, int const mid, int const right) 
{ 
    auto const arraySizeOne = mid - left + 1; 
    auto const arraySizeTwo = right - mid; 
  
    auto *leftArray = new int[arraySizeOne], *rightArray = new int[arraySizeTwo]; 
  
    for (auto i = 0; i < arraySizeOne; i++) leftArray[i] = array[left + i]; 
    for (auto j = 0; j < arraySizeTwo; j++) rightArray[j] = array[mid + 1 + j]; 
  
    auto i = 0, j = 0;  
  
    int k = left;  
  
    while (i < arraySizeOne && j < arraySizeTwo) { 
        if (leftArray[i] <= rightArray[j]) { 
            array[k] = leftArray[i]; 
            i++; 
        } else { 
            array[k] = rightArray[j]; 
            j++; 
        } 
        k++; 
    } 
      
    while (i < arraySizeOne){ 
        array[k] =  
        leftArray[i]; 
        i++; 
        k++; 
    } 
 
    while (j < arraySizeTwo){ 
        array[k] =  
        rightArray[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(int array[], int const begin, int const end) 
{ 
    if (begin >= end) 
        return;  
  
    auto mid = begin + (end - begin) / 2; 
    mergeSort(array, begin, mid); 
    mergeSort(array, mid + 1, end); 
    merge(array, begin, mid, end); 
} 

int* generateArray(int size) {
    int* data = new int[size];
    for (int i = 0; i < size; ++i) {
        data[i] = rand() % 1000;
    }
    return data;
}
  
void printArray(int array[], int size) 
{ 
    for (auto i = 0; i < size; i++) 
        cout << array[i] << " "; 
    cout<<endl; 
} 
  
int main() 
{ 
    srand(time(0)) ;
    int size = rand() % 100;
    cout << "Size of the array: " << size << endl; 

    int* data = generateArray(size);
  
    cout << "Given array is "<<endl; 
    printArray(data, size); 
    
    clock_t start = clock();
    mergeSort(data, 0, size - 1); 
    clock_t end = clock();
    double timeTaken = double(end - start) / CLOCKS_PER_SEC;
    cout << "Time taken by the program: " << timeTaken << " seconds" << endl;

    ofstream outFile("mergeSort.txt", ios::app);
    outFile << fixed << setprecision(10);
    outFile << "Size: " << size << ", Time: " << timeTaken << " seconds\n";
    outFile.close();
  
    cout << "Sorted array is "<<endl; 
    printArray(data, size); 
    return 0; 
} 