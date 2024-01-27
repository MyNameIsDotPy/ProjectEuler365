#include "reto34.h"
#include "../functions.h"




int reto34()
{
    int total_sum = 0;
    for(int i = 3; i < 90000; i++)
    {
        int num = i;
        int sum = 0;
        while(num > 0)
        {
            int digit = num % 10;
            sum += factorial(digit);
            num /= 10;
        }
        if(sum == i)
            total_sum += sum;
    }
    return total_sum;
}

