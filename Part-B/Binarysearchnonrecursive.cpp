Binary search using non-recursive function in C++
  #include <iostream>
using namespace std;
int binarySearch(int arr[], int n, int key) {
int low = 0, high = n - 1;
while (low <= high) {
int mid = low + (high - low) / 2;
if (arr[mid] == key) {
return mid; // Return the index if key is found
} else if (arr[mid] < key) {
low = mid + 1;
} else {
high = mid - 1;
}
}
return -1; // Return -1 if key is not found
}
int main() {
int n;
cout << "Enter the number of elements in the array: ";
cin >> n;
int arr[n];
cout << "Enter " << n << " sorted elements: "<<"\n";
for (int i = 0; i < n; i++) {
cin >> arr[i];
}
int key;
cout << "Enter the key to search for: ";
cin >> key;
int result = binarySearch(arr, n, key);
if (result != -1) {
cout << "Element found at index " << result << endl;
} else {
cout << "Element not found in the array" << endl;
}
return 0;
}
