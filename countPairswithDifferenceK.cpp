#include <iostream>
#include <cmath>
using namespace std;

int countPairs(int arr[], int n, int k) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (abs(arr[i] - arr[j]) == k) {
                cout << "(" << arr[i] << ", " << arr[j] << ")\n"; // print the pair
                count++;
            }
        }
    }
    return count;
}

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Enter value of k: ";
    cin >> k;

    cout << "\nPairs with difference " << k << " are:\n";
    int total = countPairs(arr, n, k);

    cout << "\nTotal pairs = " << total << endl;

    return 0;
}
