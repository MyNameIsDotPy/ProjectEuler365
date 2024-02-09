#include "reto46.h"

#include <iostream>

#include "../functions.h"

int reto46()
{
    std::set<int> primes = generate_primes_below_n(500000);
    for(int i = 9; i <= 500000; i+=2)
    {
        if(primes.count(i) != 0)
            continue;
        
        bool odd = true;

        for(unsigned int j = 1; 2*j*j < i; j++)
        {
            auto num = i - 2*j*j;
            if(primes.count(num) != 0)
            {
                odd = false;
                break;
            }
        }

        if(odd)
        {
            return i;
        }
    }
    return 0;
}
