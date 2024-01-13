#include "reto20.h"

#include <iostream>
#include <vector>

int reto20()
{
    std::vector<int> factorial = {1};
    
    for(int factor = 1; factor<=100; factor++)
    {
        int disp = 0;
        int carry = 0;
        int length = factorial.size();
        while(true)
        {
            if(disp>=length)
            {
                if(carry>10)
                {
                    factorial.push_back(carry%10);
                    carry = carry/10;
                }
                else
                {
                    factorial.push_back(carry);
                    break;
                }
            }
            else
            {
                int prod = factor*factorial[disp];
                carry = carry + prod;
                factorial[disp] = carry%10;
                carry /= 10;
                disp++;   
            }
        }
    }

    int sum = 0;
    for(int i = 0; i<factorial.size(); i++)
    {
        sum += factorial[i];
    }
    return sum;
}
