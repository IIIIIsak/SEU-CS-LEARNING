#ifndef HASHTABLE_H
#define HASHTABLE_H
#include<iostream>
#include<iomanip>
using namespace std;
const int defaultSize = 100;
template<class E,class K>
struct  ChainNode
{
	K key;
	E data;
	ChainNode* link;
};

template<class E,class K>
class HashTable
{
public:
	HashTable(int d, int sz = defaultSize);
	~HashTable();
	bool search(const K k,  E& e);
	bool insert(const K k,const E& e);
	bool remove(const K k,  E&e);
	void output(void); //���hash, hash�����ݣ�װ�����ӵ�
	void staticticAnalyse(); //��hash����з���
	void reMake(int d, int sz); //���¹���hash
private:
	int divisor;   //����ȡ�෨�ĳ�����Ӧ����һ������
	int tableSize;  //ɢ�б�Ĵ�СͰ����Ŀ
	int nums;
	ChainNode<E,K>**ht;
	ChainNode<E,K>* findPos(const K k);
	bool deleteBucket(int i);  //ɾ����i ��Ͱ��ȫ������;
	void outBucket(int i);  //�����i��Ͱ������
	int bucketLength(int i); //����Ͱ�����  Ͱ����Ⱥ�ASL�й�
	void deleteTable(); //ɾ��������;
};

template<class E, class K>
HashTable<E,K>::HashTable(int d, int sz ):divisor(d),tableSize(sz),nums(0)
{
	if (tableSize < divisor)
	{
		cout << "����ĳ�����hash��С��ƥ�䣬����ʧ��"<<endl;
		exit(1);
	}

	//����ռ�
	ht = new ChainNode<E, K>* [tableSize];
	if (ht == nullptr)
	{
		cout << "�ռ�δ����ɹ�" << endl;
		exit(1);
	}
	//��ʼ��
	for (int i = 0; i < tableSize; i++)
	{
		ht[i] = nullptr;
	}
}

template<class E, class K>
HashTable<E, K>::~HashTable()
{
	
	deleteTable();
	
}

template<class E, class K>
bool HashTable<E, K>::search(const K k,  E& e)
{
	ChainNode<E, K>* current = findPos(k);
	//���û�ҵ�
	if (current == nullptr)
		return false;
	else
	{
		e = current->data;
		return true;
	}
}

template<class E, class K>
bool HashTable<E, K>::insert(const K k,const E& e)
{
	ChainNode<E, K>* current = findPos(k);
	if (current != nullptr)   //��������ʹ�����
		return false;
	else //���ԭ���ı���û��
	{
		int pos = static_cast<int>(k) % divisor;  //��ȡͰ��
		//�Ӷ��˲���

		//�����½ڵ�
		current = new ChainNode<E, K>;
		current->key = k;
		current->data = e;
		//����ȥ
		current->link = ht[pos];
		ht[pos] = current;
		nums++;  //��Ŀ+1

		return true;
	}
}

template<class E, class K>
bool HashTable<E, K>::remove(const K k,  E&e)
{
	int pos = static_cast<int>(k) % divisor;  //��ȡͰ��
	ChainNode<E, K>* current = ht[pos];
    //�����һ��������
	if (current->key == k)
	{
		ht[pos] = current->link;
		e = current->data;
		delete current;
		nums--;
		return true;
	}
	else //�����һ������
	{
		ChainNode<E, K>* temp = current->link;   //temp ��Ҫ��ɾ����ָ��
		while (temp != nullptr)
		{
			//����ҵ���
			if (temp->key == k)
			{
				current->link = temp->link;  //����ȥ
				//ɾ��
				e = temp->data;
				nums--;
				delete temp;
				return true;
			}
			else
			{
				current = current->link;
				temp = temp->link;
			}
		}
	}
	return false;
}

template<class E, class K>
void  HashTable<E, K>::output(void) //���hash, hash�����ݣ�װ�����ӵ�
{
	cout << "--��ǰhash�������--" << endl;
	cout << " " << "����ȡ�෨�ĳ���Ϊ: " << divisor << "\tͰ�ĸ���: " << tableSize << "\t�ؼ���ĸ���: "
		<< nums << endl;
	cout << " " << "Ͱ��" << "\t\t�ؼ���" << endl;
	for (int i = 0; i < tableSize; i++)
	{
		outBucket(i);
		cout << endl;
	}
}

template<class E, class K>
void  HashTable<E, K>::staticticAnalyse() //��hash����з���
{
	cout << "ͨ�������㷨���ԱȽϴ���������ƽ����������ASL" << endl;
	//ASL��ÿ��Ͱ������й�
	//���������ɹ�����������
	int Sl = 0, Ul = 0;
	double Sa = 0, Ua = 0;
	for (int i = 0; i < divisor; i++)  //ʣ�µ�Ͱ��Զ���ᱻ�õ����Բ��������
	{
		int length = bucketLength(i);
		Ul += (length+1);
		if (length >0)  //ֻ��Ͱ����Ԫ�زż��������ɹ���
		{
			Sl += ((length*(length + 1)) / 2);
		}
	}
	Sa = double(Sl) / double(nums);
	Ua = double(Ul) / double(divisor);
	cout << "\t\tSa = " << Sa << ",Ua = " << Ua << endl;

	//���ݹ�ʽ��������ֵ
	cout << "\n����alpha����ƽ����������ASL" << endl;
	double a ;
	a = double(nums) / double(divisor);
	cout << "n = " << nums << ", m = " << divisor << ", alpha = " << a << ", Sa = " << 1 + a / 2
		<< ", Ua = " << a;
			
}

template<class E, class K>
void HashTable<E, K>::reMake(int d, int sz)
{
	//�Ȱ�ԭ��������ɾ��,���ﲻ���ó�ʼ�������б���Ϊ��ʼ�������б����ִ��
	deleteTable();
	nums = 0;
	divisor = d;
	tableSize = sz;
	if (tableSize < divisor)
	{
		cout << "����ĳ�����hash��С��ƥ�䣬����ʧ��" << endl;
		exit(1);
	}

	//����ռ�
	ht = new ChainNode<E, K>*[tableSize];
	if (ht == nullptr)
	{
		cout << "�ռ�δ����ɹ�" << endl;
		exit(1);
	}
	//��ʼ��
	for (int i = 0; i < tableSize; i++)
	{
		ht[i] = nullptr;
	}
}
template<class E, class K>
ChainNode<E,K>* HashTable<E, K>::findPos(const K k)   
{
	int pos = static_cast<int>(k) % divisor;  //��ȡͰ��
	ChainNode<E, K>* tempPtr = ht[pos];
	while (tempPtr != nullptr)
	{
		//����ҵ���
		if (tempPtr->key == k)
			break;
		else
		{
			tempPtr = tempPtr->link;
		}
	}
	return tempPtr;
	
}

template<class E, class K>
bool HashTable<E, K>::deleteBucket(int i)  //ɾ����i ��Ͱ��ȫ������
{
	if (i < 0 || i >= tableSize)
	{
		cout << "�����i �Ƿ�" << endl;
		return false;
	}
	ChainNode<E, K>* current = ht[i];
	ChainNode<E, K>* dir = current;
    //��ɾ����һ��
	if (current != nullptr)
	{
		current = current->link;
		nums--;
		delete dir;
		ht[i] = nullptr;
	}
	//ɾ��֮���
	while (current != nullptr)
	{
		dir = current; 
		current = current->link;
		nums--;
		delete dir;
	}
	return true;
}

template<class E, class K>
void HashTable<E, K>::outBucket(int i) //�����i��Ͱ��data
{
	if (i < 0 || i >= tableSize)
	{
		cout << "�����i �Ƿ�" << endl;
		return;
	}
	cout << i << "\t\t";
	ChainNode<E, K>* current = ht[i];
	while (current != nullptr)
	{
		cout << current->data << " ";
		current = current->link;
	}
	return;
}

template<class E, class K>
int HashTable<E, K>::bucketLength(int i)
{
	if (i < 0 || i >= tableSize)
	{
		cout << "�����i �Ƿ�" << endl;
		return 0;
	}
	int length=0;
	ChainNode<E, K>* current = ht[i];
	while (current != nullptr)
	{
		length++;
		current = current->link;
	}
	return length;
}

template<class E, class K>
void HashTable<E, K>::deleteTable()
{
	if (ht != nullptr)
	{
		for (int i = 0; i < tableSize; i++)
			deleteBucket(i);
		delete[]ht;
		ht = nullptr;
	}
}
#endif


