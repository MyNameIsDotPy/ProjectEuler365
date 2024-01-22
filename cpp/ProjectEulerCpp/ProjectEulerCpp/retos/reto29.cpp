#include "reto29.h"

#include <iostream>
#include <set>
#include <string>
#include <vector>

std::string multiply_strings(std::string a, std::string b);
std::string power_string_int(std::string base, int exp);

int reto29()
{
    std::set<std::string> powers;
    for(int a = 2; a<=100; a++)
    {
        for(int b = 2; b<=100; b++)
        {
            powers.insert(power_string_int(std::to_string(a),b));
        }   
    }
    return powers.size();
}

std::string power_string_int(std::string base, int exp)
{
    std::string result = base;
    for(int i = 0; i<exp-1; i++)
    {
        result = multiply_strings(result, base);
    }
    return result;
}
std::string multiply_strings(std::string num1, std::string num2) {
    int m = num1.size(), n = num2.size();
    std::vector<int> pos(m+n);
    for(int i = m - 1; i >= 0; i--)
    {
        for(int j = n - 1; j >= 0; j--)
        {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int p1 = i+j, p2 = i+j+1;
            int sum = mul + pos[p2];

            pos[p1] += sum /10;
            pos[p2] = sum %10;
        }        
    }

    std::string result;
    for(int p: pos)
    {
        if(!(result.empty() && p == 0))
        {
            result.push_back(p + '0');
        }
    }
    return result.empty() ? "0" : result;
}