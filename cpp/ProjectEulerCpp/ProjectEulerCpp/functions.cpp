#include "functions.h"

#include <cmath>

int factorial(int n)
{
    if(n==0)
        return 1;
    return n*factorial(n-1);
}

int* generate_n_primes(const int n)
{
    int* primes = new int[n];
    int i, idx = 0, prime = 2;
    while(idx < n)
    {
        for(i = 0; i<idx; i++)
        {
            if(prime%primes[i]==0)
            {
                break;
            }
        }
        if(i==idx)
        {
            primes[idx] = prime;
            idx++;
        }
        prime++;
    }
    return primes;
}

int* generate_primes_below_n(const int n)
{
    int* primes = new int[n];
    int i, idx = 0, prime = 2;
    while(prime < n)
    {
        for(i = 0; i<idx; i++)
        {
            if(prime%primes[i]==0)
            {
                break;
            }
        }
        if(i==idx)
        {
            primes[idx] = prime;
            idx++;
        }
        prime++;
    }
    return primes;
}

bool is_prime(int n)
{
    for(int i = 2; i<sqrt(n); i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}

int num_lenght(const int x)
{
    if(x>10)
    {
        return num_lenght(x/10) + 1;
    }
    return 1;
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

bool is_palindromic(std::string x)
{
    int i = 0, j = x.length()-1;
    while(i<=j)
    {
        if(x[i] != x[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}