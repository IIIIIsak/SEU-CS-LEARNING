#include "BottomUpParser.h"

BottomUpParser::BottomUpParser(set<string>ts, set<string> ns, vector<vector<string>> ps, string begin , string end , string none )
	:terminators(ts),nonTerminators(ns), string_productions(ps),begin(begin),end(end),none(none)
{
	//����ֱ�ӳ�ʼ��һ�� pm ��,��������Ҫ�����нڵ�
	pm = ProductionManager();
	int j_id = 0;
	for (auto iter = ts.begin(); iter != ts.end(); iter++) {
		Terminator t = Terminator(*iter);  //�ս��
		pm.addTerminator(*iter,t);        //��ֵ����
		if (t.get_node_name() != none) {
			tableItems_map.insert({ t.get_node_name(),j_id });
			tableItems.push_back(t.get_node_name());
			j_id++;
		}
	}
	for (auto iter = ns.begin(); iter != ns.end(); iter++) {
		NonTerminator nt = NonTerminator(*iter);  //���ɷ��ս��
		pm.addNonTerminator(*iter, nt);        //��ֵ����
		tableItems_map.insert({ nt.get_node_name(),j_id });
		tableItems.push_back(nt.get_node_name());
		j_id++;
	}
	for (auto iter = ps.begin(); iter != ps.end(); iter++) {
		string n = (*iter)[0];
		(*iter).erase((*iter).begin());      //�Ƴ���һ��Ԫ�أ� ��һ���� ����ʽ��ͷ
		pm.addProduction(n, (*iter));
	}
	int base = 0;
	for (auto iter = ns.begin(); iter != ns.end(); iter++) {
		// ��ÿһ�����ս��ӳ��һ������ַ��int ),Ϊ�˽�ÿһ������ʽ��һ��int ��Ӧ�������еĲ���ʽ���б�š��������Լ
		production_base_id.insert({(*iter), base});
		base += pm.getProductionsNum(*iter);
		// ��ÿ�����ս��ӳ��Ϊһ����ַ��Χ��int)
		for (int i = 0; i < pm.getProductionsNum(*iter); i++) {
			this->production_base_head.push_back(*iter);
		}
	}
	pm.calAllFirstSet(begin);
}

vector<pair<string, int>>  BottomUpParser::getOperations(int state, string input)const {
	vector<pair<string, int>> operations = vector<pair<string, int>>();
	if (state < 0 || state >= parserTable.size()) {
		//���״̬����
		return operations;
	}
	auto i_iter = this->tableItems_map.find(input);
	if (i_iter == tableItems_map.end()) {
		// ���������ַ����ڷ�������
		return operations;
	}
	int input_id = i_iter->second;
	return parserTable[state][input_id];
}

Production BottomUpParser::getProductionById(int p_id) {
	string head = this->production_base_head[p_id];
	int production_id = p_id - (*production_base_id.find(head)).second;
	return pm.generateProduction(head, production_id);
}
void BottomUpParser::printPaserTable(const int width, const int height)const {
	// ��ӡ��ͷ
	cout << setw(width)<<" "; 
	for (auto iter = tableItems.begin(); iter != tableItems.end(); iter++) {
		if (*iter == begin)    //�۳��ķ���ʼ����
			continue;
		cout << setiosflags(ios::right) << setw(width) << *iter;
	}
	for (int i = 0; i < height; i++) {
		cout << endl;
	}
	// ��ӡ�������
	//vector<vector<std::pair<string,int>>>
	for (int i = 0; i < parserTable.size(); i++) {
		cout << setw(width) << i;   //״̬��
		vector<vector<pair<string, int>>>  stateline = parserTable[i];
		int maxline = 1;
		// �ҵ���Ҫ���������
		for (int j = 0; j < stateline.size(); j++) {
			if (this->tableItems[j] == begin)
				continue;
			if (stateline[j].size() > maxline) {
				maxline = stateline[j].size();
			}
		}
		for (int line = 0; line < maxline; line++) {
			//�������
			if (line > 0) {
				cout << setw(width) << "";
			}
			for (int j = 0; j < stateline.size(); j++) {
				if (this->tableItems[j] == begin)    //�۳��ķ���ʼ����
					continue;
				if (line >= stateline[j].size()) {
					cout << setw(width) << "";
				}
				else {
					cout << setw(width) << stateline[j][line].first + to_string(stateline[j][line].second);
				}			
			}
			cout << endl;
		}
		maxline = 0;
		// ����
		for (int i = 0; i < height-1; i++) {
			cout << endl;
		}
	}
}

void  BottomUpParser::outPaserTableAsFile(ofstream& fout, const int width , const int height )const {
	// ��ӡ��ͷ
	fout << setw(width) << " ";
	for (auto iter = tableItems.begin(); iter != tableItems.end(); iter++) {
		if (*iter == begin)    //�۳��ķ���ʼ����
			continue;
		fout << setiosflags(ios::right) << setw(width) << *iter;
	}
	for (int i = 0; i < height; i++) {
		fout << endl;
	}
	// ��ӡ�������
	//vector<vector<std::pair<string,int>>>
	for (int i = 0; i < parserTable.size(); i++) {
		fout << setw(width) << i;   //״̬��
		vector<vector<pair<string, int>>>  stateline = parserTable[i];
		int maxline = 1;
		// �ҵ���Ҫ���������
		for (int j = 0; j < stateline.size(); j++) {
			if (this->tableItems[j] == begin)
				continue;
			if (stateline[j].size() > maxline) {
				maxline = stateline[j].size();
			}
		}
		for (int line = 0; line < maxline; line++) {
			//�������
			if (line > 0) {
				fout << setw(width) << "";
			}
			for (int j = 0; j < stateline.size(); j++) {
				if (this->tableItems[j] == begin)    //�۳��ķ���ʼ����
					continue;
				if (line >= stateline[j].size()) {
					fout << setw(width) << "";
				}
				else {
					fout << setw(width) << stateline[j][line].first + to_string(stateline[j][line].second);
				}
			}
			fout << endl;
		}
		maxline = 0;
		// ����
		for (int i = 0; i < height - 1; i++) {
			fout << endl;
		}
	}
}
void BottomUpParser::printStack(vector<int> state_stack, vector<string> string_stack, vector<token> input, int begin) {
	cout << "state stack: { ";
	if (state_stack.size ()> 0) {
		cout << state_stack[0];
	}
	for (int i = 1; i < state_stack.size(); i++) {
		cout <<","<< state_stack[i];
	}
	cout << " }";
	cout << endl;
	cout << "state stack: { ";
	if (string_stack.size()> 0) {
		cout << string_stack[0];
	}
	for (int i = 1; i < string_stack.size(); i++) {
		cout << "," << string_stack[i];
	}
	cout << " }";
	cout << endl;
	cout << "input token:";
	if (begin < input.size()) {
		cout << input[begin];
	}
	for (int i = begin + 1; i <input.size(); i++) {
		cout << "," << input[i];
	}
 }

void BottomUpParser::outputStackAsFile(ofstream& fout, vector<int> state_stack, vector<string> string_stack, vector<token> input, int begin) {
	fout << "state stack: { ";
	if (state_stack.size() > 0) {
		fout << state_stack[0];
	}
	for (int i = 1; i < state_stack.size(); i++) {
		fout << "," << state_stack[i];
	}
	fout << " }";
	fout << endl;
	fout << "string stack: { ";
	if (string_stack.size() > 0) {
		fout << string_stack[0];
	}
	for (int i = 1; i < string_stack.size(); i++) {
		fout << "," << string_stack[i];
	}
	fout << " }";
	fout << endl;
	fout << "input token: ";
	if (begin < input.size()) {
		fout << input[begin];
	}
	for (int i = begin + 1; i < input.size(); i++) {
		fout << "," << input[i];
	}
 }
 void BottomUpParser::outProductionsAsFile(ofstream& fout) {
	 int productionNum = 0;
	 for (auto iter = nonTerminators.begin(); iter != nonTerminators.end(); iter++) {
		 productionNum +=  pm.getProductionsNum(*iter);
	}
	 for (int i = 0; i < productionNum; i++) {
		 fout << "(" << i << ") ";
		 getProductionById(i).outputProductionAsFile(fout);
		 fout << endl;
	 }
}
 void  BottomUpParser::sloveAmbiguousTable(vector< pair<int, pair<string, int>>> deleteOperations) {
	 for (int i = 0; i < deleteOperations.size(); i++) {
		 pair<int, pair<string, int>> deleteOperation = deleteOperations[i];
		 int state_id = deleteOperation.first;
		 string input = deleteOperation.second.first;
		 int delete_id = deleteOperation.second.second;
		 auto input_iter = tableItems_map.find(input);
		 if (input_iter == tableItems_map.end()) {
			 continue;
		 }
		 int input_id = input_iter->second;
		 if (delete_id >= parserTable[state_id][input_id].size()) {
			 continue;
		 }
		 else {
			 parserTable[state_id][input_id].erase(parserTable[state_id][input_id].begin() + delete_id);
		 }
		}
}
bool BottomUpParser::scanTokenStream(vector<token> tokenstream, string analyze_report_dir) {
	/*
	tokenstream : token��
	analyze_report_dir : �﷨��������·���� ���ɶ�ջ�Ƶ�˳���﷨��
	analysis_model_dir: �﷨����ģ��·�������ɷ����﷨���õ�״̬ͼ�� ������
	*/
	ofstream fout1 = ofstream();
	fout1.open(analyze_report_dir, ios::out);
	if (!fout1.is_open()) {
		cout << "�޷��򿪱������ı�" << endl;
		return false;
	}
	vector<int> state_stack = vector<int>();     //״̬ջ
	vector<string> string_stack = vector<string>(); //����ջ
	vector<treeNode> tree_stack = vector<treeNode>();  //�﷨���ڵ�ջ�����������﷨��
	vector<int> tree_poses = vector<int>();  // ���������﷨��
	SyntaxTree tree = SyntaxTree();   //�﷨��
	// ����ջ����tokenstream;
	state_stack.push_back(0);   //��ʼ״̬Ϊ0
	string_stack.push_back(end);  //���� ��ֹ��
	tokenstream.push_back(token(-1, end, "_"));    //��token����ĩβ�����ս���� token�� ID�� -1 ��ֹ������token��ͻ
	int step = 0;
	fout1 << "---------------------step" << step << "---------------------------" << endl;
	outputStackAsFile(fout1, state_stack, string_stack, tokenstream, step);    //�����ջ״̬
	fout1 << endl;
	int input_pos = 0;
	for (auto t_iter = tokenstream.begin(); t_iter != tokenstream.end(); t_iter++) {
		int iter_shift = 0;                    //��Ϊ������ goto���ַ�������Ҫ���Ƶ���������������
		// ���������token��
		string input = t_iter->get_token_name();   //�������
checkAgain:	int state = state_stack.back();     // ȡ״̬ջ��ǰ״̬
		vector<pair<string, int>> operations = getOperations(state, input);
		if (operations.size() == 0) {
			//���ɶ��û�У����﷨����, ͬʱ��ӡ��ǰ�Ķ�ջ״̬
			cout << "Syntax error! can not generate Syntax tree";
			printStack(state_stack, string_stack, tokenstream, step);
			cout << endl;
			fout1 << "Syntax error! can not generate Syntax tree";
			outputStackAsFile(fout1,state_stack, string_stack, tokenstream, step);
			fout1 << "#############Syntax tree############" << endl;
			tree.outputTreeAsFile(fout1);
			fout1 << endl;
			fout1.close();
			return false;
		}
		else if (operations.size() > 1) {
			// �������ͬʱ������ �� ֤�����������ڶ�����
			cout << "Ambiguous parser table! check your parser table and your grammer!"<<endl;
			fout1 << "Ambiguous parser table! check your parser table and your grammer!" << endl;
			fout1 << "#############Syntax tree############" << endl;
			tree.outputTreeAsFile(fout1);
			fout1.close();
			return false;
		}
		else {
			pair<string, int > operation = operations[0];
			//����ɹ��ҵ���������ֻ��һ��
			if (operation.first == "S") {
				//����ǲ���ʽ
				state_stack.push_back(operation.second);       //������״̬
				string_stack.push_back(input);                     //����ջ�����µķ���
				if (iter_shift == 0) {
					// ��ǰ��input���� ����ջ�ڵ�ǰ�Ľڵ�
					treeNode t_n = treeNode(*t_iter);
					while (tree_poses.size() > 0) {
						t_n.child_ptrs.push_back(tree_poses.back());    // ���ø��ڵ�ĺ���ָ�룬 ���ڵ��ǲ���ʽ�����
						tree_poses.pop_back();
					}
					tree_stack.push_back(t_n);
				}
				else {
					token t = token(-1, input, "_");
					treeNode t_n = treeNode(t);
					while (tree_poses.size() > 0) {
						t_n.child_ptrs.push_back(tree_poses.back());    // ���ø��ڵ�ĺ���ָ�룬 ���ڵ��ǲ���ʽ�����
						tree_poses.pop_back();
					}
					tree_stack.push_back(t_n);
				}
				tree_poses.clear();                    //��ն�ջ
				t_iter += iter_shift;
				input_pos+= iter_shift;
				iter_shift = 0;
				step++;
				input_pos++;
				fout1 << "---------------------step" << step << "---------------------------" << endl;
				outputStackAsFile(fout1, state_stack, string_stack, tokenstream, input_pos);    //�����ջ״̬
				fout1 << endl;
				
			}
			else if (operation.first == "R") {
				//����ǹ�Լʽ
				Production p = getProductionById(operation.second);   // ���� id �õ� ��Ӧ�Ĳ���ʽ
				step++;
				fout1 << "---------------------step" << step << "---------------------------" << endl;
				outputStackAsFile(fout1, state_stack, string_stack, tokenstream, input_pos);    //�����ջ״̬
				fout1 << "\nR" << operation.second << ": ";
				p.outputProductionAsFile(fout1);
				fout1 << endl;
				//������ջ�ڵ� ����ʽp�ұߵķ����� ����ʽ��head���棬eg S -> ab ; �� ab ��S����
				//������ʽ�ұߵķ�������
				for (int i = 0; i < p.getProductionSize();i++) {
					string_stack.pop_back();   
					state_stack.pop_back();                  //����״̬;
					tree_poses.push_back(tree.addNode(tree_stack.back()));
					tree_stack.pop_back();
				}
				input = p.get_head()->get_node_name();   //��ǰ���������� ����ʽ p��head�� 
				if (input == begin ) {
					// �����Լ�õ��ķ���ʼ����,��Լ�ɹ�����������
					token t = token(-1, input, "_");          //��S1�����﷨��
					treeNode t_n = treeNode(t);
					while (tree_poses.size() > 0) {
						t_n.child_ptrs.push_back(tree_poses.back());    // ���ø��ڵ�ĺ���ָ�룬 ���ڵ��ǲ���ʽ�����
						tree_poses.pop_back();
					}
					tree.addNode(t_n);
					fout1 << "sucess!" << endl;
					fout1 << "#############Syntax tree############" << endl;
					tree.outputTreeAsFile(fout1);
					fout1.close();
					return true;       
				}
				if (iter_shift == 0) {
					iter_shift--;        
				} 
				// ������Ź�Լ
			
				goto checkAgain;                    // ��p ����ʽ�� head��Ϊ�����ַ��ظ������жϣ� ��������ת
			}
			else {
				cout << "There are something wrong with parser table" << endl;
				fout1 << "There are something wrong with parser table" << endl;
				fout1 << "#############Syntax tree############" << endl;
				tree.outputTreeAsFile(fout1);
				fout1.close();
				return false;
			}
			
		}
		
	}
	if (state_stack.size() > 1 || string_stack.size() > 1) {
		//������ж������ˣ�ջ�ڻ������ݣ�����false��
		cout << "Syntax error! can not generate Syntax tree";
		printStack(state_stack, string_stack, tokenstream, tokenstream.size() - 1);
		cout << endl;
		fout1 << "Syntax error! can not generate Syntax tree";
		outputStackAsFile(fout1, state_stack, string_stack, tokenstream, step);
		fout1 << endl;
		fout1.close();
		return false;
	}
}
BottomUpParser::~BottomUpParser()
{
}
