#include "reto28.h"

#include <iostream>

int reto28()
{
    int sum = 1;
    int val = 1;
    int jump = 2;
    for(int i = 0; i<500; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            val += jump;
            sum += val;
            //std::cout << val << std::endl;
        }
        jump += 2;
        //std::cout << "jump: " << jump << std::endl;
    }
    
    return sum;
}
