#include "reto14.h"
#include <unordered_map> 
#include "iostream"

int CollatzSequence(long long int n);

std::unordered_map<long long int, int> CollatzSequenceMap;

int reto14()
{
    int max = 1;
    int idx = 1;
    for(int i = 1; i<1000000; i++)
    {
        const int num = CollatzSequence(i);
        if(num > max)
        {
            max = num;
            idx = i;
        }
    }
    return idx;
}

int CollatzSequence(long long int n)
{
    if(n == 1)
    {
        return 1;
    }
    if(n%2!=0)
    {
        if (CollatzSequenceMap.find(n) == CollatzSequenceMap.end())
        {
            const int length = 1 + CollatzSequence(3*n + 1); 
            CollatzSequenceMap[n] = length;
            return length;
        }
        return CollatzSequenceMap[n];
    }
    if (CollatzSequenceMap.find(n) == CollatzSequenceMap.end())
    {
        const int length = 1 + CollatzSequence(n/2); 
        CollatzSequenceMap[n] = length;
        return length;
    }
    return CollatzSequenceMap[n];
}
