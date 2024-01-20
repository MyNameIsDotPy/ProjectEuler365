#include "reto27.h"

#include <iostream>
#include <utility>

bool es_primo(int n);
int reto27()
{
  
    std::pair<int, std::pair<int, int>> max_a_b = {0,{0,0}};
    for(int a = -999; a < 1000; a++)
    {
        for (int b = -999; b <= 1000; b++)
        {
            int n = 0;
            int l = 0;
            while(true)
            {
                int number = n*n + a*n + b;
                if(es_primo(number))
                {
                    l++;
                }
                else
                {
                    break;
                }
                n++;
            }

            if(l>max_a_b.first)
            {
                //std::cout << l << std::endl;
                max_a_b.first = l;
                max_a_b.second.first = a;
                max_a_b.second.second = b;
            }
        }
    }
    return max_a_b.second.first * max_a_b.second.second;
}

bool es_primo(int n)
{
    if(n<0)
    {
        return false;
    }
    for(int i = 2; i<sqrt(n); i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}
