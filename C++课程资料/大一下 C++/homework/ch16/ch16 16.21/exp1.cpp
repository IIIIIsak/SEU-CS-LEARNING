#include<iostream>
#include"TestException.h"
using namespace std;
void throwException()
{
	try
	{
		cout << " Function throwException throws an exception\n";
		throw TestException();
	}
	catch (TestException& test)
	{
		cout << "Exception handled in function throwException"
			<< "\n Function throwException rethrow exception\n";
		cout << test.what()<<endl;
		throw;                              //��throw ��俪ʼ����ֱ����ת����һ���� try catch ������ ���Ҳ���ִ�� throw ֮������
		
		
	}
	cout << "The end of the function throwException";
}
int main()
{
	cout << "This is a test"<<endl;
	try
	{
		cout << "\nmain invokes function throwexception\n";
		throwException();
		cout << "The end of the try block in main\n";
	}
	catch (TestException& test)
	{
		cout << "\n\nException handled in main\n";
		//cout << "\nrethrow exception in main";
		cout << test.what();
	}   //�������������׳��쳣
	cout << "The end of the test\n";
	system("pause");
}