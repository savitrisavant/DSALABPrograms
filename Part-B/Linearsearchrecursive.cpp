//Linear search using recursive function in C++
  #include <iostream>
using namespace std;
// Recursive function for linear search
int linearSearchRecursive(int arr[], int start, int end, int key) {
// Base case: If start index is greater than end index, key is not found
if (start > end) {
return -1; // Key not found
}
// If the key is found at start index, return the index
if (arr[start] == key) {
return start;
}
// Recursive case: Search in the remaining array (start + 1 to end)
return linearSearchRecursive(arr, start + 1, end, key);
}
int main() {
int n;
cout << "Enter the number of elements in the array: ";
cin >> n;
// Declare an array of size n
int arr[n];
// Input the elements of the array
cout << "Enter " << n << " elements:\n ";
for (int i = 0; i < n; i++) {
cin >> arr[i];
}
// Input the key to search for
int key;
cout << "Enter the key to search for: ";
cin >> key;
// Perform linear search using recursive function
int result = linearSearchRecursive(arr, 0, n - 1, key);
// Output the result
if (result != -1) {
cout << "Element found at index " << result << endl;
} else {
cout << "Element not found in the array" << endl;
}
return 0;
}
