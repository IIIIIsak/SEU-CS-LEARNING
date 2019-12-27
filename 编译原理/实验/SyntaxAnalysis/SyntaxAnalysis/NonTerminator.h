#pragma once
#include "Node.h"
#include<vector>
class NonTerminator :
	public Node
{
public:
	NonTerminator(string node_name);
	NonTerminator(int node_id, string node_name, string node_value);
	set<string> calFirstSet(int production_id,int stack_id=0);    //����ĳ������production��first set
	virtual set<string> calFirstSet(set<string> called_stack);
	void addDerivativeNode(int productionId,Node& n);
	void addProduction(vector<Node*> p);
	int getProductionNum()const;
	int getProductionSize(int productionID)const;
	Node* getNodeInProduction(int production_id, int stack_id);                //��ȡ����ʽ�еĽڵ�
	vector<Node*> getProduction(int production_id)const;
	~NonTerminator();
private:
	vector<vector<Node*>> productions;                   //���Զ���һϵ�еĲ���ʽ
};

