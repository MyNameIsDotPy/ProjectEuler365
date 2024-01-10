#include "reto17.h"

#include <iostream>
#include <map>
#include <string>

int reto17()
{
    std::map<int, int> letters = {
        //{-1,3},   // And
        {0,0},    // Zero
        {1,3},    // One
        {2,3},    // Two
        {3,5},    // Three
        {4,4},    // Four
        {5,4},    // Five
        {6,3},    // Six
        {7,5},    // Seven
        {8,5},    // Eight
        {9,4},    // Nine
        {10,3},   // Ten
        {11,6},   // Eleven
        {12,6},   // Twelve
        {13,8},   // Thirteen
        {14,8},   // Fourteen
        {15,7},   // Fifteen
        {16,7},   // Sixteen
        {17,9},   // Seventeen
        {18,8},   // Eighteen
        {19,8},   // Nineteen
        
        {20,6},   // Twenty
        {30,6},   // Thirty
        {40,5},   // Forty
        {50,5},   // Fifty
        {60,5},   // Sixty
        {70,7},   // Seventy
        {80,6},   // Eighty
        {90,6},   // Ninety
        {100,7},  // Hundred
        {1000,11} // Thousand
        
    };

    std::map<int, std::string> letters2 = {
        //{-1,3},   // And
        {0,""},    // Zero
        {1,"One "},
        {2,"Two "},
        {3,"Three "},
        {4,"Four "},
        {5,"Five "},
        {6,"Six "},
        {7,"Seven "},
        {8,"Eight "},
        {9,"Nine "},
        {10,"Ten "},
        {11,"Eleven "},
        {12,"Twelve "},
        {13,"Thirteen "},
        {14,"Fourteen "},
        {15,"Fifteen "},
        {16,"Sixteen "},
        {17,"Seventeen "},
        {18,"Eighteen "},
        {19,"Nineteen "},
        {20,"Twenty "},
        {30,"Thirty "},
        {40,"Forty "},
        {50,"Fifty "},
        {60,"Sixty "},
        {70,"Seventy "},
        {80,"Eighty "},
        {90,"Ninety "},
        {100,"Hundred "},
        {1000,"One Thousand "}
        
    };
    
    int totalsum = 0;

    for(int number = 1; number<1000; number++)
    {
        int sum = 0;

        int decenas = number%100;
        int centenas = number/100;
        int unidades = number%10;
        if(centenas!=0)
        {
            sum += letters[centenas];
            sum += letters[100];
            std::cout << letters2[centenas];
            std::cout << letters2[100];
            if(decenas!=0)
            {
                sum += 3;
                std::cout << "and ";
            }
        }
        if(decenas<=19)
        {
            sum += letters[decenas];
            std::cout << letters2[decenas];
        }
        else
        {
            sum += letters[decenas-unidades];
            sum += letters[unidades];
            std::cout << letters2[decenas-unidades];
            std::cout << letters2[unidades];
        }
        totalsum += sum;
        std::cout << std::endl;
    }
    totalsum += letters[1000]; // Edge case
    std::cout << letters2[1000];
    
    return totalsum;
}
