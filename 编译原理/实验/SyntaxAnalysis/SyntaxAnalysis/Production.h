#pragma once
#include"NonTerminator.h"
#include<iostream>
#include<fstream>
using namespace std;
class Production
{
	
	/*
	����ʽ�࣬����һ��ָ����ս����ָ�룬��һ�����ս���µĲ���ʽid
	*/
public:
	Production(NonTerminator* head,int production_id);
	set<string> getFirstSet();
	virtual void printProduction()const;
	virtual void outputProductionAsFile(ofstream& fout)const;
	int getProductionSize()const;
	ATTRIBUTE_READ_ONLY(NonTerminator*, head);
	ATTRIBUTE_READ_ONLY(int, production_id);
	~Production();
protected:
	NonTerminator* head;      //����ʽ��ͷ�������Ƿ��ս����ָ��
	int production_id;        //���ս���µĵڼ�������ʽ    

};

