#include "reto31.h"

#include <vector>

int target = 200;

int calculate(std::vector<int> values, int sum)
{
    if(sum == target)
    {
        return 1;
    }
    if(sum > target)
    {
        return 0;
    }
    int total_sum = 0;
    std::vector<int> values_copy = values;
    for(int pence: values)
    {
        int val = pence + sum;
        if(val <= target)
        {
            total_sum += calculate(values_copy, val);
        }
        values_copy.erase(values_copy.begin());
    }
    return total_sum;
}

int reto31()
{
    std::vector<int> pences = {200, 100, 50, 20, 10, 5, 2, 1};
    return calculate(pences, 0);
}

