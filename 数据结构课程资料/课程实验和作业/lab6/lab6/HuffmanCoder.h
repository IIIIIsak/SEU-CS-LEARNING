#ifndef HUFFMANCODER_H
#define HUFFMANCODER_H
#include"HuffmanTree.hpp"
#include<fstream>
#include<iostream>
#include<string>
using namespace std;
class HuffmanCoder
{
public:
	HuffmanCoder(int n=26);
	~HuffmanCoder();
	bool creatHuffmanTree(ifstream& fin); //���ļ��ж������ݲ�����ͳ��,Ȼ������һ�ù�������
	bool creatCode(ifstream& fin, ofstream& fout);  //���ļ��ж����ַ����������
	bool translateCode(ifstream& fin, ofstream& fout); //���ļ��ж�����룬���ҷ���
    bool compare(ifstream& finOrigin, ifstream& finTargt); //�Ƚ�Դ�������
	void makeEmpty(); //����
	void outputWeight();
	void outputCode();
private:
	HuffmanTree<double>* huffmanPtr;
	double * weight;
	int nums;

};

#endif


