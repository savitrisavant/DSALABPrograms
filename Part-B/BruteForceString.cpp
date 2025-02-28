#include <iostream>
#include <string>
using namespace std;

// Function to implement brute force string matching
void bruteForceStringMatch(const string &text, const string &pattern) {
    int n = text.length();
    int m = pattern.length();

    // Loop to slide the pattern over the text
    for (int i = 0; i <= n - m; i++) {
        int j = 0;

        // Check if the pattern matches the current substring of text
        while (j < m && text[i + j] == pattern[j]) {
            j++;
        }

        // If we have matched the entire pattern
        if (j == m) {
            cout << "Pattern found at index " << i << endl;
        }
    }
}

// Main driver function
int main() {
    string text, pattern;

    // Taking input for text and pattern from the user
    cout << "Enter the text: ";
    getline(cin, text);

    cout << "Enter the pattern: ";
    getline(cin, pattern);

    // Calling brute force string matching function
    bruteForceStringMatch(text, pattern);

    return 0;
}
