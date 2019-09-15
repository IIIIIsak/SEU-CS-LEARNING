#ifndef STRING_H
#define STRING_H
#include<iostream>
using std::cout; //����д�ھ���֮��
using std::ostream;
#include<cstring>
#include<cassert> //�ṩ��assert�Ķ��� �ڳ���ؼ��ط�ʹ���������ж��ԡ����һ�����Ա�֤��Ϊ�棬�����ڱ�׼�����������һ���ʵ�����ʾ��Ϣ������ִ���쳣��ֹ
class String
{
	friend ostream& operator<<(ostream &output,const String &s);
public:
	String(const char* const s="");//�Ȳ��ܸı�ָ��ָ������ݣ�Ҳ���ܸı�ָ���ָ��,Ĭ�Ϲ��캯��
	String(const String&);//���ƹ��캯��
	~String();
	const String& operator=(const String& );
	 String& operator+(const String&)const;
private:
	char *sPtr;
	int length;
};
#endif