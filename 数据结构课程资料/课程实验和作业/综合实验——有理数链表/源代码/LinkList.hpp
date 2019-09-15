#ifndef LINKLIST_H
#define LINKLIST_H
template<class T>
struct linkNode
{
	T data;
	linkNode* link;
	linkNode(T d=0, linkNode* l = nullptr) :data(d), link(l)
	{

	}

};

template<class T>
class LinkList
{
public:
	LinkList(T data=0);    //������ͷ�ڵ�ĳ�ʼdata��Ϊ0
	virtual ~LinkList();
	bool insert(const int i, const T data);  //�ڵ�i���ڵ�֮�����ڵ�
	linkNode<T>* search(const T data)const;   //Ѱ������Ϊ data�Ľڵ� 
	bool remove(const int i, T& t); //ɾ����i���ڵ�
	bool isEmpty(); //�п�
	void makeEmpty();//�ÿ�
	
	linkNode<T>* getHead()
	{
		return head;
	}
	linkNode<T>* getRear();

	int getLength()
	{
		return length;
	}
protected:
	//����ͷ�ڵ�,��β���Ľڵ�
	linkNode<T>* head;
	linkNode<T>* findPos(const int i); //Ѱ�ҵ�i���ڵ��λ��
	int length;
};


template<class T>
LinkList<T>::LinkList(T data):length(0)
{
	head = new linkNode<T>(data,nullptr);  //��ʼ��
}

template<class T>
LinkList<T>::~LinkList()
{
	makeEmpty();
	delete head;
}

template<class T>
bool LinkList<T>::insert(const int i, const T data)  //�ڵ�i���ڵ�֮�����ڵ�
{
	if (i == 0)  //���������ͷ�ڵ�֮�����
	{
		if (head == nullptr)
			return false;
		linkNode<T>* newNode=new linkNode<T>(data, head->link);
		head->link = newNode;
		length++;
		return true;
	}
	else
	{
		linkNode<T>* current = findPos(i);
		if (current == nullptr )  //����Ҳ�����i���ڵ�
			return false;
		//����ҵ���
		linkNode<T>* newNode= new linkNode<T>(data, current->link);  //�����Ѿ��Զ�����ȥ��

		current->link = newNode;
		length++;
		return true;
	}

}

template<class T>
linkNode<T>* LinkList<T>::search(const T data)const   //Ѱ������Ϊ data�Ľڵ�
{
	if (isEmpty())
		return nullptr;
	linkNode<T>* current = head->link;
	while (current != nullptr )
	{
		if (current->data == data)
			return current;
		else
		{
			current = current->link;  //����һ��
		}
	}
}

template<class T>
bool LinkList<T>::remove(const int i, T& t) //ɾ����i���ڵ�
{
	if (i == 1)   //�������
	{
		if (head == nullptr)
			return false;
		else
		{
			if (head->link == nullptr)
				return false;
			else
			{
				linkNode<T>* dir = head->link;
				head->link = dir->link;
				delete dir;
				length--;
				return true;
			}
		}
	}
	else
	{
		linkNode<T>* current = findPos(i - 1);  //���ҵ���i-1���ڵ�
		if (current == nullptr)  //����Ҳ�����i-1���ڵ�,currentΪ��
			return false;
		linkNode<T>* dir = current->link;
		if (dir == nullptr)  //�����ɾ���ڵ�Ϊ��,���߱�ɾ���ڵ�Ϊͷָ��
			return false;
		else
		{
			current->link = dir->link;
			length--;
			delete dir;
			return true;
		}
	}
}

template<class T>
linkNode<T>* LinkList<T>::getRear()  //βָ�������һ����Ч�ڵ��ָ�루����ͷ�ڵ㣩
{                      
	if (head == nullptr)
		return nullptr;
	if (head->link == nullptr)
		return head;
	else
	{
		int i = length;
		return findPos(length);
	}
}

template<class T>
bool LinkList<T>::isEmpty() //�п�
{
	if (head == nullptr)    //����ж�Ϊ���Է���һ
		return true;
	else if (head->link == nullptr)   
		return true;
	else
		return false;
}

template<class T>
void LinkList<T>::makeEmpty()//�ÿ�
{
	if (isEmpty())  
		return;
	linkNode<T>* current = head->link;
	int l = 0;   //�Ѿ�ɾ���ĳ���
	while (current != nullptr  && l<length)
	{
		linkNode<T>* dir = current;
		current = current->link;
		l++;
		delete dir;
	}
	head->link = nullptr;
	length = 0;
}

template<class T>
linkNode<T>* LinkList<T>::findPos(const int i) //Ѱ�ҵ�i���ڵ��λ��
{
	if (i <= 0)    //�жϱ߽�
		return nullptr;
	if (isEmpty())  //�������Ϊ�շ��ؿ�ָ��
		return nullptr;
	if (i > length)
		return nullptr;
	linkNode<T>* current = head->link;
	int k = 1;      //ͷ�ڵ���0�Žڵ�
	while (current != nullptr && k < i)
	{
		current = current->link;
		k++;
	}
	return current;
	
}
#endif // !LINKLIST_H