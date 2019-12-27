#include "LR1Parser.h"



LR1Parser::LR1Parser(set<string>ts, set<string> ns, vector<vector<string>> ps, string begin , string end, string none )
	:BottomUpParser(ts,ns,ps,begin,end,none)
{
}


LR1Parser::~LR1Parser()
{
}

void LR1Parser:: initStates(vector<std::pair<string, int>> productions, vector<set<string>> followset) {
	states.clear();
	LR1State state0 = LR1State(0);
	for (int i = 0; i<int(productions.size()); i++) {
		ProductionStack p = pm.generateProductionStack(productions[i].first, productions[i].second);
		p.set_followSet(followset[i]);
		state0.addProductionAsMerge(p);
	}
	states.insert(state0);
}
unordered_map<string, LR1State> LR1Parser::calNextStates( LR1State& s)
{
	unordered_map<string, LR1State> outputs = unordered_map<string, LR1State>();
	//�����״̬���п��ܲ�����״̬
	set<ProductionStack> productions = s.get_productions();   //��ȡ����ʽ
	for (auto p_iter = productions.begin(); p_iter != productions.end(); p_iter++) {
		//�������в���ʽ
		ProductionStack p = *p_iter;     
		int stack_id = p.get_stackState();
		Node* currentNode = p.get_head()->getNodeInProduction(p.get_production_id(), stack_id);
		if (currentNode == nullptr) {
			continue;       //���С�������ұ���...
		}
		if (currentNode->get_node_name() == end || currentNode->get_node_name() == none) {
			continue;
		}
		string edge = currentNode->get_node_name();
		auto state_iter = outputs.find(edge);  //���ҿ���û���Ѿ������״̬��
		if (state_iter == outputs.end()) {
			//���û�У�����һ��state
			LR1State outputState = LR1State(-2);    //-2��ʾ״̬δ��ʼ��
			p.set_stackState(stack_id + 1);        //���¶�ջ״̬
			p.set_isProcess(false);               //���ô���״̬
			outputState.addProductionAsMerge(p);  //���ӱ��ʽ
			outputs.insert({ edge,outputState });
		}
		else {
			//����Ѿ������״̬���ͰѲ���ʽ�ӽ�ȥ
			p.set_stackState(stack_id + 1);        //���¶�ջ״̬
			p.set_isProcess(false);               //���ô���״̬
			(*state_iter).second.addProductionAsMerge(p);  //������ʽ
		}

	}
	for (auto iter = outputs.begin(); iter != outputs.end(); iter++) {
		(*iter).second.stateGrow(pm);    //���б��ʽ���Ƶ�
	}
	return outputs;
}
void LR1Parser::buildParserGraph() {
	//����״̬ͼ
	if (states.size() != 1) {
		//�ӳ�ʼ״̬��ʼ���죬�����1 ��ʼ
		cout << "��ʼ״̬������!!" << endl;
		return;
	}
	//�Ȼ�������ĳ�ʼ״̬,����setֻ��һ����ʼ״̬,ֱ��ǿת�����ò���
	LR1State& state0 = const_cast<LR1State&>(*states.begin());
	state0.stateGrow(pm);   
	int stateID = 1;                //��1��ʼ���state ��Ϊstate0 �Ѿ�����
	while (true) {
		bool isAgain = false;
		for (auto s_iter = states.begin(); s_iter != states.end(); s_iter++) {
			LR1State& currentS = const_cast<LR1State&>(*s_iter);   //ʹ��ǿת������ֻ�ı�process��nextedge�����Բ���Ҫ��ɾ���ټ��룬isProcess��Ӱ�켯������ע��
			if ((*s_iter).get_isProcess() == false) {
				//����Ǵ�������
				isAgain = true;
			}
			else {
				continue;    //��������
			}
			// ���ø�״̬�Ѳ鿴
			currentS.set_isProcess(true);
			// �����״̬���ܵĲ�����״̬
			unordered_map<string, LR1State> generatedStates =
				calNextStates(currentS);
			for (auto iter = generatedStates.begin(); iter != generatedStates.end(); iter++) {
				if (states.find((*iter).second) == states.end() ) {
					//����²�����״̬��ԭ����״̬��û�У�������״̬
					(*iter).second.set_stateID(stateID);   //����״̬���
					stateID++;
					states.insert((*iter).second);         //����״̬
					auto next_iter = states.find((*iter).second);  //�Ȳ��룬������
					ParserState& next_state = const_cast<LR1State& >(*next_iter);  //������ָ��ǿתΪ����ָ��
					currentS.addNextState((*iter).first, &next_state);

				}
				else {
					//���ԭ��״̬�� �ӱ�
					auto next_iter = states.find((*iter).second);
					ParserState& next_state = const_cast<LR1State&>(*next_iter);  //������ָ��ǿתΪ����ָ��
					currentS.addNextState((*iter).first, &next_state);
				}
			}
		}
		if (isAgain == false) {
			break;
		}
	}
 }
void LR1Parser::printStates()const {
	for (auto iter = states.begin(); iter != states.end(); iter++) {
		(*iter).printState();
		cout << endl;
	}
}
void LR1Parser::outParserModel(ofstream& fout) {
	fout << "###############����ʽ#################" << endl;
	outProductionsAsFile(fout);
	fout << endl;
	fout << "###############״̬ͼ#################" << endl;
	outputStatesAsfile(fout);
	fout << endl;
	fout << "###############������#################" << endl;
	outPaserTableAsFile(fout,8,1);
}
void LR1Parser::outputStatesAsfile(ofstream& fout)const {
	for (auto iter = states.begin(); iter != states.end(); iter++) {
		(*iter).outputStateAsFile(fout);
		fout << endl;
	}
 }
void LR1Parser::buildParserTable() {
	//�������е� states����LR1������
	parserTable = vector<vector<vector<std::pair<string, int>>>>(states.size());
	for (auto s_iter = states.begin(); s_iter != states.end(); s_iter++) {
		//�������е�״̬
		vector<vector<pair<string, int>>> stateline = vector<vector<pair<string, int>>>(tableItems_map.size());  //�½�һ�У�һ��״̬��һ��
		set<ProductionStack> productions = (*s_iter).get_productions();
		//�������в���ʽ������û�й�Լ��
		for (auto p_iter = productions.begin(); p_iter != productions.end(); p_iter++) {
			if ((*p_iter).get_stackState() == (*p_iter).getProductionSize())
			{
				//���С�������ұ��ˣ�����follow�������еĹ�Լʽ;
				set<string> followset = (*p_iter).get_followSet();
				for (auto p_iter1 = followset.begin(); p_iter1 != followset.end(); p_iter1++) {
					auto j_iter = tableItems_map.find(*p_iter1);
					if (j_iter != tableItems_map.end()) {    //�������none
						int production_id = (*production_base_id.find(p_iter->get_head()->get_node_name())).second
							+ p_iter->get_production_id();
						stateline[(*j_iter).second] .push_back( make_pair("R", production_id));   //R�ǹ�Լʽ
					}
				}
			}
		}
		//��������״̬���ıߣ�����û�в�����
		const unordered_map<string, ParserState*>& nextStates = s_iter->getNextStates();
		for (auto ns_iter = nextStates.begin(); ns_iter != nextStates.end(); ns_iter++) {
			// �������е���һ��״̬
			auto j_iter = tableItems_map.find(ns_iter->first);   //��һ��������ַ���Ӧ������
			stateline[j_iter->second] .push_back( make_pair("S", ns_iter->second->get_stateID()));  //S�ǲ���ʽ
		}
		// �����һ��״̬�µı�Ĺ���
		parserTable[s_iter->get_stateID()] = stateline;
	}
}


