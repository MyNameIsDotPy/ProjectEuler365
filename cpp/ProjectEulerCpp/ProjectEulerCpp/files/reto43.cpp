#include "reto43.h"

#include <algorithm>
#include <string>

// auto defined stoi func because std::stoi causes an abort error, idk why
long long int strToInt(std::string n)
{
    long long int num = 0;
    for(char c : n)
    {
        num *= 10;
        num += c - 48;
    }
    return num;
}

long long int reto43() {
    long long int total_sum = 0;
    int primes[] = {2,3,5,7,11,13,17};
    std::string pandigital = "0123456789";
    
    do
    {
        bool divisible = true;
        for(int i = 0; i < 7; i++)
        {
             
            if(strToInt(pandigital.substr(i+1, 3)) % primes[i] != 0)
            {
                divisible = false;
                break;
            }
        }
        if(divisible)
        {
            total_sum = total_sum + strToInt(pandigital);
        }
    }
    // Didn't even know this function existed till now
    while(std::next_permutation(pandigital.begin(), pandigital.end()));
    
    return total_sum;
}