#include "reto25.h"

#include <iostream>
#include <vector>


void sum_vectors(std::vector<int>& a, std::vector<int>& b, std::vector<int>& c);

int reto25()
{
    std::vector<int> a = {1};
    std::vector<int> b = {1};
    std::vector<int> c = {0};

    
    int i;
    for(i = 0; a.size()<1000; i++)
    {
        sum_vectors(a, b, c);

        b = a;
        a = c;
    }
    
    
    return i+2;
}

void sum_vectors(std::vector<int>& a, std::vector<int>& b, std::vector<int>& c)
{
    

    int a_size = a.size();
    int b_size = b.size();
    int c_size = c.size();

    int carry = 0;
    for(int i = 0; i < a_size; i++)
    {
        int sum = a[i];

        if(i<b_size)
        {
            sum += b[i];
        }
        
        sum += carry;
        carry = sum / 10;
        if(i < c_size)
        {
            c[i] = sum % 10;
        }
        else
        {
            c.push_back(sum%10);
        }
    }
    if(carry!=0)
    {
        c.push_back(carry);
    }
    return;
}
