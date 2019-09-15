#ifndef HUGEINT_H
#define HUGEINT_H
#include<iostream>
using std::ostream;
class HugeInt
{
	friend ostream& operator<<(ostream&, const HugeInt&);
public:
	HugeInt(long = 0);
	HugeInt(const char*);
	HugeInt operator +(const HugeInt&)const; //ע������û�з�������
	HugeInt operator +(int)const; //ֻ��ʹ�� HugeInt + int �����ܵߵ� ��Ϊ�ⲻ����Ԫ����
	HugeInt operator +(const char*)const;
	bool operator >(const HugeInt& a)const;
	bool operator >=(const HugeInt&)const;
	bool operator <(const HugeInt& )const;
	bool operator <=(const HugeInt& )const;
	bool operator !=(const HugeInt& )const;
	bool operator ==(const HugeInt& )const;
	int getlength()const
	{
		int length = n-1;
		while (integer[length] == 0 &&length>=0)     //��Ҫ����0����� ����ͳ�������ı߽���
		{
			length--;
		}
		return length>=0 ?(length + 1):1;
	}  //����Ҫ����ʹ�� ����ʹ��inline ����
private:
    static const int n = 30; //Ϊʲô����static ���У� ֻ������const �޶����ŵ�ʱ�����������Ϊstatic������ʼ��
	short integer[n]; //��short���͵ı�����ʡ�ռ�

};
#endif