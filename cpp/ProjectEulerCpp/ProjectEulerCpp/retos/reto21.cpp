#include "reto21.h"

#include <map>
#include <iostream>
#include <set>


int d(int n);

int reto21()
{
    std::set<int> divisors = {};
    int sum = 0;
    for(int i = 1; i<10000; i++)
    {
        int div_sum = d(i);
        if(d(div_sum) == i && div_sum != i)
        {
            if(divisors.find(i)==divisors.end())
            {
                sum += i;
            }
            if(divisors.find(div_sum)==divisors.end())
            {
                sum += div_sum;
            }
            divisors.insert(i);
            divisors.insert(div_sum);
        }
        
    }
    return sum;
}

int d(const int n)
{
    int sum = 0;
    for(int i = 1; i<=n/2; i++)
    {
        if(n%i==0)
        {
            sum += i;
        }
    }
    return sum;
}
