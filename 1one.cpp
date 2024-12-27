// Program 1: Matrix Multiplication using Arrays and Functions
#include <iostream>
#include <limits> // For input validation
using namespace std;

// Function to validate integer input
int getValidatedInput() {
    int value;
    while (true) {
        cin >> value;
        // Check if input is valid
        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid input. Please enter an integer: ";
        } else {
            break;
        }
    }
    return value;
}

// Function to input matrix values
void inputMatrix(int matrix[][10], int rows, int cols) {
    cout << "Enter elements for a " << rows << " x " << cols << " matrix: " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Element [" << i + 1 << "][" << j + 1 << "]: ";
            matrix[i][j] = getValidatedInput(); // Use validated input
        }
    }
}

// Function to multiply matrices
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

// Function to display matrix
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
    m = getValidatedInput();
    n = getValidatedInput();
    inputMatrix(mat1, m, n);

    while (true) {
        cout << "Enter dimensions (n x p) of the second matrix separated by space (e.g 2 3): ";
        n2 = getValidatedInput();
        p = getValidatedInput();

        // Validate matrix dimensions
        if (n != n2) {
            cout << "Error: Number of columns in the first matrix must be equal to the number of rows in the second matrix." << endl;
            cout << "Please re-enter dimensions for the second matrix." << endl;
        } else {
            break;
        }
    }

    inputMatrix(mat2, n2, p);

    multiplyMatrices(mat1, mat2, res, m, n, p);
    cout << "\n\nMatrix A ";
    displayMatrix(mat1, m, n);
    cout << "Matrix B ";
    displayMatrix(mat2, n2, p);
    cout << "\n==> Resultant Matrix";
    displayMatrix(res, m, p);

    return 0;
}
