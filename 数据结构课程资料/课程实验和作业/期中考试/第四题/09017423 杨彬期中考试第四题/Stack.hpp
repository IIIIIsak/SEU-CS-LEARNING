#ifndef STACK_H
#define	STACK_H
template<class T>
struct StackNode
{
	//������
	T data;
	//ָ����
	StackNode* next;
	//���캯��
	StackNode(T d, StackNode* n=nullptr) :data(d), next(n)
	{};
};
template<class T>
class Stack
{
public:
	Stack();
	~Stack();
	bool push(const T data); //ѹջ
	bool pop(T& data); //��ջ��������ȡ������һ���ڵ����T��
	bool isEmpty()const;  //�пղ���
	bool getTop(T& data)const;   //��ȡջ����Ԫ��,������data��
private:
	StackNode<T>* top; //ջ����ָ��

};
template<class T>
Stack<T>::Stack()
{
	//top����Ϊ��
	top = NULL;
}
template<class T>
Stack<T>::~Stack()
{
	StackNode<T>* current = top;
	StackNode<T>* dam;
	while (current != NULL)
	{
		dam = current;
		current = current->next;
		delete dam;
	}
}
template<class T>
bool Stack<T>::push(const T data) //ѹջ
{
	//��������topΪNULL
	if (top == NULL)
	{
		top = new StackNode<T>(data, NULL);
		if (top != NULL)
			return true;
		else return false;

	}
	else
	{
		//��ͷ�ڵ�֮ǰ��ӽڵ�
		//����һ���µĽڵ�
		StackNode<T>* newNode = new StackNode<T>(data, NULL);
		//��������ȥ
		if (newNode != NULL)
		{
			newNode->next = top;
			//����top
			top = newNode;
			return true;
		}
		else
			return false;
	}
}
template<class T>
bool Stack<T>::pop(T& data) //��ջ��������ȡ��ջ����һ���ڵ����T��
{
	if (isEmpty()) //���ջΪ��
		return false;
	else
	{
		//ȡ��Ԫ��
		data = top->data;
		//ɾ��
		StackNode<T>* dam = top;
		top = top->next;
		delete dam;
		return true;
	}
}
template<class T>
bool Stack<T>::isEmpty()const   //�пղ���
{
	return top == NULL ? true : false;
}
template<class T>
bool Stack<T>::getTop(T& data)const   //��ȡջ����Ԫ��,������data��
{
	if (isEmpty())
		return false;
	else
	{
		T = top->data;
		return true;
	}
}
#endif // !STACK_H