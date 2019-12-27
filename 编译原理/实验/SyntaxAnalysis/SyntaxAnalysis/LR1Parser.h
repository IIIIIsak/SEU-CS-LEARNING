#pragma once
#include "BottomUpParser.h"
#include<iostream>
#include"LR1State.h"
class LR1Parser :
	public BottomUpParser
{

public:
	LR1Parser(set<string>terminators, set<string> nonTerminators, vector<vector<string>> productions, string begin = "S1", string end = "$", string none = "none");
	~LR1Parser();
	unordered_map<string,LR1State> calNextStates( LR1State& s);
	virtual void buildParserGraph();   //����״̬ͼ
	virtual void buildParserTable();   //�������ͼ
	virtual void printStates()const;
	virtual void outputStatesAsfile(ofstream& fout)const;
	virtual void outParserModel(ofstream& fout);
	void initStates( vector<std::pair<string,int>> productions, vector<set<string>> followset);
private:
	set<LR1State> states;                //״̬ͼ , ���е�״̬�������� Parser��
};

