#include "reto06.h"
#include <cmath>
/*
The sum of the squares of the first ten natural numbers is,
1^2 + 2^2+... + 10^2 = 385.
The square of the sum of the first ten natural numbers is,
(1 + 2 + ... +10)^2 = 55^2 = 3025.
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is
3025 - 385 2640.
Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/
int reto06()
{
    return -floor(1.0f/6.0f * 100*101*201)  +  pow((100*101)/2,2);
}