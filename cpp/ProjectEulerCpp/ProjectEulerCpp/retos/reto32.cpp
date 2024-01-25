#include "reto32.h"

#include <iostream>
#include <set>
#include <vector>

int reto32()
{
    std::set<int> products;
    for(int i = 1; i < 9000; i++)
    {
        for(int j = 1; j < 9000; j++)
        {
            int a = i, b = j;
            int product = i*j;
            bool once = true;
            std::set<int> digits = {};
            while(a>0)
            {
                if(digits.find(a%10) != digits.end() || a%10 == 0)
                {
                    once = false;
                    break;
                }
                digits.insert(a%10);
                a /= 10;
            }
            while(b>0)
            {
                if(digits.find(b%10) != digits.end() || b%10 == 0)
                {
                    once = false;
                    break;
                }
                digits.insert(b%10);
                b /= 10;
            }
            while(product>0)
            {
                if(digits.find(product%10) != digits.end() || product%10 == 0)
                {
                    once = false;
                    break;
                }
                digits.insert(product%10);
                product = product/10;
            }
            if(digits.size() == 9 && once)
            {
                products.insert(i*j);
                //std::cout << i << " * " << j << ": " << i*j << std::endl;
            }
        }
    }
    int sum = 0;
    for (auto product : products)
    {
        sum += product;
    }
    return sum;
}
