#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

const int MAX_STUDENTS = 10;

void displayMenu() {
    std::cout << "\n1. Selection Sort\n";
    std::cout << "2. Bubble Sort\n";
    std::cout << "3. Insertion Sort\n";
    std::cout << "4. Shell Sort\n";
    std::cout << "5. Quick Sort\n";
    std::cout << "6. Radix Sort\n";
    std::cout << "7. Display Top 5 Scores\n";
    std::cout << "8. STL Sort\n";
    std::cout << "9. Exit\n";
    std::cout << "Enter your choice: ";
}

void inputMarks(float marks[], int size) {
    std::cout << "Enter percentage marks for " << size << " students:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << "Enter marks for student " << i + 1 << ": ";
        std::cin >> marks[i];
    }
}

void generateRandomMarks(float marks[], int size) {
    std::cout << "Generating random percentage marks for " << size << " students...\n";
    for (int i = 0; i < size; ++i) {
        marks[i] = rand() % 101; // Random marks between 0 and 100
    }
}

void selectionSort(float arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

void bubbleSort(float arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertionSort(float arr[], int size) {
    for (int i = 1; i < size; ++i) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void shellSort(float arr[], int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; ++i) {
            float temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int partition(float arr[], int low, int high) {
    float pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] < pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(float arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int getMax(float arr[], int n) {
    float max = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void countSort(float arr[], int n, int exp) {
    const int RADIX = 10;
    float output[n];
    int count[RADIX] = {0};

    for (int i = 0; i < n; ++i) {
        count[int(arr[i] / exp) % RADIX]++;
    }

    for (int i = 1; i < RADIX; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; --i) {
        output[count[int(arr[i] / exp) % RADIX] - 1] = arr[i];
        count[int(arr[i] / exp) % RADIX]--;
    }

    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
}

void radixSort(float arr[], int n) {
    float max = getMax(arr, n);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
    }
}

void displayTopScores(float arr[], int size, int top) {
    std::cout << "Top " << top << " scores:\n";
    for (int i = size - 1; i >= size - top; --i) {
        std::cout << arr[i] << "%\n";
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    float marks[MAX_STUDENTS];
    int size = MAX_STUDENTS;

    int choice;
    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                inputMarks(marks, size);
                selectionSort(marks, size);
                std::cout << "Array sorted using Selection Sort.\n";
                break;
            case 2:
                inputMarks(marks, size);
                bubbleSort(marks, size);
                std::cout << "Array sorted using Bubble Sort.\n";
                break;
            case 3:
                inputMarks(marks, size);
                insertionSort(marks, size);
                std::cout << "Array sorted using Insertion Sort.\n";
                break;
            case 4:
                inputMarks(marks, size);
                shellSort(marks, size);
                std::cout << "Array sorted using Shell Sort.\n";
                break;
            case 5:
                inputMarks(marks, size);
                quickSort(marks, 0, size - 1);
                std::cout << "Array sorted using Quick Sort.\n";
                break;
            case 6:
                inputMarks(marks, size);
                radixSort(marks, size);
                std::cout << "Array sorted using Radix Sort.\n";
                break;
case 7:
                displayTopScores(marks, size, 5);
                break;
            case 8:
                inputMarks(marks, size);
                std::sort(marks, marks + size);
                std::cout << "Array sorted using STL Sort.\n";
                break;
            case 9:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 9);

    return 0;
}
