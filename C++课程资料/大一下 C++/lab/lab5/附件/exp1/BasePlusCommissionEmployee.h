#ifndef BASEPLUS_H
#define BASEPLUS_H
#include"CommissionEmployee.h"
class BasePlusCommissionEmployee :public CommissionEmployee
{
public:
	BasePlusCommissionEmployee(const string&, const string&, const string&, const int, const int, const int, double = 0.0, double = 0.0, double = 0.0); //���ǿ�������̳��У����캯������ҲҪ��������Ĺ��캯���Ĳ����������û���Ĺ��캯�����г�ʼ��
	void setBaseSalary(double);
	double getBaseSalary()const;
	virtual double earnings()const; //��̬
	virtual void print()const;//��̬
private:
	double baseSalary;
};
#endif
