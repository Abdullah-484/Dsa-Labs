#include <iostream>
using namespace std;

class Employee
{
public:

	virtual double calSal() = 0;
};
class FullTimeEmp :public Employee
{
private:
	double fixSal;
public:
	FullTimeEmp(double s) :fixSal(s)
	{
	}
	double calSal()
	{
		return fixSal;
	}
};
class PartialTimeEmp :public Employee
{
private:
	double workHour;
	double rate;
public:
	PartialTimeEmp(double h, double r) :workHour(h), rate(r)
	{
	}
	double calSal()
	{
		return workHour * rate;
	}
};

int main()
{
	FullTimeEmp f(500000);
	PartialTimeEmp p(20.5, 7000.0);
	cout << "Full Time Employee Salary=" << f.calSal() << endl;
	cout << "Partial Time Employee Salary=" << p.calSal() << endl;

	return 0;
}