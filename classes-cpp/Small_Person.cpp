3.Class Person
#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
	int age;
	string name;
	string country;
public:
	void setAge(int pAge)
	{
		age = pAge;
	}
	void setName(string pName)
	{
		name = pName;
	}
	void setCountry(string pCountry)
	{
		country = pCountry;
	}
	int getAge()
	{
		return age;
	}
	string getName()
	{
		return name;
	}
	string getCountry()
	{
		return country;
	}
};

int main()
{
	Person myPerson;

	myPerson.setAge(21);
	myPerson.setName("Krisko");
	myPerson.setCountry("Bulgaria");

	cout << "Name: " << myPerson.getName() << endl;
	cout << "Age: " << myPerson.getAge() << endl;
	cout << "Country: " << myPerson.getCountry() << endl;

	return 0;
}
