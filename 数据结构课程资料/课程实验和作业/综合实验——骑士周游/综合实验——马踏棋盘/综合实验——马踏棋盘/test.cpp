#include"Chess.h"
#include<iostream>

using namespace std;
int main()
{
	//����1
	bool first = true;
	do
	{
		cout << "���������̵ı߳�(>=4)" << endl;
		int size;
		cin >> size;
		Chess myChess(size);
		if (!first)
		{
			myChess.remake(size);
		}
		cout << "��ʼ������ʿ���Σ����������ε����" << endl;
		int i, j;
		cin >> i >> j;
		if (myChess.Horse(i, j))
			cout << "��ʿ���γɹ���" << endl;
		else
			cout << "����ʧ��" << endl;
		cout << "���εĽ����" << endl;
		myChess.printChess();
		cout << "\n�Ƿ�������ԣ�����n�������Խ�����һ�����ԣ����������ַ���������" << endl;
		char flag;
		cin >> flag;
		if (flag == 'n')
			break;
		first = false;
	} while (true); 

	//����2
	bool first2 = true;
	do
	{
		cout << "���������̵ı߳�(>=4)" << endl;
		int size;
		cin >> size;
		Chess myChess(size);
		if (!first2)
		{
			myChess.remake(size);
		}
		cout << "��ʼ����Ѱ��������֮����̵���ʿ·��,���������" << endl;
		int i1, j1;
		cin >> i1 >> j1;
		cout << "�������յ�" << endl;
		int i2, j2;
		int length = 0;
		cin >> i2 >> j2;
		if (myChess.findHorsePath(i1, j1, i2, j2, length))
			cout << "�ɹ��ҵ�·��!·������Ϊ: " << length << endl;
		else
			cout << "�Ҳ���·��" << endl;
		cout << "��ʿ��·���Ľ����" << endl;
		myChess.printChess();
		cout << "\n�Ƿ�������ԣ�����n�������ԣ����������ַ���������" << endl;
		char flag;
		cin >> flag;
		if (flag == 'n')
			break;
		first2 = false;
	} while (true);
}