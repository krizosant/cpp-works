//6.Class Triangle (W3Resource)
#include <iostream>

using namespace std;

class Triangle
{
private:
	int a, b, c;
public:
	Triangle(int side_1, int side_2, int side_3)
	{
		a = side_1;
		b = side_2;
		c = side_3;
	}
	void checkTypeOfTriangle()
	{
		if((a > 0) && (b > 0) && (c > 0))
		{
			if(a == b && b == c)
			{
				cout << "The triangle is quilateral.";
			}
			else if((a == b) || (a == c) || (b == c))
			{
				cout << "The triangle is isosceles.";
			}
			else
			{
				cout << "The triangle is scalene.";
			}
		}
		else
		{
			cout << "Invalid values!" << endl;
			if((a <= 0) && (b <= 0) && (c <= 0))
			{
				cout << "All three values are invalid!";
			}
			else
			{
				if((a <= 0) && (b <= 0))
				{
					cout << "Values for side A and side B are invalid!";
				}
				else if((a <= 0) && (c <= 0))
				{
					cout << "Values for side A and side C are invalid!";
				}
				else
				{
					cout << "Values for side B and side C are invalid!";
				}
			}
		}
	}
};

int main()
{
	int s1, s2, s3;

	cout << "Enter values for the three sides: " << endl;
	cout << "A = "; cin >> s1;
	cout << "B = "; cin >> s2;
	cout << "C = "; cin >> s3;
	Triangle figure(s1, s2, s3);
	figure.checkTypeOfTriangle();

	return 0;
}
