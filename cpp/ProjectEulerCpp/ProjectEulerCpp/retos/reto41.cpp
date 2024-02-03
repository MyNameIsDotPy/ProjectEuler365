#include "reto41.h"

#include <iostream>

#include "../functions.h"

int reto41()
{
    int last_pandigital = 0;
    std::cout << "PrimesGenerated" << std::endl;
    for(int i = 2; i <= 987654321; i++)
    {
        std::set<int> digits = {};
        int num = i;
        bool pandigital = true;
        int sum = 0;
        if(is_prime(i))
        {
            while(num>0)
            {
                int digit = num%10;
                num /= 10;
                if(digit != 0 && digits.find(digit) == digits.end())
                {
                    digits.insert(digit);
                    sum += digit;
                }
                else
                {
                    pandigital = false;
                    break;
                }
            }
            int n = digits.size();
            if(pandigital && sum == n*(n+1)/2)
            {
                last_pandigital = i;
                std::cout << i << "\n";
            }
        }
        
    }
    return last_pandigital;
}