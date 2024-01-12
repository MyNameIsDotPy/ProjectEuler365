#include "reto19.h"

int reto19()
{
    int day = 0;
    int month = 0;
    int weekDay = 0;
    int year = 1900;
    int months[] = {
        31,
        28,
        31,
        30,
        31,
        30,
        31,
        31,
        30,
        31,
        30,
        31
    };
    int sundayCount = 0;
    while(year<=2000)
    {
        bool isLeap = year%4==0 && (year%100!=0 || year%400==0);
        if(year>=1901)
        {
            if(weekDay == 6 && day == 0)
            {
                sundayCount++;
            }            
        }
        weekDay = (weekDay+1)%7;
        if(isLeap)
        {
            months[1] = 29;
        }
        else
        {
            months[1] = 28;   
        }
        
        if(day>=months[month]-1)
        {
            month++;
            day = 0;
            if(month >= 12)
            {
                month = 0;
                year++;
            }
            continue;
        }
        day++;
    }
    return sundayCount;
}