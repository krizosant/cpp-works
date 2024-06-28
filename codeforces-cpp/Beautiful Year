#include <iostream>
 
int main()
{
    int year, safeDigit, newYear;
    bool check = 0;
 
    do
    {
        std::cin >> year; 
        if((year < 1000) || (year > 9000))
            std::cout << "The year is not in the interval [1000; 9000]. Enter again:\n";
    }
    while((year < 1000) || (year > 9000));
 
    newYear = ++year;
    while(check != 1)
    {
        safeDigit = newYear % 10; 
        if(safeDigit != ((newYear / 10) % 10)) 
        {
            if(safeDigit != ((newYear / 100) % 10)) 
            {
                if(safeDigit != (newYear / 1000)) 
                {
                    safeDigit = (newYear / 10) % 10; 
                    if(safeDigit != (newYear / 100) % 10)
                    {
                        if(safeDigit != (newYear / 1000))
                        {
                            safeDigit = (newYear / 100) % 10; 
                            if(safeDigit != (newYear / 1000))
                            {
                                std::cout << newYear;
                                check = 1;
                            }
                            else
                            {
                                newYear++;
                            }
                        }
                        else
                        {
                            newYear++;
                        }
                    }
                    else
                    {
                        newYear++;
                    }
                }
                else
                {
                    newYear++;
                }
            }
            else
            {
                newYear++;
            }
        }
        else
        {
            newYear++;
        }
    }
    return 0;
}
