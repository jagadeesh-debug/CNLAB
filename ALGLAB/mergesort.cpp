#include <iostream>
#include <vector>
using namespace std;

// Function to merge two sorted halves into a single sorted array
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of the left half
    int n2 = right - mid;    // Size of the right half

    // Temporary arrays to hold the halves
    vector<int> L(n1), R(n2);

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    // Merge the temporary arrays back into the original array
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // Copy remaining elements of L[], if any
    while (i < n1) arr[k++] = L[i++];

    // Copy remaining elements of R[], if any
    while (j < n2) arr[k++] = R[j++];
}

// Function to perform merge sort
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
