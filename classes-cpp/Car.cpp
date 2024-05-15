//4.Class Car (W3Resource)
#include <iostream>
#include <string>

using namespace std;

class Car
{
private:
	string company, model;
	int year;
public:
	void setYear(int pYear) { year = pYear; }
	void setCompany(string pCompany) { company = pCompany; }
	void setModel(string pModel) { model = pModel; }
	int getYear() { return year; }
	string getCompany() { return company; }
	string getModel() { return model; }
};

int main()
{
	Car MakuinSvetkavicata;

	MakuinSvetkavicata.setYear(1984);
	MakuinSvetkavicata.setCompany("Real Madrid");
	MakuinSvetkavicata.setModel("Subaru Impreza");

	cout << "Year: " << MakuinSvetkavicata.getYear() << endl;
	cout << "Model: " << MakuinSvetkavicata.getModel() << endl;
	cout << "Company: " << MakuinSvetkavicata.getCompany() << endl;
	return 0;
}
