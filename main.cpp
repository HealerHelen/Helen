//Zhao Ziyin，20160303，Four arithmetics

#include<iostream>
#include<time.h>
#include<string>
using namespace std;
#define N 30
#define random(x) (rand()%x)

void main()
{
	//循环打印
	while (true)
	{
		cout << "-----------Choose the form of formulas 1 or 2:--------------" << endl;
		cout << "              Ⅰ. Integers(like  35 + 64 = )                " << endl;
		cout << "              Ⅱ. Proper fraction(like  5/6 × 7/10 = )     " << endl;
		int num, i;
		int sign_num;//记录运算符号代表的数字
		int change;//数值交换的中间值
		cin >> num;

		//选择整数运算
		if (num == 1)
		{
			srand((int)time(0));
			cout << endl;
			cout << "-----There are " << N << " arithmetic problems:-----" << endl;

			//循环打印30次
			for (i = 1; i <= N; i++)
			{
				int one, two;
				/*srand((int)time(0));*/
				one = rand() % (99 + 1) + 1;
				two = rand() % (99 + 1) + 1;

				/*srand((int)time(0));*/
				sign_num = (rand() % (99 + 1) + 1) % 4;
				switch (sign_num)
				{
				case(0) :
					cout << i << ".  ";
					cout << one << " + " << two << " = " << endl;
					break;
				case(1) :
					if (one < two)//减法的被减数要大于减数
					{
						change = one;
						one = two;
						two = change;
					}
					cout << i << ".  ";
					cout << one << " - " << two << " = " << endl;
					break;
				case(2) :
					cout << i << ".  ";
					cout << one << " × " << two << " = " << endl;
					break;
				case(3) :
					if (one < two)//除法的被除数要大于除数
					{
						change = one;
						one = two;
						two = change;
					}
					cout << i << ".  ";
					cout << one << " ÷ " << two << " = " << endl;
					break;
				}
			}
		}

		//选择含有真分数的四则运算
		else if (num == 2)
		{
			string sign;
			srand((int)time(0));
			cout << endl;
			cout << "-----There are " << N << " proper fraction arithmetic problems:-----" << endl;

			for (i = 1; i <= N; i++)
			{
				sign_num = (rand() % (99 + 1) + 1) % 4;
				switch (sign_num)//利用随机数随机产生运算符
				{
				case(0) :
					sign = '+'; break;
				case(1) :
					sign = '-'; break;
				case(2) :
					sign = '*'; break;
				case(3) :
					sign = '/'; break;
				}

				//生成四个随机数分别做两个真分数的分子和分母
				int one, two, three, four;
				/*srand((int)time(0));*/
				one = rand() % (99 + 1) + 1;
				two = rand() % (99 + 1) + 1;
				three = rand() % (99 + 1) + 1;
				four = rand() % (99 + 1) + 1;
				if (one > two)//第一个真分数的分子要小于分母
				{
					change = one;
					one = two;
					two = change;
				}
				if (three > four)//第二个真分数的分子要小于分母
				{
					change = three;
					three = four;
					four = change;
				}

				int oper_num;
				oper_num = (rand() % (99 + 1) + 1) % 3;
				switch (oper_num)
				{
				case(0) ://真分数与真分数运算
					cout << i << ".  ";
					cout << one << "/" << two << " " << sign << " " << three << "/" << four << " = " << endl;
					break;
				case(1) ://真分数与整数运算
					cout << i << ".  ";
					cout << one << "/" << two << " " << sign << " " << four << " = " << endl;
					break;
				case(2) ://整数与真分数运算
					cout << i << ".  ";
					cout << one << " " << sign << " " << three << "/" << four << " = " << endl;
					break;
				}
			}
		}
		//输入的数字错误
		else
		{
			cout << "Choose again!" << endl;
		}

	}

}



