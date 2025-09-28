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

    // Count non-zero elements
    int nonZero = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] != 0)
                nonZero++;
        }
    }

    // Sparse matrix
    int sparse[nonZero + 1][3];
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

    cout << "\nSparse Matrix Representation (row col val):\n";
    for (int i = 0; i <= nonZero; i++) {
        cout << sparse[i][0] << " " << sparse[i][1] << " " << sparse[i][2] << endl;
    }

    // Transpose sparse
    int transpose[nonZero + 1][3];
    transpose[0][0] = sparse[0][1]; // rows = original cols
    transpose[0][1] = sparse[0][0]; // cols = original rows
    transpose[0][2] = sparse[0][2]; // number of non-zero elements

    int t = 1;
    for (int col = 0; col < sparse[0][1]; col++) {
        for (int i = 1; i <= nonZero; i++) {
            if (sparse[i][1] == col) {
                transpose[t][0] = sparse[i][1]; // new row = old col
                transpose[t][1] = sparse[i][0]; // new col = old row
                transpose[t][2] = sparse[i][2];
                t++;
            }
        }
    }

    cout << "\nTranspose Sparse Matrix (row col val):\n";
    for (int i = 0; i <= nonZero; i++) {
        cout << transpose[i][0] << " " << transpose[i][1] << " " << transpose[i][2] << endl;
    }

    return 0;
}
