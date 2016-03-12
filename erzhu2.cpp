//Zhao Ziyin，2016/3/11，Four arithmetics（2）

#include<iostream>
#include<time.h>
#include<string>
#include<fstream>
using namespace std;
//#define N 
#define random(x) (rand()%x)
int MM[10000][3];//临时记录算式的二维数组

/*查重的函数*/
int WheReap(int op1,int op2,int s_n,int c)
{
	//int MM[10000][3];//临时记录算式的二维数组
	int i;
	bool flag=true;
	for (i = 0; i < c; i++)
	{
		if (MM[i][0] == op1 && MM[i][1] == s_n && MM[i][2] == op2)
		{
			flag = false;//出现了重复算式
			break;
		}
	}
	if (flag)//如果没有出现重复，随机数可以赋值
	{
		MM[c][0] = op1;
		MM[c][1] = s_n;
		MM[c][2] = op2;
	}
	return flag;
}

/*加减法运算*/
void AddSub(int n, int r1,int r2)
{
	/*srand((int)time(0));*/
	int r=r2-r1, one, two,three,four, sign_num,type, count = 0;//count记录产生的第几个算式
	char sign;
	int choose1,choose2;
	bool flag_one = false, flag_two = false,flag_three=false,flag_four=false;
loop1:cout << "是否进行带真分数的练习？请选择：1、有 2、无" << endl;
	cin >> choose1;
	if (choose1 != 1 && choose1 != 2)
	{
		cout << "没有您选择的功能，请重新选择：" << endl;
		goto loop1;
	}
	else if (choose1 == 1)//含有真分数的题目
	{
	loop2: cout << "加减法运算中有无负数？请选择：1、有 2、无" << endl;
		cin >> choose2;
		if (choose2 != 1 && choose2 != 2)
		{
			cout << "没有您选择的功能，请重新选择：" << endl;
			goto loop2;
		}
		cout << "系统将为您出" << n << "道加减法的运算题目：" << endl;
		if (choose2 == 1)//可以含有负数
		{
			srand((int)time(0));
			while (count < n)
			{
				one = r1 + rand() % r;
				two = r1 + rand() % r;
				three = r1 + rand() % r;
				four = r1 + rand() % r;
				if (one < 0)//记录第一个操作数为负数（true）
					flag_one = true;
				if (two < 0)//记录第二个操作数为负数（true）
					flag_two = true;
				if (three < 0)//记录第三个操作数为负数（true）
					flag_three = true;
				if (four < 0)//记录第四个操作数为负数（true）
					flag_four = true;
				//随机生成运算符
				sign_num = rand() % 2;
				switch (sign_num)
				{
				case(0) : sign = '+'; break;
				case(1) : sign = '-'; break;
				}
				//随机生成运算数的类型
				type = rand() % 4;
				switch (type)
				{
				case(0) ://两个整数
				{
							 if (!WheReap(one, two, sign_num, count))//如果有重复
								 count--;
							 else//如果没有重复
							 {
								 if (flag_one && !flag_two)//如果op1为负，op2为正
									 cout << count << "、 (" << one << ") " << sign << " " << two << endl;
								 if (!flag_one && flag_two)//如果op1为正，op2为负
									 cout << count << "、 " << one << " " << sign << " (" << two << ")" << endl;
								 if (flag_one && flag_two)//如果op1、op2都为负
									 cout << count << "、 （" << one << ") " << sign << " (" << two << ")" << endl;
							 }
							 break;
				}
				case(1) ://op1为真分数
				{
							 if (one > two)//第一个真分数的分子要小于分母
							 {
								 int tmp;
								 tmp = one;
								 one = two;
								 two = tmp;
							 }
							 bool flag_OT = false;
							 if ((one<0 && two>0) || (one > 0 && two < 0))//记录第一个真分数为负数（true）
								 flag_OT = true;
							 if (two!=0)//分母不为0
							 {
								 if (flag_OT && !flag_three)//如果op1为负，op2为正
									 cout << count << "、 (" << one << "/" << two << ") " << sign << " " << three << endl;
								 if (!flag_OT && flag_three)//如果op1为正，op2为负
									 cout << count << "、 " << one << "/" << two << " " << sign << " (" << three << ")" << endl;
								 if (flag_OT && flag_three)//如果op1、op2都为负
									 cout << count << "、 （" << one << "/" << two << ") " << sign << " (" << three << ")" << endl;
							 }
							 break;

				}
				case(2) ://op2为真分数
				{
							 if (three > four)//第二真分数的分子要小于分母
							 {
								 int tmp;
								 tmp = three;
								 three = four;
								 four = tmp;
							 }
							 bool flag_TF = false;
							 if ((three<0 && four>0) || (three > 0 && four < 0))//记录第二个真分数为负数（true）
								 flag_TF = true;
							 if (four!=0)//分母不为0
							 {
								 if (flag_one && !flag_TF)//如果op1为负，op2为正
									 cout << count << "、 (" << one << ") " << sign << " " << three << "/" << four << endl;
								 if (!flag_one && flag_TF)//如果op1为正，op2为负
									 cout << count << "、 " << one << " " << sign << " (" << three << "/" << four << ")" << endl;
								 if (flag_one && flag_TF)//如果op1、op2都为负
									 cout << count << "、 （" << one << ") " << sign << " (" << three << "/" << four << ")" << endl;
							 }
							 break;
				}
				case(3) ://两个数都为真分数
				{
							 if (one > two)//第一个真分数的分子要小于分母
							 {
								 int tmp;
								 tmp = one;
								 one = two;
								 two = tmp;
							 }
							 if (three > four)//第二真分数的分子要小于分母
							 {
								 int tmp;
								 tmp = three;
								 three = four;
								 four = tmp;
							 }
							 bool flag_OT = false;
							 if ((one<0 && two>0) || (one > 0 && two < 0))//记录第一个真分数为负数（true）
								 flag_OT = true;

							 bool flag_TF = false;
							 if ((three<0 && four>0) || (three > 0 && four < 0))//记录第二个真分数为负数（true）
								 flag_TF = true;

							 if (two!=0 &&four!=0)//分母不为0
							 {
								 if (flag_OT && !flag_TF)//如果op1为负，op2为正
									 cout << count << "、 (" << one << "/" << two << ") " << sign << " " << three << "/" << four << endl;
								 if (!flag_OT && flag_TF)//如果op1为正，op2为负
									 cout << count << "、 " << one << "/" << two << " " << sign << " (" << three << "/" << four << ")" << endl;
								 if (flag_OT && flag_TF)//如果op1、op2都为负
									 cout << count << "、 (" << one << "/" << two << ") " << sign << " (" << three << "/" << four << ")" << endl;
							 }
							 break;
				}

				}
				count++;
			}
		}
		if (choose2 == 2)//不可以含有负数
		{
			srand((int)time(0));
			while (count < n)
			{
				one = r1 + rand() % r;
				two = r1 + rand() % r;
				three = r1 + rand() % r;
				four = r1 + rand() % r;
				//负数变为相反数
				if (one < 0)
					one = -one;
				if (two < 0)
					two = -two;
				if (three < 0)
					three = -three;
				if (four < 0)
					four = -four;

				//随机生成运算符
				sign_num = rand() % 2;
				switch (sign_num)
				{
				case(0) : sign = '+'; break;
				case(1) : sign = '-'; break;
				}
				
				//随机生成运算数的类型
				type = rand() % 4;
				switch (type)
				{
				case(0) ://两个整数
				{
							 if (sign == '-')
							 {
								 if (one < two)//被减数大于减数
								 {
									 int tmp;
									 tmp = one;
									 one = two;
									 two = tmp;
								 }
							 }
							 if (!WheReap(one, two, sign_num, count))//如果有重复
								 count--;
							 else//如果没有重复
								 cout << count << "、 " << one << " " << sign << " " << two << endl;
							 break;
				}
				case(1) ://op1为真分数
				{
								 if (sign != '-')
								 {
										 if (one > two)//第一个真分数的分子要小于分母
										 {
											 int tmp;
											 tmp = one;
											 one = two;
											 two = tmp;
										 }
										 if (two != 0)//分母不为0
										    cout << count << "、 " << one << "/" << two << " " << sign << " " << three << endl;
								 }
							 break;
				}
				case(2) ://op2为真分数
				{
								 if (three > four)//第二真分数的分子要小于分母
								 {
									 int tmp;
									 tmp = three;
									 three = four;
									 four = tmp;
								 }
								 if (four != 0) //分母不为0
								     cout << count << "、 " << one << " " << sign << " " << three << "/" << four << endl;
							 break;
				}
				case(3) ://两个数都为真分数
				{
							 if (one > two)//第一个真分数的分子要小于分母
							 {
								 int tmp;
								 tmp = one;
								 one = two;
								 two = tmp;
							 }
							 if (three > four)//第二个真分数的分子要小于分母
							 {
								 int tmp;
								 tmp = three;
								 three = four;
								 four = tmp;
							 }
							 float OT, TF;
							 OT = one / two;
							 TF = three / four;
							 if (two != 0 && four != 0)//分母不为0
							 {
								 if (sign == '-')//减法被减数大于减数
								 {
									 if (OT<TF)
										 cout << count << "、 " << three << "/" << four << " " << sign << " " << one << "/" << two << endl;
									 else if (OT>TF)
										 cout << count << "、 " << one << "/" << two << " " << sign << " " << three << "/" << four << endl;
								 }
								 cout << count << "、 " << one << "/" << two << " " << sign << " " << three << "/" << four << endl;
							 }
							 break;
				}

				}
			     count++;
			}
		  }
		}
		else if (choose1 == 2)//不含有真分数的题目
		{
			int choose3;
		loop3: cout << "加减法运算中有无负数？请选择：1、有 2、无" << endl;
			cin >> choose3;
			if (choose3 != 1 && choose3 != 2)
			{
				cout << "没有您选择的功能，请重新选择：" << endl;
				goto loop3;
			}
			cout << "系统将为您出" << n << "道加减法的运算题目：" << endl;
			if (choose3 == 1)//包含负数
			{
				srand((int)time(0));
				while (count < n)
				{
					one = r1 + rand() % r;
					two = r1 + rand() % r;
					if (one < 0)//记录第一个操作数为负数（true）
						flag_one = true;
					if (two < 0)//记录第二个操作数为负数（true）
						flag_two = true;
					//随机生成运算符
					sign_num = rand() % 2;
					switch (sign_num)
					{
					case(0) : 
					{
								sign = '+';
								if (!WheReap(one, two, sign_num, count))//如果有重复
									count--;
								else//如果没有重复
								{
									if (flag_one && !flag_two)//如果op1为负，op2为正
										cout << count << "、 (" << one << ") " << sign << " " << two << endl;
									if (!flag_one && flag_two)//如果op1为正，op2为负
										cout << count << "、 " << one << " " << sign << " (" << two << ")" << endl;
									if (flag_one && flag_two)//如果op1、op2都为负
										cout << count << "、 （" << one << ") " << sign << " (" << two << ")" << endl;
								}
								break;
					}
					case(1) :
					{
								sign = '-';
								if (!WheReap(one, two, sign_num, count))//如果有重复
									count--;
								else//如果没有重复
								{
									if (flag_one && !flag_two)//如果op1为负，op2为正
										cout << count << "、 (" << one << ") " << sign << " " << two << endl;
									if (!flag_one && flag_two)//如果op1为正，op2为负
										cout << count << "、 " << one << " " << sign << " (" << two << ")" << endl;
									if (flag_one && flag_two)//如果op1、op2都为负
										cout << count << "、 （" << one << ") " << sign << " (" << two << ")" << endl;
								}
								break;
					}
					}
					count++;
				}
			}
			else if (choose3 == 2)//不包含负数
			{
				srand((int)time(0));
				while (count < n)
				{
					one = r1 + rand() % r;
					two = r1 + rand() % r;
					//负数变为相反数
					if (one < 0)
						one = -one;
					if (two < 0)
						two = -two;
					//随机生成运算符
					sign_num = rand() % 2;
					switch (sign_num)
					{
					case(0) :
					{
								sign = '+';
								if (!WheReap(one, two, sign_num, count))//如果有重复
									count--;
								else//如果没有重复
									cout << count << "、 " << one << " " << sign << " " << two << endl;
								break;		
					}
					case(1) : 
					{
								sign = '-';
								if (one < two)//被减数大于减数
								{
									int tmp;
									tmp = one;
									one = two;
									two = tmp;
								}
								if (!WheReap(one, two, sign_num, count))//如果有重复
									count--;
								else//如果没有重复
									cout << count << "、 " << one << " " << sign << " " << two << endl;
								break;
					}
					}
					count++;
				}
			}

		}

}

/*加减乘除运算*/
void FourOper(int n, int r1, int r2)
{
	int r = r2 - r1, one, two, three, four, sign_num, type, count = 0;//count记录产生的第几个算式
	char sign;
	int choose1, choose2;
	bool flag_one = false, flag_two = false, flag_three = false, flag_four = false;
loop1:cout << "是否进行带真分数的练习？请选择：1、有 2、无" << endl;
	cin >> choose1;
	if (choose1 != 1 && choose1 != 2)
	{
		cout << "没有您选择的功能，请重新选择：" << endl;
		goto loop1;
	}
	else if (choose1 == 1)//含有真分数的题目
	{
	loop2: cout << "除法运算中有无余数？请选择：1、有 2、无" << endl;
		cin >> choose2;
		if (choose2 != 1 && choose2 != 2)
		{
			cout << "没有您选择的功能，请重新选择：" << endl;
			goto loop2;
		}
		cout << "系统将为您出" << n << "道按您定制的四则运算题目：" << endl;

		srand((int)time(0));
		while (count < n)
		{
			one = r1 + rand() % r;
			two = r1 + rand() % r;
			three = r1 + rand() % r;
			four = r1 + rand() % r;

			//随机生成运算符
			sign_num = rand() % 4;
			switch (sign_num)//利用随机数随机产生运算符
			{
		    case(0) ://加法运算
			{
						sign = '+';
				loop4:	type = rand() % 4;
						switch(type)
						{
			            case(0) ://两个整数
			            {
						 if (!WheReap(one, two, sign_num, count))//如果有重复
							 count--;
						 else//如果没有重复
						 {
							 if (one < 0)//记录第一个操作数为负数（true）
								 flag_one = true;
							 if (two < 0)//记录第二个操作数为负数（true）
								 flag_two = true;

							 if (!flag_one && !flag_two)//如果op1、op2都为正
								 cout << count << "、 " << one << " " << sign << " " << two << endl;
							 if (flag_one && !flag_two)//如果op1为负，op2为正
								 cout << count << "、 (" << one << ") " << sign << " " << two << endl;
							 if (!flag_one && flag_two)//如果op1为正，op2为负
								 cout << count << "、 " << one << " " << sign << " (" << two << ")" << endl;
							 if (flag_one && flag_two)//如果op1、op2都为负
								 cout << count << "、 （" << one << ") " << sign << " (" << two << ")" << endl;
						 }
						 break;
			            }
			           case(1) ://op1为真分数
			          {
						 if (one > two)//第一个真分数的分子要小于分母
						 {
							 int tmp;
							 tmp = one;
							 one = two;
							 two = tmp;
						 }
						 if (one < 0)//记录第一个操作数为负数（true）
							 flag_one = true;
						 if (two < 0)//记录第二个操作数为负数（true）
							 flag_two = true;
						 if (three < 0)//记录第三个操作数为负数（true）
							 flag_three = true;
						 if (four < 0)//记录第四个操作数为负数（true）
							 flag_four = true;
						 bool flag_OT = false;
						 if ((one<0 && two>0) || (one > 0 && two < 0))//记录第一个真分数为负数（true）
							 flag_OT = true;
						 if (two != 0)//分母不为0
						 {
							 if (!flag_OT && !flag_three)//如果op1、op2都为正
								 cout << count << "、 " << one<<"/"<<two << " " << sign << " " << three << endl;
							 if (flag_OT && !flag_three)//如果op1为负，op2为正
								 cout << count << "、 (" << one << "/" << two << ") " << sign << " " << three << endl;
							 if (!flag_OT && flag_three)//如果op1为正，op2为负
								 cout << count << "、 " << one << "/" << two << " " << sign << " (" << three << ")" << endl;
							 if (flag_OT && flag_three)//如果op1、op2都为负
								 cout << count << "、 （" << one << "/" << two << ") " << sign << " (" << three << ")" << endl;
						 }
						 break;
			           }
			           case(2) ://op2为真分数
			          {
						 if (three > four)//第二真分数的分子要小于分母
						 {
							 int tmp;
							 tmp = three;
							 three = four;
							 four = tmp;
						 }
						 if (one < 0)//记录第一个操作数为负数（true）
							 flag_one = true;
						 if (two < 0)//记录第二个操作数为负数（true）
							 flag_two = true;
						 if (three < 0)//记录第三个操作数为负数（true）
							 flag_three = true;
						 if (four < 0)//记录第四个操作数为负数（true）
							 flag_four = true;
						 bool flag_TF = false;
						 if ((three<0 && four>0) || (three > 0 && four < 0))//记录第二个真分数为负数（true）
							 flag_TF = true;
						 if (four != 0)//分母不为0
						 {
							 if (!flag_one && !flag_TF)//如果op1、op2都为正
								 cout << count << "、 " << one << " " << sign << " " << three<<"/"<<four << endl;
							 if (flag_one && !flag_TF)//如果op1为负，op2为正
								 cout << count << "、 (" << one << ") " << sign << " " << three << "/" << four << endl;
							 if (!flag_one && flag_TF)//如果op1为正，op2为负
								 cout << count << "、 " << one << " " << sign << " (" << three << "/" << four << ")" << endl;
							 if (flag_one && flag_TF)//如果op1、op2都为负
								 cout << count << "、 （" << one << ") " << sign << " (" << three << "/" << four << ")" << endl;
						 }
						 break;
			           }
			          case(3) ://两个数都为真分数
			         {
						 if (one > two)//第一个真分数的分子要小于分母
						 {
							 int tmp;
							 tmp = one;
							 one = two;
							 two = tmp;
						 }
						 if (three > four)//第二真分数的分子要小于分母
						 {
							 int tmp;
							 tmp = three;
							 three = four;
							 four = tmp;
						 }
						 if (one < 0)//记录第一个操作数为负数（true）
							 flag_one = true;
						 if (two < 0)//记录第二个操作数为负数（true）
							 flag_two = true;
						 if (three < 0)//记录第三个操作数为负数（true）
							 flag_three = true;
						 if (four < 0)//记录第四个操作数为负数（true）
							 flag_four = true;
						 bool flag_OT = false;
						 if ((one<0 && two>0) || (one > 0 && two < 0))//记录第一个真分数为负数（true）
							 flag_OT = true;

						 bool flag_TF = false;
						 if ((three<0 && four>0) || (three > 0 && four < 0))//记录第二个真分数为负数（true）
							 flag_TF = true;
						 if (two != 0 && four != 0)//分母不为0
						 {
							 if (!flag_OT && !flag_TF)//如果op1、op2都为正
								 cout << count << "、 " << one <<"/"<<two<< " " << sign << " " << three << "/" << four << endl;
							 if (flag_OT && !flag_TF)//如果op1为负，op2为正
								 cout << count << "、 (" << one << "/" << two << ") " << sign << " " << three << "/" << four << endl;
							 if (!flag_OT && flag_TF)//如果op1为正，op2为负
								 cout << count << "、 " << one << "/" << two << " " << sign << " (" << three << "/" << four << ")" << endl;
							 if (flag_OT && flag_TF)//如果op1、op2都为负
								 cout << count << "、 (" << one << "/" << two << ") " << sign << " (" << three << "/" << four << ")" << endl;
						 }
						 break;
			             }
						}
					break; 
			}
			case(1) :
			{
						sign = '-';
						goto loop4;
						
			}		
			case(2) :
			{
						sign = '*';
						goto loop4;
			}
			case(3) :
			{
						sign = '/';
						if (one < two)
						{
							int tmp;
							tmp = one;
							one = two;
							two = tmp;
						}
						if (one < 0)//记录第一个操作数为负数（true）
							flag_one = true;
						if (two < 0)//记录第二个操作数为负数（true）
							flag_two = true;
			
						if (two != 0)
						{
							int yu = one%two;
							if (choose2 == 1)//除法运算含有余数
							{
								if (yu != 0)
								{
									if (!flag_one && !flag_two)//如果op1、op2都为正
										cout << count << "、 " << one << " " << sign << " " << two << endl;
									if (flag_one && !flag_two)//如果op1为负，op2为正
										cout << count << "、 (" << one << ") " << sign << " " << two << endl;
									if (!flag_one && flag_two)//如果op1为正，op2为负
										cout << count << "、 " << one << " " << sign << " (" << two << ")" << endl;
									if (flag_one && flag_two)//如果op1、op2都为负
										cout << count << "、 （" << one << ") " << sign << " (" << two << ")" << endl;
								}
							}
							else if (choose2 == 2)//除法运算不含余数
							{
								if (yu == 0)
								{
									if (!flag_one && !flag_two)//如果op1、op2都为正
										cout << count << "、 " << one << " " << sign << " " << two << endl;
									if (flag_one && !flag_two)//如果op1为负，op2为正
										cout << count << "、 (" << one << ") " << sign << " " << two << endl;
									if (!flag_one && flag_two)//如果op1为正，op2为负
										cout << count << "、 " << one << " " << sign << " (" << two << ")" << endl;
									if (flag_one && flag_two)//如果op1、op2都为负
										cout << count << "、 （" << one << ") " << sign << " (" << two << ")" << endl;
								}
							}
						}
						break; 
			}
			}
			count++;
		}
	}

	else if (choose1 == 2)//不含有真分数的题目
	{
		int choose3;
	loop3: cout << "除法运算中有无余数？请选择：1、有 2、无" << endl;
		cin >> choose3;
		if (choose3 != 1 && choose3 != 2)
		{
			cout << "没有您选择的功能，请重新选择：" << endl;
			goto loop3;
		}
		cout << "系统将为您出" << n << "道按您定制的四则运算题目：" << endl;

		srand((int)time(0));
		while (count < n)
		{
			one = r1 + rand() % r;
			two = r1 + rand() % r;
			if (one < 0)//记录第一个操作数为负数（true）
				flag_one = true;
			if (two < 0)//记录第二个操作数为负数（true）
				flag_two = true;
			//随机生成运算符
			sign_num = rand() % 4;
			switch (sign_num)
			{
			case(0) :
			{
						sign = '+';
				loop5:	if (one < 0)//记录第一个操作数为负数（true）
						   flag_one = true;
						if (two < 0)//记录第二个操作数为负数（true）
						   flag_two = true;
						if (!WheReap(one, two, sign_num, count))//如果有重复
							count--;
						else//如果没有重复
						{
							if (!flag_one && !flag_two)//如果op1、op2都为正
								cout << count << "、 " << one << " " << sign << " " << two << endl;
							if (flag_one && !flag_two)//如果op1为负，op2为正
								cout << count << "、 (" << one << ") " << sign << " " << two << endl;
							if (!flag_one && flag_two)//如果op1为正，op2为负
								cout << count << "、 " << one << " " << sign << " (" << two << ")" << endl;
							if (flag_one && flag_two)//如果op1、op2都为负
								cout << count << "、 （" << one << ") " << sign << " (" << two << ")" << endl;
						}
						break; 
			}
			case(1) :
			{
						sign = '-';
						goto loop5;
			}
			case(2) :
			{
						sign = '*'; 
						goto loop5;
			}
			case(3) :
			{
						sign = '/';
						if (one < two)
						{
							int tmp;
							tmp = one;
							one = two;
							two = tmp;
						}
						if (one < 0)//记录第一个操作数为负数（true）
							flag_one = true;
						if (two < 0)//记录第二个操作数为负数（true）
							flag_two = true;
						if (two != 0)
						{
							int yu = one%two;
							if (choose3 == 1)//除法运算含有余数
							{
								if (yu != 0)
								{
									if (!flag_one && !flag_two)//如果op1、op2都为正
										cout << count << "、 " << one << " " << sign << " " << two << endl;
									if (flag_one && !flag_two)//如果op1为负，op2为正
										cout << count << "、 (" << one << ") " << sign << " " << two << endl;
									if (!flag_one && flag_two)//如果op1为正，op2为负
										cout << count << "、 " << one << " " << sign << " (" << two << ")" << endl;
									if (flag_one && flag_two)//如果op1、op2都为负
										cout << count << "、 （" << one << ") " << sign << " (" << two << ")" << endl;
								}
							}
							else if (choose3 == 2)//除法运算不含余数
							{
								if (yu == 0)
								{
									if (!flag_one && !flag_two)//如果op1、op2都为正
										cout << count << "、 " << one << " " << sign << " " << two << endl;
									if (flag_one && !flag_two)//如果op1为负，op2为正
										cout << count << "、 (" << one << ") " << sign << " " << two << endl;
									if (!flag_one && flag_two)//如果op1为正，op2为负
										cout << count << "、 " << one << " " << sign << " (" << two << ")" << endl;
									if (flag_one && flag_two)//如果op1、op2都为负
										cout << count << "、 （" << one << ") " << sign << " (" << two << ")" << endl;
								}
							}
						}
						break; 
			}
			}
			count++;
		}
	}

}

/*输出打印方式*/
int Output(int o)
{
	/*int o;
	cout << "系统已经记录了您的定制参数！请选择打印的方式：（1、直接输出 2、保存到文件）"<<endl;
	cin >> o;*/
	if (o == 1)
		cout << "四则运算出题系统欢迎您！！" << endl;
	else if (o == 2)
	{
		cout << "四则运算出题系统欢迎您！！" << endl;
		ofstream outfile("formula.txt", ios::out);
		if (!outfile)
		{
			cout << "Open error!!" << endl;
			exit(1);
		}
		outfile.close();
	}
	else
		cout << "输入错误，重新选择！" << endl;

	return 0;
}

void main()
{
	/*srand((int)time(0));*/
	int O, F;
	int N,R,R1,R2,count;
	cout << "请选择您是否需要保存文档？（1、不需要 2、需要）" << endl;
	cin >> O;
	Output(O);
	cout << "您想为孩子定制什么范围的题目呢？先输入下限，再输入上限（以回车间隔，可含有负数且上限≥下限）："<<endl;
	cin >> R1;
	cin >> R2;
	while (1)//判断是否输入合法
	{
		if (R2 < R1)
		{
			cout << "您输入的范围不合理，应输入 上限≥下限，请重新输入:" << endl;
			cin >> R1;
			cin >> R2;
		}
		else
			break;
	}
    cout << "出多少道题呢？请输入个数："<<endl;
	cout << "(友情提示：您不要为孩子出太多的题目~1000道以内最好，上限是100000道！谢谢合作！)" << endl;
	cin >> N;
	cout << "请按照孩子的学习程度选择题目的难度：是否包含乘除运算？（1、是 2、否）" << endl;
	cin >> F;
	while (1)//判断是否输入合法
	{
		if (F!=1 && F!=2)
		{
			cout << "没有您想定制的功能，请重新输入（只输入1或2即可）:" << endl;
			cin >> F;
		}
		else
			break;
	}
	if (F == 1)//包含乘除法
		FourOper(N, R1, R2);
	if (F == 2)//不包含乘除法
	    AddSub(N, R1, R2);
	cout << "感谢您的使用，欢迎下次再来！祝您的孩子学习进步！！<(￣︶￣)>" << endl;
	

}



