#include<iostream>
#include"BasePlusCommissionEmployee.h"
using namespace std;
BasePlusCommissionEmployee::BasePlusCommissionEmployee(const string& first, const string& last, const string& ssn, const int mm, const int dd, const int yy, double sales, double
	rate, double salary) :CommissionEmployee(first, last, ssn,mm,dd,yy, sales, rate)//���ǿ�������̳��У����캯������ҲҪ��������Ĺ��캯���Ĳ����������û���Ĺ��캯�����г�ʼ��
{
	setBaseSalary(salary);
}
void BasePlusCommissionEmployee::setBaseSalary(double salary)
{
	if (salary >= 0.0)
		baseSalary = salary;
	else
		throw invalid_argument("Salary must be >=0.0");
}
double BasePlusCommissionEmployee::getBaseSalary()const
{
	return baseSalary;
}
double BasePlusCommissionEmployee::earnings()const //��̬
{
	return getBaseSalary() + CommissionEmployee::earnings();  //�ټ���֮ǰ��earnings
 }
void BasePlusCommissionEmployee::print()const//��̬
{
	cout << "base-salaried commission employee: ";
	CommissionEmployee::print();
	cout << " ,base salary:" << getBaseSalary();
 }