#include "5_6.h"
#include <iostream>
#include <cassert>
#include <cmath>
#include <fstream>

//Multiply two matrices A and B and store the result in matrix res
void Multiply(double **res, double **A, double **B, int ARows, int ACols, int BRows, int BCols){

        //Check if the number of columns in A is equal to the number of rows in B
        assert(ACols == BRows);

        //Fill out the result matrix res
        for (int i = 0; i < ARows; i++) {         // loop over rows of A
            for (int j = 0; j < BCols; j++) {     // loop over columns of B
                res[i][j] = 0;
                for (int k = 0; k < ACols; k++) { // shared dimension
                    res[i][j] += A[i][k] * B[k][j];
                }
            }
        }

    }

// Multiply a vector A with a matrix B and store the result in vector res
void Multiply(double *res, double *A, double **B, int ACols, int BRows, int BCols){ 
    assert(ACols == BRows);  

    for (int j = 0; j < BCols; j++) {  // result index = column of B
        res[j] = 0;
        for (int i = 0; i < ACols; i++) {
            res[j] += A[i] * B[i][j];  // dot product of A with column j of B
        }
    }

}

// Multiply a matrix A with a vector B and store the result in vector res
void Multiply(double *res, double **A, double *B, int ARows, int ACols, int BRows){
    assert(ACols == BRows);  

    for (int j = 0; j < ARows; j++) {  // loop over rows of A
        res[j] = 0;
        for (int i = 0; i < ACols; i++) {
            res[j] += A[j][i] * B[i];  // dot product of A with column j of B
        }
    }

}

//Multiply a scalar with a matrix B
void Multiply(double **res, double scalar, double **B, int BRows, int BCols){

    //Fill out the result matrix res
    for (int i = 0; i < BRows; i++) {         // loop over rows of B
        for (int j = 0; j < BCols; j++) {     // loop over columns of B
            res[i][j] = scalar * B[i][j];
        }
    }

}

//Multiply a matrix B with a scalar
void Multiply(double **res, double **B, double scalar, int BRows, int BCols){

        //Fill out the result matrix res
        for (int i = 0; i < BRows; i++) {         // loop over rows of B
            for (int j = 0; j < BCols; j++) {     // loop over columns of B
                res[i][j] = scalar * B[i][j];
            }
        }
}
