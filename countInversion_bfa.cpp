#include <iostream>
using namespace std;

int countInversions(int arr[], int n) {//o(n^2)-brute force approach
    int inv_count = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                inv_count++;
                cout<<inv_count<<". "<<arr[i]<<","<<arr[j]<<endl;
            }
        }
    }
    return inv_count;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Number of inversions: " << countInversions(arr, n) << endl;
    return 0;
}
