#include<iostream>
using namespace std;
int main()
{
	int number_five;
	cout << "������һ����λ����  ";
	cin >> number_five;
	int temp_five= number_five;
	cout << temp_five % 10<<" ";
	temp_five = temp_five / 10;
	cout << temp_five % 10 << " ";
	temp_five = temp_five / 10;
	cout << temp_five % 10 << " ";
	temp_five = temp_five / 10;
	cout << temp_five % 10 << " ";
	temp_five = temp_five / 10;
	cout << temp_five % 10 << " ";
	temp_five = temp_five / 10;
	system("pause");
	return 0;
	
	

}