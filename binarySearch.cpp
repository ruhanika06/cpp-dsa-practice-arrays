#include <iostream>
using namespace std;

// Binary Search function returns index if found, else -1
int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // prevents overflow

        if (arr[mid] == key) {
            return mid;  // found key at mid
        } 
        else if (arr[mid] < key) {
            left = mid + 1;  // search right half
        } 
        else {
            right = mid - 1;  // search left half
        }
    }
    return -1;  // key not found
}

int main() {
    int arr[100], n, key;

    cout << "Enter number of elements (sorted array): ";
    cin >> n;
    cout << "Enter " << n << " elements in ascending order:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter value to search: ";
    cin >> key;

    int result = binarySearch(arr, n, key);
    if (result != -1) {
        cout << "Element found at position " << result + 1 << ".\n";
    } else {
        cout << "Element not found in the array.\n";
    }

    return 0;
}
