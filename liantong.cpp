//2016/4/1 �������ͨ������ĺ͡���������&���

#include<iostream>
#include<fstream>
using namespace std;

int Max(int n, int arr[], int *Start_mark, int *Final_mark)
{
	int step[100] = { 0 };//Step��¼ÿ������������ĺ�
	int i, sum = 0, max1 = 0;
	/* sum��������ĺ�
	   max1������������
	*/
	for (i = 0; i<n; i++)
	{
		if (sum<0)
			sum = arr[i];
		else
			sum = sum + arr[i];
		step[i] = sum;
	}
	max1 = step[0];
	for (i = 0; i<n; i++)
	{
		if (max1<step[i])
		{
			max1 = step[i];
			*Final_mark = i;
		}
	}
	for (i = *Final_mark; i >= 0; i--)
	{
		if (step[i] == arr[i])
		{
			*Start_mark = i;
			break;
		}
	}
	return max1;
}

void main()
{
	int m, n, i, j, Start_mark, Final_mark, big;
	int Max1;
	int read[10000];//��ȡ�ļ����ַ���
	int up[100], down[100], h[100];
	int Arr2[100][100], Arr1[100];
	/* m��n�е�����
	   Start_mark��ʾ������������ʼ����
	   Final_mark��ʾ������������ֹ����
	   big��ʾ�������������ͨ�������
	   Max1�Ǻ������ص�һά��������������
	   up���ÿ�������������ʼ����
	   down���ÿ�������������ֹ����
	   h���ÿ�����������ĺ�
	   Arr2��Ŷ�ά����
	   Arr1��Ų�ɵ�һά����
	*/

	/*cout << "�������ά�����������������";
	cin >> m >> n;
	cout << "�����������ά����" << endl;
	for (i = 0; i<m; i++)
	{
		for (j = 0; j<n; j++)
		{
			cin >> a[i][j];
		}
	}*/

	//�ļ�����
	ifstream infile("input.txt", ios::in);
	if (infile.is_open() == false)
	{
		cerr << "open error!" << endl;
		exit(1);
	}
	infile >> read[0];//��ȡ����m
	m = read[0];
	infile >> read[1];//��ȡ����n
	n = read[1];
	cout << "ָ���ļ���" << read[0] << "�� " << read[1] << "�еĶ�ά�������£�" << endl;
	for (i = 0; i < m; i++)//��ȡ���鲢����ʽ���
	{
		for (j = 0; j < n; j++)
		{
			infile >> read[i + 2];
			Arr2[i][j] = read[i + 2];
			cout << Arr2[i][j] << " ";
			if (j % (n - 1) == 0 && j != 0)
				//if (j == n-1)
				cout << endl;
		}
	}
	infile.close();

	//�Ѷ�ά���鰴�зֽ�Ϊ����һά����
	for (i = 0; i<m; i++)
	{
		for (j = 0; j<n; j++)
		{
			Arr1[j] = Arr2[i][j];
		}
		Max1 = Max(n, Arr1, &Start_mark, &Final_mark);
		up[i] = Start_mark;
		down[i] = Final_mark;
		h[i] = Max1;
	}

	big = h[0];
	for (i = 0; i + 1<m; i++)
	{
		if (up[i] <= down[i + 1] && down[i] >= up[i + 1])//��ͨ�������
			big += h[i + 1];
		for (j = up[i]; j<up[i + 1]; j++)
		{
			if (Arr2[i + 1][j]>0)//�Ƿ���������������
				big += Arr2[i + 1][j];     
		}
	}

	cout << "�˶�ά����������ͨ������ĺ�Ϊ��" << endl;
	cout << big << endl;
	
}