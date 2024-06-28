#include <iostream>

int main()
{
	unsigned int w; //kilos
	do
	{
		std::cin >> w;
	}
	while((w < 1) || (w > 100));

	if((w % 2 == 0) && (w != 2)) //62 или 64
	{
		w = w / 2; //31 или 32
		if(w % 2 == 1) //31 -> 30 + 32
		{
			if(((w + 1) % 2 == 0) && ((w - 1) % 2 == 0)) //30 и 32
			{
				std::cout << "YES";
			}
			else
			{
				std::cout << "NO";
			}
		}
		else
		{
			std::cout << "YES"; //делят се на две равни части
		}
	}
	else
	{
		std::cout << "NO";
	}

	return 0;
}
