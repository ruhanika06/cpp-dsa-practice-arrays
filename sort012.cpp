#include <iostream>
#include <vector>
using namespace std;
//We use three pointers:
// low → marks the boundary for 0s.
// mid → traverses the array.
// high → marks the boundary for 2s.
// Steps:
// If arr[mid] == 0: swap arr[low] and arr[mid], then increment both low and mid.
// If arr[mid] == 1: just move mid forward.
// If arr[mid] == 2: swap arr[mid] and arr[high], then decrement high.


void sort012(vector<int>& arr) {
    int low = 0, mid = 0, high = arr.size() - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else { // arr[mid] == 2
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main() {
    vector<int> arr = {2, 0, 1, 2, 1, 0, 0, 2, 1};

    cout << "Before Sorting: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    sort012(arr);

    cout << "After Sorting: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}
