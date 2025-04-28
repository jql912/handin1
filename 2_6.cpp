#include "2_6.h"
#include <iostream>
#include <cassert>
#include <cmath>

/* 
The Newton-Raphson algorithm for the given function f(x) = e^x + x^3 -5, 
with x_0 = 0, is given as:

x_i = x_(i-1) - ((e^x + x^3 -5) / (3(x^2) + e^x))
*/

/* 2.6.2
double newton_Raphson(double initialGuess
    //, double epsilon
    ) {
    
    double array[101];

    array[0] = initialGuess;
    
    for (int i=1; i < 101; i++) {
        array[i] = array[i-1] - (exp(array[i-1]) + pow(3,array[i-1]) -5) / (3*pow(array[i-1],2) + exp(array[i-1]));
        std::cout << "x_" << i << " = " << array[i] << "\n";
    }

    return(0.0);

}
*/

/* 2.6.3
double newton_Raphson(double initialGuess
    //, double epsilon
    ) {
    
    double array[101];

    array[0] = initialGuess;
    double previous_diff = 1e10;
    
    for (int i=1; i < 101; i++) {
        array[i] = array[i-1] - (exp(array[i-1]) + pow(3,array[i-1]) -5) / (3*pow(array[i-1],2) + exp(array[i-1]));
        std::cout << "x_" << i << " = " << array[i] << "\n";

        double current_diff = fabs(array[i] - array[i-1]);
        assert(current_diff <= previous_diff);
        previous_diff = current_diff;

    }

    return(0.0);

}
*/

/*2.6.4
double newton_Raphson(double initialGuess
    //, double epsilon
    ) {
    
    double x_prev = initialGuess;
    double x_next;
    double previous_diff = 1e10;
    
    for (int i=1; i < 101; i++) {
        x_next = x_prev - (exp(x_prev) + pow(3,x_prev) -5) / (3*pow(x_prev,2) + exp(x_prev));
        std::cout << "x_" << i << " = " << x_next << "\n";

        double current_diff = fabs(x_next - x_prev);
        assert(current_diff <= previous_diff);

        x_prev = x_next;
        previous_diff = current_diff;

    }

    return(0.0);

}
*/
/*
double newton_Raphson(double initialGuess, double epsilon) 
{
    double x_prev = initialGuess;
    double x_next;
    double previous_diff = 1e10;
    
    for (int i=1; i < 101; i++) {
        while (previous_diff > epsilon) 
        {
            x_next = x_prev - (exp(x_prev) + pow(3,x_prev) -5) / (3*pow(x_prev,2) + exp(x_prev));
            std::cout << "x_" << i << " = " << x_next << "\n";

            double current_diff = fabs(x_next - x_prev);
            assert(current_diff <= previous_diff);

            x_prev = x_next;
            previous_diff = current_diff;
        }
    }

    return(0.0);
}

*/

double newton_Raphson(double initialGuess, double epsilon) 
{
    double x_prev = initialGuess;
    double x_next;
    double previous_diff = 1e10; //large number to start with as safety

    int i = 0;  
    
    //while loop until the difference between two iterations is less than epsilon
    while (previous_diff > epsilon && i < 100)  
    {
        //next iteration
        x_next = x_prev - (exp(x_prev) + pow(x_prev, 3) - 5) / (3 * pow(x_prev, 2) + exp(x_prev));
        
        //difference between the last and the new iteration
        double current_diff = fabs(x_next - x_prev);

        std::cout << "x_" << i+1 << " = " << x_next << ", difference from last= " << current_diff << "\n";

        //assert that the difference is less than the previous difference,
        //otherwise the algorithm is faulty as it is not converging
        assert(current_diff <= previous_diff);

        //update the values for next iteration, if the while loop continues
        x_prev = x_next;
        previous_diff = current_diff;
        i++; 
    }

    return(x_prev);
}

int main()
{
    //newton_Raphson(0.0);
    newton_Raphson(0.0, 0.00001);
    return(0);
}