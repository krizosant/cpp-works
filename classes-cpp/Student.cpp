9.Class Student (W3Resource)
#include <iostream>
#include <vector>
#include <cstring>

class Student
{
private:
	char* name;
	char* _class;
	unsigned int rollNumber, nameSize, classSize;
	std::vector<int> grades;
public:
	Student(const char* pName, const char* pClass, unsigned int pRollNumber, std::vector<int> pGrades)
	{
		nameSize = strlen(pName);
		name = new char[nameSize + 1];
		strncpy(name, pName, nameSize);
		name[nameSize] = '\0';

		classSize = strlen(pClass);
		_class = new char[classSize + 1];
		strncpy(_class, pClass, classSize);
		_class[classSize] = '\0';

		rollNumber = pRollNumber;

		for(size_t index = 0; index < pGrades.size(); index++)
		{
			grades.push_back(pGrades[index]);
		}
	}
	~Student()
	{
		delete[] name;
		delete[] _class;
	}
	float setAvgGrade()
	{
		float avgGrade = 0;
		for(size_t index = 0; index < grades.size(); index++)
		{
			avgGrade += grades[index];
		}

		return avgGrade = avgGrade / grades.size();
	}
	char* getName() { return this->name; }
	char* getClass() { return this->_class; }

};

int main()
{
	std::vector<int> mainGrades = {2, 2, 5, 4, 6, 6, 6, 5, 4, 5, 5, 6};
	Student student("Ganyo", "Mathematics", 5, mainGrades);

	std::cout << "Student " << student.getName() << "'s average grade this semester in class " << student.getClass() << " is: " << student.setAvgGrade();

	return 0;
}
