#ifndef MINESWEEPGAME_H
#define MINESWEEPGAME_H	 
//Ϊ�˷��������ҵ���
struct offset
{
	int iOffest;
	int jOffset;
} ;
class MineSweepGame
{
public:
	MineSweepGame();
	~MineSweepGame();
	bool click(int rows, int cols);					 //�û�������׵Ĳ���
	void reflashMineMatrix(); //ˢ�£������������
	int  isGameOver();	   //����m_isGameOver���flag
	void restartGame();   //���¿�ʼ��Ϸ�ĺ���
	
private:
	offset move[8];
	int** m_mineMatrix ; //�������������Ϣ�ľ���	  -1��ʾ���� 0��ʾ���ǵ���(-1��0��û�б������ �����ʾ����㱻������� 
 	int m_mineSizeA;        //���׾��������
	int m_mineSizeB;        //���׾��������
 	int m_mineNum; 	  //���׵���Ŀ
	int m_isClicked; // �Ѿ�������ĵ����Ŀ;

	int m_isGameOver;   // �����ж���Ϸ�Ƿ������ -1��ʾ��Ϸ��û���� 0��ʾ
	void chooseLevel(); 
    int countMineNum(int i, int j);  //����� i�� j����Χ�ĵ��׵���Ŀ��ע��
	void creatMine(); //�ھ������������; 
	void noneMineExpand(int i,int j);
};


#endif