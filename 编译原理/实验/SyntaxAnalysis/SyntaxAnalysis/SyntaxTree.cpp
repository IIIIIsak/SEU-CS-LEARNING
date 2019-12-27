#include "SyntaxTree.h"



SyntaxTree::SyntaxTree()
{
	head = int(nodes.size()-1);
}


SyntaxTree::~SyntaxTree()
{
}
int SyntaxTree::addNode(treeNode& t) {
	nodes.push_back(t);
	head = nodes.size() - 1;  // Ĭ��ָ�����һ��λ�ã������ڵݹ齨��
	return head;             // ����ָ��ոռ����node�� λ�ã����㽨��
}
void  SyntaxTree::outputTreeAsFile(ofstream& fout,int  subTree , int widthset , int heightset ) {
	queue<treeNode> treeNodeQueue;              //���ö��н�����ȱ���
	vector<pair<treeNode,int>> currentNodes;

	int depth = getTreeDepth(subTree);
	//���ڵ�
	if (nodes[subTree].child_ptrs.size() > 1) {
		fout << setiosflags(ios::left) << setw(widthset)<<setfill('-') << nodes[subTree].t.get_token_name() << setw(' ')<<endl;
	}
	else {
		fout << setiosflags(ios::left) << setw(widthset) << nodes[subTree].t.get_token_name() << endl;
	}
	// �Ѹ��ڵ�ĺ��������
	if (nodes[subTree].child_ptrs.size() == 0) {
		// ���û�к��ӣ���Ҫ���ռ��
		treeNode t = treeNode();
		t.width = nodes[subTree].width;              // -1��ʾ�ǿսڵ�
		treeNodeQueue.push(t);
	}
	else {
		for (int j = 0; j < nodes[subTree].child_ptrs.size(); j++) {
			treeNodeQueue.push(nodes[nodes[subTree].child_ptrs[j]]);
		}
	}
	// ���ڵ�֮���
	for (int h = 0; h < depth-1; h++) {
		//�Ѷ�������Ҫ��ӡ�Ľڵ�ת�Ƶ�vector��,ͬʱ������Ҫ��ӡ�ĺ���֦�Ŀ��
		//��vector���
		currentNodes.clear();
		while(treeNodeQueue.size()>0) {
			int printwidth = 0;
			treeNode n = treeNodeQueue.front(); 
			for (int j = 0; j < int(n.child_ptrs.size() - 1); j++) {           //������ -1
				printwidth += nodes[n.child_ptrs[j]].width;
			}
			currentNodes.push_back(make_pair(treeNodeQueue.front(),printwidth));
			treeNodeQueue.pop();          //�����ﵯ���ڵ�
		}
		//����Ƚ������
		for (int line = 0; line < heightset; line++) {
			//�������
			for (int n = 0; n < currentNodes.size(); n++) {
				//�ֽ�����
				//�����ǰ�Ľڵ�
				pair<treeNode, int> current = currentNodes[n];
				if (line == heightset - 1) {
					//������ڵ�����
					if (current.first.t.get_token_name() == "none") {
						fout << setiosflags(ios::left) << setw(widthset) << " ";
					}
					else if (current.first.t.get_value() == "_") {  //���tokenֵ�Ƿǹؼ��֣�����Ҫ��ֵ��ӡ����
						if (current.first.child_ptrs.size() > 1) {
							fout << setiosflags(ios::left) << setw(widthset) << setfill('-') << current.first.t.get_token_name() << setfill(' ');
						}
						else {
							fout << setiosflags(ios::left) << setw(widthset) << current.first.t.get_token_name();
						}
					}
					else {
						if (current.first.child_ptrs.size() > 1) {
							fout << setiosflags(ios::left) << setw(widthset) << setfill('-') << current.first.t.get_token_name() + "=" + current.first.t.get_value() << setfill(' ');
						}
						else {
							fout << setiosflags(ios::left) << setw(widthset)  << current.first.t.get_token_name() + "=" + current.first.t.get_value() ;
						}
					}
					// ��� ������֦��
					for (int i = 0; i < current.first.width-1; i++) {
						//��ӡ�ýڵ�����Ҫ�ĺ���֦
						if (current.first.t.get_token_name() == "none") {
							fout << setiosflags(ios::left) << setw(widthset) << " ";
						}
						else if (i < current.second-1) {
							fout << setiosflags(ios::left) << setw(widthset)<<setfill('-') << "-" << setfill(' ');           //��ӡ����֦

						}
						else {
							fout << setiosflags(ios::left) << setw(widthset) << " ";
						}
					}
				}
				// ��� "����֦"
				else {
					for (int i = 0; i  < current.first.width; i++) {
						if (current.first.t.get_token_name() == "none") {
							fout << setiosflags(ios::left) << setw(widthset) << " ";
							continue;
						}
						if (i == 0) {
							fout << setiosflags(ios::left) << setw(widthset) << "|";
						}
						else {
							fout << setiosflags(ios::left) << setw(widthset) << " ";
						}
					}
				}
			}
			fout << endl;
		}
		// ������һ����Ҫ����Ľڵ�
		while(treeNodeQueue.size()>0){
			treeNodeQueue.pop();
		}
		for (int i = 0; i < currentNodes.size(); i++) {
			if (currentNodes[i].first.child_ptrs.size() == 0) {
				// ���û�к��ӣ���Ҫ���ռ��
				treeNode t = treeNode();
				t.width = currentNodes[i].first.width;              // -1��ʾ�ǿսڵ�
				treeNodeQueue.push(t);
			}
			else {
				for (int j = 0; j < currentNodes[i].first.child_ptrs.size(); j++) {
					treeNodeQueue.push(nodes[currentNodes[i].first.child_ptrs[j]]);
				}
			}
		}
	}	
}
int  SyntaxTree::getTreeWidth( int subTree) {  //�������Ŀ�ȣ����Ľڵ���
	int width = 0;
	if (nodes[subTree].child_ptrs.size() == 0) {
		//�����Ҷ�ӽڵ�
		width = 1;
		nodes[subTree].width = width;
		return 1;    //��������
	}
	for (int i = 0; i < nodes[subTree].child_ptrs.size(); i++) {
		width += getTreeWidth(nodes[subTree].child_ptrs[i]);  //�ݹ������
	}
	nodes[subTree].width = width;
	return width;
}

int SyntaxTree::getTreeDepth(int subTree) {  //�����������
	int depth = 0;
	if (nodes[subTree].child_ptrs.size() == 0) {
		//�����Ҷ�ӽڵ�
		return 1;    //��������
	}
	int maxDepth = 0;
	for (int i = 0; i < nodes[subTree].child_ptrs.size(); i++) {
		int subDepth = getTreeDepth(nodes[subTree].child_ptrs[i]);  //�ݹ������
		if (subDepth > maxDepth) {
			maxDepth = subDepth;
		}
	}
	return maxDepth+1;
}