#include"BinaryTree.h"
#include<iostream>
#include<fstream>
#include"Stack.hpp"
#include<cmath>
#include<iomanip>
using namespace std;
BinaryTree::BinaryTree (T ref)
{
	root = nullptr;
	treeMatrix = NULL;
	refValue = ref;
	height=0;
	cols=0;
}
BinaryTree::~BinaryTree()
{
	deleteTree(root);
	for (int i = 0; i < height; i++)
	{
		if (treeMatrix[i] != NULL)
		{
			delete[] treeMatrix[i];
			treeMatrix[i] = NULL;
		}

	}
	if (treeMatrix != NULL)
		delete[] treeMatrix;
}

void BinaryTree::printNode(BinTreeNode* p)
{
	if (p != nullptr)  //������ǿ�ָ��                                                                                                        
	{
		cout << ".." << p->data;
	}
}
void BinaryTree::creatBinTree(ifstream&  fin, BinTreeNode*& subTree)
{
	T p;
    if(fin>>p)   //��������ļ���β�Ļ�
	{
		
		if (p != refValue)//�����������ݲ�����սڵ�,�ݹ����������
		{
			//�������ڵ�
			subTree = new BinTreeNode(p);
		    //�ݹ齨��������
			creatBinTree(fin, subTree->leftChild);
			//�ݹ齨��������
			creatBinTree(fin, subTree->rightChild);

		}
		else
		{
			return;   //�ݹ����
		}
	}
	else
	{
		return;
	}
}
void  BinaryTree::inOrder(BinTreeNode* subTree, void(*visit)(BinTreeNode* p))   //�������
{
	if (subTree == NULL)  //�ݹ����������
		return;
    //�ȵݹ����������
	inOrder(subTree->leftChild, visit);
	//���ʸ��ڵ�
	visit(subTree);
	//�ݹ����������
	inOrder(subTree->rightChild, visit);
}
void BinaryTree::printTreeInOrder(BinTreeNode* subTree)
{
	if (subTree == NULL) //�ݹ����������
		return;

	//�������Ҷ�ڵ�Ļ������ռλ��


	//�ȴ���������ʼ����
	printTreeInOrder(subTree->rightChild);
	//������ڵ�
	int k;
	if (getLength(root, subTree, k))
	{
		for (int i = 0; i <  k; i++)
			cout << "   ";
	}
	printNode(subTree);
	cout << endl;

	//�ݹ����������
	printTreeInOrder(subTree->leftChild);
  
}

int BinaryTree::getHeight(BinTreeNode* subTree)
{
	if (subTree == NULL)   //�ݹ����������
		return 0;
	else
		//����ݹ� ������1�����ڵ�ĸ߶ȣ� + ������������ߵ��Ǹ�
		return 1 + Max<T>(getHeight(subTree->leftChild), getHeight(subTree->rightChild));
}

//���ڶ�ջ����Ľڵ㣬���ӽڵ��ǵڼ���ĵڼ����Լ�����ȫ�������µ���ŵ���Ϣ
struct stackNode
{
	BinTreeNode* node;
	int id;
	int row;
	int col;
	stackNode(BinTreeNode* n, int r, int i):node(n),row(r),id(i)
	{
	    col=id-(pow(double(2),r-1)-1);
	}

};
bool BinaryTree::turnToMatrix()
{
	//��������ָ�벻�ǿվͷ���false 
	if (treeMatrix != NULL)
	{
		cout << "�Ѿ�ת��Ϊ������" << endl;
		return false;
	}
	//������ջ,������Žڵ��Լ��ڵ��һЩ�ؼ���Ϣ
    Stack<stackNode> nodeStack;
	//������̬��ά����
	//��ȡ����
	 height = getHeight();
	 cols = static_cast<int>(pow(double(2),height));
	treeMatrix = new T*[height];
	if (treeMatrix == NULL)
	{ 
		cout << "���󴴽�ʧ��" << endl;
		return false;
	}
	for (int i = 0; i < height; i++)
	{
		treeMatrix[i] = new T[cols];
		if (treeMatrix == NULL)
		{
			cout << "���󴴽�ʧ��" << endl;
			return false;
		}
	}
	//�Ծ�����г�ʼ����ȫ������0
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<cols;j++)
		{
			treeMatrix[i][j]=refValue;
		}
	}

	//���õ���ʱ����
	//��topNode���г�ʼ��
	//�ڵ��ڵڼ���
//�ڵ�����ȫ������������Ӧ�����
	stackNode topNode(root,1,1);
    //�����ڵ�ѹջ
    nodeStack.push(topNode);
	//ѭ��
	while (!nodeStack.isEmpty() && topNode.node!=NULL)
	{
        //��������(��node���з��ʣ�
	    //���ʵ����
		int j=int(pow(double(2),height-topNode.row))+(topNode.col-1)*int(pow(double(2),height-topNode.row+1))-1;
		treeMatrix[topNode.row-1][j]=topNode.node->data;
		//�������������ջ
        if(topNode.node->rightChild!=NULL)  //�п�
		{
			//���ջ
			stackNode tempNode(topNode.node->rightChild, topNode.row+1,topNode.id*2+1);
			nodeStack.push(tempNode);

		}
		//׼������������
		if(topNode.node->leftChild!=NULL)
		{
			//ȡ���ڵ��topNode��ֵ
			stackNode tempNode(topNode.node->leftChild, topNode.row +1, topNode.id *2);
		    topNode=tempNode;
		}
		else
		{
			//�˶�ջ
			nodeStack.pop(topNode);
			
		}
	}
	return true;
}
void  BinaryTree::printTreeMatrix()
{
	if(treeMatrix==NULL)
	{
		cout<<"��û�н�������"<<endl;
	}
	else
	{
		//�ٽ���һ����ʱ����
	int** printMatrix= new int*[height];
	if (printMatrix == NULL)
	{ 
		cout << "���󴴽�ʧ��" << endl;
		return;
	}
	for (int i = 0; i < height; i++)
	{
		printMatrix[i] = new int[cols];
		if (printMatrix == NULL)
		{
			cout << "���󴴽�ʧ��" << endl;
			return;
		}
	}
   //�Ա���������
	for(int i=0;i<height;i++)
	{
		int step=int (pow(double(2),height-i-2));
		
		for(int j=0;j<cols;j++)
		{
			
			if(i<height-1)  //��һ������
			{
				bool isLDot=false;
				bool isRDot = false;
				int leftBegin=0;
				int rightEnd=0;
				if(treeMatrix[i][j]!=refValue)
				{

					printMatrix[i][j]=2;
					if(treeMatrix[i+1][j-step]!=refValue) //�����������
					{
						leftBegin=j-step;
						isLDot=true;
					}
					else
					{
						isLDot=false;
						leftBegin=j+1;
					}
					if(treeMatrix[i+1][j+step]!=refValue)  //�����������
					{
						isRDot=true;
						rightEnd=j+step;
					}
					else
					{
						isRDot=false;
						rightEnd=j-1;
					}
					if(isLDot||isRDot)
					{
						for(int p=leftBegin;p<=rightEnd;p++)
						{
							if(printMatrix[i][p]!=2)
							    printMatrix[i][p]=1;
						}
						//����j
						j=rightEnd+1;
					}
					
				
				}
				else
					printMatrix[i][j]=0;
			}
			else   //���һ������
			{
				if(treeMatrix[i][j]!=refValue)
					printMatrix[i][j]=2;
				else
					printMatrix[i][j]=0;

			}
		
		}
	}
	ofstream fout;
	fout.open("BinaryTreeOutput.txt", ios::out);
	if (!fout.is_open())
	{
		cout << "�ļ����ʧ�ܣ�";
		fout.close();
	}
  //����print�������
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<cols;j++)
		{
			switch(printMatrix[i][j])
			{
			case 0:
				cout<<" ";
				fout <<" ";
				break;
			case 1:
				cout<<".";
				fout << ".";
			    break;
			case 2:
				cout<<treeMatrix[i][j];
				fout << treeMatrix[i][j];
				break;
			default:
				cout<<" ";
				fout << " ";
			}
		}
		cout<<endl;
		fout << endl;
		//���ֱ��
		if (i + 1 < height)
		{
			for (int j = 0; j < cols; j++)
			{
				switch (printMatrix[i + 1][j])
				{
				case 0:
				case 1:
					cout << " ";
					fout << " ";
					break;
				case 2:
					cout << "|";
					fout << "|";
					break;
				default:
					cout << " ";
					fout << " ";
				}
			}
			cout << endl;
			fout << endl;
		}
		
	}
	fout.close();
	//delete
	for(int i=0;i<height;i++)
	{
		if(printMatrix[i]!=NULL)
			delete[] printMatrix[i];
		printMatrix[i]=NULL;
		
	}
	if(printMatrix!=NULL)
		delete[] printMatrix;
	}
}

void  BinaryTree::deleteTree(BinTreeNode* &subTree)
{
	if(subTree==NULL)
		return ;
	if(subTree->leftChild==NULL&& subTree->rightChild==NULL)  //�ݹ�ɾ��
	{
		delete subTree;
		subTree = NULL;
		return ;
	}
	else
	{
		deleteTree(subTree->leftChild);
		deleteTree(subTree->rightChild);
		delete subTree;
		subTree = NULL;
	}
}
bool BinaryTree::getLength(BinTreeNode* subTree, BinTreeNode* node, int& length) //����ĳһ�ڵ㵽����ڵ�ľ���
{
	if (subTree == NULL)
	{
		length = 0;
		return false;
		
	}
	if (node == NULL)
	{
		length = 0;
		return false;
	}
    //�ݹ��������
	if (subTree == node)
	{
		length = 0;
		return true;
	}
	else if (subTree->leftChild == node || subTree->rightChild == node)
	{
		length = 1;
		return true;
		
	}
	else
	{
		int length1;
		if (getLength(subTree->leftChild, node, length1))
		{
			length = 1 + length1;
			return true;

		}
		else if (getLength(subTree->rightChild, node, length1))
		{
			length = 1 + length1;
			return true;
			
		}
		else
			return false;
	}
	    
}