//2016/4/1 求最大联通子数组的和——赵子茵&孔宇航

#include<iostream>
#include<fstream>
using namespace std;

int Max(int n, int arr[], int *Start_mark, int *Final_mark)
{
	int step[100] = { 0 };//Step记录每步计算子数组的和
	int i, sum = 0, max1 = 0;
	/* sum是子数组的和
	   max1是子数组最大和
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
	int read[10000];//读取文件的字符集
	int up[100], down[100], h[100];
	int Arr2[100][100], Arr1[100];
	/* m行n列的数组
	   Start_mark表示最大子数组的起始坐标
	   Final_mark表示最大子数组的终止坐标
	   big表示最后输出的最大联通子数组和
	   Max1是函数返回的一维数组最大子数组和
	   up存放每行最大子数组起始坐标
	   down存放每行最大子数组终止坐标
	   h存放每行最大子数组的和
	   Arr2存放二维数组
	   Arr1存放拆成的一维数组
	*/

	/*cout << "请输入二维数组的行数和列数：";
	cin >> m >> n;
	cout << "请输入这个二维矩阵：" << endl;
	for (i = 0; i<m; i++)
	{
		for (j = 0; j<n; j++)
		{
			cin >> a[i][j];
		}
	}*/

	//文件输入
	ifstream infile("input.txt", ios::in);
	if (infile.is_open() == false)
	{
		cerr << "open error!" << endl;
		exit(1);
	}
	infile >> read[0];//读取行数m
	m = read[0];
	infile >> read[1];//读取列数n
	n = read[1];
	cout << "指定文件中" << read[0] << "行 " << read[1] << "列的二维数组如下：" << endl;
	for (i = 0; i < m; i++)//读取数组并按格式输出
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

	//把二维数组按行分解为几个一维数组
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
		if (up[i] <= down[i + 1] && down[i] >= up[i + 1])//联通，则相加
			big += h[i + 1];
		for (j = up[i]; j<up[i + 1]; j++)
		{
			if (Arr2[i + 1][j]>0)//是否独立正数，有则加
				big += Arr2[i + 1][j];     
		}
	}

	cout << "此二维数组的最大联通子数组的和为：" << endl;
	cout << big << endl;
	
}