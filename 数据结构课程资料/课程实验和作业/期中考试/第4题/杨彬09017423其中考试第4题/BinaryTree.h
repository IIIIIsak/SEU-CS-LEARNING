#ifndef BINARYTREE_H
#define BINARYTREE_H
#include<iostream>
#include"Stack.hpp"
using namespace std;
typedef char T;
struct BinTreeNode
{
	T data;
	BinTreeNode* leftChild;
	BinTreeNode* rightChild;
	BinTreeNode( T d, BinTreeNode* l=nullptr, BinTreeNode* r =nullptr):data(d),leftChild(l),rightChild(r)
	{}

};
//����ģ��
template<class Type>
inline Type Max(const Type a, const Type b)
{
	return( a > b ? a : b);
}
class BinaryTree
{
public:
	BinaryTree(T ref); //���캯������һ�ÿյĶ�����
	~BinaryTree();
	void creatBinTree(ifstream& fin)  //���ļ��ж�ȡ�������һ�ζ�����
	{
		creatBinTree(fin, root);
	}
	//ͻȻ����һ��˼��������������ֱ�����ʽ�Ļ����ܻ����visit�����ƻ����Ľṹ����Ϊvisit���Է�������
	//���Ҳ�û�ж�visit��������ʲô���ƣ���᲻�������ȫ����
	void inOrder(void(*visit)(BinTreeNode* p))   //�������
	{
		inOrder(root, visit);
	}

	void printTreeInOrder() //������������ķ�������Ļ�ϴ�ӡ��ӡ������
	{
		printTreeInOrder(root);
	}
	int  getHeight() //��ȡ���ߵĺ���
	{
		return getHeight(root);
	}
	bool turnToMatrix();
	void printTreeMatrix();

	int Height()
	{
		return height;
	}
	int getCols()
	{
		return cols;
	}
private:
	BinTreeNode* root; //���ڵ�
	T refValue;
	T ** treeMatrix;
	int height;
	int cols;
	void printNode(BinTreeNode* p);    //��ӡ�����ڵ�ĺ���
	void creatBinTree(ifstream& in, BinTreeNode*& subTree);
	void inOrder(BinTreeNode* subTree, void(*visit)(BinTreeNode* p));   //�������
	void printTreeInOrder(BinTreeNode* subTree);
	void deleteTree(BinTreeNode* &subTree);
	int getHeight(BinTreeNode* subTree);
	bool getLength(BinTreeNode* subTree, BinTreeNode* node,int &length);


};
#endif // !BINARYTREE_H

