#include "reto04.h"
#include <cmath>

/*
    A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is
    9009 = 91 x 99.
    Find the largest palindrome made from the product of two 3-digit numbers.
*/

int num_lenght(int x);
bool is_palindromic(int x);
bool is_palindromic(int x, int length);

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

bool is_palindromic(const int x)
{
    return is_palindromic(x, num_lenght(x));
}

bool is_palindromic(const int x, const int length)
{
    int a = static_cast<int>(x / (pow(10, length-1)));
    int b = x%10;
    
    if(length == 0 || length == 1) return true;
    if(length == 2 && a==b) return true;
    
    return a==b && is_palindromic((x/10)-a*pow(10, length-2), length-2);
}

int num_lenght(const int x)
{
    if(x>10)
    {
        return num_lenght(x/10) + 1;
    }
    return 1;
}