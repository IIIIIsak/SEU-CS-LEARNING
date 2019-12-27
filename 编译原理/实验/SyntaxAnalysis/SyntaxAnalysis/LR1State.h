#pragma once
#include "ParserState.h"
#include"ProductionManager.h"
class LR1State :
	public ParserState
{
public:
	LR1State(int state_ID);
	~LR1State();
	virtual bool operator==(const ParserState& p)const;                 //����Ҫ����һ��==����
	virtual bool operator<(const ParserState& p)const;
	virtual void calFollowSet(ProductionStack& p, set<ProductionStack>& fps);          //����״̬�ڵ�һ�����ʽ��follow����
	virtual void stateGrow(ProductionManager& pm);
};

