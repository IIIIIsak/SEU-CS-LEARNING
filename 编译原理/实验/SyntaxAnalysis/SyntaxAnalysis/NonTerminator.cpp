#include "NonTerminator.h"



NonTerminator::NonTerminator(string node_name) :Node(node_name)
{

}
NonTerminator::NonTerminator(int node_id, string node_name, string node_value) : Node(node_id, node_name, node_value)
{

}
NonTerminator::~NonTerminator() {

}

void NonTerminator::addDerivativeNode( int production_id,Node& n) {
	productions[production_id].push_back(&n);
}

void NonTerminator::addProduction(vector<Node*> p) {
	productions.push_back(p);
}

int NonTerminator::getProductionNum()const {
	return productions.size();  //���ܷ���
}
int NonTerminator::getProductionSize(int production_id)const {
	if (production_id >= int(productions.size())) {
		return -1;         //-1�Ǵ�����
	}
	return productions[production_id].size();
}
Node*  NonTerminator::getNodeInProduction(int production_id, int stack_id) {
	if (production_id >= int( productions.size())) {
		return nullptr;
	}
	if (stack_id >= int(productions[production_id].size())) {
		return nullptr;
	}
	return productions[production_id][stack_id];
}

vector<Node*>   NonTerminator::getProduction(int production_id)const {
	return productions[production_id];
}

set<string> NonTerminator::calFirstSet( int production_id, int stack_id) {
	vector<Node*> p = productions[production_id];
	set<string> fset = set<string>();
	for (auto n_iter = p.begin()+ stack_id; n_iter != p.end(); n_iter++) {
		//�ڲ�ѭ����������ʽ�Ľڵ�
		set<string> subfirstSet = (*n_iter)->get_firstSet();
			fset.insert(subfirstSet.begin(), subfirstSet.end());   //��õ�ǰ�ڵ��first����  ����ע�� �ڵ��ȫ�ֵ�first�����Ѿ�������
		if (fset.erase("none") > 0) {    //����������� �մ��ķ��ս����ע��remove�����Ѿ��ѿմ��Ƴ���
			if (n_iter + 1 == p.end()) {
				//����Ѿ����������һ���ڵ㣬���Ҵ��ڿմ��ߣ�ǰ��ÿһ�������ڿմ��ߣ�,����մ���
				fset.insert("none");
			}
			continue;            //��Ϊ���ڿմ��ߣ���Ҫ�������±���
		}
		else {
			break;               //����Ͳ������������ˣ�������һ��ѭ��
		}

	}
	return fset;
}

set<string> NonTerminator::calFirstSet(set<string> called_stack) {
	// call_stack����ŵ���˳���һ�����ϣ�������ֹ���ֻ�·���������޵ݹ�
	while (true) {
		bool need_loop = false;
		int original_size = this->firstSet.size();
		for (auto p_iter = productions.begin(); p_iter != productions.end(); p_iter++) {
			//���ѭ����������ʽ
			for (auto n_iter = (*p_iter).begin(); n_iter != (*p_iter).end(); n_iter++) {
				//�ڲ�ѭ����������ʽ�Ľڵ�
				// ����һ���ڵ���û�г����� ����ջ��
				if (called_stack.find((*n_iter)->get_node_name()) == called_stack.end()) {
					//�����ڻ�·�ŵݹ���� ���� first����,������ǰ�ڵ��first������, ������ڻ�·��������
					set<string> newCalled_stack = called_stack;
					newCalled_stack.insert(node_name);
					set<string> subfirstSet = set<string>();
					if ((*n_iter)->get_calAgain() == false) {
						subfirstSet = (*n_iter)->get_firstSet();
					}
					else {
						subfirstSet = (*n_iter)->calFirstSet(newCalled_stack);//�ݹ�������е�node������Ƿ��ս���᷵��ֻ����ָ���Լ���ָ���vector���ݹ����
					}
					this->firstSet.insert(subfirstSet.begin(), subfirstSet.end());
				}
				else {
					//������ڻ�·��Ҫ����һ��
					need_loop = true;
				}
				if (this->firstSet.erase("none")>0) {    //����������� �մ��ķ��ս����ע��erase�����Ѿ��ѿմ��Ƴ���
					if (n_iter + 1 == (*p_iter).end()) {
						//����Ѿ����������һ���ڵ㣬���Ҵ��ڿմ��ߣ�ǰ��ÿһ�������ڿմ��ߣ�,����մ���
						this->firstSet.insert("none");
					}
					continue;            //��Ϊ���ڿմ��ߣ���Ҫ�������±���
				}
				else {
					break;               //����Ͳ������������ˣ�������һ��ѭ��
				}

			}
			
		}
		// ������ , ����û���ڵݹ���������֮����������
		if (called_stack.find(node_name) == called_stack.end()) {
			this->calAgain = false;
		}
		if (this->firstSet.size() == original_size || need_loop == false) {
			break;    //ֻ�в��������˲�����ȥ
		}
	}
	return this->firstSet;
	
}
