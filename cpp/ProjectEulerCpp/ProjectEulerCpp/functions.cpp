#include "functions.h"

#include <cmath>

int factorial(int n)
{
    if(n==0)
        return 1;
    return n*factorial(n-1);
}

int* generate_n_primes(const int n)
{
    int* primes = new int[n];
    int i, idx = 0, prime = 2;
    while(idx < n)
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
            idx++;
        }
        prime++;
    }
    return primes;
}

int* generate_primes_below_n(const int n)
{
    int* primes = new int[n];
    int i, idx = 0, prime = 2;
    while(prime < n)
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
            idx++;
        }
        prime++;
    }
    return primes;
}

bool is_prime(int n)
{
    for(int i = 2; i<sqrt(n); i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}