#include"HuffmanTree.hpp"
#include<iostream>
#include<fstream>
#include<string>
#include"HuffmanCoder.h"
using namespace std;
int main()
{
	ifstream fin;
	fin.open("English.txt", ios::in);
	if (!fin.is_open())
	{
		cout << "���ļ�ʧ�ܣ�" << endl;
		return 0;
	}
	ifstream fin1;
	fin1.open("English.txt", ios::in);
	if (!fin1.is_open())
	{
		cout << "���ļ�ʧ�ܣ�" << endl;
		return 0;
	}

	ofstream fout;
	fout.open("code.txt", ios::out);
	if (!fout.is_open())
	{
		cout << "���ļ�ʧ�ܣ�" << endl;
		return 0;
	}
	
	cout << "��ʼ����������,�Ը�Ŀ¼�µ�english.txt���б���" << endl;
	HuffmanCoder coder(26);
	if (coder.creatHuffmanTree(fin) && coder.creatCode(fin1, fout))
		cout << "����ɹ��������ļ��ڸ�Ŀ¼�µ�code.txt" << endl;
	else
		cout << "����ʧ�ܣ�" << endl;
	
	fin.close();
	fin1.close();
	fout.close();
	ifstream fin2;
	fin2.open("code.txt", ios::in);
	if (!fin2.is_open())
	{
		cout << "���ļ�ʧ�ܣ�" << endl;
		return 0;
	}
	ofstream fout1;
	fout1.open("uncode.txt", ios::out);
	if (!fout1.is_open())
	{
		cout << "���ļ�ʧ�ܣ�" << endl;
		return 0;
	}
	cout << "��ʼ����" << endl;
	if (coder.translateCode(fin2, fout1))
		cout << "����ɹ��������ļ��ڸ�Ŀ¼�µ�uncode.txt" << endl;
	else
		cout << "����ʧ��" << endl;
	fin2.close();
	fout1.close();
	cout << "��ʼ���������������Ȩֵ" << endl;
	coder.outputWeight();

	cout << "��ʼ��������ַ���Ӧ��ǰ׺��" << endl;
	coder.outputCode();
	//���Ȩֵ
	cout << "\n��ʼ�Ƚ��ı�" << endl;
	ifstream finOrigin;
	finOrigin.open("English.txt", ios::in);
	if (!finOrigin.is_open())
	{
		cout << "���ļ�ʧ�ܣ�" << endl;
		return 0;
	}

	ifstream finTarget;
	finTarget.open("uncode.txt", ios::in);
	if (!finTarget.is_open())
	{
		cout << "���ļ�ʧ�ܣ�" << endl;
		return 0;
	}
	if (coder.compare(finOrigin, finTarget))
		cout << "�ı��Ƚ�����" << endl;
	else
		cout << "�ı��Ƚϳ��ִ���" << endl;
	finOrigin.close();
	finTarget.close();
	system("pause");
	return 0;
}