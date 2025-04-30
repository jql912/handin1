#include "3_3.h"
#include <iostream>
#include <cassert>
#include <cmath>
#include <fstream>

void implicit_Euler(int n)
{
    //Check if n is greater than 1
    assert (n > 1);

    //Calculating step size h
    double h = 1.0 / (n-1);
    std::cout << "h = " << h << "\n";

    //x_0 and y_0
    double x = 0.0;
    double y = 1.0;

    //Output file
    //Adding starting values of x and y
    std::ofstream write_output("xy.dat");
    assert(write_output.is_open());

    while (x <= 1){
        write_output << x << ",";
        write_output << y;
        write_output << "\n";

        x += h;

        y = y/(1+h);
    }

    write_output.close();

}

int main()
{
    implicit_Euler(20);
    return(0);
}