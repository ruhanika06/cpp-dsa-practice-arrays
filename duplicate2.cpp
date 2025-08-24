#include <iostream>
#include <vector>
using namespace std;

void duplicateTwos(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        if (arr[i] == 2) {
            // Shift elements to the right
            for (int j = n - 1; j > i; j--) {
                arr[j] = arr[j - 1];
            }
            // Place duplicate 2
            if (i + 1 < n) arr[i + 1] = 2;

            // Skip over the duplicate
            i++;
        }
    }
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    duplicateTwos(arr);

    cout << "Array after duplicating 2s: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}
