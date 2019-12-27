#pragma once
#include<unordered_map>

using namespace std;

// �����State��DFA��State
class State
{
public:
	State(int id);
	~State();
	// getter
	inline int getStateID() {
		return stateID;
	}
	bool addPtrs(const string c, State* next);        //����ĳ����
	bool removePtrs(const string c);                 // �Ƴ�ĳ����
	void setEdgeJudgeFunction(string(*f)(string str));
	State* transfer(const string c);                //����������ַ�������һ��״̬��ָ��
protected:
	unordered_map<string, State*> next_ptrs ;
	string (*edgeJudgeFunction) (string str);
	int stateID;
};

