#include"RationalList.h"
#include<iostream>
using namespace std;
int main()
{
	RationalList* myList;
	do
	{
		cout << "\n��ʼ���ԣ���������Ӻͷ�ĸ(!=0)" << endl;
		int n, m;
		cin >> n >> m;
		int c = 1;
        cout << "��ʼ��������ʾΪС��" << endl;
		myList = new RationalList(n, m);
		if (myList->getCircle())
		{
			cout << "����Ҫ��ӡ��ѭ����Ĵ���(>=1)" << endl;

			cin >> c;
		}
		cout << "���Ϊ��" << endl;
		myList->output(c);
		cout << "\n���Խ�����������n�������ԣ����������ַ���������" << endl;
		if (myList != nullptr)
		{
			delete myList;
			myList =nullptr;
		}
		char flag;
		cin >> flag;
		if (flag == 'n')
		{
			break;
		}


	} while (true);
	return 0;
}