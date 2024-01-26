#include "reto33.h"

#include <iostream>
#include <numeric>


std::pair<int, int> reduceFraction(std::pair<int, int> fraction);

int reto33()
{
    std::pair<int, int> fraction = {1,1};

    for(int num = 10; num < 100; num++)
    {
        for(int den = 10; den < 100; den++)
        {
            int a1 = num/10;
            int a2 = num%10;
    
            int b1 = den/10;
            int b2 = den%10;

            float a = 0, b = 0;
    
            if(a1 == b1)
            {
                a = a2;
                b = b2;
                if(a1 == 0)
                {
                    continue;
                }
            }
            if(a1 == b2)
            {
                a = a2;
                b = b1;
                if(a1 == 0)
                {
                    continue;
                }
            }
            if(a2 == b1)
            {
                a = a1;
                b = b2;
                if(a2 == 0)
                {
                    continue;
                }
            }
            if(a2 == b2)
            {
                a = a1;
                b = b1;
                if(a2 == 0)
                {
                    continue;
                }
            }

            if(a == 0 && a == b)
            {
                continue;
            }

            if(a<b)
            {
                if(float(a)/float(b) == float(num)/float(den))
                {
                    /*std:: cout << num << "/" << den << ": ";
                    std::cout << a << "/" << b << std::endl;*/
                    fraction.first *= a;
                    fraction.second *= b;
                }
            }
        }
    }
    
    fraction = reduceFraction(fraction);
    return fraction.second;
}

int gcd(int a, int b)
{
    // Find Minimum of a and b
    int result = std::min(a, b);
    while (result > 0) {
        if (a % result == 0 && b % result == 0) {
            break;
        }
        result--;
    }
 
    // Return gcd of a and b
    return result;
}

std::pair<int, int> reduceFraction(std::pair<int, int> fraction) {
    int GCD = gcd(fraction.first, fraction.second);
    return {fraction.first / GCD, fraction.second / GCD};
}

