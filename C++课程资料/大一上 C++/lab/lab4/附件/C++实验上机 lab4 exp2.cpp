#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int count = 0;
	long int hypotenuseSquared;
	long int sidetenuseSquared;
	cout << setw(5) << "Side1" << setw(5) << "Side2" << setw(5) << "Side3"<<endl;
	for (int side1 = 1;side1 <= 500;side1++)
	{
		for (int side2 = side1;side2 <= 500;side2++)
		{
			for (int side3 = side2; side3 <= 500 && side3 < side1 + side2; side3++)  //����������֮�ʹ��ڵ�����
			{
				sidetenuseSquared = side1*side1 +side2*side2;
				hypotenuseSquared = side3*side3;
				if (sidetenuseSquared == hypotenuseSquared)
				{
					cout << setw(5) << side1 << setw(5) << side2 << setw(5) << side3 << endl;
					count++;
				}
			}
		}
	}
	cout << "A total of " << count << " triples were found." << endl;
    system("pause");
	return 0;

}