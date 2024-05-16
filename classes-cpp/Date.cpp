8.Class Date (W3Resource)
#include <iostream>

class Date
{
private:
	int day, month, year;
public:
	Date(int pDay, int pMonth, int pYear)
	{
		day = pDay;
		month = pMonth;
		year = pYear;
	}
	bool checkForValidDate()
	{
		int presentYear = 2024;
		if(year >= 1582 && year <= presentYear)
		{
			if(month >= 1 && month <= 12)
			{
				if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
				{
					if(day >= 1 && day <= 31)
					{
						return 1;
					}
					else
					{
						std::cout << "Day number not valid!" << std::endl;
						return 0;
					}
				}
				else if(month == 4 || month == 6 || month == 9 || month == 11)
				{
					if(day >= 1 && day <= 30)
					{
						return 1;
					}
					else
					{
						std::cout << "Day number not valid!" << std::endl;
						return 0;
					}
				}
				else if(month == 2)
				{
					if(day >= 1 && day <= 29)
					{
						return 1;
					}
					else
					{
						std::cout << "Day number not valid!" << std::endl;
						return 0;
					}
				}
				else
				{
					std::cout << "Month number not valid so date " << day << " doesn't exist!" << std::endl;
				}
			}
			else
			{
				std::cout << "Month number not valid!" << std::endl;
				if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
				{
					if(day >= 1 && day <= 31)
					{
						return 0;
					}
					else
					{
						std::cout << "Day number not valid!" << std::endl;
						return 0;
					}
				}
				else if(month == 4 || month == 6 || month == 9 || month == 11)
				{
					if(day >= 1 && day <= 30)
					{
						return 0;
					}
					else
					{
						std::cout << "Day number not valid!" << std::endl;
						return 0;
					}
				}
				else if(month == 2)
				{
					if(day >= 1 && day <= 29)
					{
						return 0;
					}
					else
					{
						std::cout << "Day number not valid!" << std::endl;
						return 0;
					}
				}
				else
				{
					std::cout << "Month number not valid so date " << day << " doesn't exist!" << std::endl;
				}
			}
		}
		else
		{
			std::cout << "Year not valid!" << std::endl;
			if(month >= 1 && month <= 12)
			{
				if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
				{
					if(day >= 1 && day <= 31)
					{
						return 0;
					}
					else
					{
						std::cout << "Day number not valid!" << std::endl;
						return 0;
					}
				}
				else if(month == 4 || month == 6 || month == 9 || month == 11)
				{
					if(day >= 1 && day <= 30)
					{
						return 0;
					}
					else
					{
						std::cout << "Day number not valid!" << std::endl;
						return 0;
					}
				}
				else if(month == 2)
				{
					if(day >= 1 && day <= 29)
					{
						return 0;
					}
					else
					{
						std::cout << "Day number not valid!" << std::endl;
						return 0;
					}
				}
				else
				{
					std::cout << "Month number not valid so date " << day << " doesn't exist!" << std::endl;
				}
			}
			else
			{
				std::cout << "Month number not valid!" << std::endl;
				if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
				{
					if(day >= 1 && day <= 31)
					{
						return 0;
					}
					else
					{
						std::cout << "Day number not valid!" << std::endl;
						return 0;
					}
				}
				else if(month == 4 || month == 6 || month == 9 || month == 11)
				{
					if(day >= 1 && day <= 30)
					{
						return 0;
					}
					else
					{
						std::cout << "Day number not valid!" << std::endl;
						return 0;
					}
				}
				else if(month == 2)
				{
					if(day >= 1 && day <= 29)
					{
						return 0;
					}
					else
					{
						std::cout << "Day number not valid!" << std::endl;
						return 0;
					}
				}
				else
				{
					std::cout << "Month number not valid so date " << day << " doesn't exist!" << std::endl;
				}
			}
		}
		return 0;
	}
	int getDay() { return this->day;}
	int getMonth() { return this->month; }
	int getYear() { return this->year; }
};

int main()
{
	int day, month, year;
	std::cout << "Enter number of day: "; std::cin >> day;
	std::cout << "Enter number of month: "; std::cin >> month;
	std::cout << "Enter number of year: "; std::cin >> year;
	Date maybe(day, month, year);
	if(maybe.checkForValidDate())
	{
		std::cout << "The date " << maybe.getDay() << "." << maybe.getMonth() << "." << maybe.getYear() << " you've entered is correct!";
	}
	else
	{
		std::cout << "The date you've entered is not correct!";
	}
	return 0;
}
/* Tests
den mesec godina
y   y     y 	da
y   y     n		da
y   n     n		da
n   n     n		da
n   n     y		da
n   y     y		da
y   n     y		da
n   y     n		da
*/
