#include "reto36.h"

#include <iostream>
#include <string>

#include "../functions.h"


std::string to_binary_string(int n);

int reto36()
{
    int total_sum = 0;
    for(int i = 0; i < 1000000; i++)
    {
        if(is_palindromic(i))
        {
            std::string binary = to_binary_string(i);
            if(is_palindromic(binary))
            {
                total_sum += i;
            }
        }
    }
    return total_sum;
}

std::string to_binary_string(int n)
{
    std::string binary_number;
    while (n>0)
    {
        if(n%2 == 0)
        {
            binary_number += "0";
        }
        else
        {
            binary_number += "1";
        }
        n /= 2;
    }
    std::reverse(binary_number.begin(), binary_number.end());
    return  binary_number;
    
}

