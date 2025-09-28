#include <iostream>
using namespace std;

struct Element {
    int row;
    int col;
    int val;
};

// Function to add two sparse matrices
void sparseAddition(Element a[], int n1, Element b[], int n2) {
    Element result[100];
    int i = 1, j = 1, k = 1;

    result[0].row = a[0].row;
    result[0].col = a[0].col;

    while (i <= n1 && j <= n2) {
        if (a[i].row < b[j].row || (a[i].row == b[j].row && a[i].col < b[j].col)) {
            result[k++] = a[i++];
        } else if (b[j].row < a[i].row || (b[j].row == a[i].row && b[j].col < a[i].col)) {
            result[k++] = b[j++];
        } else {
            // Same position
            result[k] = a[i];
            result[k].val = a[i].val + b[j].val;
            i++; j++; k++;
        }
    }

    while (i <= n1) result[k++] = a[i++];
    while (j <= n2) result[k++] = b[j++];

    result[0].val = k - 1;

    cout << "\nSparse Matrix Addition Result (row col val):\n";
    for (int t = 0; t < k; t++)
        cout << result[t].row << " " << result[t].col << " " << result[t].val << endl;
}

// Function to multiply two sparse matrices
void sparseMultiplication(Element a[], int n1, Element b[], int n2) {
    int rows = a[0].row;
    int cols = b[0].col;
    Element result[100];
    int k = 1;

    result[0].row = rows;
    result[0].col = cols;

    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (a[i].col == b[j].row) {
                int r = a[i].row;
                int c = b[j].col;
                int val = a[i].val * b[j].val;

                // Check if already exists in result
                int found = 0;
                for (int t = 1; t < k; t++) {
                    if (result[t].row == r && result[t].col == c) {
                        result[t].val += val;
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    result[k].row = r;
                    result[k].col = c;
                    result[k].val = val;
                    k++;
                }
            }
        }
    }

    result[0].val = k - 1;

    cout << "\nSparse Matrix Multiplication Result (row col val):\n";
    for (int t = 0; t < k; t++)
        cout << result[t].row << " " << result[t].col << " " << result[t].val << endl;
}

int main() {
    int choice;
    cout << "Sparse Matrix Operations Menu:\n";
    cout << "1. Addition\n2. Multiplication\nEnter choice: ";
    cin >> choice;

    int r1, c1, r2, c2;

    cout << "Enter rows and columns of Matrix A: ";
    cin >> r1 >> c1;
    int n1;
    cout << "Enter number of non-zero elements in Matrix A: ";
    cin >> n1;
    Element a[n1 + 1];
    a[0].row = r1;
    a[0].col = c1;
    a[0].val = n1;

    cout << "Enter row, col, value for each non-zero element of A:\n";
    for (int i = 1; i <= n1; i++) {
        cin >> a[i].row >> a[i].col >> a[i].val;
    }

    cout << "Enter rows and columns of Matrix B: ";
    cin >> r2 >> c2;
    int n2;
    cout << "Enter number of non-zero elements in Matrix B: ";
    cin >> n2;
    Element b[n2 + 1];
    b[0].row = r2;
    b[0].col = c2;
    b[0].val = n2;

    cout << "Enter row, col, value for each non-zero element of B:\n";
    for (int i = 1; i <= n2; i++) {
        cin >> b[i].row >> b[i].col >> b[i].val;
    }

    if (choice == 1) {
        if (r1 != r2 || c1 != c2) {
            cout << "Matrices dimensions must be same for addition!\n";
        } else {
            sparseAddition(a, n1, b, n2);
        }
    } else if (choice == 2) {
        if (c1 != r2) {
            cout << "Number of columns of A must equal rows of B for multiplication!\n";
        } else {
            sparseMultiplication(a, n1, b, n2);
        }
    } else {
        cout << "Invalid choice!\n";
    }

    return 0;
}
