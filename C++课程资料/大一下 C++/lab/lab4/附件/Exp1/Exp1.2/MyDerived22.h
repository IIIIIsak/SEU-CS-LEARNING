#ifndef MYDERIVED22_H
#define MYDERIVED22_H
#include"MyDerived2.h"
using std::cout;
using std::endl;
class MyDerived22 : public MyDerived2
{
	 MyBase1 a1;//����̳еõ��Ͱ�����õ��Ķ�����ͬ����ʲôЧ���� ��ʵ֤����ͬʱͨ���̳кͰ����õ�ͬһ���ࣨ���������MyBase1�����ǹ��棬���Ҵӹ����˳���Ͽ� �����ϡ����ڡ����ס� ��������˳��͹����˳�������෴
public:
	MyDerived22()
	{
		cout<<"...Second layer derived Object is created"<<endl;
	}
	~MyDerived22()
	{
		cout<<"...Second layer derived Object is destroyed"<<endl;
	}
};
#endif