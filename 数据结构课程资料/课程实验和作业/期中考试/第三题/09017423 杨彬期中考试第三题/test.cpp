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
	cout << "��������������array[" << myTree.Height() << "][" << myTree.getCols() << "]" << endl;
	myTree.printTreeMatrix();
	cout << "��Ϊһ�Ľڵ�ĸ���Ϊ" << myTree.getDegreeOne() << endl;
	system("pause");
}