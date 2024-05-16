//10.*Last Class* class Polygon (inheritance, virtual function members)
#include <iostream>
#include <math.h>

template<typename T>
class Polygon
{
protected: //Достъп единствено от наследниците
	virtual T area();
	virtual T perimeter();
	virtual ~Polygon() {}
};

template<typename T>
T Polygon<T>::area() { return 0; }

template<typename T>
T Polygon<T>::perimeter() { return 0; }

template<typename T>
class Rectangle : public Polygon<T>
{
private:
	T a, b;
public:
	void setValues(T par_1, T par_2)
	{
		a = par_1;
		b = par_2;
	}
	T area() override
	{
		return (a * b);
	}
	T perimeter() override
	{
		return (2*a + 2*b);
	}
	~Rectangle() override {}
};

template<typename T>
class Triangle : public Polygon<T>
{
private:
	T a, b, c, h;
public:
	void setValues(T par_1, T par_2, T par_3, T par_4)
	{
		a = par_1;
		b = par_2;
		c = par_3;
		h = par_4;
	}
	T area() override
	{
		return ((a * h) / 2);
	}
	T perimeter() override
	{
		return (a + b + c);
	}
	~Triangle() override {}
};

template<typename T>
class Circle : public Polygon<T>
{
private:
	T r;
public:
	void setValues(T par)
	{
		r = par;
	}
	T area() override
	{
		return (M_PI * pow(r, 2));
	}
	T perimeter() override
	{
		return (2 * M_PI * r);
	}
	~Circle() override {}
};

int main()
{
	Rectangle<int> rec;
	rec.setValues(12, 6);
	std::cout << "Perimeter of rectangle: " << rec.perimeter() << std::endl;
	std::cout << "Area of rectangle: " << rec.area() << std::endl;

	Triangle<int> tr;
	tr.setValues(9, 6, 12, 2);
	std::cout << "Perimeter of triangle: " << tr.perimeter() << std::endl;
	std::cout << "Area of triangle: " << tr.area() << std::endl;

	Circle<float> fCir;
	Circle<double> dCir;

	fCir.setValues(4.1091);
	dCir.setValues(211.3009);
	std::cout << "Perimeter of circle (float value): " << fCir.perimeter() << std::endl << "Perimeter of circle (double value): " << dCir.perimeter() <<
			std::endl << "Area of circle (float value): " << fCir.area() << std::endl << "Area of circle (double value): " << dCir.area();

	return 0;
}
