#include <iostream>
using namespace std;

// Function to merge two halves of the array
void merge(int arr[], int left, int mid, int right) {
    // Find the size of the two subarrays to be merged
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays to hold the values of the subarrays
    int leftArr[n1], rightArr[n2];

    // Copy the data to temporary arrays
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into the original array
    int i = 0; // Initial index for left subarray
    int j = 0; // Initial index for right subarray
    int k = left; // Initial index for merged subarray
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements of the left subarray, if any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy any remaining elements of the right subarray, if any
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Function to implement Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Find the midpoint
        int mid = left + (right - left) / 2;

        // Recursively sort the left and right halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;

    // Taking input for the size of the array
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    // Taking input for the elements of the array
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Original array: ";
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);  // Sort the array using Merge Sort

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
