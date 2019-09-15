#ifndef MINHEAP_H
#define MINHEAP_H
#include<iostream>
using namespace std;
const int defaultSize = 20;
template<class T>
class MinHeap
{
public:
	MinHeap(const int max);
	MinHeap(T arr[], int num, int max);
	~MinHeap();
	bool insert(const T &x);
	bool removeMin(T& x);
	bool isEmpty()const
	{
		return ( (currentSize == 0) ? true : false);
	}
	bool isFull()const
	{
		return ( (currentSize == maxSize) ? true : false);
	}
	void makeEmpty()
	{
		currentSize = 0;
	}
private:
	T* minHeap;
	int maxSize;
	int currentSize;
	void siftDown(int start, int end);
	void siftUp(int start);
};

template<class T>
MinHeap<T>::MinHeap(const int max)
{
	//ȷ�����Ŀռ�
	maxSize = ((defaultSize < max) ? max : defaultSize);
	//����ռ�
	minHeap = new T[maxSize];
	if (minHeap == nullptr)
	{
		cout << "��С�ѿռ����ʧ��!" << endl;
		return;
	}
	currentSize = 0;
}

template<class T>
MinHeap<T>::MinHeap(T arr[], int num, int max)
{
	//ȷ�����Ŀռ�
	maxSize = ((defaultSize < max) ? max : defaultSize);
	//�ж�
	if (num >= maxSize)
	{
		cerr << "�������Ŀ���ڶѵ������Ŀ������";
		exit(1);
	}
	//����ռ�
	minHeap = new T[maxSize];
	if (minHeap == nullptr)
	{
		cout << "��С�ѿռ����ʧ��!" << endl;
		return;
	}
	currentSize = 0;
	//�������������
	for (int i = 0; i < num; i++)
	{
		minHeap[i] = arr[i];
		currentSize++;
	}
    //��ʼ���µ���
	int currentSiftPos = (currentSize - 2) / 2;   //�����һ����Ҷ�ڵ㿪ʼ,currentSiftPos�����һ����Ҷ�ڵ���±�
	while(currentSiftPos>=0)
	{
		siftDown(currentSiftPos, currentSize - 1);  //�����µ���
		currentSiftPos--;
	}
}

template<class T>
MinHeap<T>::~MinHeap()
{
	if (minHeap != nullptr)
	{
		delete[]minHeap;
		minHeap = nullptr;
	}
}

template<class T>
bool MinHeap<T>::insert(const T &x)
{
	if (isFull())
	{
		cout << "��С���������޷�����" << endl;
		return false;
	}
	minHeap[currentSize] = x;
	currentSize++;
	siftUp(currentSize - 1);  //���ϵ���
	return true;
}

template<class T>
bool MinHeap<T>::removeMin(T& x)
{
	if (isEmpty())
	{
		cout << "��С���ǿյģ��޷�ɾ��";
		return false;
	}
	x = minHeap[0];
	minHeap[0] = minHeap[currentSize - 1];
	currentSize--;
	siftDown(0, currentSize - 1);
	return true;
}
template<class T>
void MinHeap<T>::siftDown(int start, int end)   //���϶��µ���,
//�������ǰ���Ǽ������ߵ��������Ѿ�����С����
{
	int currentSiftPos = start; //��ǰ���ڱȽϵĽڵ�
	int childPos = 2 * currentSiftPos + 1; //��ǰ�������
	T temp = minHeap[currentSiftPos];  //��ֵȡ����
	
	while (childPos <= end)  //�жϵ������ǻ�û�г�����Χ
	{
	    //���Һ��ӱȽϣ�ѡһ��С��ֵ
		if(childPos<end)    //��������Һ��ӵĻ�
		childPos = ((minHeap[childPos] <= minHeap[childPos + 1]) ? childPos : childPos + 1);
		if (temp <= minHeap[childPos])    //�����ǰ�Ľڵ�����ĺ��Ӷ�С�����õ�����
			break;
		else
		{
			//��С��ֵ�ϸ�
			minHeap[currentSiftPos] = minHeap[childPos];
			currentSiftPos = childPos;
			childPos = 2 * currentSiftPos + 1;
		}

	}
	//��ԭ����ֵ��λ
	minHeap[currentSiftPos] = temp;
} 

//���¶��ϵ���,���¶����㷨���������������Ѿ�����С��
template<class T>
void MinHeap<T>::siftUp(int start)
{
	int currentSiftPos = start; 
	T temp = minHeap[currentSiftPos]; //ȡ����ǰ��ֵ
	int parentPos = (currentSiftPos - 1) / 2; //���ڵ��ֵ
	while (currentSiftPos > 0)   //�����������ڵ�
	{
		if (temp >= minHeap[parentPos])  //����ȸ��ڵ��,���õ�����
			break;
		else
		{
			minHeap[currentSiftPos] = minHeap[parentPos];  //��Ľڵ��³�
			currentSiftPos = parentPos;
			parentPos = (currentSiftPos - 1) / 2;
		}
	}
	//��Ϊ
	minHeap[currentSiftPos] = temp;
}
#endif // !MINHEAP_H

