#include "reto03.h"
#include <cmath>
#include "../functions.h"

/*
    The prime factors of 13195 are 5, 7, 13 and 29.
    What is the largest prime factor of the number 600851475143? 
*/

bool is_prime(int x);

int reto03()
{
    constexpr long long value = 600851475143;
    int max_factor = 1;
    for(int i = 1; i<sqrt(value); i++)
    {
        if(value%i==0 && is_prime(i))
        {
            max_factor = i;
        }
    }
    return max_factor;
}


