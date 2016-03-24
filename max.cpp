//测试：找到(整数!!)数组中的最大值
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
	cout << "输入一组测试用例（包含10个整数数组）：" << endl;
	
	for (i = 0; i < 10; i++)
	{
		cin >> in;
		arr[i] = in;
	}
	
	int big;
	big= Largest(arr, 10);
	cout << "数组最大值为：" << big << endl;
}