// ###########################################################################
// ############## Introduction to Computer Programming #######################
// ############## Group Assignment Questions(20pt) ###########################
// ###########################################################################
/*
    Group Members
    1. Eyael Mekuanint  ETS0508/16
    2. 
*/
// ########################################################################
// Question 1: Matrix Multiplication using Arrays and Functions
// ########################################################################
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

int main_1() {
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

// ########################################################################
// Question 2: Dynamic Memory Allocation for an Array
// ########################################################################
int main_2() {
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

// ########################################################################
// Question 3: Function Pointers for Sorting
// ########################################################################
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

int main_3() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int choice;
    cout << "Choose Sorting Order (1-Ascending(default), 2-Descending): ";
    cin >> choice;

    if (choice == 2)
        bubbleSort(arr, n, ascending);
    else
        bubbleSort(arr, n, descending);

    cout << "Sorted Array: ";
    displayArray(arr, n);

    return 0;
}
// ########################################################################
// Question 4.A: Constructor in OOP
// ########################################################################
/*
A constructor is a special method within a class that is used to initialize objects of that class.
It is automatically called when an instance (object) of the class is created.

The primary purpose of a constructor is to ensure that the object being created starts with valid and appropriate initial values for its attributes or properties.
It allows to set the initial state of an object, allocate necessary resources, and perform any necessary setup tasks.
*/

// Example:
class Dog1 {
private:
    int age;
public:
    Dog1(int age) { // Constructor
        this->age = age; // Assign parameter 'age' to private variable 'age'
        cout << "Constructor called!" << endl;
        cout << "This Dog's age is "<<age << endl;

    }
    void bark(){
        cout<< "Woof! I am " << age << " years old.\n";
    }
};

int main_4A() {
    Dog1 obj(15); // Constructor is automatically invoked
    obj.bark(); // bark method is called
    cout<<"Main program ended\n";
    return 0;
}

// ########################################################################
//  Question 4.B: Destructor in OOP
// ########################################################################
/*
A destructor is a special member function (method) of a class that is automatically called when an object of that class is about to be destroyed or goes out of scope. 
Its primary purpose is to perform cleanup tasks, such as releasing resources that the object has acquired during its lifetime.

To deallocate resources (memory, file handles, network connections, etc.) held by an object before it is destroyed.
This prevents memory leaks and other resource-related issues.

Feature	        | Constructor	                   | Destructor
-----------------------------------------------------------------------------------------
Purpose	        | Initialize an object	           | Clean up resources held by an object
Invocation	    | Object creation	               | Object destruction/going out of scope
Name	        | Same as class name	           | ~ + class name
Parameters	    | Can have parameters	           | Cannot have parameters
Return Type     | None	                           | None
Number	        | Can have multiple (overloading)  | Only one

*/
// Example 
class Dog2 {
private:
    int age; // Private member variable to store the age of the dog

public:
    // Constructor
    Dog2(int age) { 
        this->age = age; // Assign parameter 'age' to private variable 'age'
        cout << "Constructor called!" << endl;
        cout << "This Dog's age is " << age << " years." << endl;
    }

    // Destructor
    ~Dog2() {
        cout << "Destructor called! Cleaning up resources." << endl;
    }

    // Member function to simulate the dog barking
    void bark() {
        cout << "Woof! I am " << age << " years old.\n";
    }
};

int main_4B() {
    Dog2 obj(15); // Constructor is automatically invoked, creates an object of class Dog
    obj.bark();  // Calls the bark method to display dog's age
    cout << "Main program ended\n"; // End of program
    return 0; // Destructor is called automatically when obj goes out of scope
}

// ########################################################################
// Question 4.C: Default Constructor
// ########################################################################
/*
A default constructor is a special type of constructor in object-oriented programming that is automatically called when an object of a class is created,
without any explicit arguments being provided. It initializes the object to a default or known state.
Its characteristics are: 
1. No Parameters: A default constructor takes no arguments (parameters).
2. Automatic Invocation: It's automatically called in the following situations:
    When an object is declared without any arguments
    When an array of objects is created
    When an object is dynamically allocated using new without arguments
3. Compiler-Generated (If No Other Constructors): If the constructor isn't define  for a class, the compiler will automatically generate a default constructor.

Differences from Other Constructors (Parameterized Constructors):
Feature	            | Default Constructor	                    | Parameterized Constructor
--------------------------------------------------------------------------------------------------------------
Parameters	        | No parameters	                            | Accepts one or more parameters
Invocation	        | Object creation without arguments	        | Object creation with specific arguments
Compiler Generation | Generated if no other constructors exist	| Never generated automatically
Purpose	            | Initialize object to a default state	    | Initialize object with specific values
*/
// Example 
class Dog3 {
private:
    int age; // Private member variable to store the age of the dog

public:
    // Default Constructor
    Dog3() {
        age = 0; // Initialize age to 0
        cout << "Default Constructor called! Age set to 0." << endl;
    }

    // Parameterized Constructor
    Dog3(int age) { 
        this->age = age; // Assign parameter 'age' to private variable 'age'
        cout << "Parameterized Constructor called!" << endl;
        cout << "This Dog's age is " << age << " years." << endl;
    }

    // Destructor
    ~Dog3() {
        cout << "Destructor called! Cleaning up resources." << endl;
    }

    // Member function to simulate the dog barking
    void bark() {
        cout << "Woof! I am " << age << " years old.\n";
    }
};

int main_4C() {
    cout << "Creating dog with parameterized constructor..." << endl;
    Dog3 obj1(15); // Parameterized constructor is invoked
    obj1.bark();  // Calls the bark method to display dog's age

    cout << "Creating dog with default constructor..." << endl;
    Dog3 obj2; // Default constructor is invoked
    obj2.bark();  // Calls the bark method to display dog's age

    cout << "Main program ended\n"; // End of program
    return 0; // Destructor is called automatically when objects go out of scope
}

// ########################################################################
/* Question 4.D: Constructor Overloading 
// ########################################################################
In short: Multiple constructors in a class with different parameters.

Constructor overloading means having multiple constructors within the same class, each with a different parameter list.
This allows you to create objects of the class in various ways, providing flexibility in how you initialize them.

Constructors are overloaded based on their signatures, which include:
    1. Number of parameters: Constructors with different numbers of parameters are considered different.
    2. Types of parameters: Constructors with the same number of parameters but different parameter types are also considered different.
    3. Order of parameters: Constructors with the same number and types of parameters but in a different order are also different.
*/
// Example 
class Dog4 {
private:
    int age; // Private member variable to store the age of the dog

public:
    // Default Constructor
    Dog4() {
        age = 0; // Initialize age to 0
        cout << "Default Constructor called! Age set to 0." << endl;
    }

    // Parameterized Constructor with one argument
    Dog4(int age) { 
        this->age = age; // Assign parameter 'age' to private variable 'age'
        cout << "Parameterized Constructor called!" << endl;
        cout << "This Dog's age is " << age << " years." << endl;
    }

    // Parameterized Constructor with two arguments (Constructor Overloading)
    Dog4(int age, string name) { 
        this->age = age; // Assign parameter 'age' to private variable 'age'
        cout << "Overloaded Constructor called!" << endl;
        cout << "This Dog's name is " << name << " and age is " << age << " years." << endl;
    }

    // Destructor
    ~Dog4() {
        cout << "Destructor called! Cleaning up resources." << endl;
    }

    // Member function to simulate the dog barking
    void bark() {
        cout << "Woof! I am " << age << " years old.\n";
    }
};

int main_4D() {
    cout << "Creating dog with parameterized constructor..." << endl;
    Dog4 obj1(15); // Parameterized constructor is invoked
    obj1.bark();  // Calls the bark method to display 4's age

    cout << "Creating 4 with default constructor..." << endl;
    Dog4 obj2; // Default constructor is invoked
    obj2.bark();  // Calls the bark method to display dog's age

    cout << "Creating dog with overloaded constructor..." << endl;
    Dog4 obj3(8, "Buddy"); // Overloaded constructor is invoked
    obj3.bark();  // Calls the bark method to display dog's age

    cout << "Main program ended\n"; // End of program
    return 0; // Destructor is called automatically when objects go out of scope
}

// ########################################################################
// Main Method: Method to call each questions 
// ########################################################################
int main() {

    cout<<"Group Members\n";
    cout<<"1. Eyael Mekuanint \t ETS0508/16\n";
    cout<<"2. Eyael Mekuanint \t ETS0508/16\n";
    cout<<"3. add more here  \t ETS0508/16\n";
    int choice;

    // Interactive Menu
    while (true) {
        cout << "\n====== MENU ======" << endl;
        cout << "1.  Question 1: Matrix Multiplication" << endl;
        cout << "2.  Question 2: Dynamic Memory Allocation" << endl;
        cout << "3.  Question 3: Function Pointers for Sorting" << endl;
        cout << "41. Question 4A: Constructor Example" << endl;
        cout << "42. Question 4B: Destructor Example" << endl;
        cout << "43. Question 4C: Default Constructor Example" << endl;
        cout << "44. Question 4D: Constructor Overloading Example" << endl;
        cout << "5. Exit" << endl;
        cout << "Choose an option: ";

        choice = getValidatedInput(); // Validate user input
        cout<<"\n\n";

        switch (choice) {
            case 1:
                main_1(); // Matrix Multiplication
                break;
            case 2:
                main_2(); // Dynamic Memory Allocation
                break;
            case 3:
                main_3(); // Function Pointers for Sorting
                break;
            case 41:
                main_4A(); // Constructor Example
                break;
            case 42:
                main_4B(); // Destructor Example
                break;
            case 43:
                main_4C(); // Default Constructor Example
                break;
            case 44:
                main_4D(); // Constructor Overloading Example
                break;
            case 5:
                cout << "Exiting the program. Goodbye!" << endl;
                return 0; // Exit program
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
