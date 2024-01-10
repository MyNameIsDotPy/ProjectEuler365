#include "reto16.h"

#include <vector>

#include "iostream"

long double reto16()
{
    std::vector<int> products = {1}; // 4321

    int exponent = 1000;
    int carry = 0;
    while(exponent>0)
    {
        int i = 0;
        int size = products.size();
        
        while(i<size)
        {
            int back = products[i];
            back *= 2;
            back += carry;
            carry = 0;
            if(back >= 10)
            {
                back-=10;
                carry = 1;
            }
            products[i] = back;
            i++;
        }
        if(carry != 0)
        {
            products.push_back(carry);
            carry = 0;
        }
        exponent--;
    }
    int sum = 0;
    for (auto product : products)
    {
        sum += product;
    }
    return sum;
}