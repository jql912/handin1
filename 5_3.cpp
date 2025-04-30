#include "5_3.h"
#include <iostream>
#include <cassert>
#include <cmath>
#include <fstream>

double value1 = 5;
double value2 = 10;



//double* a= &value1;
//double* b= &value2;

void swap_pointer(double *a, double *b){

    //temporary storage variable
    double storage;     

    storage = *a;  //storage is now value1 (storage was empty before)
    *a = *b;        //The value pointed at by a is now value2
    *b = storage;   //he value pointed at by b is now storage, which now is value1

}


//double& a= value1;
//double& b= value2;

void swap_ref(double &a, double &b){

    double storage;     //temporary storage variable

    storage = a;  //storage is now value1 (storage was empty before)
    a = b;        //The value of referance a is overwritten by reference b, THUS value1 is now value2
    b = storage;   //The value of referance b is overwritten by storage, THUS value2 is now value1

}

/*
int main()
{
    swap_pointer(a, b);
    swap_ref(a, b);
    return(0);
}
*/