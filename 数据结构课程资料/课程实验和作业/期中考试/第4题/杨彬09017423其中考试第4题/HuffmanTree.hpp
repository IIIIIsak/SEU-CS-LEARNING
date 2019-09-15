#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H
#include"MinHeap.hpp"
struct HuffmanNode
{
	float data;
	HuffmanNode* LChild, *RChild,*parent;
	HuffmanNode() :LChild(nullptr), RChild(nullptr), parent(nullptr) {}
	HuffmanNode(float elem, HuffmanNode* left=nullptr, HuffmanNode* right=nullptr,HuffmanNode* pr=nullptr):data(elem),LChild(left),RChild(right),parent(pr)
	{}
	bool operator<=(HuffmanNode& R) { return data <= R.data; }
	bool operator>(HuffmanNode& R) { return data > R.data; }
};
class HuffmanTree
{
public:
	HuffmanTree(float w[], int n); //���캯��
	//~HuffmanTree(); //��������
	int getWeightLength()
	{
		return getWeightLength(root, 0);
	}
protected:
	HuffmanNode* root;
	//void deleteTree(HuffmanNode* t);
	void mergeTree(HuffmanNode& ht1, HuffmanNode& ht2, HuffmanNode* & parent);
	int getWeightLength(HuffmanNode* subTree, int length);
	
};
HuffmanTree::HuffmanTree(float w[], int n)
{
	root = NULL;
	MinHeap<HuffmanNode> hp;
	HuffmanNode*  parent=nullptr; 
	HuffmanNode  first;
	HuffmanNode  second;
	HuffmanNode  work;
	for (int i = 0; i < n; i++)
	{
		work.data = w[i];
		work.LChild = nullptr;
		work.RChild = nullptr;
		work.parent = nullptr;
		hp.Insert(work);
		
	}
	for (int i = 0; i < n - 1; i++)
	{
		hp.RemoveMin(first);
		hp.RemoveMin(second);
		mergeTree(first, second, parent);
		hp.Insert(*parent);
	}
	root = parent;
}
void HuffmanTree::mergeTree(HuffmanNode& bt1, HuffmanNode& bt2, HuffmanNode* & parent)
{
	parent = new HuffmanNode;
	parent->LChild = &bt1;
	parent->RChild = &bt2;
	parent->data = bt1.data+bt2.data;
	bt1.parent = bt2.parent = parent;
	
}
int HuffmanTree::getWeightLength(HuffmanNode* subTree, int length)
{
	if (subTree == nullptr)  //����ǿսڵ�Ļ�����0;
	{
		return 0;
	}
	if (!( subTree->LChild == nullptr && subTree->RChild == nullptr ))  //�������Ҷ�ӽڵ�
	{
		return getWeightLength(subTree->LChild, length + 1) + getWeightLength(subTree->RChild, length + 1);
	}
	else
	{
		return subTree->data *length;    //����Ȩֵ����·����
	}
}
#endif