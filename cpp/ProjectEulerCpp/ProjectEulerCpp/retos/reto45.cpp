#include "reto45.h"
#include <cmath>
#include <iostream>


bool isPentagonal(unsigned long long n)
{
    unsigned long long i = (1+std::sqrt(24*n+1))/6;
    
    return n == i*(3*i-1)/2;
}

unsigned int hexagonal(unsigned int n){
    return n*(2*n-1);
}

int reto45()
{
    unsigned int n = 144;
    unsigned int b;
    
    while(true){
        b = hexagonal(n);
        //std::cout << b << std::endl;
        if(isPentagonal(b)){// && isTriangular(b)){
            return b;
        }
        n++;
    }
}