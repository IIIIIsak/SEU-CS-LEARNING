#include "ProductionManager.h"



ProductionManager::ProductionManager()
{
}


ProductionManager::~ProductionManager()
{
}
bool ProductionManager::addNonTerminator(string name, NonTerminator& n)
{
	auto iter = nonTerminators.find(name);
	if (iter == nonTerminators.end()) {
		//���û��
		nonTerminators.insert({ name,n });
		return true;
	}
	else {
		return false;
	}
}
bool ProductionManager::addTerminator(string name, Terminator& t) {
	auto iter = terminators.find(name);
	if (iter == terminators.end()) {
		//���û��
		terminators.insert({ name,t });
		return true;
	}
	else {
		return false;
	}
}
bool ProductionManager::addProduction(string nonterminator, vector<string> production) {
	auto non_iter = nonTerminators.find(nonterminator);
	if (non_iter == nonTerminators.end())
	{
		//û�ҵ�
		return false;
	}
	vector<Node*> p = vector < Node* >();
	for (auto string_iter = production.begin(); string_iter != production.end(); string_iter++) {
		//��������ʽ
		auto iter1 = nonTerminators.find(*string_iter);
		auto iter2 = terminators.find(*string_iter);
		if (!(iter1 == nonTerminators.end() && iter2 == terminators.end()) &&
			!(iter1 != nonTerminators.end() && iter2 != terminators.end())) {
			//������㣬�����ܶ��в����ܶ�û��
			if (iter1 != nonTerminators.end()) {
				Node& n = (*iter1).second;   //����ת����
				p.push_back(&n);
				continue;
			}
			if (iter2 != terminators.end()) {
				Node& n = (*iter2).second;   //����ת����
				p.push_back(&n);
			}
		}
		else {
			return false;
		}
	}
	(*non_iter).second.addProduction(p);
	return true;
}

ProductionStack ProductionManager::generateProductionStack(string n_key, int production_id) {
	//�ر�ע���ڴ�����,production��ŵĶ����漰�ڴ棬���Լ򵥵�ǳ�����Ϳ���
	// production_id �� �±������� 0 ��ʼ
	auto iter = nonTerminators.find(n_key);
	if (iter == nonTerminators.end()) {
		//���û�ҵ�
		return ProductionStack(nullptr, -1);
	}
	if (production_id >= (*iter).second.getProductionNum()) {
		//û���������ʽ
		return ProductionStack(nullptr, -1);
	}
	return ProductionStack(&((*iter).second), production_id);
}
vector<ProductionStack> ProductionManager::generateProductionStacks(string n_key) {
	vector<ProductionStack> productions = vector<ProductionStack>();
	auto iter = nonTerminators.find(n_key);
	if (iter == nonTerminators.end()) {
		//���û�ҵ�
		return productions;
	}
	for (int i = 0; i < (*iter).second.getProductionNum(); i++) {
		productions.push_back(ProductionStack(&((*iter).second), i));
	}
	return productions;
}

Production ProductionManager::generateProduction(string n_key, int production_id) {
	auto iter = nonTerminators.find(n_key);
	if (iter == nonTerminators.end()) {
		//���û�ҵ�
		return Production(nullptr, -1);
	}
	if (production_id >= (*iter).second.getProductionNum()) {
		//û���������ʽ
		return Production(nullptr, -1);
	}
	return Production(&((*iter).second), production_id);
}

vector<Production> ProductionManager::generateProductions(string n_key) {
	vector<Production> productions = vector<Production>();
	auto iter = nonTerminators.find(n_key);
	if (iter == nonTerminators.end()) {
		//���û�ҵ�
		return productions;
	}
	for (int i = 0; i < (*iter).second.getProductionNum(); i++) {
		productions.push_back(Production(&((*iter).second), i));
	}
	return productions;
}
int  ProductionManager::getProductionsNum(string n_key) {
	auto iter = nonTerminators.find(n_key);
	if (iter == nonTerminators.end()) {
		//���û�ҵ�
		return 0;
	}
	else {
		return (*iter).second.getProductionNum();
	}
}
vector<ProductionStack> ProductionManager::derivateProductions(ProductionStack p) {
	vector<ProductionStack> outputs = vector<ProductionStack>();
	NonTerminator* nt_ptr = p.get_head();  //��ָ��
	Node* n = nt_ptr->getNodeInProduction(p.get_production_id(), p.get_stackState());
	if (n == nullptr) {
		return outputs;         //��� û�ҵ��� �������ۣ����û�ҵ�Ӧ�� 100% �ĸ�����Ϊstack_id�Ѿ��������
	}
	n = dynamic_cast<NonTerminator*>(n);    //�������� ��Node������ʹ����������������������仰Ӧ���ܹ��жϡ�
	if (n == nullptr) {
		//���Ƿ��ս���Ͳ��ò���ʽ����,ע�������滹Ҫ���ж�һ�Σ�����������䶼���ؼٵ�����
		return outputs;
	}
	//�Ƿ��ս���������µĲ���ʽ
	outputs = generateProductionStacks(n->get_node_name());
	return outputs;
}
void ProductionManager::calAllFirstSet(string begin) {
	for (auto iter = terminators.begin(); iter != terminators.end(); iter++) {
		set<string> stack;
		iter->second.calFirstSet(stack);
	}
	for (auto iter = nonTerminators.begin(); iter != nonTerminators.end(); iter++) {
		set<string> stack;
		iter->second.calFirstSet(stack);
	}
}