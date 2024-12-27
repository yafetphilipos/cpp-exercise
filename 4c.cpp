// ###########################################################################
// ############## Introduction to Computer Programming #######################
// ############## Group Assignment Questions(20pt) ###########################
// ###########################################################################
/*
    Group Members
    1. Eyael Mekuanint  ETS0508/16
    2. 
*/
/*
Question C: Default Constructor
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
#include <iostream>
using namespace std;

class Dog {
private:
    int age; // Private member variable to store the age of the dog

public:
    // Default Constructor
    Dog() {
        age = 0; // Initialize age to 0
        cout << "Default Constructor called! Age set to 0." << endl;
    }

    // Parameterized Constructor
    Dog(int age) { 
        this->age = age; // Assign parameter 'age' to private variable 'age'
        cout << "Parameterized Constructor called!" << endl;
        cout << "This Dog's age is " << age << " years." << endl;
    }

    // Destructor
    ~Dog() {
        cout << "Destructor called! Cleaning up resources." << endl;
    }

    // Member function to simulate the dog barking
    void bark() {
        cout << "Woof! I am " << age << " years old.\n";
    }
};

int main() {
    cout << "Creating dog with parameterized constructor..." << endl;
    Dog obj1(15); // Parameterized constructor is invoked
    obj1.bark();  // Calls the bark method to display dog's age

    cout << "Creating dog with default constructor..." << endl;
    Dog obj2; // Default constructor is invoked
    obj2.bark();  // Calls the bark method to display dog's age

    cout << "Main program ended\n"; // End of program
    return 0; // Destructor is called automatically when objects go out of scope
}
