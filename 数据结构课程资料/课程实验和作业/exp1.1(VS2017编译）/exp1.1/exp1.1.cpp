#include<iostream>
#include<ctime>
using namespace std;
long int Inequality(long int n, long  int& count, long int &pos)
{

	long int tempCount = 0;
	long int total = 0;
	long int i = 1;

	tempCount += 3;
	while (total < n)
	{
		tempCount += 1;
		total += i;
		i++;
		tempCount += 2;
	}
	tempCount += 1;
	count = tempCount;
	pos = i - 2;
	return i;
}

int main()
{

	long  int n;
	char flag = 'n';
	long int count, i = 0;
	double duration;
	clock_t start=0, stop=0;

	do {
		cout << "������һ������n" << endl;
		cin >> n;
		 start = clock();
		Inequality(n, count, i);
		 stop = clock();
		duration = (static_cast<double>(stop - start)) / CLK_TCK;
		cout << "���㲻��ʽi����Сֵ" << i << endl;
		cout << "�㷨(ֻ���㺯��ִ�еĳ��򲽣��ĳ�����" << count << endl;
		cout << "�㷨ִ�е�ʱ��" << duration << endl;
		cout << endl;
		cout << "����n�˳�" << endl;
		cin >> flag;
	} while (flag != 'n');
	system("pause");
	return 0;
}