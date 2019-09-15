#include<iostream>
#include<cstring>
#include<cassert>
#include"String.h"
using namespace std;

String::String(const char* const s)
{
	length = strlen(s);
	sPtr = new char[length + 1];
	strcpy_s(sPtr, length + 1, s);
	return;
}
String::String(const String &s)
{
	length=s.length;
	if(sPtr!=NULL)
	{delete[]sPtr;
	sPtr=NULL;}
	sPtr=new char[length+1];
	strcpy_s(sPtr,length+1,s.sPtr);
	return;
}
String::~String()
{
	delete[] sPtr;
   sPtr=NULL;
}
const String& String:: operator=(const String& s) 
{
 	length=s.length;
	if(sPtr!=NULL)
	{delete[]sPtr;
	sPtr=NULL;}
    sPtr=new char[length+1];
	strcpy_s(sPtr,length+1,s.sPtr);
	return *this;
}    // ????
  String& String:: operator+(const String &s) const
{
    static String temp;//����Ҫ��static ���� ��������ٵ���һ��+����Ļ����ܻ��ͬһ���ڴ��ٽ���new ����
	if(temp.sPtr!=NULL)
	{
		delete[]temp.sPtr;
	    temp.sPtr=NULL;
	}
	temp.length=length+s.length;
	temp.sPtr=new char[temp.length+1];
	if(temp.sPtr!=NULL)
	{
		strcpy_s(temp.sPtr,temp.length+1,sPtr);
	    strcat_s(temp.sPtr, temp.length + 1,s.sPtr);
	}
	else
		cout<<"fail";
	return temp;               //���������������¾ֲ������������� 2�����ⷵ�ؾֲ����������û���ָ�� �ڴ�й¶����
}
ostream& operator<<(ostream &output,const String &s)
{
	output<<s.sPtr;
	return output;
}

	

