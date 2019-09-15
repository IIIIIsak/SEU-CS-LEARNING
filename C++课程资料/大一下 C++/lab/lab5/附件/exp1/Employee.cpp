#include<iostream>
#include"Employee.h"
#include"Date.h"
using namespace std;
Employee::Employee(const string& first, const string& last, const string& ssn,const int mm,const int dd,const int yy ):firstName(first), lastName(last), socialSecurityNumber(ssn),birthDate(mm,dd,yy)
{
}
void Employee::setFirstName(const string& first)
{
	firstName = first;
}
string Employee::getFirstName()const
{
	return firstName;
}
void Employee::setLastName(const string& last)
{
	lastName = last;
}
string Employee::getLastName()const
{
	return lastName;
}
void Employee::setSocialSecurityNumber(const string& ssn)
{
	socialSecurityNumber = ssn;
}
string Employee::getSocialSecurityNumber()const
{
	return socialSecurityNumber;
}
void Employee::print()const//�麯���ؼ���virtual ����������һ��
{
	cout << getFirstName() << " " << getLastName()<<"\nbirthday: "<<birthDate
		<< "\nsocial security number: " << getSocialSecurityNumber();   //˼��Ϊʲô��ֱ�ӷ���string?
	
}
Date Employee::getdate()
{
	return birthDate;
}