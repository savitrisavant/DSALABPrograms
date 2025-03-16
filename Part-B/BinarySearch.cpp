// Binary Search using recursive function in C++

#include <iostream>
using namespace std;
// Recursive function for binary search
int binarySearchRecursive(int arr[], int low, int high, int key) {
if (low > high) {
return -1; // Key not found
}
int mid = low + (high - low) / 2;
if (arr[mid] == key) {
return mid; // Key found at index mid
} else if (arr[mid] < key) {
return binarySearchRecursive(arr, mid + 1, high, key); // Search in the right half
} else {
return binarySearchRecursive(arr, low, mid - 1, key); // Search in the left half
}
}
int main() {
int n;
cout << "Enter the number of elements in the array: ";
cin >> n;
int arr[n];
cout << "Enter " << n << " sorted elements: " <<"\n";
for (int i = 0; i < n; i++) {
cin >> arr[i];
}
int key;
cout << "Enter the key to search for: ";
cin >> key;
int result = binarySearchRecursive(arr, 0, n - 1, key);
if (result != -1) {
cout << "Element found at index " << result << endl;
} else {
cout << "Element not found in the array" << endl;
}
return 0;
}
