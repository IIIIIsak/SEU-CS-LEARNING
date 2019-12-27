#include "ParserState.h"



ParserState::ParserState(int state_ID):stateID(state_ID)
{
	//��ʼ��
	init();
}
void ParserState::init() {
	//��ʼ��
	productions = set<ProductionStack>();
	nextStates = unordered_map<string, ParserState*>();
	isProcess = false;
}
ParserState* ParserState::transfer(string input)
{
	auto iter = nextStates.find(input);
	if (iter != nextStates.end()) {
		return (*iter).second;
	}
	return nullptr;
}

bool ParserState::addNextState(string key, ParserState* s)
{
	return nextStates.insert({ key,s }).second;
}
bool ParserState::addProduction(ProductionStack& p)
{
	// ��עû�д���� isProcess
	return productions.insert(p).second;    //�������ɹ�����true
}

bool ParserState::addProductionAsMerge(ProductionStack& p) {
	// ��ɲ���merge follow set�ķ�ʽ���������ʽp����ô����true�������ȫ����ӵķ���false
	for (set<ProductionStack>::iterator iter = productions.begin(); iter != productions.end(); iter++) {
		//ProductionStack& ip = const_cast<ProductionStack&>(*iter);  //����set�ĵ���������Ĭ����const���ͣ���Ҫ�޸�setԪ�ص����ԣ���Ҫ����ǿת
		ProductionStack ip = *iter;    //��ֹ��������˱Ƚϱ��ص� ��ɾ���ٲ��룬������������򷽱�����ıȽ�
		if (ip.isProductionEuqal(p)) {
			//�����������ʽ���ı��ʽ����ͬ��
			if (ip.insertFollowSets(p.get_followSet())) {				//��������follow�� �ϲ���ԭ���Ĳ���ʽ��
				//����������µ�follow���ϣ��Ѵ���������Ϊfalse
				ip.set_isProcess(false);
			}
			productions.erase(iter);   
			productions.insert(ip);
			return true;
		}
	}
	//���û�оͲ���
	ProductionStack p1 = p;
	return productions.insert(p1).second;
}
set<string> ParserState::convertFirstSetToString(set<Node*>& firstset) {
	set<string> output = set<string>();
	for (auto iter = firstset.begin(); iter != firstset.end(); iter++) {
		output.insert((*iter)->get_node_name());
	}
	return output;
}
void ParserState::printState()const {
	cout << "state: " << stateID << endl;
	for (auto iter = productions.begin(); iter != productions.end(); iter++) {
		(*iter).printProduction();
		cout << endl;
	}
	for (auto iter = nextStates.begin(); iter != nextStates.end(); iter++) {
		cout << "input:" << (*iter).first << " --> state" << (*iter).second->get_stateID() << endl;
	}
 }
void ParserState::outputStateAsFile(ofstream& fout)const {
	fout << "state: " << stateID << endl;
	for (auto iter = productions.begin(); iter != productions.end(); iter++) {
		(*iter).outputProductionAsFile(fout);
		fout << endl;
	}
	for (auto iter = nextStates.begin(); iter != nextStates.end(); iter++) {
		fout << "input:" << (*iter).first << " --> state" << (*iter).second->get_stateID() << endl;
	}
}
const unordered_map<string, ParserState*>& ParserState::getNextStates()const {
	return nextStates;
}
ParserState::~ParserState()
{
}
