#pragma once
#include"ProductionStack.h"
#include"NonTerminator.h"
#include"Terminator.h"
#include<unordered_map>

class ProductionManager
{
public:
	ProductionManager();
	~ProductionManager();
	bool addNonTerminator(string name, NonTerminator& n);
	bool addTerminator(string name, Terminator& t);
	bool addProduction(string nonterminator, vector<string> terminators);
	ProductionStack generateProductionStack(string noterminator, int production_id);   //���ﷵ�صĶ���ֵ����Ҫ�ر�ע���ڴ������
	Production generateProduction(string noterminator, int production_id);
	vector<Production> generateProductions(string noterminator);
	vector<ProductionStack> generateProductionStacks(string noterminator);
	int getProductionsNum(string nonterminator);
	vector<ProductionStack> derivateProductions(ProductionStack p);     //��һ������ʽ�Ƶ������Ĳ���ʽ
	void calAllFirstSet(string begin);
private:
	unordered_map<string, NonTerminator> nonTerminators;
	unordered_map<string, Terminator> terminators;

};

