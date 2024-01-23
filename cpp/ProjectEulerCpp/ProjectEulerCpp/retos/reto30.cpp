#include "reto30.h"

#include <cmath>
#include <iostream>

int reto30()
{
    int sum = 0;
    for(int i = 2; i < 900000; i++)
    {
        int tmp_sum = 0;
        int tmp = i;

        for(int j = 0; j < 6; j++)
        {
            tmp_sum += pow(tmp%10, 5);
            tmp /= 10;
        }

        if(tmp_sum == i)
        {
            sum += tmp_sum;
            //std::cout << tmp_sum << std::endl;
        }
    }
    return sum;
}
