#include<iostream>
#include"Item.h"
using namespace std;
void test()
{
	cout << "The test function begins!\n\n";
	try
	{
		Item m_Iitem1(1);
		Item m_Iitem2(2);
		Item m_Iitem3(3);
	}
	catch (runtime_error&test)
	{
		cout << test.what() << '\n';     //��Ϊ�׳�����֮�� ����Ĺ��캯���Լ��޷����� �������ϼ�����Item3�Ĺ��캯��û����ȫִ����
	}                                    //Item3Ӧ��û�б����죬��ȻҲ���ᱻ������
	cout << "\n\nThe end of function test function\n"; 
	return;
}
int main()
{
	test();
	getchar();
}