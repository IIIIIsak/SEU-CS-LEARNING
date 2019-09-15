#ifndef SEQQUEUE_H
#define SEQQUEUE_H
#include<iostream>
using namespace std;
const int defaltSize = 20;
template<class T>
class SeqQueue
{
public:
	SeqQueue(int size = defaltSize);
	~SeqQueue();
	bool isEmpty()
	{
		if (front == rear)
			return true;
		else
			return false;
	}
	bool isFull()
	{
		if ((rear + 1) % maxSize == front)  //�����β�ڶ�ͷ��ǰ�棬�Ӷ�β����
			return true;
		else
			return false;
	}
	bool enQueue(const T& x); //����
	bool deQueue(T& x); //����
	bool getFront(T& x);  //ȡ����ͷ
	void makeEmpty()
	{
		front = rear = 0;
	}
private:
	int maxSize;
	int front;
	int rear;
	T * element;
};
template<class T>
SeqQueue<T>::SeqQueue(int size) :maxSize(size),front(0),rear(0)
{
	//���붯̬����
	element = new T[maxSize];
	if (element == nullptr)
	{
		cout << "����ռ�ʧ��";
		exit(1);
	}
}
template<class T>
SeqQueue<T>::~SeqQueue()
{
	if (element != nullptr)
	{
		delete[] element;
		element = nullptr;
	}
}
template<class T>
bool SeqQueue<T>::enQueue(const T& x)
{
	if (isFull())
		return false;
	else
	{
		
		element[rear] = x;
		rear = (rear + 1) % maxSize;
		return true;
	}
}
template<class T>
bool  SeqQueue<T>::deQueue(T& x)
{
	if (isEmpty())
		return false;
	else
	{
		x = element[front];
		front = (front + 1) % maxSize;
	}
}
template<class T>
bool  SeqQueue<T>::getFront(T& x)
{
	if (isEmpty())
		return false;
	else
	{
		x = element[front];
	}
}
#endif // !SEQQUEUE_H
#pragma once
