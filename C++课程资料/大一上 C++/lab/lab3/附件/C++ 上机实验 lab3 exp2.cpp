#include<iostream>
using namespace std;
int main()
{
	cout << "������һ��5λ��";
	int number, Numarrays[5];
	cin >> number;
	int pos1 = 0;
	while (number>0)
	{
		Numarrays[pos1++] = number % 10;
		number = number / 10;
	}
	pos1 -= 1;   // �ؼ���Ҫ��ȥ����ϵ��Ǹ���
	int flag = 1, pos = 0;
	while (pos<pos1&&flag==1)
	{
		if (Numarrays[pos++] == Numarrays[pos1--])
			flag = 1;
		else flag = 0;
	}
	if (flag == 1)
		cout << endl << "����λ����һ��������";
	else
		cout << endl << "����λ������һ��������";
	system("pause");
	return 0;
}
