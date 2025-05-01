#include "5_9.h"
#include <iostream>
#include <cassert>
#include <cmath>
#include <fstream>


// Solves 3x3 linear system A * u = b using Gaussian elimination
void solve3by3(double **A, double *b, double *u) {
    // Forward elimination
    for (int k = 0; k < 2; k++) {  // Only two steps needed for 3x3
        for (int i = k + 1; i < 3; i++) {
            double m = A[i][k] / A[k][k];
            for (int j = k; j < 3; j++) {
                A[i][j] -= m * A[k][j];
            }
            b[i] -= m * b[k];
        }
    }

    // Back substitution
    for (int i = 2; i >= 0; i--) {
        double sum = b[i];
        for (int j = i + 1; j < 3; j++) {
            sum -= A[i][j] * u[j];
        }
        u[i] = sum / A[i][i];
    }
}


