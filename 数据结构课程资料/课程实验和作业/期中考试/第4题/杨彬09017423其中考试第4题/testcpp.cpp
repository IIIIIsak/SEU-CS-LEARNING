#include<fstream>
#include<iostream>
#include"HuffmanTree.hpp";
using namespace std;
int main()
{
	float w[] = { 1,2,3,4,5,6, };
	HuffmanTree myTree(w, 6);
	cout<<"��Ȩ��Ϊ"<<myTree.getWeightLength();
	system("pause");
	return 0;
}