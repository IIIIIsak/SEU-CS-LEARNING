#include<iostream>
#include"HugeInteger.h"
#include<ctime>
#include<cstdlib>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	cout << "A text for the HugeInteger class \n" << "Text 1 ���������ָ�ֵ,����+ - = != > < >= <=����"<<endl<<endl;
	srand(time(0));   //Text 1
	for (int i = 0; i < 10;i++)
	{
		 long long int a = 0 + rand() % 10000;
		 long long int b= 0 + rand() % 10000;
		HugeInteger x = a;
		HugeInteger y = b;
		cout<< "x is " << x << "    y is " << y << endl;
		cout << x << "+" << y << "=" << x + y << "\t" << "text value (the ture value of x+y)" << a + b<<endl;
		if(x>y)
		cout <<"x is greater than y"<<endl
			<<x<<"-"<<y<<"=" << x - y <<"\t"  << "text value (the ture value of x-y )" << a - b << endl;
		if(x<y)
			cout  << "y is greater than x" << endl
			<< y << "-" << x<< "="  << y - x << "\t"  << "text value (the ture value of y-x )" << b - a << endl;
		if (x == y)
			cout << "x is equal to y" << endl;
		if(x>=y)
			cout << "x is greater or equal to y" << endl;
		if(x<=y)
			cout << "x is less or equal to y" << endl;
		cout << endl << endl;
	}
	cout << "Text 2 �����ַ�������ʽ�����ַ�������ֵ��ϵ���ʽ��ֵ��" << endl;
	char text = 'y';
	while (text == 'y')
	{
		HugeInteger x;
		HugeInteger y;
		cout << "������x ��ֵ ";
		cin >> x;
		cout << "������y ��ֵ ";
		cin >> y;
		cout << "x is " << x << "    y is " << y << endl;
		cout << x << "+" << y << "=" << x + y << "\t"<<endl;
		if (x > y)
			cout << "x is greater than y" << endl
			<< x << "-" << y << "=" << x - y << "\t" << endl;
		if (x < y)
			cout << "y is greater than x" << endl
			<< y << "-" << x << "=" << y - x << "\t" << endl;
		if (x == y)
			cout << "x is equal to y" << endl;
		if (x >= y)
			cout << "x is greater or equal to y" << endl;
		if (x <= y)
			cout << "x is less or equal to y" << endl;
		cout << "y continue n not continue";
		cin >> text;
		cout << endl << endl;
	}
	cout << "Text3 ";
	HugeInteger x("0");
	if (x.isZero())
		cout << "x contains the value of zero";
	system("pause");
}