#include "reto24.h"
#include "../functions.h"
#include <iostream>
#include <string>



std::string reto24()
{
    int remain = static_cast<int>(1e6)-1;
    std::string numbers = "0123456789";
    std::string answer = "";
    int n = 10;
    for(int i = 1; i <= 10; i++)
    {
        int j = remain/factorial(n-i);
        answer += numbers[j];
        remain = remain % factorial(n-i);
        numbers.erase(numbers.begin()+j);
    }
    
    return answer;
}

