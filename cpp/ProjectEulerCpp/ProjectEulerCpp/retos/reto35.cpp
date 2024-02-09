#include "reto35.h"

#include <cmath>
#include <iostream>

#include "../functions.h"


int number_digits(int n);
int rotate_number(int n, int rotations);


int reto35()
{
    std::cout << is_prime(14) << std::endl;
    int sum = 0;
    std::set<int> primes = generate_primes_below_n(1000000);

    //TODO: UPDATE CHALLENGE WITH NEW GENERATE PRIMES IMPLEMENTATION
    
    /*for(int n = 0; primes[n] > 0; n++)
    {
        int prime = primes[n];
        int size = number_digits(prime);
        bool ciclical = true;
        for(int i = 1; i < size; i++)
        {
            int rotated = rotate_number(prime, i);
            if(!is_prime(rotated))
            {
                ciclical = false;
                break;
            }
        }
        if(ciclical)
        {
            std::cout << prime << std::endl;
            sum++;
        }
    }*/
    return sum;
}

int rotate_number(int n, int rotations)
{
    int size = number_digits(n);
    int front = n%static_cast<int>(pow(10, rotations % size));
    int back = n/static_cast<int>(pow(10,rotations%size));
    return static_cast<int>(pow(10, size-rotations))* front + back;
}

int number_digits(int n)
{
    int digits = 0;
    while(n>0)
    {
        digits++;
        n/=10;
    }
    return digits;
}