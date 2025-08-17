#include <iostream>
using namespace std;

int findMissingLinear(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != i + 1) {
            return i + 1; // missing number
        }
    }
    return n; // if no mismatch found, missing is n
}

int main() {
    int arr[] = {1, 2, 3, 4, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]) + 1; // n = array size + 1

    int missing = findMissingLinear(arr, n);
    cout << "Missing number (Linear): " << missing << endl;

    return 0;
}

//binary search approach

#include <iostream>
using namespace std;

int findMissingBinary(int arr[], int low, int high) {
    if (low > high) {
        return high + 2; // missing number
    }

    int mid = low + (high - low) / 2;

    // If element matches index+1, missing number is in right half
    if (arr[mid] == mid + 1) {
        return findMissingBinary(arr, mid + 1, high);
    } else {
        // Else missing number is in left half
        return findMissingBinary(arr, low, mid - 1);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]) + 1; // n = array size + 1

    int missing = findMissingBinary(arr, 0, n - 2);
    cout << "Missing number (Binary Search): " << missing << endl;

    return 0;
}
