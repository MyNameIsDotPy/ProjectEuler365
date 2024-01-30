#include "reto37.h"

#include <iostream>
#include <set>

#include "../functions.h"

int reto37()
{
    int* primes = generate_primes_below_n(1000000);
    std::cout << "primes generated" << std::endl;
    int primes_found = 0;
    int total_sum = 0;
    for(int i = 11; primes_found < 11; i+=2)
    {
        
        bool prime = true;
        // Truncate left
        int left = i;
        int right = i;
        int lenght = num_lenght(i);
        
        while(left > 0 && prime)
        {
            //std::cout << i << ": " << left << std::endl;

            prime = is_prime(left, primes);
            
            left /= 10;
        }

        while(right > 0 && prime)
        {
            
            prime = is_prime(right, primes);
            
            right %= static_cast<int>(pow(10, lenght - 1));
            lenght--;
        }
        if(!prime)
        {
            continue;
        }
        primes_found++;
        total_sum += i;
        std::cout << i << std::endl;
    }
    return total_sum;
}