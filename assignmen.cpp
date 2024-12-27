// Program 1: Matrix Multiplication using Arrays and Functions
#include <iostream>
using namespace std;

void inputMatrix(int matrix[][10], int rows, int cols) {
    cout << "Enter elements: " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}

void multiplyMatrices(int mat1[][10], int mat2[][10], int res[][10], int m, int n, int p) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            res[i][j] = 0;
            for (int k = 0; k < n; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void displayMatrix(int matrix[][10], int rows, int cols) {
    cout << "Resultant Matrix: " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int mat1[10][10], mat2[10][10], res[10][10];
    int m, n, p;

    cout << "Enter dimensions of first matrix (m x n): ";
    cin >> m >> n;
    inputMatrix(mat1, m, n);

    cout << "Enter dimensions of second matrix (n x p): ";
    cin >> n >> p;
    inputMatrix(mat2, n, p);

    multiplyMatrices(mat1, mat2, res, m, n, p);
    displayMatrix(res, m, p);

    return 0;
}

// Program 2: Dynamic Memory Allocation for an Array
#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int* arr = new int[size];
    cout << "Enter elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    cout << "Sum: " << sum << endl;
    cout << "Average: " << (float)sum / size << endl;

    delete[] arr; // Free allocated memory
    return 0;
}

// Program 3: Function Pointers for Sorting
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n, bool (*compare)(int, int)) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (compare(arr[j], arr[j + 1])) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

bool ascending(int a, int b) { return a > b; }
bool descending(int a, int b) { return a < b; }

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int choice;
    cout << "Choose Sorting Order (1-Ascending, 2-Descending): ";
    cin >> choice;

    if (choice == 1)
        bubbleSort(arr, n, ascending);
    else
        bubbleSort(arr, n, descending);

    cout << "Sorted Array: ";
    displayArray(arr, n);

    return 0;
}

// Question A: Constructor in OOP
// A constructor is a special member function in OOP that initializes objects.
// It is automatically invoked when an object is created.

// Example:
#include <iostream>
using namespace std;

class Example {
public:
    Example() { // Constructor
        cout << "Constructor called!" << endl;
    }
};

int main() {
    Example obj; // Constructor is automatically invoked
    return 0;
}

// Question B: Destructor in OOP
// A destructor is a member function that deallocates resources when an object goes out of scope.
// It differs from a constructor as it cleans up resources rather than initializing them.

class Demo {
public:
    Demo() { cout << "Constructor called!" << endl; }
    ~Demo() { cout << "Destructor called!" << endl; }
};

int main() {
    Demo obj;
    return 0;
}

// Question C: Default Constructor
// A default constructor takes no arguments and initializes an object.

class DefaultDemo {
public:
    int x;
    DefaultDemo() { x = 0; }
    void display() { cout << "x = " << x << endl; }
};

int main() {
    DefaultDemo obj;
    obj.display();
    return 0;
}

// Question D: Constructor Overloading
// Multiple constructors in a class with different parameters.

class OverloadDemo {
public:
    int a, b;
    OverloadDemo() { a = b = 0; }
    OverloadDemo(int x, int y) { a = x; b = y; }

    void display() { cout << "a = " << a << ", b = " << b << endl; }
};

int main() {
    OverloadDemo obj1;
    OverloadDemo obj2(10, 20);

    obj1.display();
    obj2.display();
    return 0;
}
