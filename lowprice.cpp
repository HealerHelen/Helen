//���������ͼ۸� 2016/6/3 Zhao Ziyin
#include<iostream>
using namespace std;

int main()
{
	int num = 0, s, b;
	int multi, remain;
	double p_price = 8;//����Ϊ8
	double rate, low_price;

	//����
	cout << "���������������";
	cin >> num;
	while (num < 1)
	{
		cout << "�������������"<<endl;
		cout << "���������������";
		cin >> num;
	}

	multi = num / 10;//����10����
	remain = num % 10;//����
	s = num % 5;//����5������
	b = num / 5;//��
	switch (s)//����������5�ļ������ۿ���rate
	{
	case 0: rate = 0.75; break;
	case 1: rate = 1; break;
	case 2: rate = 0.95; break;
	case 3: rate = 0.9; break;
	case 4: rate = 0.8; break;
	}
	if (remain == 8)//8����������4+4����ʽ
	{
		low_price = (multi * 10 * p_price * 0.75) + (2 * 4 * p_price * 0.8);
	}
	else
	{
		low_price = (b * 5 * p_price * 0.75) + (s * p_price * rate);
	}
	cout << "��������Щ�����ͼ۸�Ϊ��" << low_price << endl;

	return 0;     
}
