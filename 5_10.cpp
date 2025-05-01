#include "5_10.h"
#include <iostream>
#include <cassert>
#include <cmath>
#include <fstream>

// Swap two doubles
void swapDouble(double& a, double& b) {
    double temp = a;
    a = b;
    b = temp;
}

// Swap two rows of a matrix (swap pointers)
void swapRows(double*& row1, double*& row2) {
    double* temp = row1;
    row1 = row2;
    row2 = temp;
}

// Gaussian elimination with partial pivoting
void gaussian_elimination(double** A, double* b, double* u, int n) {
    // Forward elimination with partial pivoting
    for (int k = 0; k < n - 1; ++k) {
        // Find the row with the largest pivot
        int pivotRow = k;
        double maxVal = fabs(A[k][k]);
        for (int i = k + 1; i < n; ++i) {
            if (fabs(A[i][k]) > maxVal) {
                maxVal = fabs(A[i][k]);
                pivotRow = i;
            }
        }

        // Swap rows in A and b
        if (pivotRow != k) {
            swapRows(A[k], A[pivotRow]);
            swapDouble(b[k], b[pivotRow]);
        }

        // Eliminate entries below pivot
        for (int i = k + 1; i < n; ++i) {
            double m = A[i][k] / A[k][k];
            for (int j = k; j < n; ++j) {
                A[i][j] -= m * A[k][j];
            }
            b[i] -= m * b[k];
        }
    }

    // Back substitution
    for (int i = n - 1; i >= 0; --i) {
        double sum = b[i];
        for (int j = i + 1; j < n; ++j) {
            sum -= A[i][j] * u[j];
        }
        u[i] = sum / A[i][i];
    }
}
