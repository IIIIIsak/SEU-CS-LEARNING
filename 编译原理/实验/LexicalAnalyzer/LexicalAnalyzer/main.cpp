#include "DFA.h"
#include "State.h"
#include "token.h"
#include<cctype>
#include<fstream>
string s5edgeJudge(string s) {
	if (s != "\"" || s == "digit" || s == "letter") {
		return "chars1";
	}
	else {
		return s;
	}
}
string s7edgeJudge(string s) {
	if (s != "'" || s =="digit" || s=="letter") {
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
    //####################################### ��������ļ�·�� ####################################
	const string inputfile = "D:\\input.txt";
	const string tokenOutPutFile = "D:\\tokenstream.txt";
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
	vector<string> keepWords = vector<string>({ "if","else","while","do","(",")","+","-","*","/", ";" ,"=","and","or","not",">","<",">=","<","==","!=" ,"true","false",
											"then","{" ,"}" });
	for (int i = 0; i < keepWords.size(); i++) {
		myDFA.addKeepWord(keepWords[i], 5 + i);
	}
	// ���ӱ��жϺ���
	myDFA.getState(7).setEdgeJudgeFunction(s7edgeJudge);
	myDFA.getState(5).setEdgeJudgeFunction(s5edgeJudge);

	//######################### ɨ���ļ�ģ��
	ifstream fin = ifstream();
	fin.open(inputfile, ios::in);
	if (!fin.is_open()) {
		cout << "�޷����ļ���" << endl;
		return 0;
	}
	ofstream fout = ofstream();
	fout.open(tokenOutPutFile, ios::out);
	if (!fout.is_open()) {
		cout << "�޷����ļ���" << endl;
		return 0;
	}
	string str;
	char c;
	bool isIgnore = false;
	while (fin.get(c)) {
		if ((c == ' ' || c == '\n' || c == '\t') && isIgnore ==false) {
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
	system("pause");
	return 0;
	
}



