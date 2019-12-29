#include "DFA.h"



DFA::DFA()
{
}


DFA::~DFA()
{
}

bool DFA :: addTokenItem(int key, tokenItem i) {
	if (tokenDict.find(key) == tokenDict.end())
	{
		tokenDict.insert({ key, i });
		return true;                            //������ڱߵĻ�����true
	}
	else {
		return false;
	}
}
bool DFA::addTokenItem(int key, int token_id, string token_name) {
	tokenItem i = tokenItem(token_id, token_name);
	if (tokenDict.find(key) == tokenDict.end())
	{
		tokenDict.insert({ key, i });
		return true;                            //������ڱߵĻ�����true
	}
	else {
		return false;
	}
}
bool DFA :: removeTokenItem(int key, tokenItem i) {
	auto iter = tokenDict.find(key);
	if (iter != tokenDict.end())
	{
		tokenDict.erase(iter);
		return true;                            //������ڱߵĻ�����true
	}
	else {
		return false;
	}
}
bool  DFA::addKeepWord(string keyword, int token_id) {
	auto iter = keepWords.find(keyword);
	if (iter == keepWords.end())
	{
		token t =  token(token_id, keyword, "_");      //�ؼ��ʵ�tokenû��ֵ
		keepWords.insert({ keyword,t });
		return true;
	}
	else {
		return false;
	}
}
void DFA::addState(State s)                     //���״̬
{
	states.push_back(s);
}
void  DFA::initStates(const int stateNum,  vector<int>** stateMatrix, const string edgeList[]) {
    //��ʼ��state
	// stateMatrix ���� ������ ��״̬ i -> j �ı� ��ֵΪ edgeList[i][j]<<
	for (int i = 0; i < stateNum;  i++) {
		states.push_back(State(i));
	}
	for (int i = 0; i < stateNum; i++) {
		for (int j = 0; j < stateNum; j++) {
			vector<int> v = *(*(stateMatrix + i) + j);
			//vector<int> v = stateMatrix[i][j];
			if (v.size()<=0) {
				continue;                     // edge vector��û������
			}
			else {
				for (int p = 0; int(p < v.size()); p++) {
					states[i].addPtrs(edgeList[v[p]], &states[j]);
				}
			}
		}
	}
}
State& DFA::getState(int i) {
	return (states[i]);
}
token DFA::isKeepWord(string keyword) {
	auto iter = keepWords.find(keyword);
	if (iter != keepWords.end())
	{
		return (*iter).second;
	}
	else {
	    token t = token(-1, "no key word", "_");
		return t;
	}
}
token DFA::scan(string str, string(*inputConvert)(char c)) {
	// ɨ���ַ������ַ����Ľ�β�����ǽ����� end, DFA�� states 0 �ǳ�ʼ״̬,�ڶ���������һ������ָ�룬ָ��һ�����ַ�ӳ��Ϊ�ַ����ߵĺ�����Ĭ�Ͻ��ַ�ֱ��ת��Ϊstring
    // ���ж��ǲ��ǹؼ���
	token  t = isKeepWord(str);
	if (t.getTokenID() != -1) {
		return t;
	}
	State* state = &(states[0]);   // ��ó�ʼ״̬��ָ��
	int index = 0;
	while (state != nullptr) {
		char c = str[index];
		string ch = inputConvert(c);
		if (index>=int(str.length())) {
			//������ս��
			int key = state->getStateID();
			auto iter = tokenDict.find(key);     //����
			if (iter != tokenDict.end()) {
				//����ҵ���
				tokenItem ti = (*iter).second;
				token t = token(ti.token_id, ti.token_name, str);
				return t;
			}
			else {
				cout << "lexical_error\n";    //�ʷ�����
				token t = token(-1, "lexical_error", str);
				cout << t << endl;
				return t;
			}
		}
		//��������ս����������һ��״̬
		state = state->transfer(ch);
		if (state == nullptr) {
			//����Ҳ����Ļ�������
			cout << "lexical_error\n";
			str.pop_back();
			token t = token(-1, "lexical_error", str);
			cout << t << endl;
			return t;
		}
		index++;     //��ȡ��һ���ַ�
	}
	
}