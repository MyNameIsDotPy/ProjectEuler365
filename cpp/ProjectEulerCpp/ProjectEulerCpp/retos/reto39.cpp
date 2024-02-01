#include "reto39.h"

#include <cmath>
#include <iostream>
#include <map>

int reto39()
{
    std::map<int, int> triplas;
    
    for(int a = 1; a < 1000; a++)
    {
        for(int b = 1; b < 1000; b++)
        {
            float c_f = sqrt(a*a + b*b);
            int c = sqrt(a*a + b*b);
            if(c == c_f)
            {
                int perimetro = a+b+c;
                if(perimetro < 1000)
                {
                    if(triplas.find(perimetro) == triplas.end())
                    {
                        triplas[perimetro] = 1;
                    }
                    else
                    {
                        triplas[perimetro] = triplas[perimetro]+1;
                    }
                }
            }
        }
    }
    std::pair<int, int> maximized_value = {0, 0};
    for(auto val : triplas)
    {
        if(val.second > maximized_value.second)
        {
            maximized_value.second = val.second;
            maximized_value.first = val.first;
        }
    }
    return maximized_value.first;
}
