//2.Class Rectangle (W3Resource)
#include <iostream>

class Rectangle
{
private:
	int width, height;
public:
	void recArea(int pWidth, int pHeight)
	{
		width = pWidth;
		height = pHeight;
		std::cout << "Rectangle area is: " << width << "*" << height << "=" << width * height << std::endl;
	}
	void recPerimeter(int pWidth, int pHeight)
	{
		width = pWidth;
		height = pHeight;
		std::cout << "Rectangle perimeter is: " << width << "*2" << " + " << height << "*2 " << "= " << height*2 + width*2 << std::endl;
	}
};

int main()
{
	Rectangle myRectangle;
	myRectangle.recArea(2, 9);
	myRectangle.recPerimeter(2, 9);

	return 0;
}
