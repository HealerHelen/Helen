//����������������������2
//��� ������ 2016/3/25

#include <iostream>
using namespace std;
#define N 1000

int value(int arry[], int length)
{
	int max[N], max1;
	int maxweizhi[N];
	for (int j = 0; j<(length + 1) / 2; j++)
	{
		int sum = 0;
		max1 = -9999999;                   //������ͷ�Χ
		int z = 0;
		for (int i = j; i<(length + 1) / 2 + j; i++)   //��������������������
		{
			sum = sum + arry[i];
			if (sum >= max1)
			{
				max1 = sum;
				z++;
			}
		}
		max[j] = max1;
		maxweizhi[j] = z;

	}
	int fmax = max[0];
	int q = 0;
	for (int i = 0; i<(length + 1 / 2); i++)  //�����к͵������������ֵ
	{
		if (max[i]>fmax)
		{
			fmax = max[i];
			q = i;
		}
	}

	int weizhi = maxweizhi[q];

	cout << "���������Ϊ��" << endl;
	for (int num = q; num<q + weizhi; num++)  //�������������λ��
	{
		cout << arry[num] << " ";
	}

	cout << "���Ϊ:  " << fmax << endl;
	return 0;
}

void main(int argc, char* argv[])
{
	int arry[N];
	int length = 1;
	int max[N], max1; //max[N]��ÿһ����͵Ľ���������������ֵ��Ϊ����
	int maxweizhi[N];
	int num = 0;
	int value(int arry[], int length);
	cout << "���������飺" << endl;
	cin >> arry[0];
	while (getchar() != '\n')      //��������
	{
		cin >> arry[length];
		length++;
	}

	for (int j = length; j<2 * length - 1; j++)   //�γɻ������飬��λ����
	{
		arry[j] = arry[num];
		num++;
	}

	cout << "���⼸�����γɵĻ�������";
	value(arry, 2 * length - 1);

}

