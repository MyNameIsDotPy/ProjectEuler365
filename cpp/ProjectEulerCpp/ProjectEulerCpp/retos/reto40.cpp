#include "reto40.h"
#include "../functions.h"

#include <iostream>

int reto40() {
	int total_product = 1;
	int digits = 1;
	int potencia = 10;
	for(int digit = 1, num = 1; digit <= 1000000; num++)
	{
		int copy = num;
		int numlen = num_lenght(copy);
		while(numlen>0)
		{
			int b = pow(10,numlen-1);
			numlen--;
			int first_digit = copy/b;
			copy = copy - first_digit*b;
			
			
			if((digit)%potencia==0)
			{
				
				potencia *= 10;
				total_product *= first_digit;
				std::cout << first_digit << std::endl;

			}
			digit++;
		}
	}
	return total_product;
}
