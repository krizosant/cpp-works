//Class Person
#include <iostream>
#include <cstring>

class Person
{
private:
	char gender;
	char* name;
	char* degree;
	int nameSize, degreeSize;
	int age;
	float weight, height;
	static int numberOfObjects;
public:
	Person() //Default Constructor
	{
		gender = '/';
		nameSize = 1, degreeSize = 1;
		name = new char[nameSize];
		degree = new char[degreeSize];
		*(name + nameSize) = '\0';
		*(degree + degreeSize) = '\0';
		age = 0;
		weight = 0.000;
		height = 0.000;
		numberOfObjects++;
	}
	Person(char pGender, const char* pName, const char* pDegree, int pAge, float pWeight, float pHeight) //Constructor
	{
		gender = pGender;

		nameSize = strlen(pName);
		name = new char[nameSize + 1];
		strncpy(name, pName, nameSize);
		name[nameSize] = '\0';

		degreeSize = strlen(pDegree);
		degree = new char[degreeSize + 1];
		strncpy(degree, pDegree, degreeSize);
		degree[degreeSize] = '\0';

		age = pAge;
		weight = pWeight;
		height = pHeight;

		numberOfObjects++;
	}
	Person(const Person& copyPerson) //Copy Constructor
	{
		gender = copyPerson.gender;

		nameSize = strlen(copyPerson.name);
		name = new char[nameSize + 1];
		strncpy(name, copyPerson.name, nameSize);
		name[nameSize] = '\0';

		degreeSize = strlen(copyPerson.degree);
		degree = new char[degreeSize + 1];
		strncpy(degree, copyPerson.degree, degreeSize);
		degree[degreeSize] = '\0';

		age = copyPerson.age;
		weight = copyPerson.weight;
		height = copyPerson.height;

		numberOfObjects++;
	}
	Person& operator=(const Person& copyPerson)
	{
//		!!!!!! The keyword this represents a pointer !!!!!!
//		!!!!!! to the object whose member function is !!!!!!
//		!!!!!! being executed. It is a pointer to the object itself. !!!!!!
		if(this != &copyPerson)
		{
			gender = copyPerson.gender;

			nameSize = strlen(copyPerson.name);
			name = new char[nameSize + 1];
			strncpy(name, copyPerson.name, nameSize);
			name[nameSize] = '\0';

			degreeSize = strlen(copyPerson.degree);
			degree = new char[degreeSize + 1];
			strncpy(degree, copyPerson.degree, degreeSize);
			degree[degreeSize] = '\0';

			age = copyPerson.age;
			weight = copyPerson.weight;
			height = copyPerson.height;

			//numberOfObjects++;
		}
		return *this;
	}
	~Person() //Destructor
	{
		delete[] name;
		delete[] degree;
	}
	void printPersonData();
	int getStaticVariable() { return numberOfObjects; }
};

int Person::numberOfObjects = 0; //Definition of static member of a class!

void Person::printPersonData()
{
	if(gender && name)
	{
		std::cout << "Gender: " << gender << std::endl
				<< "Name: " << name << std::endl
				<< "Science degree: " << degree << std::endl
				<< "Age: " << age << std::endl
				<< "Height: " << height << std::endl
				<< "Weight: " << weight << std::endl << std::endl;
	}
	else
	{
		std::cout << "Invalid data!";
	}
}

int main()
{
	Person p1('F', "Gergana", "Professor", 55, 82.134, 1.82);
	Person p2('M', "Milen", "Associate Professor", 70, 89.142, 1.88);

	Person p3(p1);

	Person p4;
	p4 = p2;

	p1.printPersonData();
	p2.printPersonData();
	p3.printPersonData();
	p4.printPersonData();

	std::cout << "Instantiations (objects) of the class \"Person\": " << p1.getStaticVariable();

	return 0;
}
