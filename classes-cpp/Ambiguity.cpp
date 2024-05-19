//Ambiguos inheritance / Not proper member function overloading
#include <iostream>

class A
{
public:
	void print() { std::cout << "\n"; }
};

class B
{
public:
	void print() { std::cout << "///"; }
};


class C : public A, public B {};

int main()
{
	C c1;
	c1.print(); //'print' is ambiguous' Candidates are: void print()'

	c1.A::print(); //Correct
	c1.B::print(); //Correct
  
	return 0;
}
