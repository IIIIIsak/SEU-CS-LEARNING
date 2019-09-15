#include<iostream>
#include"GraphMtx.hpp"
int main()
{
	
	GraphMtx<char, int> myUGraph(100,GraphMtx<char,int>::UNDIRECTED);
	GraphMtx<char,int> myGraph(100, GraphMtx<char, int>::DIRECTED);
	ifstream finV;
	//���붥�㼯
	finV.open("vertexes.txt", ios::in);
	if (!finV.is_open())
	{
		cout << "�㼯�ļ���ȡʧ�ܣ�" << endl;
		exit(1);
	}
	else
	{
		myGraph.inputVertexesFromFile(finV);
	}
	finV.close();
	ifstream finE;
	finE.open("edges.txt", ios::in);
	if (!finE.is_open())
	{
		cout << "�߼��ļ���ȡʧ�ܣ�" << endl;
		exit(1);
	}
	else
	{
		myGraph.inputEdgesFromFile(finE);
	}
	finE.close();

	ifstream finUV;
	finUV.open("vertexes.txt", ios::in);
	if (!finUV.is_open())
	{
		cout << "�㼯�ļ���ȡʧ�ܣ�" << endl;
		exit(1);
	}
	else
	{
		myUGraph.inputVertexesFromFile(finUV);
	}
	finUV.close();

	ifstream finUE;
	finUE.open("edges.txt", ios::in);
	if (!finUE.is_open())
	{
		cout << "�߼��ļ���ȡʧ�ܣ�" << endl;
		exit(1);
	}
	else
	{
		myUGraph.inputEdgesFromFile(finUE);
	}
	finUE.close();
	//����ڽӾ���
	cout << "����ͼ���ԣ�" << endl;
	myGraph.outputGraph();
	cout << "����ͼ��ȱ�����" << endl;
	myGraph.DFS(myGraph, 'c');
	cout << endl;
	cout << "����ͼ��ȱ�����" << endl;
	myGraph.BFS(myGraph, 'c');
	cout << endl;

	cout<<"����ͼ����" << endl;
	myUGraph.outputGraph();
	cout << "����ͼ��ȱ�����" << endl;
	myUGraph.DFS(myUGraph, 'c');
	cout << endl;
	cout << "����ͼ��ȱ�����" << endl;
	myUGraph.BFS(myUGraph, 'c');
	
	system("pause"); 
	return 0;
}