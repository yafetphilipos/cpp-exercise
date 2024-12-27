/* Question D: Constructor Overloading 
In short: Multiple constructors in a class with different parameters.

Constructor overloading means having multiple constructors within the same class, each with a different parameter list.
This allows you to create objects of the class in various ways, providing flexibility in how you initialize them.

Constructors are overloaded based on their signatures, which include:
    1. Number of parameters: Constructors with different numbers of parameters are considered different.
    2. Types of parameters: Constructors with the same number of parameters but different parameter types are also considered different.
    3. Order of parameters: Constructors with the same number and types of parameters but in a different order are also different.
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

    // Parameterized Constructor with one argument
    Dog(int age) { 
        this->age = age; // Assign parameter 'age' to private variable 'age'
        cout << "Parameterized Constructor called!" << endl;
        cout << "This Dog's age is " << age << " years." << endl;
    }

    // Parameterized Constructor with two arguments (Constructor Overloading)
    Dog(int age, string name) { 
        this->age = age; // Assign parameter 'age' to private variable 'age'
        cout << "Overloaded Constructor called!" << endl;
        cout << "This Dog's name is " << name << " and age is " << age << " years." << endl;
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

    cout << "Creating dog with overloaded constructor..." << endl;
    Dog obj3(8, "Buddy"); // Overloaded constructor is invoked
    obj3.bark();  // Calls the bark method to display dog's age

    cout << "Main program ended\n"; // End of program
    return 0; // Destructor is called automatically when objects go out of scope
}
