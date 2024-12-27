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