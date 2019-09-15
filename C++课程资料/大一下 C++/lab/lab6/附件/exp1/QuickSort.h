#ifndef QUICKSORT_H
#define QUICKSORT_H
template<typename T>
class QuickSort
{
private: 
		 void Swap(T& t_Tx, T& t_Ty)
		 {
			 T t_Tz = t_Tx;
			 t_Tx = t_Ty;
			 t_Ty = t_Tz;
		 }
		 bool Judging(int t_ileft, int t_iright)   //�ж��Ƿ񹹳�һ�����У������� β�������ͷ
		 {
			 if (t_iright > t_ileft)
				 return true;
			 else
				 return false;
		 }
		 int LeftPartition(T* t_Tarray, int t_ipos, int t_ileft, void(*swap)(T&, T&)=swap);  //������ָ�֮���pos��λ�� ����-1��
		 int RightPartition(T* t_Tarray, int t_ipos, int t_iright, void(*swap)(T&, T&)=swap);
		 int Partition(T* t_Tarray, int t_ileft, int t_iright);
         
public:
	void quicksort(T*, int, int);
    
};


template<typename T>
int QuickSort<T>::LeftPartition(T* t_Tarray, int t_ipos, int t_ileft, void(*swap)(T&, T&))  //������ָ�֮���pos��λ�� ����-1��
{
	if (!Judging(t_ileft, t_ipos))             //-1��ʾ��������ָ�,������ָ�ʧ��
	return -1;
	int i = t_ileft; //i��ѭ������
	for (i;i < t_ipos;i++)
	{
		if (t_Tarray[i] > t_Tarray[t_ipos])
		{
			swap(t_Tarray[i], t_Tarray[t_ipos]);
			t_ipos = i;
			return t_ipos;
		}
	}
	if (i == t_ipos)
		return -1;

}
template<typename T>
int  QuickSort<T>::RightPartition(T* t_Tarray, int t_ipos, int t_iright, void(*swap)(T&, T&))
{
	if (!Judging(t_ipos, t_iright))
		return -1;
	int i = t_iright; //i ��ѭ������
	for (i;i > t_ipos;i--)
	{
		if (t_Tarray[i] < t_Tarray[t_ipos])
		{
			swap(t_Tarray[i], t_Tarray[t_ipos]);
			t_ipos = i;
			return t_ipos;
		}
	}
	if (i == t_ipos)
		return -1;
}
template<typename T>
int QuickSort<T>::Partition(T* t_Tarray, int t_ileft, int t_iright)
{
	if (!Judging(t_ileft, t_iright))
		return -1;
	int t_ipos = t_ileft;
	int t_iflagleft = 1, t_iflagright = 1;    //������������������ ״̬  
	while ((t_iflagleft !=-1 || t_iflagright !=-1))
	{
		if (t_iflagright = RightPartition(t_Tarray, t_ipos, t_iright), t_iflagright != -1)
		{
			t_ileft = t_ipos + 1;
			t_ipos = t_iflagright;
		}
		if (t_iflagleft = LeftPartition(t_Tarray, t_ipos, t_ileft), t_iflagleft != -1)
		{
			t_iright = t_ipos - 1;
			t_ipos = t_iflagleft;
		}
	}
	return t_ipos;
}
template<typename T>
void QuickSort<T>::quicksort(T* t_Tarray, int t_ifirst, int t_ilast)
{
	if (!Judging(t_ifirst, t_ilast))
		return;
	else
	{
		int t_ipos = t_ifirst;
		if ((t_ipos = Partition(t_Tarray, t_ifirst, t_ilast), t_ipos != -1))
		{
			quicksort(t_Tarray, t_ifirst, t_ipos - 1);
			quicksort(t_Tarray, t_ipos + 1, t_ilast);
		}
		else
			return;
	}
}
#endif // !QUICKSORT_H

