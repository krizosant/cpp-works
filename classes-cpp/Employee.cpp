// 7.Class Employee (W3Resource)
#include <iostream>
#include <cstring>

using namespace std;

class Employee
{
private:
	char* name;
	char* employeeId;
	double salary;
	unsigned int nameSize, idSize;
public:
	Employee(const char* pName, const char* pEmployeeId, double pSalary)
	{
		nameSize = strlen(pName);
		name = new char[nameSize + 1];
		strncpy(name, pName, nameSize);
		name[nameSize] = '\0';

		idSize = strlen(pEmployeeId);
		employeeId = new char[idSize];
		strncpy(employeeId, pEmployeeId, idSize);
		employeeId[idSize] = '\0';

		salary = pSalary;
	}
	~Employee()
	{
		delete[] name;
		delete[] employeeId;
	}
	void setSalary(double pAmount)
	{
		if(pAmount < 0)
		{
			salary -= (-pAmount);
		}
		else
		{
			salary += pAmount;
		}

	}
	double getSalary() { return this->salary; }
	char* getId() { return this->employeeId; }
	char* getName() { return this->name; }
};

int main()
{
	double amount;
	bool raiseChoice;
	Employee empOne("Gosho", "HT000", 3200);

	std::cout << "Would you increase (1) or decrease (0) salary?" << std::endl;
	std::cin >> raiseChoice;

	if(!raiseChoice)
	{
		std::cout << "Enter amount of money to decrease: " << std::endl;
		std::cin >> amount;
		std::cout << "Salary of " << empOne.getName() << " with id " << empOne.getId() << " is being decreased by " << -amount << "lv" << std::endl;
		empOne.setSalary(-amount);
		std::cout << empOne.getName() << "'s salary is: " << empOne.getSalary();
	}
	else
	{
		std::cout << "Enter amount of money to decrease: " << std::endl;
		std::cin >> amount;
		std::cout << "Salary of " << empOne.getName() << " with id " << empOne.getId() << " is being increased by " << amount << "lv" << std::endl;
		empOne.setSalary(amount);
		std::cout << empOne.getName() << "'s salary is: " << empOne.getSalary();
	}

	return 0;
}
