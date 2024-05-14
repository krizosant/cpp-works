// 1.Class Cirlce (W3Resource)
#include <iostream>
#include <math.h>

using namespace std;

class Circle
{
	int radius;
public:
	void circleCircumference(int pRadius);
	void circleArea(int pRadius);
};

void Circle::circleCircumference(int pRadius)
{
	radius = pRadius;
	int circumference = 2*M_PI*radius;
	cout << "The circle circumference: " << circumference << endl;
}
void Circle::circleArea(int pRadius)
{
	radius = pRadius;
	int area = M_PI*pow(radius, 2);
	cout << "The are of the circle is: " << area << endl;
}

int main()
{
	Circle newCircle;
	newCircle.circleArea(6);
	newCircle.circleCircumference(4);

	return 0;
}
