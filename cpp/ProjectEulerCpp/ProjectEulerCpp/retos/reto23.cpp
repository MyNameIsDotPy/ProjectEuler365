#include "reto23.h"

#include <iostream>
#include <vector>

bool is_abundant(int n);

std::vector<int> abundant_numbers;

int reto23()
{
    // Generate all abundant numbers below 28.123
    for(int i = 1; i < 28123; i++)
    {
        if(is_abundant(i))
        {
            abundant_numbers.push_back(i);
        }
    }

    int total_sum = 0;
    for(int n = 1; n<=28123; n++)
    {
        int i = 0, j = abundant_numbers.size()-1;

        // Check if a number can be writen by 2 abundant numbers
        while(true)
        {

            int numbers_sum = abundant_numbers[i] + abundant_numbers[j];
        
            if(numbers_sum == n)
            {
                //std::cout << n << ": true" << std::endl;
                break;
            }
            if(i>=j)
            {
                //std::cout << n << ": false" << std::endl;
                total_sum+=n;
                break;
            }
            if(numbers_sum > n)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
    }
    
    return total_sum;
}

bool is_abundant(int n)
{
    int sum = 0;
    for(int i = 1; i <= n/2; i++)
    {
        if(n%i==0)
        {
            sum += i;
        }
    }
    return sum>n;
}