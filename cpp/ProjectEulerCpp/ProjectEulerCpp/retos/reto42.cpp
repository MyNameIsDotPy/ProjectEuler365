#include "reto42.h"

#include <fstream>
#include <iostream>

#include "../functions.h"

int reto42()
{
    int words = 0;
    std::ifstream myfile;
    myfile.open("./files/0042_words.txt");

    std::string mystring;
    
    if(myfile.is_open())
    {
        myfile >> mystring;
    }

    std::string tmp_string = "";
    int score = 0;
    
    for(int i = 0; i < mystring.length(); i++)
    {
        if(mystring[i] != '"')
        {
            if(mystring[i] == ',')
            {
                

                float n = -(1-sqrt(1+8*score))/2.0f;
                int m = -(1-sqrt(1+8*score))/2;

                if(n==m)
                {
                    std::cout << tmp_string << ": " << n << "\n";
                    words++;
                }

                
                
                tmp_string = "";
                score = 0;
            }
            else
            {
                score += mystring[i]-64;
                tmp_string += mystring[i];
            }
        }
    }
    return words;
}
