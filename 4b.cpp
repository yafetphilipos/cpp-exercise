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
 Question B: Destructor in OOP
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
#include <iostream>
using namespace std;

class Dog {
private:
    int age; // Private member variable to store the age of the dog

public:
    // Constructor
    Dog(int age) { 
        this->age = age; // Assign parameter 'age' to private variable 'age'
        cout << "Constructor called!" << endl;
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
    Dog obj(15); // Constructor is automatically invoked, creates an object of class Dog
    obj.bark();  // Calls the bark method to display dog's age
    cout << "Main program ended\n"; // End of program
    return 0; // Destructor is called automatically when obj goes out of scope
}
