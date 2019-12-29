#include"Node.h"
#include"LR1Parser.h"
#include"DFA.h"

//################################�ʷ�����������Ҫ�Ķ��⺯�� #################################
string s5edgeJudge(string s) {
	if (s != "\"" || s == "digit" || s == "letter") {
		return "chars1";
	}
	else {
		return s;
	}
}
string s7edgeJudge(string s) {
	if (s != "'" || s == "digit" || s == "letter") {
		return "chars2";
	}
	else {
		return s;
	}
}
string convertInput(char c) {
	if (isdigit(c)) {
		return string("digit");
	}
	else if (isalnum(c)) {
		return string("letter");
	}
	else {
		return string(1, c);
	}
}
int main() {
	const string inputfile = "D:\\input.txt";
	const string reportfile = "D:\\report.txt";
	const string modelfile = "D:\\model.txt";
	const string tokenfile = "D:\\token.txt";
	vector<token> tokenstream = vector<token>();
	//####################################### �ʷ�����ģ�� #######################################################//
	//����״̬��
	int stateNum = 10; // ��10��״̬
	string edges[] = { "_", "letter","digit",".", "\"","chars1","'","chars2" }; //chars1������ˡ�֮����ַ���chars2 ������ˡ�֮����ַ�
	//����һ��2ά����,��ʼ��Ϊ-1
	vector<int>** stateM = new vector<int>*[stateNum];
	for (int i = 0; i < stateNum; i++) {
		stateM[i] = new vector<int>[stateNum];
		for (int j = 0; j < stateNum; j++) {
			stateM[i][j] = vector<int>();
		}
	}
	stateM[0][1] = vector<int>({ 0,1 });
	stateM[1][1] = vector<int>({ 0,1,2 });
	stateM[0][2] = vector<int>({ 2 });
	stateM[2][2] = vector<int>({ 2 });
	stateM[2][3] = vector<int>({ 3 });
	stateM[3][4] = vector<int>({ 2 });
	stateM[4][4] = vector<int>({ 2 });
	stateM[0][5] = vector<int>({ 4 });
	stateM[5][5] = vector<int>({ 5 });
	stateM[5][6] = vector<int>({ 4 });
	stateM[0][7] = vector<int>({ 6 });
	stateM[7][8] = vector<int>({ 7 });
	stateM[8][9] = vector<int>({ 6 });
	DFA myDFA = DFA();                     //��ֹ���ǿո�
	myDFA.initStates(stateNum, stateM, edges);
	// ������ֹ״̬
	myDFA.addTokenItem(1, 0, "id"); // 1״̬����̬ �� id(������
	myDFA.addTokenItem(2, 1, "num"); //2 ״̬��̬ �� ����
	myDFA.addTokenItem(4, 2, "num"); //4 ״̬��̬ �� ����
	myDFA.addTokenItem(6, 3, "string"); //6 ״̬ ���ַ���
	myDFA.addTokenItem(9, 4, "char"); //9 ״̬ ���ַ�
	//���ӱ�����
	vector<string> keepWords= vector<string>({ "if","else","while","do","(",")","+","-","*","/", ";" ,"=","and","or","not",">","<",">=","<","==","!=" ,"true","false"
											 "id","num","then","{" ,"}" });
	for (int i = 0; i < keepWords.size(); i++) {
		myDFA.addKeepWord(keepWords[i], 5 + i);
	}
	// ���ӱ��жϺ���
	myDFA.getState(7).setEdgeJudgeFunction(s7edgeJudge);
	myDFA.getState(5).setEdgeJudgeFunction(s5edgeJudge);
	
	//######################### ɨ���ļ�ģ��
	ifstream fin = ifstream();
	fin.open("D:\\input.txt", ios::in);
	if (!fin.is_open()) {
		cout << "�޷����ļ���" << endl;
		return 0;
	}
	ofstream fout = ofstream();
	fout.open(tokenfile, ios::out);
	if (!fout.is_open()) {
		cout << "�޷����ļ���" << endl;
		return 0;
	}
	string str;
	char c;
	bool isIgnore = false;
	while (fin.get(c)) {
		if ((c == ' ' || c == '\n' || c == '\t') && isIgnore == false) {
			if (str == "") {
				continue;
			}
			token t = myDFA.scan(str, convertInput);
			tokenstream.push_back(t);
			fout << t << endl;
			str.clear();
			continue;
		}
		else {
			if (c == '\"') {
				if (isIgnore == false) {
					isIgnore = true;
				}
				else {
					isIgnore = false;
				}
			}
			str += c;
		}
	};
	if (str != "") {
		token t = myDFA.scan(str, convertInput);
		tokenstream.push_back(t);
		fout << t << endl;
	}
	fin.close();
	//delete����
	for (int i = 0; i < stateNum; i++) {
		if (stateM[i] != nullptr) {
			delete[] stateM[i];
		}
	}
	delete[] stateM;

	//########################################�﷨����ģ��####################################################
	// ������ʽ�����ʽ������ķ�ͬ �ʷ������� , �ӱ��ʽ����״̬��

	set<string> nonTerminators = set<string>({ "S1","S","E","EA","EO","rop","C","T","WD","I" });
	set<string> terminators = set<string>({ "if","else","while","do","(",")","+","-","*","/", ";" ,"=","and","or","not",">","<",">=","<=","<","==","!=" ,"true","false",
											 "id","num","then","$","none","{","}" });
	vector < vector<string>> productions = vector < vector<string>>();
	productions.push_back(vector<string>({ "S1","S" }));
	productions.push_back(vector<string>({ "S","id","=","E" ,";"}));
	productions.push_back(vector<string>({ "S","S","S" }));
	productions.push_back(vector<string>({ "S","T","{","S","}" }));
	productions.push_back(vector<string>({ "S","C","{","S","}" }));
	productions.push_back(vector<string>({ "T","C","{","S","}","else" }));
	productions.push_back(vector<string>({ "C","if","(","E",")","then" }));
	productions.push_back(vector<string>({ "S","WD","{","S","}" }));
	productions.push_back(vector<string>({ "WD","while","(","E",")" ,"do"}));
	productions.push_back(vector<string>({ "E","EA","E" }));
	productions.push_back(vector<string>({ "E","EO","E" }));
	productions.push_back(vector<string>({ "E","not","E" }));
	productions.push_back(vector<string>({ "E","(","E",")" }));
	productions.push_back(vector<string>({ "E","E","rop","E" }));
	productions.push_back(vector<string>({ "EA","E","and" }));
	productions.push_back(vector<string>({ "EO","E","or" }));
	productions.push_back(vector<string>({ "E","id" }));
	productions.push_back(vector<string>({ "E","true" }));
	productions.push_back(vector<string>({ "E","false" }));
	productions.push_back(vector<string>({ "E","num" }));
	productions.push_back(vector<string>({ "rop",">" }));
	productions.push_back(vector<string>({ "rop",">=" }));
	productions.push_back(vector<string>({ "rop","<" }));
	productions.push_back(vector<string>({ "rop","<=" }));
	productions.push_back(vector<string>({ "rop","==" }));
	productions.push_back(vector<string>({ "rop","!=" }));
	productions.push_back(vector<string>({ "E","E" ,"+","E"}));
	productions.push_back(vector<string>({ "E","E" ,"-","E" }));
	productions.push_back(vector<string>({ "E","E" ,"*","E" }));
	productions.push_back(vector<string>({ "E","E" ,"/","E" }));

	LR1Parser myParser = LR1Parser(terminators, nonTerminators, productions);

	/*
	//#########################small demo ##################################
	set<string> terminators = set<string>({"none","$","a","b","c","d"});
	set<string> nonTerminators = set<string>({ "S1","S","A","B"});
	vector < vector<string>> productions = vector < vector<string>>();
	productions.push_back(vector<string>({ "S1","S" }));
	productions.push_back(vector<string>({ "S","A","a" }));
	productions.push_back(vector<string>({ "S","b","A","c" }));
	productions.push_back(vector<string>({ "S","B","c" }));
	productions.push_back(vector<string>({ "S","b","B","a" }));
	productions.push_back(vector<string>({ "S","S","S" }));
	productions.push_back(vector<string>({ "S","none" }));
	productions.push_back(vector<string>({ "A","d" }));
	productions.push_back(vector<string>({ "B","d" }));
	LR1Parser myParser = LR1Parser(terminators, nonTerminators, productions);
	*/
	//���ó�ʼ״̬
	std::pair<string, int> p1 = make_pair("S1", 0);
	vector<std::pair<string, int>> ps = vector<std::pair<string, int>>();
	ps.push_back(p1);
	vector<set<string>> followset = vector<set<string>>({ set<string>{"$"} });
	myParser.initStates(ps, followset);
	myParser.buildParserGraph();
	myParser.buildParserTable();
	// �������������
	

	vector < pair<int, pair<string, int>> >deleteOperations = vector < pair<int, pair<string, int>>>();
	deleteOperations.push_back(make_pair(48, make_pair("id", 1)));  // 83״̬�¶���ֺ� ��ɾ������ʽ
	deleteOperations.push_back(make_pair(47, make_pair("id", 1)));  // 84״̬�¶���ֺ� ��ɾ������ʽ
	deleteOperations.push_back(make_pair(79, make_pair("id", 1)));  // 84״̬�¶���ֺ� ��ɾ������ʽ
	deleteOperations.push_back(make_pair(48, make_pair("if", 1)));  // 83״̬�¶���ֺ� ��ɾ������ʽ
	deleteOperations.push_back(make_pair(47, make_pair("if", 1)));  // 84״̬�¶���ֺ� ��ɾ������ʽ
	deleteOperations.push_back(make_pair(79, make_pair("if", 1)));  // 84״̬�¶���ֺ� ��ɾ������ʽ
	deleteOperations.push_back(make_pair(48, make_pair("while", 1)));  // 83״̬�¶���ֺ� ��ɾ������ʽ
	deleteOperations.push_back(make_pair(47, make_pair("while", 1)));  // 84״̬�¶���ֺ� ��ɾ������ʽ
	deleteOperations.push_back(make_pair(79, make_pair("while", 1)));  // 83״̬�¶���ֺ� ��ɾ������ʽ
	//������ȼ��ͽ���Դ����Ĵ�ͼ
	deleteOperations.push_back(make_pair(33, make_pair("!=", 0)));   //33 ״̬ S - > EA E  �����ȼ���and�߱�������ʽ�� ���ȼ� <= and ������Լʽ
	deleteOperations.push_back(make_pair(33, make_pair("+", 0)));    //���ϱ�����Լʽ
	deleteOperations.push_back(make_pair(33, make_pair("-", 0)));
	deleteOperations.push_back(make_pair(33, make_pair("*", 0)));
	deleteOperations.push_back(make_pair(33, make_pair("/", 0)));
	deleteOperations.push_back(make_pair(33, make_pair("<", 0)));
	deleteOperations.push_back(make_pair(33, make_pair("<=", 0)));
	deleteOperations.push_back(make_pair(33, make_pair("==", 0)));
	deleteOperations.push_back(make_pair(33, make_pair(">", 0)));
	deleteOperations.push_back(make_pair(33, make_pair(">=", 0)));
	deleteOperations.push_back(make_pair(33, make_pair("and", 1)));
	deleteOperations.push_back(make_pair(33, make_pair("or", 1)));
	deleteOperations.push_back(make_pair(34, make_pair("!=", 0)));   //34 ״̬ S - > E0 E  �����ȼ���or�߱�������ʽ(0)�� ���ȼ� <= or ������Լʽ(1)
	deleteOperations.push_back(make_pair(34, make_pair("+", 0)));    //���ϱ�����Լʽ
	deleteOperations.push_back(make_pair(34, make_pair("-", 0)));
	deleteOperations.push_back(make_pair(34, make_pair("*", 0)));
	deleteOperations.push_back(make_pair(34, make_pair("/", 0)));
	deleteOperations.push_back(make_pair(34, make_pair("<", 0)));
	deleteOperations.push_back(make_pair(34, make_pair("<=", 0)));
	deleteOperations.push_back(make_pair(34, make_pair("==", 0)));
	deleteOperations.push_back(make_pair(34, make_pair(">", 0)));
	deleteOperations.push_back(make_pair(34, make_pair(">=", 0)));
	deleteOperations.push_back(make_pair(34, make_pair("and", 0)));
	deleteOperations.push_back(make_pair(34, make_pair("or", 1)));
	deleteOperations.push_back(make_pair(35, make_pair("!=", 1)));   //35 ״̬ S - > not E  �����ȼ���not�߱�������ʽ(0)�� ���ȼ� <= not ������Լʽ(1)
	deleteOperations.push_back(make_pair(35, make_pair("+", 1)));    //���ϱ�����Լʽ  
	deleteOperations.push_back(make_pair(35, make_pair("-", 1)));
	deleteOperations.push_back(make_pair(35, make_pair("*", 1)));
	deleteOperations.push_back(make_pair(35, make_pair("/", 1)));
	deleteOperations.push_back(make_pair(35, make_pair("<", 1)));
	deleteOperations.push_back(make_pair(35, make_pair("<=", 1)));
	deleteOperations.push_back(make_pair(35, make_pair("==", 1)));
	deleteOperations.push_back(make_pair(35, make_pair(">", 1)));
	deleteOperations.push_back(make_pair(35, make_pair(">=", 1)));
	deleteOperations.push_back(make_pair(35, make_pair("and", 1)));
	deleteOperations.push_back(make_pair(35, make_pair("or", 1)));
	deleteOperations.push_back(make_pair(37, make_pair("!=", 1)));   //37 ״̬ S - > E rop E  (rop��> < >= <=, ==, !=) �����ȼ���not�߱�������ʽ(0)�� ���ȼ� <= not ������Լʽ(1)
	deleteOperations.push_back(make_pair(37, make_pair("+", 0)));    //���ϱ�����Լʽ  
	deleteOperations.push_back(make_pair(37, make_pair("-", 0)));
	deleteOperations.push_back(make_pair(37, make_pair("*", 0)));
	deleteOperations.push_back(make_pair(37, make_pair("/", 0)));
	deleteOperations.push_back(make_pair(37, make_pair("<", 1)));
	deleteOperations.push_back(make_pair(37, make_pair("<=", 1)));
	deleteOperations.push_back(make_pair(37, make_pair("==", 1)));
	deleteOperations.push_back(make_pair(37, make_pair(">", 1)));
	deleteOperations.push_back(make_pair(37, make_pair(">=", 1)));
	deleteOperations.push_back(make_pair(37, make_pair("and", 0)));
	deleteOperations.push_back(make_pair(37, make_pair("or", 0)));
	deleteOperations.push_back(make_pair(38, make_pair("!=", 1)));   //38 ״̬ S - > E + E   �����ȼ���+�߱�������ʽ(0)�� ���ȼ� <=+ ������Լʽ(1)
	deleteOperations.push_back(make_pair(38, make_pair("+", 1)));    //���ϱ�����Լʽ  (1)
	deleteOperations.push_back(make_pair(38, make_pair("-", 1)));
	deleteOperations.push_back(make_pair(38, make_pair("*", 0)));
	deleteOperations.push_back(make_pair(38, make_pair("/", 0)));
	deleteOperations.push_back(make_pair(38, make_pair("<", 1)));
	deleteOperations.push_back(make_pair(38, make_pair("<=", 1)));
	deleteOperations.push_back(make_pair(38, make_pair("==", 1)));
	deleteOperations.push_back(make_pair(38, make_pair(">", 1)));
	deleteOperations.push_back(make_pair(38, make_pair(">=", 1)));
	deleteOperations.push_back(make_pair(38, make_pair("and", 1)));
	deleteOperations.push_back(make_pair(38, make_pair("or", 1)));
	deleteOperations.push_back(make_pair(39, make_pair("!=", 1)));   //39 ״̬ S - > E - E   �����ȼ���+�߱�������ʽ(0)�� ���ȼ� <= - ������Լʽ(1)
	deleteOperations.push_back(make_pair(39, make_pair("+", 1)));    //���ϱ�����Լʽ  (1)
	deleteOperations.push_back(make_pair(39, make_pair("-", 1)));
	deleteOperations.push_back(make_pair(39, make_pair("*", 0)));
	deleteOperations.push_back(make_pair(39, make_pair("/", 0)));
	deleteOperations.push_back(make_pair(39, make_pair("<", 1)));
	deleteOperations.push_back(make_pair(39, make_pair("<=", 1)));
	deleteOperations.push_back(make_pair(39, make_pair("==", 1)));
	deleteOperations.push_back(make_pair(39, make_pair(">", 1)));
	deleteOperations.push_back(make_pair(39, make_pair(">=", 1)));
	deleteOperations.push_back(make_pair(39, make_pair("and", 1)));
	deleteOperations.push_back(make_pair(39, make_pair("or", 1)));
	deleteOperations.push_back(make_pair(40, make_pair("!=", 1)));   //40 ״̬ S - > E * E   �����ȼ���+�߱�������ʽ(0)�� ���ȼ� <= - ������Լʽ(1)
	deleteOperations.push_back(make_pair(40, make_pair("+", 1)));    //���ϱ�����Լʽ  (1)
	deleteOperations.push_back(make_pair(40, make_pair("-", 1)));
	deleteOperations.push_back(make_pair(40, make_pair("*", 1)));
	deleteOperations.push_back(make_pair(40, make_pair("/", 1)));
	deleteOperations.push_back(make_pair(40, make_pair("<", 1)));
	deleteOperations.push_back(make_pair(40, make_pair("<=", 1)));
	deleteOperations.push_back(make_pair(40, make_pair("==", 1)));
	deleteOperations.push_back(make_pair(40, make_pair(">", 1)));
	deleteOperations.push_back(make_pair(40, make_pair(">=", 1)));
	deleteOperations.push_back(make_pair(40, make_pair("and", 1)));
	deleteOperations.push_back(make_pair(40, make_pair("or", 1)));
	deleteOperations.push_back(make_pair(41, make_pair("!=", 1)));   //41 ״̬ S - > E / E   �����ȼ���/�߱�������ʽ(0)�� ���ȼ� <= /������Լʽ(1)
	deleteOperations.push_back(make_pair(41, make_pair("+", 1)));    //���ϱ�����Լʽ  (1)
	deleteOperations.push_back(make_pair(41, make_pair("-", 1)));
	deleteOperations.push_back(make_pair(41, make_pair("*", 1)));
	deleteOperations.push_back(make_pair(41, make_pair("/", 1)));
	deleteOperations.push_back(make_pair(41, make_pair("<", 1)));
	deleteOperations.push_back(make_pair(41, make_pair("<=", 1)));
	deleteOperations.push_back(make_pair(41, make_pair("==", 1)));
	deleteOperations.push_back(make_pair(41, make_pair(">", 1)));
	deleteOperations.push_back(make_pair(41, make_pair(">=", 1)));
	deleteOperations.push_back(make_pair(41, make_pair("and", 1)));
	deleteOperations.push_back(make_pair(41, make_pair("or", 1)));

	//
	deleteOperations.push_back(make_pair(86, make_pair("!=", 0)));   //86 ״̬ S - > EA E  �����ȼ���and�߱�������ʽ�� ���ȼ� <= and ������Լʽ
	deleteOperations.push_back(make_pair(86, make_pair("+", 0)));    //���ϱ�����Լʽ
	deleteOperations.push_back(make_pair(86, make_pair("-", 0)));
	deleteOperations.push_back(make_pair(86, make_pair("*", 0)));
	deleteOperations.push_back(make_pair(86, make_pair("/", 0)));
	deleteOperations.push_back(make_pair(86, make_pair("<", 0)));
	deleteOperations.push_back(make_pair(86, make_pair("<=", 0)));
	deleteOperations.push_back(make_pair(86, make_pair("==", 0)));
	deleteOperations.push_back(make_pair(86, make_pair(">", 0)));
	deleteOperations.push_back(make_pair(86, make_pair(">=", 0)));
	deleteOperations.push_back(make_pair(86, make_pair("and", 1)));
	deleteOperations.push_back(make_pair(86, make_pair("or", 1)));
	deleteOperations.push_back(make_pair(87, make_pair("!=", 0)));   //87 ״̬ S - > E0 E  �����ȼ���or�߱�������ʽ(0)�� ���ȼ� <= or ������Լʽ(1)
	deleteOperations.push_back(make_pair(87, make_pair("+", 0)));    //���ϱ�����Լʽ
	deleteOperations.push_back(make_pair(87, make_pair("-", 0)));
	deleteOperations.push_back(make_pair(87, make_pair("*", 0)));
	deleteOperations.push_back(make_pair(87, make_pair("/", 0)));
	deleteOperations.push_back(make_pair(87, make_pair("<", 0)));
	deleteOperations.push_back(make_pair(87, make_pair("<=", 0)));
	deleteOperations.push_back(make_pair(87, make_pair("==", 0)));
	deleteOperations.push_back(make_pair(87, make_pair(">", 0)));
	deleteOperations.push_back(make_pair(87, make_pair(">=", 0)));
	deleteOperations.push_back(make_pair(87, make_pair("and", 0)));
	deleteOperations.push_back(make_pair(87, make_pair("or", 1)));
	deleteOperations.push_back(make_pair(88, make_pair("!=", 1)));   //88 ״̬ S - > not E  �����ȼ���not�߱�������ʽ(0)�� ���ȼ� <= not ������Լʽ(1)
	deleteOperations.push_back(make_pair(88, make_pair("+", 1)));    //���ϱ�����Լʽ  
	deleteOperations.push_back(make_pair(88, make_pair("-", 1)));
	deleteOperations.push_back(make_pair(88, make_pair("*", 1)));
	deleteOperations.push_back(make_pair(88, make_pair("/", 1)));
	deleteOperations.push_back(make_pair(88, make_pair("<", 1)));
	deleteOperations.push_back(make_pair(88, make_pair("<=", 1)));
	deleteOperations.push_back(make_pair(88, make_pair("==", 1)));
	deleteOperations.push_back(make_pair(88, make_pair(">", 1)));
	deleteOperations.push_back(make_pair(88, make_pair(">=", 1)));
	deleteOperations.push_back(make_pair(88, make_pair("and", 1)));
	deleteOperations.push_back(make_pair(88, make_pair("or", 1)));
	deleteOperations.push_back(make_pair(89, make_pair("!=", 1)));   //89 ״̬ S - > E rop E  (rop��> < >= <=, ==, !=) �����ȼ���not�߱�������ʽ(0)�� ���ȼ� <= not ������Լʽ(1)
	deleteOperations.push_back(make_pair(89, make_pair("+", 0)));    //���ϱ�����Լʽ  
	deleteOperations.push_back(make_pair(89, make_pair("-", 0)));
	deleteOperations.push_back(make_pair(89, make_pair("*", 0)));
	deleteOperations.push_back(make_pair(89, make_pair("/", 0)));
	deleteOperations.push_back(make_pair(89, make_pair("<", 1)));
	deleteOperations.push_back(make_pair(89, make_pair("<=", 1)));
	deleteOperations.push_back(make_pair(89, make_pair("==", 1)));
	deleteOperations.push_back(make_pair(89, make_pair(">", 1)));
	deleteOperations.push_back(make_pair(89, make_pair(">=", 1)));
	deleteOperations.push_back(make_pair(89, make_pair("and", 0)));
	deleteOperations.push_back(make_pair(89, make_pair("or", 0)));
	deleteOperations.push_back(make_pair(90, make_pair("!=", 1)));   //90 ״̬ S - > E + E   �����ȼ���+�߱�������ʽ(0)�� ���ȼ� <=+ ������Լʽ(1)
	deleteOperations.push_back(make_pair(90, make_pair("+", 1)));    //���ϱ�����Լʽ  (1)
	deleteOperations.push_back(make_pair(90, make_pair("-", 1)));
	deleteOperations.push_back(make_pair(90, make_pair("*", 0)));
	deleteOperations.push_back(make_pair(90, make_pair("/", 0)));
	deleteOperations.push_back(make_pair(90, make_pair("<", 1)));
	deleteOperations.push_back(make_pair(90, make_pair("<=", 1)));
	deleteOperations.push_back(make_pair(90, make_pair("==", 1)));
	deleteOperations.push_back(make_pair(90, make_pair(">", 1)));
	deleteOperations.push_back(make_pair(90, make_pair(">=", 1)));
	deleteOperations.push_back(make_pair(90, make_pair("and", 1)));
	deleteOperations.push_back(make_pair(90, make_pair("or", 1)));
	deleteOperations.push_back(make_pair(91, make_pair("!=", 1)));   //91 ״̬ S - > E - E   �����ȼ���+�߱�������ʽ(0)�� ���ȼ� <= - ������Լʽ(1)
	deleteOperations.push_back(make_pair(91, make_pair("+", 1)));    //���ϱ�����Լʽ  (1)
	deleteOperations.push_back(make_pair(91, make_pair("-", 1)));
	deleteOperations.push_back(make_pair(91, make_pair("*", 0)));
	deleteOperations.push_back(make_pair(91, make_pair("/", 0)));
	deleteOperations.push_back(make_pair(91, make_pair("<", 1)));
	deleteOperations.push_back(make_pair(91, make_pair("<=", 1)));
	deleteOperations.push_back(make_pair(91, make_pair("==", 1)));
	deleteOperations.push_back(make_pair(91, make_pair(">", 1)));
	deleteOperations.push_back(make_pair(91, make_pair(">=", 1)));
	deleteOperations.push_back(make_pair(91, make_pair("and", 1)));
	deleteOperations.push_back(make_pair(91, make_pair("or", 1)));
	deleteOperations.push_back(make_pair(92, make_pair("!=", 1)));   //92 ״̬ S - > E * E   �����ȼ���+�߱�������ʽ(0)�� ���ȼ� <= - ������Լʽ(1)
	deleteOperations.push_back(make_pair(92, make_pair("+", 1)));    //���ϱ�����Լʽ  (1)
	deleteOperations.push_back(make_pair(92, make_pair("-", 1)));
	deleteOperations.push_back(make_pair(92, make_pair("*", 1)));
	deleteOperations.push_back(make_pair(92, make_pair("/", 1)));
	deleteOperations.push_back(make_pair(92, make_pair("<", 1)));
	deleteOperations.push_back(make_pair(92, make_pair("<=", 1)));
	deleteOperations.push_back(make_pair(92, make_pair("==", 1)));
	deleteOperations.push_back(make_pair(92, make_pair(">", 1)));
	deleteOperations.push_back(make_pair(92, make_pair(">=", 1)));
	deleteOperations.push_back(make_pair(92, make_pair("and", 1)));
	deleteOperations.push_back(make_pair(92, make_pair("or", 1)));
	deleteOperations.push_back(make_pair(93, make_pair("!=", 1)));   //93״̬ S - > E / E   �����ȼ���/�߱�������ʽ(0)�� ���ȼ� <= /������Լʽ(1)
	deleteOperations.push_back(make_pair(93, make_pair("+", 1)));    //���ϱ�����Լʽ  (1)
	deleteOperations.push_back(make_pair(93, make_pair("-", 1)));
	deleteOperations.push_back(make_pair(93, make_pair("*", 1)));
	deleteOperations.push_back(make_pair(93, make_pair("/", 1)));
	deleteOperations.push_back(make_pair(93, make_pair("<", 1)));
	deleteOperations.push_back(make_pair(93, make_pair("<=", 1)));
	deleteOperations.push_back(make_pair(93, make_pair("==", 1)));
	deleteOperations.push_back(make_pair(93, make_pair(">", 1)));
	deleteOperations.push_back(make_pair(93, make_pair(">=", 1)));
	deleteOperations.push_back(make_pair(93, make_pair("and", 1)));
	deleteOperations.push_back(make_pair(93, make_pair("or", 1)));
	myParser.sloveAmbiguousTable(deleteOperations);
	ofstream fout2 = ofstream();
	fout2.open(modelfile, ios::out);
	if (!fout2.is_open()) {
		cout << "�޷���ģ���ı�" << endl;
		return false;
	}
	myParser.outParserModel(fout2);
	fout2.close();
    // �����﷨����
	myParser.scanTokenStream(tokenstream, reportfile);
	system("pause");
	return 0;
}

/*
// ������ʽ�����ʽ������ķ�ͬ �ʷ������� , �ӱ��ʽ����״̬��
	set<string> nonTerminators = set<string>({ "S","A","B","S1" });
	set<string> terminators = set<string>({ "a","b","none","$","c","d" });
	vector<string> production0 = vector<string>({ "S1","S", });
	vector<string> production1 = vector<string>({ "S","A","a"});
	vector<string> production2 = vector<string>({ "S","b","A","c" });
	vector<string> production3 = vector<string>({ "S","B","c" });
	vector<string> production4 = vector<string>({ "S","b","B","a" });
	vector<string> production5 = vector<string>({ "A","d" });
	vector<string> production6 = vector<string>({ "B","d", });
	vector < vector<string>> productions = vector < vector<string>>(
		{
			production0,production1,production2,production3,production4,production5,production6
		});
*/