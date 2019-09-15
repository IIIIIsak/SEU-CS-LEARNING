#include<iostream>;
#include<ctime>;
#include<cstdlib>;
using namespace std;
int swapPosRighit(int firstPos, int lastPos, int a[])// firstPos ��ʾһ�����е���ʼ��λ�ã�
{
	int pos =firstPos;
	int i= lastPos;
	for (i;i > firstPos;i--)
	{
		if (a[firstPos] >a[i])
		{
			pos = i;
			int temp = a[pos];
			a[pos] = a[firstPos];  //�ҵ���һ������С�������ҽ�����������λ�ã�Ȼ�󷵻���λ�ã�
			a[firstPos] = temp;
			break;
		}
	}
	
	return pos;
}
int swapPosLeft(int firstPos, int lastPos, int a[])
{
	int pos = lastPos;
	int i = firstPos;
	for (i;i < lastPos;i++)
	{
		if (a[lastPos] < a[i])
		{
			pos = i;
			int temp = a[pos];
			a[pos] = a[lastPos];
			a[lastPos] = temp;
			break;
			
		}
	}
	
	return pos;
}
void quicksort(int firstPos, int lastPos,int a[])
{
	
	if (firstPos >= lastPos)  //�߽�ֻʣ��һ������ʱ��
		return;
	else
	{
		int firstswap = firstPos; int lastswap = lastPos;int finalPos=firstPos;
		int flag1 = 1, flag2 = 1;//����С���������ж��Ƿ����˽���������û�н�����Ҳ����˵�������߶�����С�ұ߶�������ʱ������ѭ����
		while (flag1==1&&flag2==1)
		{
			if (finalPos < lastswap)
			{
				firstswap = finalPos + 1;
				finalPos = swapPosRighit(finalPos, lastswap, a);
			}
			else
				flag1 = 0;
			if (finalPos > firstswap)
			{
				lastswap = finalPos - 1;
				finalPos = swapPosLeft(firstswap, finalPos, a);
			}
			else
				flag2 = 0;
		}
		quicksort(firstPos, finalPos - 1, a);
		quicksort(finalPos + 1, lastPos, a);
	}
}
bool Text(const int a[],const int SIZE)
{
	int flag = 1;
	for (int i = 0;i < SIZE - 1;i++)
	{
		if (a[i] > a[i + 1])
			flag = 0;
	}
	if (flag == 1)
		return true;
	else
		return false;
}
int main()
{
	srand(time(0));
	const int SIZE =30;
	int a[SIZE];
	for (int i = 0;i < SIZE;i++)
	{
		a[i] = rand() % 100;
	}
	cout << "The origianl number series is" << endl;
	for (int i = 0;i < SIZE;i++)
		cout << a[i]<<" ";
	cout << endl;
	if (Text(a,SIZE))
		cout << "The result of the text is that the number series has Been sorted" << endl;
	else
		cout<< "The result of the text is that the number series has NOT Been sorted" << endl;
	quicksort(0, SIZE - 1, a);
	cout << "\nThe number series after sorting is"<<endl;
	for (int i = 0;i < SIZE;i++)
		cout << a[i]<<" ";
	cout << endl;
	if (Text(a,SIZE))
		cout << "The result of the text is that the number series has Been sorted" << endl;
	else
		cout << "The result of the text is that the number series has NOT Been sorted" << endl;
	system("pause");
	return 0;
	
}