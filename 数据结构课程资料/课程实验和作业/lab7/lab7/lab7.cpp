#include<iostream>
#include"HashTable.hpp"
#include<ctime>
#include<stdlib.h>
using namespace std;
int main()
{
	srand(time(0)); //������
	bool first = true;
	do
	{ 
	cout << "����������{3��7��11��19}��ѡ��һ��ֵ" << endl;
	int prim;
	cin >> prim;
	cout << "��{10��20��50}��ѡȡһ��n" << endl;
	int n;
	cin >> n;
	HashTable<int, int> myHash(prim, prim+1);
	if (!first)//���ǵ�һ�ν���ѭ��
		myHash.reMake(prim, prim + 1);
	int x;
	cout << "�ؼ��� : ";
	for (int i = 0; i < n; i++)
	{
		x = 1 + rand() % 1000;
		cout << x << " ";
		myHash.insert(x, x);
	}
	//���ԭʼ����
	cout << endl;
	myHash.output();
	cout << endl;
	myHash.staticticAnalyse();
	cout << "\n�Ƿ�ֹͣ���ԣ���ֹͣ��������n,�������������ַ�����ʵ��" << endl;
	char flag;
	cin >> flag;
	if (flag == 'n')
		break;
	first = false;
	cout << "\n\n";
	} while (true);
	system("pause");
		return 0;
}