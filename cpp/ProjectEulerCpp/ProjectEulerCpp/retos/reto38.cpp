#include "reto38.h"

#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "../functions.h"


int reto38()
{
    std::string max_pandigit = "123456789";
    
    for(int i = 1; i < 493827160; i++)
    {
        int idx = 1;
        bool is_pandigital = true;
        std::vector<int> digits;
        bool greater = false;

        while(digits.size() < 9 && is_pandigital)
        {
            int copy = i*idx;
            idx++;
            while(copy > 0)
            {
                int b = pow(10,num_lenght(copy)-1);
                int digit = copy/b;
                copy = copy - digit*b;

                
                if(digit < max_pandigit[digits.size()] - 48 && !greater)
                {
                    is_pandigital = false;
                    break;
                }
                if(digit > max_pandigit[digits.size()] - 48)
                {
                    greater = true;
                }
                
                int cnt = std::count(digits.begin(), digits.end(), digit);
                if(cnt != 0 || digit == 0)
                {
                    is_pandigital = false;
                    break;
                }
                digits.push_back(digit);
            }
        }
        if(is_pandigital && idx > 1)
        {
            std::string new_pandigit = "";
            for(int c: digits)
            {
                new_pandigit += (c+48);
            }
            max_pandigit = new_pandigit;
            
            std::cout << max_pandigit << ": " << i << std::endl;
            
        }
    }
    return 0;
}

