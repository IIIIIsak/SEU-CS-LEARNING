#include<iostream>
#include<iomanip>
#include<vector>
#include"Employee.h"
#include"SalariedEmployee.h"
#include"CommissionEmployee.h"
#include"BasePlusCommissionEmployee.h"
#include"Date.h"
using namespace std;
void virtualViaPointer(const Employee* const);//ͨ��ָ������麯��
void virtualViaReference(const Employee& );//ͨ�����÷���   �²� ָ����Դﵽ�麯����Ч���������ò��� �������ָ������ö����Դﵽ�麯����Ч��
int main()
{
	cout << fixed << setprecision(2);
	SalariedEmployee salariedEmployee("John", "Smith", "111-11-1111", 800);
	CommissionEmployee commissonEmployee("Sue", "Jones", "333-33-3333", 10000, .06);
	BasePlusCommissionEmployee basePlusCommissionEmployee("Bob", "Lewis", "444-44-4444", 5000, .04, 300);
	cout << "Employees processed individually ysing static binding:\n\n";
	salariedEmployee.print();
	cout << "\nearned $" << salariedEmployee.earnings() << "\n\n";
	commissonEmployee.print();
	cout << "\nearned $" << commissonEmployee.earnings() << "\n\n";
	basePlusCommissionEmployee.print();
	cout << "\nearned $" << basePlusCommissionEmployee.earnings() << "\n\n";
	vector<Employee*> employees(3);
	employees[0]= &salariedEmployee;
	employees[1]= &commissonEmployee;
	employees[2]= &basePlusCommissionEmployee;
	cout << "Employees processed polymorphically via dynamic binding:\n\n";
	cout << "Virtual function calls mad off base-class pointers:\n\n";
	for (size_t i = 0;i < employees.size();++i)
		virtualViaPointer(employees[i]);
	for (size_t i = 0;i < employees.size();++i)  //emoloyees[i]��һ��ָ��
		virtualViaReference(*employees[i]);
     Employee* a = &salariedEmployee;
	(*a).print();
	cout<<"\nearned $" << (*a).earnings();   //ֻ�ܲ���ָ��������õķ�ʽ�������С���ķ������ܴﵽ�麯����Ч����
	system("pause");
	return 0;
}
void virtualViaPointer(const Employee*const baseClassPtr)
{
	baseClassPtr->print();
	cout << "\nearned $" << baseClassPtr->earnings() << "\n\n";
}
void virtualViaReference(const Employee&  baseClassRef)
{
	baseClassRef.print();
	cout << "\nearned $" << baseClassRef.earnings() << "\n\n";
}
