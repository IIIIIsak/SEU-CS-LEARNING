#pragma once
#include"ProductionStack.h"
#include<unordered_map>
#include"ProductionManager.h"
#include<fstream>
class ParserState
{
public:
	ParserState(int state_ID);
	virtual ~ParserState();
	void init();
	virtual ParserState* transfer(string input);
	virtual void calFollowSet(ProductionStack& p, set<ProductionStack>& fps ) = 0;          //����״̬�ڵ�һ�����ʽ��follow����
	virtual void stateGrow(ProductionManager& pm) = 0;
	virtual bool operator==( const ParserState& p)const= 0;                 //����Ҫ����һ��==����
	virtual bool operator<(const ParserState& p)const=0;
	virtual void printState()const;
	virtual void outputStateAsFile(ofstream& fout)const;
	bool addNextState(string key, ParserState* s);
	bool addProduction(ProductionStack &p);                       //ע�⣬���������ֵ���ݣ�Ҳ����˵ÿ��state�����ڲ������ж�����productionStack���󸱱����������ܻ����
	bool addProductionAsMerge(ProductionStack& p);               // ��ǿ��һ��C++��ֵ���ݺ����ô��ݵ������ر��Ƕ�������˵
	const unordered_map<string, ParserState*>& getNextStates()const;
	static set<string> convertFirstSetToString(set<Node*>& firstset);
	ATTRIBUTE_READ_ONLY(set<ProductionStack>, productions);
	ATTRIBUTE_MEMBER_FUNC(int, stateID)
	ATTRIBUTE_MEMBER_FUNC(bool,isProcess)
protected:
	bool isProcess;
	int stateID;   //stateID >=0 ��Ч�� stateID = -1ʱ����ʾ�����ڸ�״̬�� stateID=-2�Ǳ�ʾ״̬δ����idֵ
	set<ProductionStack> productions;                          //����
	unordered_map<string, ParserState*> nextStates;

};

