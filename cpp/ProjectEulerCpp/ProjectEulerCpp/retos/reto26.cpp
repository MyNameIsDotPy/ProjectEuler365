#include "reto26.h"

#include <iostream>
#include <valarray>
#include <vector>


int get_index(std::vector<int> v, int K);
int get_cycle_decimals(int den);

int reto26()
{
    std::pair<int, int> max_length = {0,-1};

    
    for(int den = 1; den<1000; den++)
    {
        const int count = get_cycle_decimals(den);
        if(count>max_length.first)
        {
            // std::cout << "1/" << den << ": " << 1.0f/den << " count: " << count << std::endl;
            max_length.first = count;
            max_length.second = den;
        }        
    }
    return max_length.second;
}

int get_cycle_decimals(int den)
{
    std::vector<int> remains;
    int a = 1;
    bool is_periodic = false;
    int count = 0;
    int b;
    while(a > 0)
    {
        if(a<den)
        {
            a *= 10;
        }
        b = a/den;
        int index = get_index(remains, a);

        if(index != -1)
        {
            count = count - index;
            is_periodic = true;
            break;
        }
        count++;
        remains.push_back(a);
        a = a-b*den;
    }
    if (is_periodic)
    {
        return count;
    }
    return 0;
}

int get_index(std::vector<int> v, int K)
{ 
    auto it = find(v.begin(), v.end(), K); 
  
    if (it != v.end())  
    { 
        return it - v.begin(); 
    } 
    return -1; 
    
} 