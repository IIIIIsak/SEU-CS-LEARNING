#include<iostream>
#include"Polynomial.h"
using namespace std;
//int* m_iptrPolarray;
//int m_iMaxexponent;//����ʽ������ϵ���� �쳣ֵΪ-1
//char m_cX;   //����ʽÿһ��ķ���     ��ֵ ���쳣 ��ֵΪ0

Polynomial::Polynomial(const int t_iptrPolarray[], const int t_iMaxexponent, char t_cX )
{
	m_cX = t_cX;
	if (t_iptrPolarray == nullptr)
	{
		cout << "the polynomial has not been set \n";
		m_iptrPolarray = nullptr;
		m_iMaxexponent = -1;
		return;
	}
	setMaxexponent(t_iMaxexponent);
	if (getMaxexponent() == -1)
	{
		cout <<"the polynomial has not been set \n";
		m_iptrPolarray = nullptr;
		m_iMaxexponent = -1;
		return;
	}
	else
	{
		m_iptrPolarray = new int[getMaxexponent()+1];     //��һ����Ϊ����Ҫһ����0�η�
		for (int i = 0;i <= getMaxexponent();i++)    //+1��Ҫ©
			setTerms(i,t_iptrPolarray[i]);
	}

}
Polynomial::Polynomial(int t_x)
{
	m_cX = 'x';
	setMaxexponent(0);
	m_iptrPolarray = new int[getMaxexponent() + 1];
	setTerms(0, t_x);
}
Polynomial::Polynomial(const Polynomial& t_P)
{
	this->m_cX = t_P.m_cX;
	if (t_P.m_iptrPolarray == nullptr)
	{
		cout << "the polynomial has not been set \n";
		m_iptrPolarray = nullptr;
		m_iMaxexponent = -1;
		return;
	}
	setMaxexponent(t_P.m_iMaxexponent);
	if (getMaxexponent() == -1)
	{
		cout << "the polynomial has not been set \n";
		m_iptrPolarray = nullptr;
		m_iMaxexponent = -1;
		return;
	}
	else
	{
		m_iptrPolarray = new int[getMaxexponent() + 1];     //��һ����Ϊ����Ҫһ����0�η�
		for (int i = 0;i <= getMaxexponent();i++)    //+1��Ҫ©
			setTerms(i, t_P.m_iptrPolarray[i]);
	}
}
Polynomial::~Polynomial()
{
	m_cX = 'x';
	m_iMaxexponent = -1;
	delete[] m_iptrPolarray;
	m_iptrPolarray = nullptr;
}
ostream& operator<<(ostream& output, Polynomial t_P)
{
	if (t_P.getMaxexponent() == -1 || t_P.getWholepolynomial() == nullptr)
	{
		output << "This polynomial is invalid";
		return output;
	}
	else
	{
		if (t_P.getTerms(t_P.getMaxexponent()) != 0)
		{
			if(t_P.getTerms(t_P.getMaxexponent())>0)
				output<< t_P.getTerms(t_P.getMaxexponent()) << t_P.m_cX << "^" << t_P.getMaxexponent();
			else if(t_P.getTerms(t_P.getMaxexponent())<0)
				output << " + " << abs(t_P.getTerms(t_P.getMaxexponent())) << t_P.m_cX << "^" << t_P.getMaxexponent();
		}
		for (int i = t_P.getMaxexponent()-1;i >=0;i--)   //Ϊ�˴�ӡ�ĸ�ʽ
		{
			if (t_P.getTerms(i) != 0)
			{ 
				if(t_P.getTerms(i)>0)
					output <<" + "<< t_P.getTerms(i) << t_P.m_cX << "^" << i ;
				else if(t_P.getTerms(i)<0)
					output << " - " <<abs(t_P.getTerms(i)) << t_P.m_cX << "^" << i;
			}	
		}
		output << endl;
		return output;
	}
}
Polynomial& Polynomial::operator=(const Polynomial& t_P)
{
	this->m_cX = t_P.m_cX;
	if (t_P.m_iptrPolarray == nullptr)
	{
		cout << "the polynomial has not been set \n";
		m_iptrPolarray = nullptr;
		m_iMaxexponent = -1;
		return *this;
	}
	setMaxexponent(t_P.m_iMaxexponent);
	if (getMaxexponent() == -1)
	{
		cout << "the polynomial has not been set \n";
		m_iptrPolarray = nullptr;
		m_iMaxexponent = -1;
		return  *this;
	}
	else
	{
		m_iptrPolarray = new int[getMaxexponent() + 1];     //��һ����Ϊ����Ҫһ����0�η�
		for (int i = 0;i <= getMaxexponent();i++)    //+1��Ҫ©
			setTerms(i, t_P.m_iptrPolarray[i]);
		return *this;
	}
}
Polynomial Polynomial::operator+(const Polynomial& t_P)const
{
	Polynomial t_Presult(0);
	if (m_iptrPolarray == nullptr || m_iMaxexponent == -1 || t_P.m_iptrPolarray == nullptr || t_P.m_iMaxexponent == -1)
	{
		cout << "The add doesn't make";
		return t_Presult;
    }
	else
	{
		if (m_iMaxexponent > t_P.m_iMaxexponent)
			t_Presult.setMaxexponent(m_iMaxexponent);
		else
			t_Presult.setMaxexponent(t_P.m_iMaxexponent);
		t_Presult.m_iptrPolarray = new int[t_Presult.getMaxexponent() + 1];
		for (int i = 0;i <= t_Presult.getMaxexponent();i++)
		{
			t_Presult.setTerms(i, t_P.m_iptrPolarray[i] + this->m_iptrPolarray[i]);
		}
		return t_Presult;
	}
	   
}
Polynomial Polynomial::operator-(const Polynomial& t_P)const
{
	Polynomial t_Presult(0);
	if (m_iptrPolarray == nullptr || m_iMaxexponent == -1 || t_P.m_iptrPolarray == nullptr || t_P.m_iMaxexponent == -1)
	{
		cout << "The add doesn't make";       //�ж��Ƿ��ܹ����м���
		return t_Presult;
	}
	else
	{
		if (m_iMaxexponent > t_P.m_iMaxexponent)
			t_Presult.setMaxexponent(m_iMaxexponent);
		else
			t_Presult.setMaxexponent(t_P.m_iMaxexponent);
		t_Presult.m_iptrPolarray = new int[t_Presult.getMaxexponent() + 1];
		for (int i = 0;i <= t_Presult.getMaxexponent();i++)
		{
			t_Presult.setTerms(i, this->m_iptrPolarray[i]-t_P.m_iptrPolarray[i] );
		}
		return t_Presult;
	}
}
Polynomial Polynomial::operator*(const Polynomial& t_P)const
{
	Polynomial t_Presult(0);
	if (m_iptrPolarray == nullptr || m_iMaxexponent == -1 || t_P.m_iptrPolarray == nullptr || t_P.m_iMaxexponent == -1)
	{
		cout << "The add doesn't make";       //�ж��Ƿ��ܹ����м���
		return t_Presult;
	}
	else
	{
		t_Presult.setMaxexponent(m_iMaxexponent + t_P.m_iMaxexponent );
		t_Presult.m_iptrPolarray = new int[t_Presult.getMaxexponent()+1];
		for (int i = 0;i <= t_Presult.getMaxexponent();i++)          //Ĭ�Ϲ��������ָ��Ϊ�� ����������ȫ�����ó�0
		{
			t_Presult.setTerms(i, 0);
		}
		for (int i = 0;i<=getMaxexponent();i++)
		{
			if (this->getTerms(i) != 0)
			{
				for (int j = 0;j <= t_P.getMaxexponent();j++)
				{
					if(t_P.getTerms(j)!=0)
					t_Presult.addTerms(i + j, this->m_iptrPolarray[i] * t_P.m_iptrPolarray[j]);
				}
			}
		}
		return t_Presult;
	}
}
Polynomial& Polynomial::operator+=(const Polynomial& t_P)
{
	Polynomial t_Presult(0);
	if (m_iptrPolarray == nullptr || m_iMaxexponent == -1 || t_P.m_iptrPolarray == nullptr || t_P.m_iMaxexponent == -1)
	{
		cout << "The add doesn't make";
		return *this;
	}
	else
	{
		if (m_iMaxexponent > t_P.m_iMaxexponent)
			t_Presult.setMaxexponent(m_iMaxexponent);
		else
			t_Presult.setMaxexponent(t_P.m_iMaxexponent);
		t_Presult.m_iptrPolarray = new int[t_Presult.getMaxexponent() + 1];
		for (int i = 0;i <= t_Presult.getMaxexponent();i++)
		{
			t_Presult.setTerms(i, t_P.m_iptrPolarray[i] + this->m_iptrPolarray[i]);
		}
		return *this= t_Presult;
	}
}
Polynomial& Polynomial::operator-=(const Polynomial& t_P)
{
	Polynomial t_Presult(0);
	if (m_iptrPolarray == nullptr || m_iMaxexponent == -1 || t_P.m_iptrPolarray == nullptr || t_P.m_iMaxexponent == -1)
	{
		cout << "The add doesn't make";       //�ж��Ƿ��ܹ����м���
		return *this;
	}
	else
	{
		if (m_iMaxexponent > t_P.m_iMaxexponent)
			t_Presult.setMaxexponent(m_iMaxexponent);
		else
			t_Presult.setMaxexponent(t_P.m_iMaxexponent);
		t_Presult.m_iptrPolarray = new int[t_Presult.getMaxexponent() + 1];
		for (int i = 0;i <= t_Presult.getMaxexponent();i++)
		{
			t_Presult.setTerms(i, this->m_iptrPolarray[i] - t_P.m_iptrPolarray[i]);
		}
		return *this=t_Presult;
	}
}
Polynomial& Polynomial::operator*=(const Polynomial& t_P)
{
	Polynomial t_Presult(0);
	if (m_iptrPolarray == nullptr || m_iMaxexponent == -1 || t_P.m_iptrPolarray == nullptr || t_P.m_iMaxexponent == -1)
	{
		cout << "The add doesn't make";       //�ж��Ƿ��ܹ����м���
		return *this;
	}
	else
	{
		t_Presult.setMaxexponent(m_iMaxexponent + t_P.m_iMaxexponent);
		t_Presult.m_iptrPolarray = new int[t_Presult.getMaxexponent()+1];
		for (int i = 0;i <= t_Presult.getMaxexponent();i++)          //Ĭ�Ϲ��������ָ��Ϊ�� ����������ȫ�����ó�0
		{
			t_Presult.setTerms(i, 0);
		}
		for (int i = 0;i <= getMaxexponent();i++)
		{
			if (this->getTerms(i) != 0)
			{
				for (int j = 0;j <= t_P.getMaxexponent();j++)
				{
					if (t_P.getTerms(j) != 0)
						t_Presult.addTerms(i + j, this->m_iptrPolarray[i] * t_P.m_iptrPolarray[j]);
				}
			}
		}
		return *this=t_Presult;
	}
}