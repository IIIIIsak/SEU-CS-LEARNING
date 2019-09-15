#include "Chess.h"
#include<iostream>
#include<iomanip>
using namespace std;
Chess::Chess( int s)
{
	
	if (s < 4)
	{
		cout << "���̵Ĵ�С̫С" << endl;
		exit(1);
	}
	size = s;
	//����ռ�
	chess = new int* [size];
	for (int i = 0; i < size; i++)
	{
		chess[i] = new int[size];
	}
	//��ʼ��
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			chess[i][j] = 0;
		}
	}

}


Chess::~Chess()
{
	if (chess != nullptr)
	{
		for (int i = 0; i < size; i++)
		{
			if (chess[i] != nullptr)
			{
				delete[]chess[i];
				chess[i] = nullptr;
			}
		}
		delete[]chess;
		chess = nullptr;
	}
}

bool  Chess::Horse(int x,int y)  //������ʿ���Σ����εĽ�������������С�
{
	return Horse(x, y, 1);
}
void Chess::remake(int s)  //���������߳�Ϊsize������
{
	//��ԭ����ɾ��
	if (s < 4)
	{
		cout << "���̵Ĵ�С̫С" << endl;
		return;
	}
	if (chess != nullptr)
	{
		for (int i = 0; i < size; i++)
		{
			if (chess[i] != nullptr)
			{
				delete[]chess[i];
				chess[i] = nullptr;
			}
		}
		delete[]chess;
		chess = nullptr;
	}
	size = s;
	//����ռ�
	chess = new int*[size];
	for (int i = 0; i < size; i++)
	{
		chess[i] = new int[size];
	}
	//��ʼ��
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			chess[i][j] = 0;
		}
	}
}
void Chess::makeEmpty()  //��������գ�������������
{
	//ȫ����Ϊ0
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			chess[i][j] = 0;
		}
	}
}

void Chess::printChess() //��ӡ����
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout <<resetiosflags(ios::right) <<setw(4) <<chess[i][j] << " ";
		}
		cout << endl<<endl;
	}
}

bool Chess::findHorsePath(int i1, int j1, int i2, int j2,int& length)
{
	//�ж��Ƿ�Ϸ�
	if (i1 < 0 || i1 >= size || i2 < 0 || i2 >= size || j1 < 0 || j1 >= size || j2 < 0 || j2 >= size)
	{
		cout << "���������յ㲻�Ϸ�" << endl;
		return false;
	}
	//�ȹ���һ����Ǿ��󣬺�chess���ֿ�
	int** path = new int*[size];
	for (int i = 0; i < size; i++)
	{
		path[i] = new int[size];
	}
	//��ʼ��
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			path[i][j] = 0;
		}
	}
	//�������Ϊ1;
	length = 0;
	//��ʼ����㿪ʼ��������
	growHorsePath(path, size, i1, j1, i2, j2, 0);  //���һ��������0

	//������ϣ����յ㿪ʼ������
	int tempI = i2, tempJ = j2;
	if (path[tempI][tempJ] <= 0)   //���û�ߵ�
	{
		length = -1;
		return false;
	}
	else
	{
		chess[tempI][tempJ] = path[tempI][tempJ];
		while (tempI != i1 || tempJ != j1)  //��û�ҵ��յ�
		{
			//��8������ʼ,�ض����ҵ�һ��
			for (int p = 0; p < 8; p++)
			{
				int i = tempI + offsetI[p], j = tempJ+offsetJ[p];
				//�ж��Ƿ�Խ��
				if (i < 0 || i >= size || j < 0 || j >= size)
					continue;
				else
				{
					if (path[i][j] == (path[tempI][tempJ] - 1))  //�ҵ����ڵľͿ���ֱ������ѭ��
					{
						chess[i][j] = path[i][j];
						tempI = i;
						tempJ = j;
						length++;
						break;  
					}
				}
			}
		}
		chess[i1][j1] = path[i1][j1];
		return true;
	}
}

bool Chess::Horse(int i, int j, int num)
{
    //�ݹ����������
	if (i < 0 || i >= size || j < 0 || j >= size)   //�������̷�Χ
		return false;
	else if (chess[i][j] != 0)    //�Ѿ����ʹ���
		return false;
	else if (chess[i][j] == 0 && num == size * size)  //���λ�û�û�з��ʶ��������һ��
	{
		chess[i][j] = num;
		return true;
	}
	else
	{ 
		//�ڰ˸�����ݹ�����
		//ֻ���ڳɹ��ҵ���Ӧ��·��֮��Ÿı����̵���ֵ
		chess[i][j] = num; //�����һ�����ʵ�λ��
		//��8������ݹ���̽
		//��̰���㷨���иĽ�
		direction d[8];
		for (int p = 0; p < 8; p++)   //������ܵķ���(��һ�����ܵ� i��j��
		{
			d[p].i = i + offsetI[p];
			d[p].j = j + offsetJ[p];
			d[p].count = countDirection(d[p].i, d[p].j);
		}
		insertSort(d, 8);  //��������
		for (int p = 0; p < 8; p++)
		{
			if (d[p].count > 0)
			{
				if (Horse(d[p].i, d[p].j, num + 1))  //�ɹ��ҵ�·��֪������true
				{
					return true;
				}
			}
		}
		//���ǰ���8������û����̽�ɹ�ִ�е���һ��
		chess[i][j] = 0;  //ȥ�����
		return false;  
	}
	
}
int Chess::countDirection(const int i, const int j) //������һ���˸�����ÿ�������Ӧ�Ŀ��ܵ��߷�
{
	int count = 0;
	if (i < 0 || i >= size || j < 0 || j >= size)
		return count;
	count++;  //�����Լ������
	for (int p = 0; p< 8; p++)  //����8����������ߵķ���
	{
		int tempI = i + offsetI[p];
		int tempJ = j + offsetJ[p];
		if (tempI >= 0 && tempI < size && tempJ >= 0 && tempJ < size && chess[tempI][tempJ] == 0)
			count++;
	}
	return count;
}
void Chess::insertSort(direction d[], const int n)  //�Է����������
{
	for (int i = 1;i < n; i++)
	{
		int pos = i;
		direction tempD = d[pos];
		while (pos > 0)
		{
			if (tempD.count < d[pos - 1].count)
			{
				d[pos] = d[pos - 1];
				pos--;
			}
			else
				break;
		}
		d[pos] = tempD;
	}
}
void Chess::growHorsePath(int** path, int size, int i1, int j1,int i2,int j2,int length)
{
	//��һ���㿪ʼ��������Χ�����ţ�������ͻʱȡС����һ�������ŵ������߽���ߵ���Ŀ�ĵؽ���
	if (i1 < 0 || i1 >= size || j1 < 0 || j1 >= size)  //���������
	{
		return;  //ֱ�ӷ���
	}
	else //û����
	{
		if (path[i1][j1] != 0 && path[i1][j1] <= length + 1)   //�����ǰ�㲻�ǿյĶ��ҵ�ǰ��ֵ��length+1��С�����������·��������Ҫ��������ȥ�ˣ�
		{
			return;   //����Ҫ��������,�ݹ��������֮һ
		}
		else  //��������
		{
			if (i1 == i2 && j1 == j2)  //��������յ���,���±�ǲ�����������
			{
				//���±��
				path[i1][j1] = length + 1;
				return;   
			}
			else
			{
				//���±��
				path[i1][j1] = length + 1;
				//�����ݹ���8����������
				for (int p = 0; p < 8; p++)
				{
					growHorsePath(path, size, i1 + offsetI[p], j1 + offsetJ[p], i2, j2, path[i1][j1]);  //ע�����һ�����������ǵ�ǰ��i1 j1
				}
			}

		}
	}
}

