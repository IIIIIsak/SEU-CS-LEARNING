#include "State.h"



State::State(int id)
{
	stateID = id;     //  -1 ��ʾ��Ч״̬
	edgeJudgeFunction = nullptr; //Ϊ��
}


State::~State()
{
}

bool State::addPtrs(string c, State* next)        //����ĳ����
{
	if (next_ptrs.find(c) == next_ptrs.end())
	{
		next_ptrs.insert({ c, next });
		return true;                            //������ڱߵĻ�����true
	}
	else {
		return false;                       
	}
}

bool State::removePtrs(string c)                // �Ƴ�ĳ����
{	
	auto iter = next_ptrs.find(c);
	if (iter != next_ptrs.end())
	{
		next_ptrs.erase(iter);
		return true;                            //������ڱߵĻ�����true
	}
	else {
		return false;
	}
}
State* State::transfer(string c)            //����������ַ�������һ��״̬��ָ��
{   
	string key = c;
	if (edgeJudgeFunction != nullptr) {
		key = edgeJudgeFunction(c);
	}
	auto iter = next_ptrs.find(key);
	if (iter != next_ptrs.end())
	{
		return (*iter).second;                        //������ڱߵĻ�����ָ��
	}
	else {
		return nullptr;
	}
}

void State::setEdgeJudgeFunction(string(*f)(string str)) {
	edgeJudgeFunction = f;
}