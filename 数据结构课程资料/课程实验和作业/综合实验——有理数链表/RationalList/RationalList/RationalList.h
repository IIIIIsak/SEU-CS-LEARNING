#ifndef RATIONALLIST_H
#define RATIONALLIST_H
#include<iostream>
#include"LinkList.hpp"
#include<iostream>
using namespace std;

class RationalList 
{
public:
	RationalList(int x,int y,int c=1);  
	~RationalList();
	void output(int c = 1);  //Ĭ�ϴ�ӡһ��ѭ��
	bool getCircle()const
	{
		return isCircle;
	}
private:
	int n; //��ĸ
	int m; //����
	int count; //��ӡ��ѭ���Ĵ���
	bool compare( LinkList<int>& lastR, int tempR, int tempD, linkNode<int>* & c);
	bool isCircle;
	LinkList<int> rList;
	
};

#endif 


