#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H
#include"MinHeap.hpp"
#include<iostream>
#include<string>
#include<fstream>
#include"Stack.hpp"
using namespace std;
template<class T>
struct HuffmanNode
{
	//Ȩֵ��
	T weight; 
	//ָ���򣬲��������ھ�̬����Ľṹ
	int leftChild, rightChild, parent;
	int locate;
	//���캯��
	HuffmanNode():leftChild(-1), rightChild(-1), parent(-1),locate(-1)
	{}   //Ĭ�Ϲ���
	HuffmanNode(const T& w, const int l=-1, const int r=-1
		,const int p = -1,const int loc=-1):weight(w),leftChild(l),rightChild(r),parent(p),locate(loc)
	{}
	//�ȽϺ���������
	bool operator<(const HuffmanNode& rh)
	{
		if (weight < rh.weight)
			return true;
		else
			return false;
	}
	bool operator>(const HuffmanNode& rh)
	{
		if (weight > rh.weight)
			return true;
		else
			return false;
	}
	bool operator<=(const HuffmanNode& rh)
	{
		if (weight <= rh.weight)
			return true;
		else
			return false;
	}
	bool operator>=(const HuffmanNode& rh)
	{
		if (weight >= rh.weight)
			return true;
		else
			return false;
	}
	bool operator==(const HuffmanNode& rh)
	{
		if (weight == rh.weight)
			return true;
		else
			return false;
	}
	
};

template<class T>
class HuffmanTree
{
public:
	HuffmanTree(const T arr[],const char D[], int num);  //ͨ�������������������
	~HuffmanTree()
	{
		if (huffmanTree != nullptr)
		{
			delete[] huffmanTree;
			huffmanTree = nullptr;
		}
		if (dictionary != nullptr)
		{
			delete[]dictionary;
			dictionary = nullptr;
		}
	}
	bool findHuffmanCode(const int i, string& code);   //�ҵ�ĳһ���ڵ�������Ĺ���������
	void translateHuffmanCode(ifstream& fin, ofstream& fout);   //���ļ��ж�ȡ���ݣ����Ұѷ�����������ļ���
	void outputWholeWeight();

private:
	HuffmanNode<T>* huffmanTree;
	char* dictionary; //�ַ���Ӧ���ֵ�
	int root;
	int nums;
	void mergeTree(const int  lchild, const int  rchild, const int  parent);
	//���������ڵ�ֱ���lchild��rchild�������ϳ�Ϊһ�����������ĸ��ڵ�ָ��Ϊparent��ע��parent�Ĳ�������
	
	
};

template<class T>
HuffmanTree<T>::HuffmanTree(const T arr[],const char D[] ,int num) //ͨ�������������������
{
	//���ڵ���ȡ-1
	root = -1;
	//�ܽ��ĸ���
	nums = num ;
	//�����ֵ�
	dictionary = new char[nums];
	for (int i = 0; i < nums; i++)
	{
		dictionary[i] = D[i];
	}
	//�������������ľ�̬����洢�ռ䣬���ݽڵ�Ĺ�ϵ��һ����num��Ҷ�ڵ㣬������������2*num-1���ڵ�
	huffmanTree = new HuffmanNode<T>[2 * num - 1];
	//������ǰnum����ֵΪҶ�ڵ�
	for (int i = 0; i < num; i++)
	{
		huffmanTree[i].weight = arr[i];
		huffmanTree[i].locate = i;
	}
	//������С��
	MinHeap<HuffmanNode<T>>heap(num);
	
	//�����еĽڵ������С��
	for (int i = 0; i < num; i++)
	{
		heap.insert(huffmanTree[i]); 
	} 
	
	int first, second;
	HuffmanNode<T> firstNode, secondNode;
	int currentSize = num; //��ǰ�����нڵ����Ŀ
    //��num- 1��
	for (int i = 0; i < num - 1; i++)
	{
		//ȡ��Ȩֵ��С��������
		heap.removeMin(firstNode);
		heap.removeMin(secondNode);

		//��ȡ�ڵ��locate��
		first = firstNode.locate;
		second = secondNode.locate;

		//�ϲ�������
		mergeTree(first, second, currentSize);
		//���µ����������
		heap.insert(huffmanTree[currentSize]);
		currentSize++;
	
	}
	if (currentSize != 2 * num - 1)
	{
		cout << "�����Ĺ����г���δ֪����!" << endl;
	}
	root = currentSize-1;
}

template<class T>
bool HuffmanTree<T>::findHuffmanCode(const int i, string& code)
{
	code = ""; //���ÿ�
	if (i >= nums)
		return false;
	//�ö�ջʵ���������
	Stack<char> S;
	int currentPos = i; //·���ϵ�ǰ�Ľڵ�
	while (huffmanTree[currentPos].parent != -1)   //�ҵ����ڵ�֮��ͣ����(����ǰ�ڵ��Ǹ��ڵ��ʱ��
	{
		int parentPos=huffmanTree[currentPos].parent; //��ָ��
		if (huffmanTree[parentPos].leftChild == currentPos)  //�����ǰ�ڵ�������
		{
			//ѹ��0
			S.push('0');
		}
		else   //�����ǰ�ڵ����Һ���
		{
			//ѹ��1��
			S.push('1');
		}
		currentPos = parentPos;   //�ڵ�����Ѱ
	}
	//���ö�ջ�������
	while(!S.isEmpty())
	{
		char x;
		if (!S.pop(x))
			cout << "����δ֪����" << endl;
		code += x;
	}
	return true;
}

template<class T>
void HuffmanTree<T>::translateHuffmanCode(ifstream& fin, ofstream& fout)
{
	int currentPos = root;  //��ǰ·���Ľڵ�
	char x=0;

	while (fin>>x)  //�����������
	{
		
		//�����Ҷ�ڵ�


		
			if (x == '0')
				currentPos = huffmanTree[currentPos].leftChild;  //�����
			else if (x == '1')
				currentPos = huffmanTree[currentPos].rightChild; //���ұ���
			else
			{
				cout << "������0����1���ַ�����";
			}
			if (huffmanTree[currentPos].leftChild == -1 && huffmanTree[currentPos].rightChild == -1)
			{
				//�ҵ�Ҷ�ڵ��ˣ������ַ�
				fout << dictionary[currentPos];
				//����Ϊ��
				currentPos = root;

			}
		
	}
}

template<class T>
void HuffmanTree<T>::mergeTree(const int  lchild, const int  rchild, const int  parent)
{
	//�����½ڵ�Ȩֵ���
	huffmanTree[parent].weight = huffmanTree[lchild].weight + huffmanTree[rchild].weight;
	//�����½ڵ㣬�������������е��±�,���ھɵĽڵ�����Ҫ
	huffmanTree[parent].locate = parent;
	//����ȥ
	//�ӽڵ�ҵ����ڵ���
	huffmanTree[parent].leftChild = lchild;
	huffmanTree[parent].rightChild = rchild;
    
	//�ı��ӽڵ�ĸ�ָ��
	huffmanTree[lchild].parent = huffmanTree[rchild].parent = parent;
}
template<class T>
void HuffmanTree<T>::outputWholeWeight()
{
	T total = 0;
	for (int i = 0; i < 2*nums-1; i++)
	{
		total += huffmanTree[i].weight;
	}
	cout << "��ȨֵΪ" << total << endl;
	cout << "���ڵ��ȨֵΪ" << huffmanTree[root].weight;
}
#endif 

