//Linear search using non-recursive function
#include <iostream>
using namespace std;
int linearSearch(int arr[], int n, int key) {
for (int i = 0; i < n; i++) {
if (arr[i] == key) {
return i; // Return the index if key is found
}
}
return -1; // Return -1 if key is not found
}
int main() {
int n;
cout << "Enter the number of elements in the array: ";
cin >> n;
int arr[n];
cout << "Enter " << n << " elements: "<<"\n";
for (int i = 0; i < n; i++) {
cin >> arr[i];
}
int key;
cout << "Enter the key to search for: ";
cin >> key;
int result = linearSearch(arr, n, key);
if (result != -1) {
cout << "Element found at index " << result << endl;
} else {
cout << "Element not found in the array" << endl;
}
return 0;
}
