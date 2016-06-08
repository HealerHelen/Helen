//求买书的最低价格 2016/6/3 Zhao Ziyin
#include<iostream>
using namespace std;

int main()
{
	int num = 0, s, b;
	int multi, remain;
	double p_price = 8;//单价为8
	double rate, low_price;

	//输入
	cout << "输入买书的数量：";
	cin >> num;
	while (num < 1)
	{
		cout << "输入的数量有误！"<<endl;
		cout << "输入买书的数量：";
		cin >> num;
	}

	multi = num / 10;//除以10的商
	remain = num % 10;//余数
	s = num % 5;//除以5的余数
	b = num / 5;//商
	switch (s)//根据数量是5的几倍求折扣率rate
	{
	case 0: rate = 0.75; break;
	case 1: rate = 1; break;
	case 2: rate = 0.95; break;
	case 3: rate = 0.9; break;
	case 4: rate = 0.8; break;
	}
	if (remain == 8)//8是特例，是4+4的形式
	{
		low_price = (multi * 10 * p_price * 0.75) + (2 * 4 * p_price * 0.8);
	}
	else
	{
		low_price = (b * 5 * p_price * 0.75) + (s * p_price * rate);
	}
	cout << "您购买这些书的最低价格为：" << low_price << endl;

	return 0;     
}
