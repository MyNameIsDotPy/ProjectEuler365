#include "reto10.h"
/*
    The sum of the primes below 10 is 2 + 3 5 + 7 17
    Find the sum of all the primes below two million.
*/
long long int reto10()
{
    int primes[200000] = {2, 3, 5, 7, 11, 13};
    int i, idx = 6, prime = 13;
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
            idx++;
        }
        prime++;
    }
    long long int sum = 0;
    for(int j = 0; j<idx; j++)
    {
        sum+=primes[j];
    }
    return sum;
}