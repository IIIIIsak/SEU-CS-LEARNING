#include<iostream>
#include"CommissionEmployee.h"
using namespace std;
CommissionEmployee::CommissionEmployee(const string& first, const string& last, const string& ssn, const int mm, const int dd, const int yy, double sales, double rate) :Employee(first, last, ssn, mm, dd, yy) //����Ը�����г�ʼ��
{
	setGrossSales(sales);
	setCommissionRate(rate);
}
void CommissionEmployee::setGrossSales(double sales)
{
	if (sales >= 0.0)
		grossSales = sales;
	else
		throw invalid_argument("Gross sales must be >=0.0");
}
double CommissionEmployee::getGrossSales()const
{
	return grossSales;
}
void CommissionEmployee::setCommissionRate(double rate)
{
	if (rate >= 0.0&&rate<1.0)
		commissionRate = rate;
}
double CommissionEmployee::getCommissionRate()const
{
	return commissionRate;
}
double CommissionEmployee::earnings()const//��������
{
	return getCommissionRate()*getGrossSales();
}
void CommissionEmployee::print()const //��ӡ
{
	cout << "commission employee: ";
	Employee::print();   //�õ�����ĺ���
	cout << "\ngross sales: " << getGrossSales()
		<< "; commission rate; " << getCommissionRate();
}