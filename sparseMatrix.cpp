#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    int mat[10][10];

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> mat[i][j];
        }
    }

    cout << "\nOriginal Matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    // Count non-zero elements
    int nonZero = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] != 0)
                nonZero++;
        }
    }

    // Sparse matrix representation
    int sparse[nonZero + 1][3]; // +1 for header
    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = nonZero;

    int k = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = mat[i][j];
                k++;
            }
        }
    }

    cout << "\nSparse Matrix Representation (row col value):\n";
    for (int i = 0; i <= nonZero; i++) {
        cout << sparse[i][0] << " " << sparse[i][1] << " " << sparse[i][2] << endl;
    }

    // Reconstruct original matrix
    int reconstruct[10][10] = {0}; // initialize with 0
    for (int i = 1; i <= nonZero; i++) {
        int r = sparse[i][0];
        int c = sparse[i][1];
        int val = sparse[i][2];
        reconstruct[r][c] = val;
    }

    cout << "\nReconstructed Matrix from Sparse Representation:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << reconstruct[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
