#pragma once
#include<vector>
#include "State.h"
#include<string>
#include<unordered_map>
#include<vector>
#include "token.h"
#include<iostream>
using namespace std;
class DFA
{
	struct tokenItem{      //�ýṹ���� token�� id �� name��Ӧ��һ���ṹ��
		int token_id;
		string token_name;
		tokenItem(int t_id, string t_name):token_id(t_id),token_name(t_name) {
		}
	};
public:
	DFA();
	~DFA();
	bool addTokenItem(int key, tokenItem i);
	bool addTokenItem(int key, int token_id, string token_name);
	bool removeTokenItem(int key, tokenItem i);     
	bool addKeepWord(string keyword,int token_id);
	void addState(State s);                          //���״̬
	State& getState(int i);
	void initStates(const int stateNum,  vector<int>** stateMatrix, const string edgeList[]);
	token isKeepWord(string keyword);                       //�ж��ǲ��Ǳ�����
	token scan(string str,  string(*inputConvert)(char c) = [](char c)->string {return string(1, c); });// ɨ���ַ�������token
private:
	string end;
	unordered_map<int, tokenItem> tokenDict;       // �ս��
	unordered_map<string, token> keepWords;        // ������
	vector<State> states;
};
