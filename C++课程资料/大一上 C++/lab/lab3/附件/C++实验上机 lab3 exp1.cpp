#include<iostream>
using namespace std;
int main()
{
	const int ArraySize = 10;
	int Num[ArraySize];
	cout << "Please enter ten integers" << endl;
	for (int i = 0;i < 10;i++)
		cin >> Num[i];         //��ѭ���������10���� i ��Ϊ counter;
	int Max = Num[0];
	int pos = 1; //pos ��ʾ�±�
	while (pos < ArraySize)
	{
		if (Max < Num[pos])
			Max = Num[pos];
		pos++;
	}
	cout << "The largest number is:  " << Max;
	system("pause");
	return 0;


	
}