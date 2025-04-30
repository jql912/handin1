#include "5_4.h"
#include <iostream>
#include <cassert>
#include <cmath>
#include <fstream>

double a[3] = {1.0, 2.0, 3.0};
int length = 3;


double calc_std(double a[], int length){

    if (length < 2) {
        std::cerr << "Error: length of array must be greater than 1. Program terminated. \n";

        return -1;

    } else {
        double dev;
        double inner_sum= 0.0;
        double s_dev;

        //Use calc_mean to find mean
        double mean = calc_mean(a, length);

        //find numerator of standard deviation
        for (int i = 0; i < length; i++) {
            dev = a[i] - mean;
            inner_sum += dev * dev; 
        }

        //find standard deviation
        s_dev = sqrt(inner_sum / (length - 1));

        std::cout << "the standard deviation is " << s_dev << "\n";

        return s_dev;
    }
    
}


double calc_mean(double a[], int length)
{
    //sum of all values in array a
    double sum = 0.0;
    for (int i = 0; i < length; i++) {
        sum += a[i];
    }

    //mean of all values in array a
    double mean = sum / length;

    return mean;
}

int main()
{
    calc_std(a, length);
    return(0);
}