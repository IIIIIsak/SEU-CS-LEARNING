#include"HuffmanCoder.h"
HuffmanCoder::HuffmanCoder(int n):nums(n)
{
	huffmanPtr = nullptr;
	weight = nullptr;
}
HuffmanCoder::~HuffmanCoder()
{
	if (huffmanPtr != nullptr)
	{
		delete huffmanPtr;
		huffmanPtr = nullptr;

	}
	if (weight != nullptr)
	{
		delete[] weight;
		weight = nullptr;

	}
}
bool HuffmanCoder::creatHuffmanTree(ifstream& fin) //���ļ��ж������ݲ�����ͳ��,Ȼ������һ�ù�������
{
	if (huffmanPtr != nullptr)
	{
		cout << "�Ѿ����������������ˣ��޷���������" << endl;
		return false;
	}
	//����һ����ʱ����������26����ĸ�������ִ�Сд��
	char* dictionary=new char[nums];
	if (dictionary == nullptr)
	{
		cerr << "�޷�����ռ�";
		exit(1);
	}
	for (int i = 0; i < nums; i++)  //��ʼ��
	{
		dictionary[i] = 'a' + i;
	}
	//��ʼ����ͳ��
	int total = 0; //����Ŀ
    weight = new double[nums]; //Ȩֵ����
	if (weight == nullptr)
	{
		cerr << "�޷�����ռ�";
		exit(1);
	}
	for (int i = 0; i < nums; i++)
	{
		weight[i] = 0;
	}
	char x=0; 
	while (fin >> x)  //������Ƕ����ļ���β�Ļ�
	{

		if (x >= 'a'&& x <= 'z')  //�����Сд��
		{
			//Ŀǰֻ��ͳ����Ŀ
			weight[x - 'a']++;
			total++;
		}
		else if (x >= 'A'&& x <= 'Z')  //����Ǵ�д��ĸ
		{
			//Ŀǰֻ��ͳ����Ŀ

			weight[x - 'A']++;
			total++;
		}
		else  //��������ǵĻ�����
		{
			;
		}

	}
	//����Ȩֵ
	/*for (int i = 0; i < nums; i++)
	{
		weight[i] = weight[i] / total;
	}*/
	//������������
	huffmanPtr = new HuffmanTree<double>(weight, dictionary, nums);
	//���տռ�
	delete[]dictionary;
	return true;
}
bool HuffmanCoder::creatCode(ifstream& fin, ofstream& fout)  //���ļ��ж����ַ����������
{
	if (huffmanPtr == nullptr)
	{
		cout << "��δ���������������޷�����" << endl;
		return false;
	}
	char x=0 ;
	string code;
	while (fin>> x)  //������Ƕ����ļ���β�Ļ�
	{
		code = "";
		if (x >= 'a'&& x <= 'z')  //�����Сд��
		{
			huffmanPtr->findHuffmanCode(int(x - 'a'), code);
		}
		else if (x >= 'A'&& x <= 'Z')  //����Ǵ�д��ĸ
		{
			huffmanPtr->findHuffmanCode(int(x-'A'), code);
		}
		else  //��������ǵĻ�����
		{
				;
		}
		//�������

		fout << code;
	}
	return true;
}
bool  HuffmanCoder::translateCode(ifstream& fin, ofstream& fout)//���ļ��ж�����룬���ҷ���
{
	if (huffmanPtr == nullptr)
	{
		cout << "��δ���������������޷�����" << endl;
		return false;
	}
	huffmanPtr->translateHuffmanCode(fin, fout);
	return true;
}
bool HuffmanCoder::compare(ifstream& finOrigin, ifstream& finTarget)//�Ƚ�Դ�������
{
	char x=0, y=0;

	while (finOrigin >> x)  //������Ƕ����ļ���β�Ļ�
	{
		if (x >= 'a'&& x <= 'z')  //�����Сд��
		{
			finTarget >> y;
			if (x != y)
				return false;

		}
		else if (x >= 'A'&& x <= 'Z')  //����Ǵ�д��ĸ
		{
			finTarget >> y;
			if (int(x - 'A') != int(y - 'a'))
				return false;
		
		}
		else  //��������ǵĻ�����
		{
			;
		}
	}
	//����
	if (finTarget >> y)
		return false;
	else
		return true;

}
void HuffmanCoder::makeEmpty()
{
	if (weight != nullptr)
	{
		delete[] weight;
		weight = nullptr;

	}
	if (huffmanPtr != nullptr)
	{
		delete huffmanPtr;
		huffmanPtr = nullptr;
	}
}
void HuffmanCoder::outputWeight()
{
	if (weight == nullptr)
		return;
	for (int i = 0; i < nums; i++)
	{
		cout <<char( 'a' + i) << "��ȨֵΪ: " << weight[i] << endl;
	}
	cout << "��Ȩֵ֮��Ϊ��"; 
	huffmanPtr->outputWholeWeight();
	cout << endl;
}
void HuffmanCoder::outputCode()
{
	string code;
	for (int i = 0; i < nums; i++)
	{
		code = "";
		huffmanPtr->findHuffmanCode(i, code);
		cout << char('a' + i) << "�Ĺ���������Ϊ�� " << code<<endl;
	}
}