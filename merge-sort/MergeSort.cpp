#include <iostream> 
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
  
void printArray(int array[], int size) 
{ 
    for (auto i = 0; i < size; i++) 
        cout << array[i] << " "; 
    cout<<endl; 
} 
  
int main() 
{ 
    int array[] = { 34, 89, 22, 11, 78, 22, 9 }; 
    auto array_size = sizeof(array) / sizeof(array[0]); 
  
    cout << "Given array is "<<endl; 
    printArray(array, array_size); 
  
    mergeSort(array, 0, array_size - 1); 
  
    cout << "Sorted array is "<<endl; 
    printArray(array, array_size); 
    return 0; 
} 