#include"mineSweepGame.h"
#include<iostream>
using namespace std;
int main()
{
	cout<<"��ӭ����ɨ����Ϸ��ף����Ŀ��ģ�  made by ���"<<endl;
	cout << "��Ϸ��ʾ��#��ʾ��û��������������ֱ�ʾ���������Χ���׵���Ŀ����Ϸ������*��ʾ����";
	MineSweepGame myGame;
	bool isContinue=true;
	bool isGameContinue=false;
	int row=0,col=0;
	int isGameOver=-1;
	while(isContinue)
	{
		if (isGameContinue)
		{
			myGame.restartGame();
			isGameContinue = false;
		}
		cout<<"���ڼ�������������Ҫ��������������row ������col(r, c��1��ʼ)"<<endl;
		cin>>row>>col;
		myGame.click(row,col);
		isGameOver=myGame.isGameOver();
		myGame.reflashMineMatrix();
		cout<<endl;
		if(isGameOver==0)
		{
			cout<<"�����ˣ������Ƿ����������1 ������0 �˳���Ϸ"<<endl;
			int flag;
			cin>>flag;
			if(flag==1)
			{
				isContinue=true;
				isGameContinue=true;
			}
			else
			{
				isContinue=false;
				isGameContinue=false;
				break;
			}
			
		}
		else if (isGameOver == 1)
		{
			cout << "��Ӯ�ˣ������Ƿ����������1 ������0 �˳���Ϸ" << endl;
			int flag;
			cin >> flag;
			if (flag == 1)
			{
				isContinue = true;
				isGameContinue = true;
			}
			else
			{
				isContinue = false;
				isGameContinue = false;
				break;
			}
		}
		
	}
	cout<<"��л����!�����Ϸ�����������κ�bug���뼰ʱ��������ϵ��лл"<<endl;
	system("pause");
	return 0;
}