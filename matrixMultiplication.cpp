#include <iostream>
using namespace std;

int main() {
    int A[10][10], B[10][10], C[10][10];
    int r1, c1, r2, c2;

    cout << "Enter rows and columns of matrix A: ";
    cin >> r1 >> c1;
    cout << "Enter elements of matrix A:\n";
    for(int i=0; i<r1; i++) {
        for(int j=0; j<c1; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Enter rows and columns of matrix B: ";
    cin >> r2 >> c2;
    if(c1 != r2) {
        cout << "Matrix multiplication not possible.\n";
        return 0;
    }

    cout << "Enter elements of matrix B:\n";
    for(int i=0; i<r2; i++) {
        for(int j=0; j<c2; j++) {
            cin >> B[i][j];
        }
    }

    // Initialize result matrix C with zeros
    for(int i=0; i<r1; i++) {
        for(int j=0; j<c2; j++) {
            C[i][j] = 0;
        }
    }

    // Multiply
    for(int i=0; i<r1; i++) {
        for(int j=0; j<c2; j++) {
            for(int k=0; k<c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "Resultant matrix after multiplication:\n";
    for(int i=0; i<r1; i++) {
        for(int j=0; j<c2; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
