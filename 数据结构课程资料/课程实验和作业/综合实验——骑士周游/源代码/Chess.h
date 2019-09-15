#ifndef CHESS_H
#define CHESS_H
const int offsetI[8] = { -1,1,2,2,1,-1,-2,-2 };
const int offsetJ[8] = { 2,2,1,-1,-2,-2,-1,1 };
struct direction
{
	int count;
	int i;  
	int j;
};
class Chess
{
public:
	Chess(int size=6);
	~Chess();
	bool Horse(int x,int y);   //������ʿ���Σ����εĽ�������������С�
	void remake(int size);  //���������߳�Ϊsize������
	void makeEmpty();  //��������գ�������������
	void printChess(); //��ӡ����
	bool findHorsePath(int i1, int j1, int i2, int j2,int& length);
private:
	bool Horse(int x, int y,int num);  //�ݹ���õĺ���,num��ʾ�ǵڼ���
	int countDirection(int i, int j); //������һ���˸�����ÿ�������Ӧ�Ŀ��ܵ��߷�
	void insertSort(direction d[], int n);   //�Է����������
	void growHorsePath(int** path,int size,int i1,int j1,int i2,int j2,int length);   //�����·������������
	int size;
	int** chess;
	
};
#endif // !CHESS_H
