#include "reto44.h"

#include <iostream>


bool is_pentagonal(int n);
int pentagonal(int n);

int reto44()
{
    int min_dif = 9999999;
    for(int i = 1; i < 10000; i++)
    {
        for(int j = 1; j < 10000; j++)
        {
            int sum = pentagonal(j) + pentagonal(i);  
            int dif = pentagonal(j) - pentagonal(i);

            if(is_pentagonal(sum) && is_pentagonal(dif))
            {
                if(dif < min_dif)
                {
                    min_dif = dif;
                }
            }
        }        
    }
    return min_dif;
}

int pentagonal(int n)
{
    return n*(3*n-1)/2;
}

bool is_pentagonal(int n)
{
    int a = (1 + std::sqrt(1+24*n))/6;
    float b = (1 + std::sqrt(1+24*n))/6;
    return a == b;
}