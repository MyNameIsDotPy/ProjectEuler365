#include "reto09.h"

#include <complex>

int reto09()
{
    for(int a = 3; a<10000; a++)
    {
        for(int b = a; b<10000; b++)
        {
            double c = std::sqrt(a*a + b*b);
            if(floor(c) == c)
            {
                if((a+b+c) == 1000)
                {
                    return a*b*c;
                }
            }
        }
    }
    return 1;
}
