#include "reto22.h"
#include <iostream>
#include <fstream>
#include <map>
#include <string>


int reto22()
{
    std::map<std::string, int> names = {};
    
    std::ifstream myfile;
    myfile.open("./files/0022_names.txt");

    std::string mystring;
    
    if(myfile.is_open())
    {
        myfile >> mystring;
    }

    std::string tmp_string = "";
    int score = 0;
    
    for(int i = 0; i < mystring.length(); i++)
    {
        //std::cout << mystring[i];
        if(mystring[i] != '"')
        {
            if(mystring[i] == ',')
            {
                names[tmp_string] = score;
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
    names[tmp_string] = score;

    int total_score = 0;
    int pos = 1;
    for (auto name : names)
    {
        
        total_score += name.second * pos;
        
        pos++;

    }
    
    return total_score;
}