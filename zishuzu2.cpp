//返回整数数组最大子数组和2
//孔宇航 赵子茵 2016/3/25

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
		max1 = -9999999;                   //设置最低范围
		int z = 0;
		for (int i = j; i<(length + 1) / 2 + j; i++)   //环形数组找最大子数组和
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
	for (int i = 0; i<(length + 1 / 2); i++)  //在所有和的数组中找最大值
	{
		if (max[i]>fmax)
		{
			fmax = max[i];
			q = i;
		}
	}

	int weizhi = maxweizhi[q];

	cout << "最大子数组为：" << endl;
	for (int num = q; num<q + weizhi; num++)  //输出最大子数组的位置
	{
		cout << arry[num] << " ";
	}

	cout << "其和为:  " << fmax << endl;
	return 0;
}

void main(int argc, char* argv[])
{
	int arry[N];
	int length = 1;
	int max[N], max1; //max[N]存每一次求和的结果，在其中找最大值，为所求
	int maxweizhi[N];
	int num = 0;
	int value(int arry[], int length);
	cout << "请输入数组：" << endl;
	cin >> arry[0];
	while (getchar() != '\n')      //输入数组
	{
		cin >> arry[length];
		length++;
	}

	for (int j = length; j<2 * length - 1; j++)   //形成环形数组，首位相连
	{
		arry[j] = arry[num];
		num++;
	}

	cout << "由这几个数形成的环形数组";
	value(arry, 2 * length - 1);

}

