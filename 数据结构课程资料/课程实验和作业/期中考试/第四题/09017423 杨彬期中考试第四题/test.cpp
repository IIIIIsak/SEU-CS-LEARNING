#include<iostream>
#include"BinaryTree.h"
#include<fstream>
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
	myTree.turnToMatrix();
	myTree.printTreeMatrix();
	cout << "��Ȩֵ֮��Ϊ" << myTree.getWeightLength() << endl;
	system("pause");
}