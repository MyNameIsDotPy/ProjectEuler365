#include "reto04.h"
#include "../functions.h"

/*
    A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is
    9009 = 91 x 99.
    Find the largest palindrome made from the product of two 3-digit numbers.
*/



int reto04()
{
    int max_palindromic = 0;
    for(int i = 100; i<=999; i++)
    {
        for(int j = 100; j<=999; j++)
        {
            if(is_palindromic(i*j))
            {
                if(i*j>max_palindromic) max_palindromic = i*j;
            }
        }   
    }
    return max_palindromic;
}



