#include"RationalList.h"
#include<iostream>

using namespace std;
RationalList::RationalList(int x, int y, int c ):n(x),m(y),count(c),rList(n/m)
{
	if (y == 0 || c <= 0)
	{
		cout << "����ĳ�ʼ��������" << endl;
		exit(1);
	}
	//������������
	int remainder = x % y;
	int dividend = x / y;
	if (remainder == 0)
	{
		return;
	}

	//����С�����ֵĵ�һλ
	dividend = (remainder * 10) / m;
	remainder = (remainder * 10) % m;
	rList.insert(rList.getLength(), dividend);
	LinkList<int> lastR;
	int tempR = remainder;
	int tempD = dividend;
    lastR.insert(lastR.getLength(), tempR);  //�����е�������������,��ʼ�Ѿ�����С��λ��
	linkNode<int>* begin = nullptr;  //ѭ����ʼ��ָ��
	//����С������
	while (tempR != 0)  //��������Ϊ0��ʱ��
	{
		tempD = (tempR * 10) / m;
		tempR = (tempR * 10) % m;

		//�ж��Ƿ�ѭ����ͷ
		/*
		if(tempR==remainder && tempD==dividend)  //��������������ͬʱ��ͬ��,����ѭ��С��������,��ͷ��ʼѭ��
		{
			rList.getRear()->link = rList.getHead()->link;
			isCircle = true;
			break;
		}

		else if ( tempR == lastR && tempD == lastD)
		{
			rList.getRear()->link = rList.getRear();
			isCircle = true;
			break;
		}
		*/
		if (compare(lastR, tempR, tempD, begin))   //����ҵ�ѭ����
		{
			rList.getRear()->link = begin;
			isCircle = true;
			break;
		}
		rList.insert(rList.getLength(), tempD);
		lastR.insert(lastR.getLength(), tempR);
	}
	if (tempR == 0)
		isCircle = false;
	 
}

RationalList::~RationalList()
{

}
void RationalList::output(int c )  //Ĭ�ϴ�ӡһ��ѭ��
{
	if (c <= 0)
	{
		cout << "�����ѭ����������" << endl;
		return;
	}
	linkNode<int>* current = rList.getHead()->link;
	linkNode<int>* begin = rList.getRear()->link;
	cout << rList.getHead()->data;
	if (current == nullptr)  //���û��С������
		return;
	cout << ".";
    //��С������ ��ӡС���Ĳ�ѭ���Ĳ���
	while (current != nullptr && current != begin)
	{
		cout << current->data;
		current = current->link;
	}
	if (current == nullptr && !isCircle)
	{
		cout << "\n������С��";
		return;
	}
	for (int i = 0; i < c; i++)   //��ӡѭ������
	{
		cout << current->data;  //��ӡbegin��
		current = current->link;	
		//��ӡʣ�µ�
		while (current != nullptr && current != begin)
		{
			cout << current->data;
			current = current->link;
		}
	    if(i<c-1)  //���һ�δ�ӡ������
		{
			current = begin;   //ѭ��С���ֻص�ͷ��
		}
	}
	if (current == begin && isCircle)   //ѭ�����ӡ����
	{
		cout << "..." << endl;
		cout << "������ѭ��С����ѭ����Ϊ";
		cout << current->data;
		current = current->link;
		while (current != nullptr && current != begin)
		{
			cout << current->data;
			current = current->link;
		}
	}
	
}
bool RationalList::compare( LinkList<int> &lastR, int tempR, int tempD,linkNode<int>* &c)
{
	int l = 0;  //�Ѿ��ȽϵĴ���
	if (lastR.getLength() != rList.getLength())
	{
		cout << "���ֲ�֪������" << endl;
		return false;
	}
	else if (lastR.isEmpty() || rList.isEmpty())
		return false;
	else
	{
		linkNode<int>* currentR = lastR.getHead()->link;
		linkNode<int>* currentD = rList.getHead()->link;
		while (l < rList.getLength()&& currentD!=nullptr&& currentR!=nullptr)
		{
			if (currentD->data == tempD && currentR->data == tempR)
			{
				c= currentD;
				return true;
			}
			else
			{
				currentD = currentD->link;
				currentR = currentR->link;
				l++;
			}
		}
		return false;
	}

}
