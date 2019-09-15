#ifndef INTEGER_SET_H
#define INTEGER_SET_H
class IntegerSet
{
private:
	int set[101];
	int validEntry( int x) const
	{
		return(x>=0&&x<=100);
	}//�����ж������Ƿ���Ч��ͬ������Ѻ������������� ʹ֮���inline �������Լ��ٺ������ô��� ���Ч��
public:
	IntegerSet()
	{
		emptySet();
	} //���ٺ����ĵ��� ���� inline �ķ�ʽ
	IntegerSet(int[],int);
	IntegerSet unionOfSets(const IntegerSet&); //ע�� const ���÷�
	IntegerSet intersectionOfSets(const IntegerSet&);
	void emptySet();
	void inputSet();
	void insertElement(int);
	void deleteElement(int);
	void printSet()const;
	bool isEqualTo(const IntegerSet&) const;
};
#endif
