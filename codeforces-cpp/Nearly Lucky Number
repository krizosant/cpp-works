#include <iostream>

bool checkForLuckyNumber(long long luckyNumber);

int main()
{
	//lucky numbers are positive decimal integers that contain digits 4 and 7 only
	//nearly lucky numbers are number that contain lucky number of lucky digits

	bool key = 0;
	long long n; //1 <= n <= 1e+18
	do
	{
		std::cin >> n;
	}
	while((n < 1) || (n > 1e+18));


	key = checkForLuckyNumber(n);
	if(key == 1)
	{
		std::cout << "YES";
	}
	else
	{
		std::cout << "NO";
	}

	return 0;
}

bool checkForLuckyNumber(long long luckyNumber)
{
	int countLuckyDigits;

	countLuckyDigits = 0;
	do
	{
		if((luckyNumber % 10 == 4) || (luckyNumber % 10 == 7))
		{
			luckyNumber = luckyNumber / 10;
			++countLuckyDigits;
		}
		else
		{
			luckyNumber = luckyNumber / 10;
		}
	}
	while(luckyNumber != 0);

	if((countLuckyDigits == 4) || (countLuckyDigits == 7))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//36515209562 44 012668952105 777 09815 4 21111 7
//1 000 000 000 000 000 000
//2 155 647 432 568 908 744
//44 723 186 677 094

/* 47 - NO
 * 474 - NO
 * 1147 - NO
 * 44727 - YES
 * 78474 - YES
 * 94474 - YES
 * 354724 - NO
 * 437745 - YES
 * 994474 - YES
 * 346678 - NO
 * 9432774 - YES
 * 2748977 - YES
 * 1111111 - NO
 * 978 377 411 - YES
 * 978 356 244 211 - NO
 * 978 356 244 211 101 124 - YES
 * 1 000 000 000 000 000 000 - NO
 */
