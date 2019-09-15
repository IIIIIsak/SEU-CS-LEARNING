#ifndef GRAPHMTX_H
#define GRAPHMTX_H
#include<iostream>
#include<fstream>
#include<iomanip>

#include"SeqQueue.hpp"
using namespace std;
const int defaultSize = 20;
template<class V, class W>
class GraphMtx
{
/*
template<class V,class W>
friend ifstream& operator>>(ifstream& fin, GraphMtx<V,W>& graph);
template<class V, class W>
friend ofstream& operator<<(ofstream& fout, GraphMtx<V,W>& graph);
*/
public:
	enum GraphType{ UNDIRECTED,DIRECTED };
	GraphMtx(W max, GraphType type = UNDIRECTED,int maxV = defaultSize);  //Ĭ��������ͼ
	~GraphMtx();
	bool isGraphEmpty()
	{
		return numVertexes <= 0 ? true : false;
	}
	
	bool isGraphFull()
	{
		if ( numVertexes >= maxVertexes|| numEdges >= maxVertexes* (maxVertexes - 1))  //���������(�����ж�ֻ���������ͼ)
		{
			return true;
		}
		else
			return false;
	}
   
    int numOfVertexes()
	{ return numVertexes; }

	int numOfEdges()
	{
		return numEdges;
	}

	bool getVertexValue(int i, V& value) // ���ص�i �������ֵ������value��
	{
		if (i < 0 || i >= numVertexes)   //���Խ��Ļ�
		{
			return false;
		}
		else
		{
			value = vertexesList[i];
			return true;
		}
	};

	bool getEdgeWeight(int v1, int v2, W& weight)   //���� ����v1 �� v3 ֮��ߵ�Ȩֵ
	{
		if (v1 < 0 || v1 >= numVertexes || v2 < 0 || v2 >= numVertexes)
		{
			return false;
		}
		else
		{
			return edgesMatrix[v1][v2];
		}
	}
	bool insertVertex(const V& value);
	bool insertEdge(const int v1, const int v2, const W& weight);
	bool getFirstNeighbor(const int v1, int& v);
	bool getNextNeighbor(const int v1, const int w, int& v);
    
	bool inputVertexesFromFile(ifstream& fin); //���ļ��ж�ȡ�㼯
	bool inputEdgesFromFile(ifstream& fin); //���ļ��ж�ȡ�߼�
	void outputGraph();
	
	//��ȱ���
	void DFS(GraphMtx& G , const V& v);
	void BFS(GraphMtx& G, const V&v);
private:
	int numVertexes;  //��ǰ�Ľڵ���
	int numEdges; //��ǰ�ı���
	int maxVertexes; //���Ľڵ���
	GraphType graphType;
	W maxWeight; //����Ȩֵ��������ʾ��������֮���ǲ��ڽӵ�
	V* vertexesList; //������б�
	W** edgesMatrix;   //�ߵ��ڽӾ���
	bool  getVertex(const V value, int& pos) //���Ҳ�����ֵΪValue�Ķ����λ��
	{
		int i = 0;
		for (i; i < numVertexes; i++)
		{
			if (value == vertexesList[i])
			{
				pos = i;
				return true;
			}

		}
		if (i >= numVertexes)
		{ 
			pos = -1;
			return false;
		}
			
	}
	void DFS( GraphMtx& G, const int & v,bool* visted);

};

template<class V,class W>
GraphMtx<V, W>::GraphMtx(W max, GraphType type, int maxV ):maxWeight(max),maxVertexes(maxV),graphType(type)
{
	numVertexes = 0;
	numEdges = 0;
    //�������������
    vertexesList = new V[maxVertexes];  
	if (vertexesList == nullptr)
	{
		cout << "�ڴ�����ʧ��";
		exit(1);
	}
	for (int i = 0; i < maxVertexes;i++)
		vertexesList[i] = 0;   //��ʼ��
    
	//��ʼ���ߵ��ڽӾ���
	edgesMatrix = new W*[maxVertexes];
	if (edgesMatrix == nullptr)
	{
		cout << "�ڴ�����ʧ��";
		exit(1);
	}
	for (int i = 0; i < maxVertexes; i++)
	{
		edgesMatrix[i] = new W[maxVertexes];
		if (edgesMatrix[i] == nullptr)
		{
			cout << "�ڴ�����ʧ��" << endl;
			exit(1);
		}
	}

	//��ʼ��
	for (int i = 0; i < maxVertexes; i++)
	{
		for (int j = 0; j < maxVertexes; j++)
		{
			if (i == j)
			{
				edgesMatrix[i][j] = 0;
			}
			else
			{
				edgesMatrix[i][j] = maxWeight;
			}
			//edgesMatrix[i][j] = (i == j ? 0 : maxWeight);  //����ط�Ϊʲô��ֱ��ȫ������ʼ��ΪmaxWeight��
		}
	}
	
	
}
template<class V, class W>
GraphMtx<V, W>::~GraphMtx()
{
	if (vertexesList != nullptr)
	{
		delete[] vertexesList;
		vertexesList = nullptr;
	}
	if (edgesMatrix != nullptr)
	{
		for (int i = 0; i < maxVertexes; i++)
		{
			if (edgesMatrix[i] != nullptr)
			{
				delete[] edgesMatrix[i];
				edgesMatrix[i] = nullptr;
			}
		}
		delete[] edgesMatrix;
		edgesMatrix = nullptr;
	}
}

template<class V, class W>
bool GraphMtx<V,W>::insertVertex(const V& value)
{
	if (numVertexes >= maxVertexes)  //���������Χ��
	{
		return false;
	}
	else
	{
		vertexesList[numVertexes++] = value;
		return true;
	}
}
template<class V, class W>
bool GraphMtx<V,W>::insertEdge(const int v1, const int v2, const W& weight)
{
	if(v1 < 0 || v1 >= numVertexes || v2 < 0 || v2 >= numVertexes)
	{
		return false;
	}
	else
	{
		if (edgesMatrix[v1][v2] != maxWeight )   // �������������֮���Ѿ����ڱ�
		{
			cout << "��v1 ��v2 ֮���Ѿ��бߴ����ˣ��޷������" << endl;
			return false;
		}
		else
		{
			edgesMatrix[v1][v2] = weight;
			numEdges++;   //�ߵ���Ŀ+1
			return true;
		}
	}
}
template<class V, class W>
bool GraphMtx<V, W>::getFirstNeighbor(const int v1, int& v)
{
	int i = 0;
	for (i; i < numVertexes; i++)
	{
		if (edgesMatrix[v1][i] != maxWeight && edgesMatrix[v1][i] != 0)  //���Ȩֵ��Ϊ���޴�
		{
			v = i; 
			return true;
		}
	}
	if (i >= numVertexes)
	{
		v = -1;
		return false;
	}
}

template<class V, class W>
bool GraphMtx<V, W>::getNextNeighbor(const int v1, const int w, int& v)
{
	int i = w+1;
	for (i; i < numVertexes; i++)
	{
		if (edgesMatrix[v1][i] != maxWeight && edgesMatrix[v1][i]!=0)  //���Ȩֵ��Ϊ���޴�
		{
			v = i;
			return true;
		}

	}
	if (i >= numVertexes)
	{
		v = -1;
		return false;
	}
}
template<class V, class W>
bool  GraphMtx<V, W>::inputVertexesFromFile(ifstream& fin) //���ļ��ж�ȡ�㼯
{
	int nums;   //�㼯����Ŀ
	V tempV; //��ʱ����
	fin >> nums;  //����㼯����Ŀ
	if (isGraphFull())
	{
		cout << "�������Ŀ���࣬����ͼ������������Ŀ,��ȡʧ��" << endl;
		return false;
	}
	for (int i = 0; i < nums; i++)
	{
		fin >> tempV;
		if (!insertVertex(tempV))  //�������ʧ�ܵĻ�
		{
			return false;   
		}
	}
	return true;
}
template<class V, class W>
bool GraphMtx<V,W>::inputEdgesFromFile(ifstream& fin) //���ļ��ж�ȡ�߼�
{
	int nums; //�߼�����Ŀ
	V v1, v2; //������
	W weight; //Ȩֵ 
	fin >> nums;
	if (isGraphFull())
	{
		cout << "�ߵ���Ŀ���࣬����߼�ʧ��" << endl;
		return false;
	}
	else
	{
		for (int i = 0; i < nums; i++)
		{
			fin >> v1 >> v2 >> weight;
			int x1, x2;
			if (!(getVertex(v1, x1) && getVertex(v2, x2)))
			{
				return false;
			}
			else
			{
				if (graphType == DIRECTED)  //���������ͼ�Ļ�
				{
					if (!insertEdge(x1, x2, weight))
						return false;
				}
				else  //���������ͼ�Ļ�
				{
					bool isFind1 = insertEdge(x1, x2, weight);
					bool isFind2 = insertEdge(x2, x1, weight);
					if(!(isFind1||isFind2))
						return false;
				}
			}
		}
		return true;
    }
}
template<class V, class W>
void  GraphMtx<V, W>::outputGraph()
{
	const int place = 4; //ռλ���ĳ���
	if (isGraphEmpty())
	{
		cout << "ͼΪ��ͼ" << endl;
		return;
	}
	cout << "ͼ���ڽӾ���Ϊ��" << endl;
	//��ӡ��һ��
	cout << setw(place) << '|';
	for (int i = 0; i < numVertexes; i++)
	{
		cout << setw(place) << vertexesList[i];
	}
	cout << endl;
	//��ӡ�ڶ���
	cout << setw(place) << '|';
	for (int i = 0; i < numVertexes; i++)
	{
		cout << "____";
	}
	cout << endl;
	//��ӡ����������
	for (int i = 0; i < numVertexes; i++)
	{
		cout << vertexesList[i] << setw(place - 1) << '|';
		for (int j = 0; j < numVertexes; j++)
		{
			if (edgesMatrix[i][j] != maxWeight)
			{
				cout << setw(place) << edgesMatrix[i][j];
			}
			else
			{
				cout <<setw(place)<<" ";
			}
		}
		cout << endl;
	}
}
template<class V, class W>
void  GraphMtx<V, W>::DFS( GraphMtx& G, const V& v)
{
	int num = G.numVertexes;
	//�ȹ���һ����������
	bool* visited = new bool[num];
	//��ʼ��
	for (int i = 0; i < num; i++)
	{
		visited[i] = false;
	}

	//��ȡ���������
	int loc;
	if (!G.getVertex(v, loc))
	{
		cout << "û���ҵ�����" << v << endl;
		return;
	}
	DFS(G, loc, visited);
	cout << endl;
	//�ж��ǲ������еĶ�����һ����
	for (int i = 0; i < num; i++)
	{
		if (visited[i] == false)  //��������û�б�������ô�ͽ��Ŵ�����㿪ʼ��������
		{
			DFS(G, i, visited);
			cout << endl;
		}
	}






	delete[]visited;

	//

}

template<class V,class W>
void  GraphMtx<V, W>::DFS( GraphMtx& G, const int& vLoc, bool* visited)
{
	//����������ж���v��û�б����ʵ�
	
	//�ȷ��ʶ���v
	V tempValue;
	if (!G.getVertexValue(vLoc, tempValue))
	{
		cout << "�����vloc��ֵ�Ƿ�" << endl;
		return;
	}
	visited[vLoc] = true;
	//���ֵ
	cout << tempValue;
    
	//��ȡ���һ���ڽӵ��λ��
	int nextLoc;
	bool isFind = G.getFirstNeighbor(vLoc, nextLoc);  //�ݹ����������
	while (isFind)
	{
		int tempLoc = nextLoc;
		if (visited[nextLoc] == false) //���û�з��ʹ�
		{
			//���û�з��ʹ���·��
			G.getVertexValue(nextLoc, tempValue);
			cout << "->";
			DFS(G, nextLoc, visited);
		}
		else
		{
			G.getVertexValue(nextLoc, tempValue);
			cout << "->(" << tempValue << ")";
		}
		isFind = G.getNextNeighbor(vLoc,tempLoc, nextLoc);
	}
	return;
	
}

template<class V,class W>
void GraphMtx<V, W>::BFS(GraphMtx& G, const V&v)
{
	//������������
	int num = G.numVertexes;
	//�ȹ���һ����������
	bool* visited = new bool[num];
	//��ʼ��
	for (int i = 0; i < num; i++)
	{
		visited[i] = false;
	}
	int loc;
	if (!G.getVertex(v,loc))
	{
		cout << "û���ҵ�����" << v<<" ��ȱ����˳�" << endl;
		return;
	}
	//���ʽڵ�v
	visited[loc] = true;
	cout<< v ;

	//ִ�й�ȱ���
	SeqQueue<int>Q;   //����һ������
	//�Ȼ�ȡv�ĵ�һ���ڽӽڵ�
	if(!Q.enQueue(loc))
		return ;
   //�����ﻹΪ��
	while (!Q.isEmpty())
	{
		int FoundLoc;  //ȡ���Ѿ��ҵ��Ľڵ㣬׼�����й�ȱ���
		Q.deQueue(FoundLoc);
		int nextLoc;
		bool isFoundNext=G.getFirstNeighbor(FoundLoc, nextLoc);
		if (isFoundNext)  //��һ���ڽӽڵ�
		{
			//����
			V tempValue;
			if (visited[nextLoc] == false)
			{
				if(!Q.enQueue(nextLoc))
					return ;  //����
				visited[nextLoc] = true;
				G.getVertexValue(nextLoc, tempValue);
				cout << "->" << tempValue ;
			}
			else
			{
				//���·��
				G.getVertexValue(nextLoc, tempValue);
				cout << "->(" << tempValue << ")";
			}
			int tempLoc = nextLoc;  //��ʱ����
			isFoundNext = G.getNextNeighbor(FoundLoc, tempLoc, nextLoc);
			while (isFoundNext)   //����֮����ڽӽڵ�
			{
				//����ҵ��Ļ�
				//����
				if (visited[nextLoc] == false)
				{
					if(!Q.enQueue(nextLoc))
						return ;  //����
					visited[nextLoc] = true;
					G.getVertexValue(nextLoc, tempValue);
					cout << "->" << tempValue ;
				}
				else
				{
					//���·��
					G.getVertexValue(nextLoc, tempValue);
					cout << "->(" << tempValue << ")";
				}
				tempLoc = nextLoc;
				isFoundNext = G.getNextNeighbor(FoundLoc, tempLoc, nextLoc);
			}
			//�����е��ڽӽڵ㶼���ʹ��ˣ�������ѭ��ȡ�������еĽڵ�
		}
		if (Q.isEmpty())   //��������ǿյ�
		{
			cout << endl;
			for (int i = 0; i < num; i++)
			{
				if (visited[i] == false)  //������е�û�б���������ô��������㲢�ҽ�������
				{
					visited[i] = true;
					V tempV;
					G.getVertexValue(i, tempV);
					cout << tempV;
					if(!Q.enQueue(i))
						return ;
					break;
				}
			}
		}
	}
     

	
}
#endif // !GRAPHMTX_H
#pragma once
