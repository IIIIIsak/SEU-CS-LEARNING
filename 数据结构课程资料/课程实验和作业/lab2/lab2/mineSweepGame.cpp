#include"mineSweepGame.h"
#include<iostream>
#include<limits.h>
#include<ctime>
#include<stdlib.h>
#include<iomanip>
using namespace std;
MineSweepGame::MineSweepGame()
{   

	{
		move[0].iOffest=-1;
		move[0].jOffset=-1;
		
		move[1].iOffest=-1;
		move[1].jOffset= 0;
		
		move[2].iOffest=-1;
		move[2].jOffset=1;
		
		move[3].iOffest=0;
		move[3].jOffset=-1;
		
		move[4].iOffest=0;
		move[4].jOffset=1;
		
		move[5].iOffest=1;
		move[5].jOffset=-1;
		
		move[6].iOffest=1;
		move[6].jOffset=0;
		
		move[7].iOffest=1;
		move[7].jOffset=1;
		}
	chooseLevel();
	if(m_mineNum>m_mineSizeA*m_mineSizeB)  //������׵���Ŀ����
	{
		cerr<<"���׵���Ŀ���࣬��Ϸ����ʧ��"<<endl;
		exit(1);
	}
	// �ȴ�����̬��ά����
	m_mineMatrix= new int* [m_mineSizeA];	  
	if(m_mineMatrix==NULL)
	{
		cerr<<"ɨ����Ϸ���󴴽�ʧ�ܣ�/n";
		exit(1);
	}
	else
	{
		for(int i=0;i<m_mineSizeA;i++)
		{
			m_mineMatrix[i]=new int[m_mineSizeB];
		}
	}
    //��ʼ����Ϸ��ôijieshu
	m_isGameOver=-1; 
	m_isClicked=0; //һ��ʼû�е㱻���
	//�����
	creatMine();
	reflashMineMatrix();
}
MineSweepGame::~MineSweepGame()
{

	//�Ѷ�̬��ά��������
	if(m_mineMatrix!=NULL)
	{
		for(int i=0;i<m_mineSizeA;i++)
		{
			if(m_mineMatrix[i]!=NULL)
				delete[]m_mineMatrix[i];
		}
		delete m_mineMatrix;
	}
	m_mineMatrix=NULL;
}

 bool MineSweepGame::click(int rows, int cols)				 //�û�������׵Ĳ��� �д�1��ʼ �д�1��ʼ
 {
	 
	 //�ж��Ƿ�Խ��	
	if(rows>m_mineSizeA || cols>m_mineSizeB ||rows<1 || cols<1)
	{
		cout<<"��������򳬳������ˣ��볢�����µ��"<<endl;
		return false;
	}
        int i=rows-1, j=cols-1;
		int t_mineFlag=m_mineMatrix[i][j];
		//���ݾ���Ե������������ж�
		//����������Ѿ�������ĵ� �����
		if(t_mineFlag==	INT_MAX)
		{
			cout<<"�����������Ѿ�������ˣ��볢�����µ��"<<endl;
			return false;
		}
		else if( t_mineFlag==-1)  //����ȵ�������
		{
			cout<<"�ȵ������ˣ� �����ˣ� ������"<<endl;
			//�ж���Ϸ�Ƿ������flag
			m_isGameOver=0;
			return true;
		}
		else    //���û�ȵ�����
		{
			cout<<"����ɹ����������Ϸ"<<endl;
			noneMineExpand(i,j);
			return true;
		}
 }
 void MineSweepGame::reflashMineMatrix() //ˢ�£������������
 {
    //cout<<"��Ϸ���������ͣ�"<<endl;
	//�����ʾ�ľ���
	//����к�
	 cout << "   ";
	 for (int i = 0; i < m_mineSizeB; i++)
	 {
		
		 cout << setw(2) << setiosflags(ios::right) << i + 1 << " ";
	 }
	 cout << endl<<endl;
	for(int i=0;i<m_mineSizeA;i++)
	{
		
		cout << setw(2) << setiosflags(ios::right) <<i + 1 << " ";
		for(int j=0;j<m_mineSizeB;j++)
		{
			
			//����ǻ�û�е�����ĵ�
			int t_mineFlag=m_mineMatrix[i][j];
			if(m_isGameOver== 0 || m_isGameOver==1 )   //�������Ϸʧ���ˣ���������Ϸ�ɹ��ˣ� �����ͼ
			{
				if(	t_mineFlag  == INT_MAX ) //�Ѿ�������ķ��׵ĵ㣬�������Χ�ĵ�����Ŀ
				{
					int count=countMineNum(i, j) ;
					cout<< setw(2) << setiosflags(ios::right) <<count<<" ";
				}
				else if (t_mineFlag==0)   //����Ƿ��ײ��һ�û�����
				{
					cout  << setw(2) << setiosflags(ios::right) <<"#"<<" ";
				}
				else  //����ǵ��ף���Ϊ��Ϸ�Ѿ������ˣ��ѵ��׵�λ�ù���
				{
					cout << setw(2) << setiosflags(ios::right) <<"*"<<" ";
				}
			}
			//�����Ϸ������������
			else
			{
				if(	t_mineFlag  == INT_MAX ) //�Ѿ�������ķ��׵ĵ㣬�������Χ�ĵ�����Ŀ
				{
					int count=countMineNum(i, j);
					cout << setw(2) << setiosflags(ios::right) <<count<<" ";
				}
                else
				{
					cout  << setw(2) << setiosflags(ios::right) <<"#"<<" ";
				}
			}
  
			
		}
		cout<<endl;
	}

 }
 int  MineSweepGame::isGameOver()	   //����m_isGameOver���flag
 {
	 if(m_isGameOver==0) //�����Ϸʧ��
	 {
		 cout<<"��Ϸʧ�ܣ�"<<endl;
		 return 0;
	 }
	 else if(m_isGameOver==1)
	 {
		  cout<<"��ϲ�㣬��Ӯ��!"<<endl;
		  m_isGameOver=1;
		  return 1;
	 }
	 else   //�����Ϸ�������� 
	 {
		//�ж���Ϸ�Ƿ�ɹ�
		 //����Ѿ������˳��˵���֮��ĵ�
		 if(m_isClicked+m_mineNum>=m_mineSizeA*m_mineSizeB)
		 {
			 cout<<"��ϲ�㣬��Ӯ��!"<<endl;
			 m_isGameOver=1;
			 return 1;
		 }
		 else 
		 {
			 //cout<<"��Ϸ����"<<endl;
			 return -1;
		 }
	 }
 }
 void  MineSweepGame::chooseLevel()	 //ѡ����Ϸ�Ѷ�
 {
	 cout<<"��ѡ����Ϸ�Ѷ�, �ڼ���������1 ��ʾ���Ѷȣ� 2��ʾ��ͨ�Ѷȣ� 3��ʾ�����Ѷȣ� 4��ʾ�Զ����Ѷ�"<<endl;
	 int t_level;
	 cin>>t_level;
	 switch(t_level)
	 {
	 case 1:
		 m_mineSizeA=4;
		 m_mineSizeB=4;
		 m_mineNum=1;
		 break;
	 case 2:
		 m_mineSizeA=7;
		 m_mineSizeB=7;
		 m_mineNum=8;
		 break;
	 case 3:
		 m_mineSizeA=12;
		 m_mineSizeB=12;
		 m_mineNum=20;
		 break;
	 case 4:
		 cout<<"��ѡ���Զ����Ѷȣ�������������������������Ŀ(�������������С��100)"<<endl;
		 cin >> m_mineSizeA >> m_mineSizeB>>m_mineNum;
		 break;
	 default:
		  cout<<"��������󣬽�Ĭ��Ϊ���Ѷ�"<<endl;
		 	 m_mineSizeA=4;
		 	 m_mineSizeB=4;
		 	 m_mineNum=1;
		 	 
	 }
	 
 }
 void MineSweepGame::restartGame()   //���¿�ʼ��Ϸ�ĺ���
 {
     cout<<"���¿�ʼ��Ϸ��ף�����"<<endl;
	 
	 //�Ȱ�ԭ������������
	 //�Ѷ�̬��ά��������
	 if(m_mineMatrix!=NULL)
	 {
	 	for(int i=0;i<m_mineSizeA;i++)
	 	{
	 		if(m_mineMatrix[i]!=NULL)
	 			delete[]m_mineMatrix[i];
	 	}
	 	delete m_mineMatrix;
	 }
	 chooseLevel();
	 //�����µ�����
	  	if(m_mineNum>m_mineSizeA*m_mineSizeB)  //������׵�
	  	{
	  		cerr<<"���׵���Ŀ���࣬��Ϸ����ʧ��"<<endl;
	  		exit(1);
	  	}
	  	// �ȴ�����̬��ά����
	  	m_mineMatrix= new int* [m_mineSizeA];	  
	  	if(m_mineMatrix==NULL)
	  	{
	  		cerr<<"ɨ����Ϸ���󴴽�ʧ�ܣ�/n";
	  		exit(1);
	  	}
	  	else
	  	{
	  		for(int i=0;i<m_mineSizeA;i++)
	  		{
	  			m_mineMatrix[i]=new int[m_mineSizeB];
	  		}
	  	}
	      //��ʼ����Ϸ��ôijieshu
	  	m_isGameOver=-1; 
	  	m_isClicked=0; //һ��ʼû�е㱻���
	  	//�����
	  	creatMine();
		reflashMineMatrix()	;
 }

int  MineSweepGame::countMineNum(int i, int j)  //����� i�� j����Χ�ĵ��׵���Ŀ��ע��߽�
{
	 int count=0;
	 //���Ͻ�
	 int tempi=i,tempj=j;
	 for(int p=0;p<8;p++)//����8������
	 {
		 tempi=i+move[p].iOffest;
		 tempj=j+move[p].jOffset;
		 //�ж��Ƿ�Խ��
		 if(tempi<0||tempi>=m_mineSizeA||tempj<0 ||tempj>=m_mineSizeB)
		 {
			 continue;
		 }
		 else
		 {
			 if(m_mineMatrix[tempi][tempj]==-1) //����ǵ���
			 {
				
				 count++;
			 }
		 }
	 }
	 return count;
}
void  MineSweepGame::creatMine() //�ھ������������; 
{
    srand(time(0));
	int tempNum=0; //�Ѿ����ĵ�����Ŀ
	int tempI,tempJ;
	while(tempNum<m_mineNum)
	{
		//��α���������������׵�����
		tempI=rand()%m_mineSizeA;
		tempJ=rand()%m_mineSizeB; 
		m_mineMatrix[tempI][tempJ]=-1;  //����
		tempNum++;
	}
	//�������ĵط����ó�0
	for(int i=0; i<m_mineSizeA;i++)
	{
		for(int j=0; j<m_mineSizeB;j++)
		{
			if(m_mineMatrix[i][j]!=-1) //���������
			   m_mineMatrix[i][j]=0;
		}
	}

}
void MineSweepGame::noneMineExpand(int i,int j)  //�������������
{
	if (i < 0 || i >= m_mineSizeA || j < 0 || j >= m_mineSizeB)
		return;
	if (m_mineMatrix[i][j] == -1 || m_mineMatrix[i][j]==INT_MAX)//������׵Ļ�,�����Ѿ��������
		return;
	else  //��������ײ��Ҳ����Ѿ������������
	{
		//��� 
		m_mineMatrix[i][j] = INT_MAX;
		m_isClicked++;
		if (countMineNum(i, j) != 0)  //���������Χû����
		{
			return;
		}
		else
		{
            int tempi, tempj;
			for (int p = 0; p < 8; p++)//����8������
			{
				tempi = i + move[p].iOffest;
				tempj = j + move[p].jOffset;
				//�ж��Ƿ�Խ��
				if (tempi < 0 || tempi >= m_mineSizeA || tempj < 0 || tempj >= m_mineSizeB)
				{
					continue;
				}
				//�ݹ����
				else
				{
						noneMineExpand(tempi, tempj);
				}
		    }
		}
	}
}




















