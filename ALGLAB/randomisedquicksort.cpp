#include <iostream>
#include <vector>
#include <cstdlib> // For rand()
using namespace std;

// Function to partition the array
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to randomly select a pivot and partition the array
int randomizedPartition(vector<int>& arr, int low, int high) {
    int randomPivotIndex = low + rand() % (high - low + 1); // Random pivot index
    swap(arr[randomPivotIndex], arr[high]);                // Move random pivot to end
    return partition(arr, low, high);                      // Partition the array
}

// Recursive Quick Sort function
void randomizedQuickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = randomizedPartition(arr, low, high); // Randomly partition
        randomizedQuickSort(arr, low, pivotIndex - 1);        // Sort left of pivot
        randomizedQuickSort(arr, pivotIndex + 1, high);       // Sort right of pivot
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();

    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    randomizedQuickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
