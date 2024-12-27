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
