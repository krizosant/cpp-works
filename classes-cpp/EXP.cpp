#include <iostream>

/*
 *Experimenting with inheritance (virtual and not), virtual functions (and virtual destructors), override specifier and pointers
 */

class Base
{
public:
	Base()
	{
		std::cout << "Base default constructor." << std::endl;
	}
	void print() const
	{
		std::cout << "Base function"  << std::endl;
	}
	virtual void printInfo() const { std::cout << "printInfo() function (that is virtual) of class Base has been invoked!" << std::endl; }
	virtual ~Base() {}
};

class Derived1 : virtual public Base
{
public:
	Derived1()
	{
		std::cout  << "Derived1 default constructor" << std::endl;
//		Base::print();
	}
	void printInfo() const override { std::cout << "printInfo() function of class Derived1 has been invoked (overriden!)." << std::endl; }
};

class Derived2 : virtual public Base
{
public:
	Derived2()
	{
		std::cout  << "Derived2 default constructor" << std::endl;
//		Base::print();
	}
	void printInfo() const override { std::cout << "printInfo() function of class Derived2 has been invoked (overriden!)." << std::endl; }
};

class Derived3 : public Derived1, public Derived2
{
public:
	//Derived3() : Derived1(), Derived2(), Base() {}
	/*
	 *\\\\\\\\\COMPILER GIVES WARNING!\\\\\\\\\\\\\
	 *Sequence is important! "Base" class is the base class and its members (in this case only print() method) is shared by both Derived1 and Derived2
	 *by virtual inheritance and warning says "base 'Derived2' will be initialized after' with symbol ^ pointing upwards to Base() constructor call,
	 *implicating that base class constructor will be called first and Derived2 will be called after.
	 *Result after executing line 35:
		Derived1 function
		Base function
		Derived2 function
		Base function
	 */

	Derived3() { std::cout << "Derived3 default construtor." << std::endl; }
	//Even though sequence is important, there is not significant difference in the end result. However, warnings should be avoided.
	/*Derived1(), Derived2()
	 * Result:
		Derived1 function
		Base function
		Derived2 function
		Base function
	 */

	Derived3(int a) { std::cout << "a = " << a << std::endl; } //c-tor

	void printInfo() const { std::cout << "printInfo() function of class Derived3 has been invoked (overriden!)." << std::endl; }


};

int main() //Decomment lines 79,85,87,101,113,126,128,130-135,179-184,214-216 to test
{
//	Derived3 obj; //calls default c-tor of class Derived3 (line 47)
	//Prints out messages on lines 27 and 17. If you add parameter in the default c-tors of the base classes D.1 and D.2, it will mark line 47 calls of default c-tor/s
	//(/s if you call them with the : operator) as 'could not be resolved'. This is because when inherited, classes give access (based on the specifier they are derived from)
	//to their own members (variables, methods, functions, etc.) and the derived class is looking for the member in the base classes that it inherited. When anything doesn't match - error.
	//

	//std::cout << "\n";

//	Derived3 obj2(7); //calls c-tor (line 57)
    /*Procedures:
     *call Derived3(int a) (body still not executed)
     *call Derived1() (body still not executed)
     *call Base() (body executed) -> prints (in this case)
     *return to Derived1() (body executed) -> prints (in this case)
     *call Derived2() (body still not executed)
     *call Base() (body executed) -> prints (in this case)
     *return to Derived2() (body executed) -> prints (in this case)
     *return to Derived3(int a) (body executed) -> prints (in this case)
     *
     *Successful predictionss
     */

//	Derived3 obj3(7); //virtual inheritance of classes Derived1 and Derived2
	/*Procedures:
	 *call Derived3() (body still not executed)
	 *call Derived1() (body still not executed)
	 *call Base() (body executed) -> prints (in this case)
	 *return to Derived1() (body executed) -> prints (in this case)
	 *call Derived2() (body executed) -> prints (in this case)
	 *return to Derived3() (body executed) -> prints (in this case)
	 *
	 *Successful predictionss
	 */

//	Derived3 obj4;
	/*Even though 4 warnings are being displayed (Class 'Derived3' (or 'Derived2','Derived1','Base') has virtual method 'printInfo' but non-virtual destructor,
	 *the compiler still manages to translate the program and run it. Warnings are active until virtual destructor is declared!
	 *Procedures predictions:
	 *call Derived3() (body still not executed)
	 *call Derived1() (body still not executed)
	 *call Base() (body executed) -> prints (in this case)
	 *call Derived1 (body executed) -> prints (in this case)
	 *call Derived2 (body executed) -> prints (in this case)
	 *call Derived3 (body executed) -> prints (in this case)
	 *
	 *Successful predictionss
	 */
//	obj4.printInfo(); //prints the content of the function printInfo() in class Derived3

//	Base *obj5, *obj6, *obj7;
//	//Dynamic memory allocation on lines 122, 123, 124.
//	obj5 = new Derived1;
//	obj6 = new Derived2;
//	obj7 = new Derived3;
//	obj5->printInfo(); //DECOMMENT THE DELETE KEYWORDS AT THE END OF THE main()
//	obj6->printInfo();
//	obj7->print();
	/*
	 *On line 120 are declared three pointers to objects of type Base*
	 *-------------------------------We assign these pointers to point to whole new objects of type Derived1 (line 122), Derived2 (line 123) and Derived3 (line 124)-------------------------------
	 *Procedures predictions (lines 125-127):
	 *call Derived1() (body still not executed)
	 *call Base() (body executed) -> prints (in this case)
	 *call Derived1() (body executed) -> prints (in this case)
	 *call Derived2() (body still not executed)
	 *call Base() (body executed) -> prints (in this case)
	 *call Derived2() (body executed) -> prints (in this case)
	 *call Derived3() (body still not executed)
	 *call Derived1() (body still not executed)
	 *call Base() (body executed) -> prints (in this case)
	 *return to Derived1() (body executed) -> prints (in this case)
	 *call Derived2() (body executed) -> prints (in this case)
	 *return to Derived3 (body executed) -> prints (in this case)
	 *call function printInfo() of class Derived1
	 *call function printInfo() of class Derived2
	 *call function print() of class Derived3 <---------- only wrong prediction. print() doesn't exist in class Derived3, so pointer turns to its Base* function. If we write 'obj7->print();', then
	 *the prediction would have been true.
	 *
	 *Almost successful set of predictions
	 *
	 *
	 *--------------------------------------------------------Deleting 'virtual' and 'override' keywords effect--------------------------------------------------------
	 *Procedures prediction (lines 125-127)
	 *call Derived1() (body still not executed)
	 *call Base() (body executed) -> prints (in this case)
	 *call Derived1() (body executed) -> prints (in this case)
	 *call Derived2() (body still not executed)
	 *call Base() (body executed) -> prints (in this case)
	 *call Derived2() (body executed) -> prints (in this case)
	 *call Derived3() (body still not executed)
	 *call Derived1() (body still not executed)
	 *call Base() (body executed) -> prints (in this case)
	 *return to Derived1() (body executed) -> prints (in this case)
	 *call Derived2() (body executed) -> prints (in this case)
	 *return to Derived3 (body executed) -> prints (in this case)
	 *lines 133 and 134 would display the same result (printInfo() of class Base) and line 135 would display print() of class Base
	 *
	 *Successfull prediction!
	 */

//	Derived1* drv1 = new Derived1;
//	Derived2* drv2 = new Derived2;
//	Derived3* drv3 = new Derived3;
//	drv1->printInfo();
//	drv2->printInfo();
//	drv3->print();
	/*
	 *Declaring pointers to objects from their respective class types and invoking the virtual method printInfo() and class Base method print()
	 *Procedures prediction for lines 179-184:
	 *call Derived1() (body not executed)
	 *call Base() (body executed) -> prints (in this case)
	 *return to Derived1() (body executed) -> prints (in this case)
	 *call Derived2() (body not executed)
	 *call Base() (body executed) -> prints (in this case)
	 *return to Derived2() (body executed) -> prints (in this case)
	 *call Derived3() (body not executed)
	 *call Derived1() (body not executed)
	 *call Base() (body executed) -> prints (in this case)
	 *return to Derived1() (body executed) -> prints (in this case)
	 *call Derived2() (body executed) -> prints (in this case)
	 *return to Derived3 (body executed) -> prints (in this case)
	 *lines 182 and 183 executes the overriden function printInfo() for their respective class and line 184 prints the class Base function print()
	 *
	 *
	 */

	/*The delete operator won't work if virtual destructor not provided!
	 *Warning messages:
	 *1. ..\main.cpp:127:9: warning: deleting object of polymorphic class type 'Base' which has non-virtual destructor might cause undefined behavior [-Wdelete-non-virtual-dtor]
	 *2. ..\main.cpp:128:9: warning: deleting object of polymorphic class type 'Base' which has non-virtual destructor might cause undefined behavior [-Wdelete-non-virtual-dtor]
	 *3. ..\main.cpp:129:9: warning: deleting object of polymorphic class type 'Base' which has non-virtual destructor might cause undefined behavior [-Wdelete-non-virtual-dtor]
	 *
	 *After 'virtual ~Base() {}' it has been added to line 19, ever warning disappears and the compiler translates successfully.
	 */

//	delete obj5;
//	delete obj6;
//	delete obj7;

	/*If we remove the keyword 'virtual' from the inheritance, we would get two specific errors for this program
	 *Error 1: ..\main.cpp:132:16: error: 'Base' is an ambiguous base of 'Derived3'
	 *Error 2: ..\main.cpp:184:15: error: request for member 'print' is ambiguous
	 *   + two notes
	 *..\main.cpp:14:14: note: candidates are: 'void Base::print() const'
	 *..\main.cpp:14:14: note:                 'void Base::print() const'
	 *
	 *Explanation (my understanding): When we remove the keyword virtual, classes 'Derived1' and 'Derived2' inherit SEPERATE "copies" (take the word as a grain of salt) of class Base and so
	 *inherit SEPERATE copies of Base members. So when class 'Derived3' inherits 'Derived1' and 'Derived2', apart from the 'Derived1' and 'Derived2''s members (constructors, methods and variables),
	 *it would also inherit the two "copies" and its members. Basically, TWO EQUAL version of the same class Base would be inherited. The ambiguity comes from there. The compiler doesn't know WHICH
	 *constructor, method or variable to call. That's it.
	 */

	return 0;
}
