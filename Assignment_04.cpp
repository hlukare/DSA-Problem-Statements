/* Problem Statement : Sparse Matrix: Write a menu driven C++ program with class for Sparse Matrix.
                        Write functions to perform Sparse Matrix operations as listed below 
                        1. Read sparse matrix 
                        2. Display sparse matrix 
                        3. Add two sparse matrices 
                        4. Find transpose using Simple transpose algorithm 
                        5. Find transpose using Fast transpose algorithm Compare complexity of simple and fast transpose using counter

*/
#include <iostream>
using namespace std;

const int M_TERMS = 100;

int rows, cols, n;
int matrix1[M_TERMS][3], matrix2[M_TERMS][3], result[M_TERMS][3];
int rowTerms[M_TERMS], startingPos[M_TERMS];

void read_Matrix(int matrix[M_TERMS][3], int& rows, int& cols, int& n) {
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    n = 0;
    cout << "Enter the dense matrix elements:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int value;
            cin >> value;
            if (value != 0) {
                matrix[n][0] = i;
                matrix[n][1] = j;
                matrix[n][2] = value;
                n++;
            }
        }
    }
}

void display_Matrix(int matrix[M_TERMS][3], int rows, int cols, int n) {
    cout << "Sparse Matrix :" << endl;
    for (int i = 0; i < n; i++) {
        cout << matrix[i][0] << " " << matrix[i][1] << " " << matrix[i][2] << endl;
    }
}

void addSparseMatrices(int matrix1[M_TERMS][3], int matrix2[M_TERMS][3], int result[M_TERMS][3], int rows, int cols, int& nResult) {
    int i = 0, j = 0, k = 0;
    while (i < n && j < n) {
        if (matrix1[i][0] < matrix2[j][0] || (matrix1[i][0] == matrix2[j][0] && matrix1[i][1] < matrix2[j][1])) {
            result[k][0] = matrix1[i][0];
            result[k][1] = matrix1[i][1];
            result[k][2] = matrix1[i][2];
            i++;
        } else if (matrix1[i][0] > matrix2[j][0] || (matrix1[i][0] == matrix2[j][0] && matrix1[i][1] > matrix2[j][1])) {
            result[k][0] = matrix2[j][0];
            result[k][1] = matrix2[j][1];
            result[k][2] = matrix2[j][2];
            j++;
        } else {
            result[k][0] = matrix1[i][0];
            result[k][1] = matrix1[i][1];
            result[k][2] = matrix1[i][2] + matrix2[j][2];
            i++;
            j++;
        }
        k++;
    }

    while (i < n) {
        result[k][0] = matrix1[i][0];
        result[k][1] = matrix1[i][1];
        result[k][2] = matrix1[i][2];
        i++;
        k++;
    }

    while (j < n) {
        result[k][0] = matrix2[j][0];
        result[k][1] = matrix2[j][1];
        result[k][2] = matrix2[j][2];
        j++;
        k++;
    }

    nResult = k;
}

void s_Transpose(int matrix[M_TERMS][3], int result[M_TERMS][3], int rows, int cols, int n) {
    result[0][0] = cols;
    result[0][1] = rows;
    result[0][2] = n;

    if (n > 0) {
        int B[M_TERMS][3];  // Temporary matrix for the result1 result
        B[0][0] = matrix[0][1];
        B[0][1] = matrix[0][0];
        B[0][2] = matrix[0][2];

        int index = 1;

        for (int j = 0; j < cols; j++) {
            for (int k = 1; k <= n; k++) {
                if (matrix[k][1] == j) {
                    B[index][0] = matrix[k][1];
                    B[index][1] = matrix[k][0];
                    B[index][2] = matrix[k][2];
                    index++;
                }
            }
        }

        // Copy the result1 matrix from B to the result
        for (int i = 0; i <= n; i++) {
            result[i][0] = B[i][0];
            result[i][1] = B[i][1];
            result[i][2] = B[i][2];
        }
    }
}


void f_Transpose(int matrix[M_TERMS][3], int result[M_TERMS][3], int rows, int cols, int n) {
    result[0][0] = cols;
    result[0][1] = rows;
    result[0][2] = n;

    if (n > 0) {
        int rowTerms[M_TERMS] = {0}; // Initialize rowTerms array

        for (int i = 1; i <= n; i++) {
            rowTerms[matrix[i][1]]++;
        }

        int startingPos[M_TERMS];
        startingPos[0] = 1;

        for (int i = 1; i < cols; i++) {
            startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
        }

        int currentPos[M_TERMS]; // Use an array to keep track of the current position
        for (int i = 0; i < cols; i++) {
            currentPos[i] = startingPos[i];
        }

        for (int i = 1; i <= n; i++) {
            int j = currentPos[matrix[i][1]];
            result[j][0] = matrix[i][1];
            result[j][1] = matrix[i][0];
            result[j][2] = matrix[i][2];
            currentPos[matrix[i][1]]++;
        }
    }
}

int main() {
    int choice;

    do {
        cout << "Menu:\n1. Read Sparse Matrix 1\n2. Display Sparse Matrix 1"
             << "\n3. Read Sparse Matrix 2\n4. Display Sparse Matrix 2\n5. Add Sparse Matrices\n"
             << "6. Transpose using Simple Algorithm\n7. Transpose using Fast Algorithm\n8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                read_Matrix(matrix1, rows, cols, n);
                break;
            case 2:
                display_Matrix(matrix1, rows, cols, n);
                break;
            case 3:
                read_Matrix(matrix2, rows, cols, n);
                break;
            case 4:
                display_Matrix(matrix2, rows, cols, n);
                break;
            case 5:
                int nResult;
                addSparseMatrices(matrix1, matrix2, result, rows, cols, nResult);
                cout << "Result of addition:" << endl;
                display_Matrix(result, rows, cols, nResult);
                break;
            case 6:
                int result1[M_TERMS][3];
                s_Transpose(matrix1, result1, cols, rows, n);
                cout << "Transpose using Simple Algorithm:" << endl;
                display_Matrix(result1, cols, rows, n);
                break;
            case 7:
                //int result1[M_TERMS][3];
                f_Transpose(matrix1, result1, cols, rows, n);
                cout << "Transpose using Fast Algorithm:" << endl;
                display_Matrix(result1, cols, rows, n);
                break;
        }
    }
    while(choice>0 && choice<8);
    return 0;
}
            
