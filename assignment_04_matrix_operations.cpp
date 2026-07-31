// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Maximum size allowed for matrix dimensions
const int MAX = 10;

// Function prototypes
void inputMatrix(int matrix[MAX][MAX], int rows, int cols, string name = "");
void printMatrix(const int matrix[MAX][MAX], int rows, int cols);
void transposeMatrix(const int input[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void addMatrices(const int A[MAX][MAX], const int B[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void multiplyMatrices(const int A[MAX][MAX], const int B[MAX][MAX], int result[MAX][MAX], int M, int N, int P);

int main() {
    // ==========================================
    // PART A - Transpose a Matrix
    // ==========================================
    cout << "--- PART A: Transpose Matrix ---" << endl;
    int rowsA, colsA;
    cout << "Enter number of rows: ";
    cin >> rowsA;
    cout << "Enter number of columns: ";
    cin >> colsA;

    int A[MAX][MAX];
    inputMatrix(A, rowsA, colsA);

    cout << "\nOriginal Matrix:" << endl;
    printMatrix(A, rowsA, colsA);

    int A_transposed[MAX][MAX];
    transposeMatrix(A, A_transposed, rowsA, colsA);

    cout << "\nTransposed Matrix:" << endl;
    printMatrix(A_transposed, colsA, rowsA);

    // ==========================================
    // PART B - Add Two Matrices
    // ==========================================
    cout << "\n--- PART B: Add Two Matrices ---" << endl;
    int rowsB, colsB;
    cout << "Enter number of rows: ";
    cin >> rowsB;
    cout << "Enter number of columns: ";
    cin >> colsB;

    int B1[MAX][MAX], B2[MAX][MAX], sumResult[MAX][MAX];
    
    cout << "For First Matrix:" << endl;
    inputMatrix(B1, rowsB, colsB);
    
    cout << "For Second Matrix:" << endl;
    inputMatrix(B2, rowsB, colsB);

    addMatrices(B1, B2, sumResult, rowsB, colsB);

    cout << "\nSum Result:" << endl;
    printMatrix(sumResult, rowsB, colsB);

    // ==========================================
    // PART C - Multiply Two Matrices
    // ==========================================
    cout << "\n--- PART C: Multiply Two Matrices ---" << endl;
    int M, N, P;
    cout << "Enter rows for Matrix A (M): ";
    cin >> M;
    cout << "Enter columns for Matrix A / rows for Matrix B (N): ";
    cin >> N;
    cout << "Enter columns for Matrix B (P): ";
    cin >> P;

    int multA[MAX][MAX], multB[MAX][MAX], multResult[MAX][MAX];

    cout << "Input Matrix A (" << M << "x" << N << "):" << endl;
    inputMatrix(multA, M, N, "A");

    cout << "Input Matrix B (" << N << "x" << P << "):" << endl;
    inputMatrix(multB, N, P, "B");

    multiplyMatrices(multA, multB, multResult, M, N, P);

    cout << "\nProduct Result (A x B):" << endl;
    printMatrix(multResult, M, P);

    return 0;
}

// Function to handle element-by-element user input
void inputMatrix(int matrix[MAX][MAX], int rows, int cols, string name) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Function to print a matrix in a neat, aligned grid using setw()
void printMatrix(const int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// PART A: Transpose (rows become columns, columns become rows)
void transposeMatrix(const int input[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = input[i][j];
        }
    }
}

// PART B: Element-wise addition of two matrices
void addMatrices(const int A[MAX][MAX], const int B[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// PART C: Matrix multiplication (A of M x N multiplied by B of N x P)
void multiplyMatrices(const int A[MAX][MAX], const int B[MAX][MAX], int result[MAX][MAX], int M, int N, int P) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            result[i][j] = 0;
            for (int k = 0; k < N; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}