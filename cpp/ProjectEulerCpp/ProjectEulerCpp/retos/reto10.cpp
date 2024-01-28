#include "reto10.h"

#include <iostream>

#include "../functions.h"
/*
    The sum of the primes below 10 is 2 + 3 5 + 7 17
    Find the sum of all the primes below two million.
*/
long long int reto10()
{
    int* primes = new int[200000];
    int i, idx = 0, prime = 2;
    long long int sum = 0;

    while(prime < 2000000)
    {
        for(i = 0; i<idx; i++)
        {
            if(prime%primes[i]==0)
            {
                break;
            }
        }
        if(i==idx)
        {
            primes[idx] = prime;
            sum += prime;
            idx++;
        }
        prime++;
    }
    return sum;
}