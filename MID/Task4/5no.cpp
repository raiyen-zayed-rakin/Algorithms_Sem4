//Write a program to do addition, subtraction, multiplication of  transpose matrices of two matrices. 
#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

void transpose(int matrix[][MAX_SIZE], int rows, int cols, int result[][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

void addition(int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE], int rows, int cols) {
    int result[MAX_SIZE][MAX_SIZE];

    int transposedMatrix2[MAX_SIZE][MAX_SIZE];
    transpose(matrix2, rows, cols, transposedMatrix2);

    //addition
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = matrix1[i][j] + transposedMatrix2[i][j];
        }
    }

    //Print
    cout << "Matrix Addition Result:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

//subtraction
void matrixSubtraction(int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE], int rows, int cols) {
    int result[MAX_SIZE][MAX_SIZE];

    int transposedMatrix2[MAX_SIZE][MAX_SIZE];
    transpose(matrix2, rows, cols, transposedMatrix2);

    //subtraction
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = matrix1[i][j] - transposedMatrix2[i][j];
        }
    }

    //Print
    cout << "Matrix Subtraction Result:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

//multiplication
void matrixMultiplication(int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE], int row1, int col1, int col2) {
    int result[MAX_SIZE][MAX_SIZE];

    int transposedMatrix2[MAX_SIZE][MAX_SIZE];
    transpose(matrix2, col1, col2, transposedMatrix2);

    //multiplication
    for (int i = 0; i < row1; ++i) {
        for (int j = 0; j < col2; ++j) {
            int sum = 0;
            for (int k = 0; k < col1; ++k) {
                sum += matrix1[i][k] * transposedMatrix2[j][k];
            }
            result[i][j] = sum;
        }
    }

    //Print
    cout << "Matrix Multiplication Result:\n";
    for (int i = 0; i < row1; ++i) {
        for (int j = 0; j < col2; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int row1, col1, row2, col2;

    cout<<"Enter the sizes of the first matrix: ";
    cout<<"Enter row : ";
    cin>>row1;
    cout<<"Enter column : ";
    cin>>col1;

    int matrix1[MAX_SIZE][MAX_SIZE];
    cout << "Enter sizess of the first matrix:\n";
    //matrix 1
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
          cout<<"arr["<<i<<"]["<<j<<"] : ";
          cin>>matrix1[i][j];
        }
    }

    cout << "Enter the sizes of the second matrix: ";
    cout<<"Enter row : ";
    cin>>row2;
    cout<<"Enter col : ";
    cin>>col2;

    // matrix 2
    int matrix2[MAX_SIZE][MAX_SIZE];
    cout << "Enter elements of the second matrix:\n";
    for (int i = 0; i < row2; ++i) {
        for (int j = 0; j < col2; ++j) {
          cout<<"arr["<<i<<"]["<<j<<"] : ";
          cin >> matrix2[i][j];
        }
    }

    // Check
    if (row1 != row2 || col1 != col2) {
        cout << "Matrices must have the same dimensions for addition, subtraction, and multiplication." << endl;
        return 1;
    }

    addition(matrix1, matrix2, row1, col1);
    matrixSubtraction(matrix1, matrix2, row1, col1);
    matrixMultiplication(matrix1, matrix2, row1, col1, col2);

    return 0;
}
