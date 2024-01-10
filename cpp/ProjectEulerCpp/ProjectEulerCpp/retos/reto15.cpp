#include "reto15.h"
#include "iostream";

long long int lattice(int x, int y, int size);

long long int reto15()
{
    return lattice(0,0,20);
}

// This shit take too long, but it works.
// It can easily made with combinatorics (n!)/((n-m)! * m!) where n = 40 and m = 20
// The answer is 137846528820
long long int lattice(int x, int y, int size)
{
    long long int sum = 0;
    if(x<size)
    {
        sum += lattice(x+1, y, size);
    }
    if(y<size)
    {
        sum += lattice(x, y+1, size);
    }
    
    if(x == size && x == y)
    {
        return 1;
    }
    return sum;
}