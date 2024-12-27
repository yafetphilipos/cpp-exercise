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
Question A: Constructor in OOP

A constructor is a special method within a class that is used to initialize objects of that class.
It is automatically called when an instance (object) of the class is created.

The primary purpose of a constructor is to ensure that the object being created starts with valid and appropriate initial values for its attributes or properties.
It allows to set the initial state of an object, allocate necessary resources, and perform any necessary setup tasks.
*/

// Example:
#include <iostream>
using namespace std;

class Dog {
private:
    int age;
public:
    Dog(int age) { // Constructor
        this->age = age; // Assign parameter 'age' to private variable 'age'
        cout << "Constructor called!" << endl;
        cout << "This Dog's age is "<<age << endl;

    }
    void bark(){
        cout<< "Woof! I am " << age << " years old.\n";
    }
};

int main() {
    Dog obj(15); // Constructor is automatically invoked
    obj.bark(); // bark method is called
    cout<<"Main program ended\n";
    return 0;
}