#pragma once
#include<string>
#include<set>
#include"MarcoDef.h"
using namespace std;
class Node
{
public:
	Node(string node_name);
	Node(int node_id, string node_name, string node_value);
	virtual ~Node();
	virtual bool operator<(const Node& n)const;
	ATTRIBUTE_MEMBER_FUNC(int, node_id);
	ATTRIBUTE_MEMBER_FUNC(string, node_value);
	ATTRIBUTE_READ_ONLY(string, node_name)
	virtual set<string> calFirstSet(set<string> called_stack)=0;
	ATTRIBUTE_READ_ONLY(set<string>, firstSet)
	ATTRIBUTE_MEMBER_FUNC(bool, calAgain);
protected:
	int node_id;                       //��һ��node��id, ��ͬ��node(����ͬ���͵�node������һ����
	string node_value;                // ���nodeԭʼ��token��ֵ
	string node_name;                 // ����ڵ�����Ʊ���˵ S, a , b ��
	set<string> firstSet;            // first����
	bool calAgain;
};

