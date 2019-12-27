#pragma once
#include "Production.h"
class ProductionStack :
	public Production
{
	/*
	������� ��LR(1)�ķ��еģ�����ʽ������ follow���ϣ���LR(1)�����ϵ�follow���ϣ�
	�Լ���ǰstack��״̬������С��㣩
	����һ������Ǹ�ʽ���Ƿ񱻷��ʹ���
	*/
public:
	ProductionStack(NonTerminator* head, int production_id);
	void stateInit();
	virtual bool operator==(const ProductionStack& p)const;    //��������
	virtual bool operator<(const ProductionStack& p)const;
	virtual bool operator>(const ProductionStack& p)const;
	virtual void printProduction()const;
	virtual void outputProductionAsFile(ofstream& fout)const;
	virtual bool isProductionEuqal(ProductionStack& p);   //�жϱ��ʽ��ֻ�жϲ���ʽ�ӣ��Ƿ���ͬ
	bool insertFollowSets(set<string> set);
	bool insertFollowSet(string set);
	//set ��get����
	ATTRIBUTE_MEMBER_FUNC(int, stackState); 
	ATTRIBUTE_MEMBER_FUNC(bool, isProcess);
	ATTRIBUTE_MEMBER_FUNC(set<string>, followSet);
	~ProductionStack();
private:
	int stackState;
	set<string> followSet;       //LR(1)�ķ��е�follow����
	bool isProcess;                      
};

