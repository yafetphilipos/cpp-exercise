// Program 1: Matrix Multiplication using Arrays and Functions
#include <iostream>
using namespace std;

void inputMatrix(int matrix[][10], int rows, int cols) {
    cout << "Enter elements for a " << rows << " x " << cols << " matrix: " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}

void multiplyMatrices(int mat1[][10], int mat2[][10], int res[][10], int m, int n, int p) {
    // Initialize result matrix to zero
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            res[i][j] = 0;
        }
    }

    // Perform multiplication
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < n; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void displayMatrix(int matrix[][10], int rows, int cols) {
    cout << "(" << rows << " x " << cols << "): " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int mat1[10][10], mat2[10][10], res[10][10];
    int m, n, p, n2;

    cout << "Enter dimensions (m x n) of the first matrix separated by space (e.g 3 2): ";
    cin >> m >> n;
    inputMatrix(mat1, m, n);

    cout << "Enter dimensions (n x p) of the second matrix separated by space (e.g 2 3): ";
    cin >> n2 >> p;

    // Validate matrix dimensions
    if (n != n2) {
        cout << "Error: Number of columns in the first matrix must be equal to the number of rows in the second matrix." << endl;
        return 1;
    }

    inputMatrix(mat2, n2, p);

    multiplyMatrices(mat1, mat2, res, m, n, p);
    cout<<"\n\nMatrix A ";
    displayMatrix(mat1, m, n);
    cout<<"Matrix B ";
    displayMatrix(mat2, n2, p);
    cout<<"\n==> Resultant Matrix";
    displayMatrix(res, m, p);

    return 0;
}
