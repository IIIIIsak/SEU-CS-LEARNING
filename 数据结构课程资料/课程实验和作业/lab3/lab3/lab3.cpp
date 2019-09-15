#include"BinaryTree.h"
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	BinaryTree myTree('#');
	ifstream fin;
	fin.open("binaryTree.txt", ios::in);
	if (!fin.is_open())
	{
		cout << "��ȡ�ļ�ʧ��<<endl";
		return 0;
	}
	myTree.creatBinTree(fin);
	cout << "���ļ��д���һ�ö�����\n" << endl;
	cout << "����Ļ�����һ�ö�����" << endl;
	myTree.printTreeInOrder();
	myTree.turnToMatrix();
	cout << "��������������array[" << myTree.Height() << "][" << myTree.getCols() << "]" << endl;
	myTree.printTreeMatrix();
	fin.close();
	system("pause");
	return 0;
}