#include "functions.h"

#include <cmath>
#include <iostream>
#include <set>

int factorial(int n)
{
    if(n==0)
        return 1;
    return n*factorial(n-1);
}

std::set<int> generate_n_primes(const int n)
{
    std::set<int> primes = {2};
    for(unsigned int i = 3; primes.size() < n; i += 2)
    {
        bool prime = true;
        for(auto p: primes)
        {
            if(p*p > i)
                break;
            
            if(i%p==0)
            {
                prime = false;
                break;
            }
        }
        if(prime)
            primes.insert(i);
    }
    return primes;
}

std::set<int> generate_primes_below_n(const int n)
{
    std::set<int> primes = {2};
    for(unsigned int i = 3; i < n; i += 2)
    {
        bool prime = true;
        for(auto p: primes)
        {
            if(p*p > i)
                break;
            
            if(i%p==0)
            {
                prime = false;
                break;
            }
        }
        if(prime)
            primes.insert(i);
    }
    return primes;
}

bool is_prime(int n) {
    if (n <= 1) {
        return false; // 1 or less is not prime
    }
    if (n <= 3) {
        return true; // 2 and 3 are prime
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false; // Divisible by 2 or 3
    }

    // Efficiently check divisibility up to sqrt(n)
    for (int i = 5; i * i <= n; i += 6) { // Increment by 6 to skip even numbers
        if (n % i == 0 || n % (i + 2) == 0) {
            return false; // Divisible by i or i + 2
        }
    }

    return true; // No divisors found, n is prime
}

bool is_prime(int n, std::set<int> primes)
{
    return primes.count(n) != 0;
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

int triangular_num(const int n)
{
    return n*(n+1)/2;
}