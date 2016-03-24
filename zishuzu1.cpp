//返回一个整数数组中最大子数组的和
//孔宇航，赵子茵 2016/3/21

#include<iostream>
using namespace std;

int main()
{
	int arr[1000];
	int i, MaxSum = 0, max, sum = 0, num = 1, count = 0;
	/*MaxSum是子数组最大和
	  max是整数组的最大值
	  sum是子数组的和
	  num是元素个数
	  count是元素中负数的个数*/
	cout << "请输入一个整数数组（不超过1000个）：" << endl;
	cin >> arr[0];
	while (getchar() != '\n')
	{
		cin >> arr[num];
		num++;
	}

	for (i = 0; i < num; i++)
	{
		if (sum < 0)
			sum = arr[i];//当子数组和小于0时，与无论与后面数组如何相加，和肯定小于后一段数组之和，此时，将b重新赋值，置为下一个元素
		else
			sum += arr[i];
		if (MaxSum < sum)
			MaxSum = sum;
	}

	max = arr[0];//d记录数组中的最大元素值
	for (i = 0; i<num; i++)  //如果数组全为负数，最大子数组和就是数组中最大值
	{
		if (arr[i]<0)
			count++;
		if (arr[i]>max)
			max = arr[i];
		if (count == num)
			MaxSum = max;

	}
	cout << "子数组的最大和为：" << MaxSum << endl;
	return 0;

}


