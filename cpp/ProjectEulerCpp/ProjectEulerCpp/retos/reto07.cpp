#include "reto07.h"
/*
    By listing the first Six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
    What is the 10 001st prime number? 
*/

int reto07(){
    int primes[10001] = {2, 3, 5, 7, 11, 13};
    int idx = 6;
    int prime = 14;
    int i;
    while(idx<10001)
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
    return prime-1;
}