#include<iostream>
using namespace std;
int main()
{
	int number_three;
	cout << "����������һλ��"<<endl;
	int a1, a2, a3;
	cin >> a1 >> a2 >> a3;
	int number = 0;
	number = ((a1 * 10) + a2) * 10 + a3;
	cout << number;
	system("pause");
	return 0;
}