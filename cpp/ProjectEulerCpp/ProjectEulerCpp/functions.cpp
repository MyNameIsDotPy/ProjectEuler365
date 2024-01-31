#include "functions.h"

#include <cmath>
#include <set>

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
    if(n<2)
        return false;
    
    for(int i = 2; i-1 <sqrt(n); i += 1)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}

bool is_prime(int n, int* primes)
{
    if(n<2)
        return false;
    int i = 0, p = 2;
    while(p > 0)
    {
        p = primes[i];
        if(n%p==0 && n!=p)
            return false;
        if(n<p)
            
            return true;
        i++;
    }
    return false;
}

int num_lenght(const int x)
{
    if(x>=10)
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