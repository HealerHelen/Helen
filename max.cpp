//���ԣ��ҵ�(����!!)�����е����ֵ
//Zhao Ziyin,20160310

#include<iostream>
using namespace std;

int Largest(int list[], int length)
{
	int i, max=list[0];
	for (i = 0; i<=length - 1; i++)
	{
		if (list[i]>max)
		{
			max = list[i];
		}
	}
	return max;
	//if (list == NULL|| length == 0)
	//{
	//	return 0;
	//}
}

void main()
{
	int i;
	int arr[10];
	int in;
	cout << "����һ���������������10���������飩��" << endl;
	
	for (i = 0; i < 10; i++)
	{
		cin >> in;
		arr[i] = in;
	}
	
	int big;
	big= Largest(arr, 10);
	cout << "�������ֵΪ��" << big << endl;
}