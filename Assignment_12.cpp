#include <iostream>
#include <algorithm>
#include<cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_STUDENTS = 10;
bool linearSearch(const int arr[], int size, int key) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key) {
            return true; // Found
        }
    }
    return false; // Not found
}

bool binarySearch(const int arr[], int size, int key) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return true; // Found
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return false; // Not found
}

bool jumpSearch(const int arr[], int size, int key) {
    int jump = sqrt(size); // Jump size
    int prev = 0;

    while (arr[min(jump, size) - 1] < key) {
        prev = jump;
        jump += sqrt(size);
        if (prev >= size) {
            return false; // Not found
        }
    }

    for (int i = prev; i < min(jump, size); ++i) {
        if (arr[i] == key) {
            return true; // Found
        }
    }

    return false; // Not found
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int rollNumbers[MAX_STUDENTS];
    int size;
    char choice;

    cout << "Enter the number of students (up to " << MAX_STUDENTS << "): ";
    cin >> size;

    if (size > MAX_STUDENTS) {
        cout << "Error: Number of students exceeds maximum limit." << endl;
        return 1;
    }

    cout << "Do you want to enter roll numbers manually? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        cout << "Enter the roll numbers:" << endl;
        for (int i = 0; i < size; ++i) {
            cout << "Roll number " << i + 1 << ": ";
            cin >> rollNumbers[i];
        }
    } else {
        srand(static_cast<unsigned>(time(0)));
        for (int i = 0; i < size; ++i) {
            rollNumbers[i] = rand() % 100; 
        }
        cout << "Randomly generated roll numbers: ";
        printArray(rollNumbers, size);
    }

    sort(rollNumbers, rollNumbers + size);
    int searchKey;
    cout << "Enter the roll number to search: ";
    cin >> searchKey;

    // Linear search
    if (linearSearch(rollNumbers, size, searchKey)) {
        cout << "Linear Search: Student attended the lecture." << endl;
    } else {
        cout << "Linear Search: Student did not attend the lecture." << endl;
    }

    // Binary search
    if (binarySearch(rollNumbers, size, searchKey)) {
        cout << "Binary Search: Student attended the lecture." << endl;
    } else {
        cout << "Binary Search: Student did not attend the lecture." << endl;
    }

    // Jump search
    if (jumpSearch(rollNumbers, size, searchKey)) {
        cout << "Jump Search: Student attended the lecture." << endl;
    } else {
        cout << "Jump Search: Student did not attend the lecture." << endl;
    }

    return 0;
}
