#pragma once
#include"ProductionManager.h"
#include"ParserState.h"
#include<iomanip>
#include"token.h"
#include<vector>
#include"SyntaxTree.h"
class BottomUpParser
{
	
public:
	BottomUpParser(set<string>terminators, set<string> nonTerminators, vector<vector<string>> productions,string begin="S1",string end="$",string none="none");
	virtual ~BottomUpParser();
	virtual void buildParserGraph() = 0;   //����״̬ͼ
	virtual void buildParserTable() = 0;   //���������
	virtual void printPaserTable(const int width=4,const int height =1)const;        //��ӡ״̬��
	virtual void outPaserTableAsFile (ofstream& fout, const int width = 4, const int height = 1)const;        //��ӡ״̬��
	virtual void outProductionsAsFile(ofstream& fout);        //��ӡ����ʽ
	virtual void outParserModel(ofstream& fout) {};
	virtual bool scanTokenStream(vector<token> tokenstream , string analyze_report_dir );//�� tokenstream�н����﷨���������ҽ��������棨�������̣��﷨���ȣ��ͷ���ģ�ͣ�״̬ͼ��״̬��������ļ��У�           
	vector<pair<string, int>> getOperations(int state, string input)const;
	static void printStack(vector<int> state_stack, vector<string> string_stack, vector<token> input, int begin);
	static void outputStackAsFile(ofstream& fout,vector<int> state_stack, vector<string> string_stack, vector<token> input ,int begin);
	Production getProductionById(int p_id); //ͨ�� id����Ψһ�ı��ʽ
	void sloveAmbiguousTable(vector< pair<int, pair<string, int>>> deleteOperations);
	ATTRIBUTE_MEMBER_FUNC(set<string>, nonTerminators);
	ATTRIBUTE_MEMBER_FUNC(set<string>, terminators);
	ATTRIBUTE_READ_ONLY(string, end);
	ATTRIBUTE_READ_ONLY(string, none);
	ATTRIBUTE_READ_ONLY(string, begin);
protected:
	string begin;
	string end;
	string none;
	set<string>terminators;           //�ս���ţ�������$��һ����  ,��Ӧ���ظ���
	set<string> nonTerminators;       //���ս�ڵ㣬�������Ϊ��������������ֵ��Ӧ���ظ���
	unordered_map<string,int> tableItems_map;           //��������������int ��Ӧ���ֵ�
	vector<string> tableItems;                           // ������������꣬ �� map ����ӳ��
	vector<string> production_base_head;                    // base_head �� base_id����ӳ��
	unordered_map<string, int> production_base_id;
	vector<vector<string>> string_productions;    //����ʽ
	vector<vector<vector<std::pair<string,int>>>> parserTable;     //������   pair��һ����ʾ ���� s ת��,r��Լ�� int ��ʾĿ��
	ProductionManager pm;                    //���еĽڵ㶼������pm��
};

