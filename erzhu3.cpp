//二柱子四则运算3，2016/3/14，赵子茵&孔宇航

#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<fstream>
#include<iomanip>
#include<cmath> 
#define random(x) (rand()%x)
using namespace std;

/*选择打印方式*/
void Output(int sf)
{
	if (sf == 1)//保存文档
	{
		ofstream outfile("formula.txt", ios::out);
		if (!outfile)
		{
			cout << "Open error!!" << endl;
			exit(1);
		}
		outfile << "----------------欢迎！小学生四则运算答题系统:-D----------------" << endl;
		outfile.close();
	}
}

/*判断输入0.1的是否输入正确*/
int Istrue_input(int mnu01)
{
	while (1)
	{
		if (mnu01 != 0 && mnu01 != 1)
		{
			cout << "输入有误，请重新输入（请输入0或1）:" << endl;
			cin >> mnu01;
		}
		else
			break;
	}
	return mnu01;
}

/*生成一个某范围内的随机数（正负都有）*/
int Creat_random(int r1, int r2)
{
	int r, shu;
	/*srand((int)time(0));*/
	r = r2 - r1;
	shu = r1 + rand() % r;
	return shu;
}

/*生成一个随机运算符*/
string Create_oper(int lai)
{
	srand((int)time(0));
	string sign;
	int Num_sym, Sign_num;
	if (lai == 0)//加减
		Num_sym = 2;
	else if (lai == 1)//加减乘除
		Num_sym = 4;
	Sign_num = rand() % Num_sym;//生成随机的数字代表运算符
	switch (Sign_num)
	{
	case(0) : sign = '+'; break;
	case(1) : sign = '-'; break;
	case(2) : sign = '*'; break;
	case(3) : sign = '/'; break;
	}
	return sign;
}

/*判断整数正负并取相反数*/
int Opp_zf(int a)
{
	if (a < 0)
		a = -a;
	return a;
}

/*把int类型转换为string类型*/
string Int_str(int shu)
{
	char zhuan[100];
	string str,zuo="(",you=")";
	str=itoa(shu, zhuan, 10);
	if (shu < 0)
		str = zuo + str + you;
	return str;
}

/*生成一个(某范围)真分数*/
void Creat_fen(int r1, int r2, string &fenshu, double &zhi)
{
	/*srand((int)time(0));*/
	int i, r = r2 - r1, up, down, s;
	bool flag;
	string xian = "/", fu = "-", zuo = "(", you = ")";
	/*char zhuan1[10], zhuan2[10];*/
	string zhuan1, zhuan2;
loop:do
	{
		 flag = false;//不能定义全局变量！！
		 up = r1 + rand() % r;
		 up = Opp_zf(up);
		 down = r1 + rand() % r;
		 down = Opp_zf(down);
    } while ((up >= down) || (down == 0) || (up == 0));//分子≥分母 or 分母=0 or 分子=0 重新生成
	
	for (i = 2; i <= up; i++)
	{
		/*if ((i == -1)|| (i == 0))
		continue;*/
		if (up%i == 0 && down%i == 0)
		{
			flag = true;//有公约数	
			break;
		}
	}
	if (flag == true)
	{
		goto loop;
	}
	else
	{
		zhi = (double)up / (double)down;
		//itoa(up, zhuan1, 10);//分子转换成string类型
		//itoa(down, zhuan2, 10);//分母转换成string类型
		zhuan1 = Int_str(up);//up/down都是正数不会再加一层括号
		zhuan2 = Int_str(down);
		s = rand() % 2;
		switch (s)
		{
			//正分数
		    case(0) : 
				fenshu = zuo + zhuan1 + xian + zhuan2 + you; 
			    break;
			//负分数
		    case(1) : 
				fenshu = zuo + fu + zhuan1 + xian + zhuan2 + you;
				zhi = -zhi;
				break;
		}
	}
	//return fenshu;
}

///*查重*/
//bool Is_rept(string str1, string str2)
//{
//	if (str1 == str2)
//		return true;//重复
//	return false;//不重复
//}

/*含有括号*/
void Have_kuohao(int r1, int r2, string &formula,double &zhi)
{
	srand((int)time(0));
	int op,op1, op2;
	int yn, qh;//代表“是否加括号”和“运算符在前后”的数字
	string symbol1,symbol2;
	string zhuan,zhuan1, zhuan2;
	string jia = "+", jian = "-", cheng = "*", chu = "/",zuo="(",you=")";

	zhi = (double)Creat_random(r1, r2);
	op1 = Creat_random(r1, r2);
	op2 = Creat_random(r1, r2);
	op = Creat_random(r1, r2);//假设op2做分母不能为0
	while (1)
	{
		if (op == 0)
			op = Creat_random(r1, r2);
		else
			break;
	}
	zhuan1 = Int_str(zhi);
	zhuan2 = Int_str(op);
	symbol1 = Create_oper(1);

	if (symbol1 == "+")
	{
		zhi = (double)op1 + (double)op2;
		formula = zhuan1 + jia + zhuan2;
		yn = rand() % 2;
		switch (yn)
		{
			//外面不加括号
		    case(0) : break;
			//外面加括号
			case(1) :
			{
						formula = zuo + formula + you;
						qh = rand() % 2;
						symbol2 = Create_oper(1);
						switch (qh)
						{
							//加到前面
						    case(0) :
						   {
									formula = symbol2 + formula;
									op = Creat_random(r1, r2);
									zhuan = Int_str(op);
									if (symbol2 == "+")
									{
										zhi = (double)op + zhi;
										formula = zhuan + jia + formula;
									}
									else if (symbol2 == "-")
									{
										zhi = (double)op - zhi;
										formula = zhuan + jian + formula;
									}
									else if (symbol2 == "*")
									{
										zhi = (double)op * zhi;
										formula = zhuan + cheng + formula;
									}
									else if (symbol2 == "/")
									{
										if (zhi == 0)//防止出现随机生成的除号后面的值为0；
											break;
										else
										{
											zhi = (double)op / zhi;
											formula = zhuan + chu + formula;
										}	
									}
									break;

						     }
							 //加到后面
						    case(1) :
						    {
									formula = formula + symbol2;
									op = Creat_random(r1, r2);//防止后面随机产生除号，分母为0
									while (1)
									{
										if (op == 0)
											op = Creat_random(r1, r2);
										else
											break;
									}
									zhuan = Int_str(op);
									if (symbol2 == "+")
									{
										zhi = zhi + (double)op;
										formula = formula + jia + zhuan;
									}
									else if (symbol2 == "-")
									{
										zhi = zhi - (double)op;
										formula = formula + jian + zhuan;
									}
									else if (symbol2 == "*")
									{
										zhi = zhi * (double)op;
										formula = formula + cheng + zhuan;
									}
									else if (symbol2 == "/")
									{
										zhi = zhi / (double)op;
										formula = formula + chu + zhuan;
									}
									break;
						      }

						}
						break;
			}
				
				
		}
		
		
	}
	else if (symbol1 == "-")
	{
		zhi = (double)op1 - (double)op2;
		formula = zhuan1 + jian + zhuan2;
	}
	else if (symbol1 == "*")
	{
		zhi = (double)op1 * (double)op2;
		formula = zhuan1 + cheng + zhuan2;
	}
	else if (symbol1 == "/")
	{
		zhi = (double)op1 / (double)op2;
		formula = zhuan1 + chu + zhuan2;
	}

		
	
	

}

/*含有真分数*/
void Have_fenshu(int LL, int r1, int r2, string &formula, double &zhi, int jj)
{
	srand((int)time(0));
	string F1, F2, symbol, zhuan;
	double Z1, Z2;//值
	int inter, type;
	inter = Creat_random(r1, r2);//整数
	zhuan = Int_str(inter);
	Creat_fen(r1, r2, F1, Z1);//分数1
	Creat_fen(r1, r2, F2, Z2);//分数2
	symbol = Create_oper(LL);//符号
	type = rand() % 3;//类型

	if (jj == 0)//加减没有负数
	{
		inter = Opp_zf(inter);
		zhuan = Int_str(inter);
		while (1)
		{
			if (Z1 <0)
				Creat_fen(r1, r2, F1, Z1);
			else
				break;
		}
		while (1)
		{
			if (Z2 <0)
				Creat_fen(r1, r2, F2, Z2);
			else
				break;
		}
	}

	switch (type)
	{
		//op1分数
	case(0) :
		formula = F1 + symbol + zhuan;
		if (symbol == "+")
			zhi = Z1 + (double)inter;
		else if (symbol == "-")
		{
			if (jj == 0)
				break;
			else
				zhi = Z1 - (double)inter;
		}
		else if (symbol == "*")
			zhi = Z1 * (double)inter;
		else if (symbol == "/")
		{
			if (inter != 0)
				break;
			else
				zhi = Z1 / (double)inter;
		}
		break;
		//op2分数
	case(1) :
		formula = zhuan + symbol + F1;
		if (symbol == "+")
			zhi = (double)inter + Z1;
		else if (symbol == "-")
			zhi = (double)inter - Z1;
		else if (symbol == "*")
			zhi = (double)inter * Z1;
		else if (symbol == "/")
		{
			if (Z1 != 0)
				zhi = (double)inter / Z1;
			else
				break;
		}
		break;
		//全分数  
	case(2) :
		formula = F1 + symbol + F2;
		if (symbol == "+")
			zhi = Z1 + Z2;
		else if (symbol == "-")
		{
			if ((jj == 0) && (Z1 < Z2))
				break;
			else
				zhi = Z1 - Z2;
		}
		else if (symbol == "*")
			zhi = Z1 * Z2;
		else if (symbol == "/")
		{
			if (Z1 != 0)
				zhi = Z1 / Z2;
			else
				break;
		}
		break;
	}

}

/*不含有真分数*/
void Only_integer(int LL, int r1, int r2, string &formula, double &zhi,int jj,int cc)
{
	srand((int)time(0));
	int op1, op2;
	string symbol,zhuan1,zhuan2;
	op1 = Creat_random(r1, r2);//整数1
	op2 = Creat_random(r1, r2);//整数2
	symbol = Create_oper(LL);//符号

	if (jj == 0)//加减不含负号
	{
		op1 = Opp_zf(op1);
		op2 = Opp_zf(op2);
		if ((symbol == "-") && (op1 < op2))
		{
			int temp;
			temp = op1;
			op1 = op2;
			op2 = temp;
		}
	}

	if ((cc == 0) && (symbol == "/"))//除法不含余数（去除负号计算的情况）
	{
		while (1)
		{
			op1 = Opp_zf(op1);
			op2 = Opp_zf(op2);
			if (op1 % op2 != 0)//有余数，重新生成
			{
				op1 = Creat_random(r1, r2);
				op2 = Creat_random(r1, r2);
			}
			else
				break;
		}
	}

	zhuan1 = Int_str(op1);
	zhuan2 = Int_str(op2);
	formula = zhuan1 + symbol + zhuan2;
	if (symbol == "+")
		zhi = op1 + op2;
	else if (symbol == "-")
		zhi = op1 - op2;
	else if (symbol == "*")
		zhi = op1*op2;
	else if (symbol == "/")
		zhi = op1 / op2;
}

void main()
{
	ofstream outfile("formula.txt", ios::out);
	if (!outfile)
	{
		cout << "open error!" << endl;
		exit(1);
	}
	outfile << "----------------欢迎！小学生四则运算答题系统:-D----------------" << endl;

	int i,j,N, R1, R2;
	int SF, KH, FS, Lei,JJ,CC,count=0;
	string question="";//生成的问题
	double Zhi, answer;
	int fenzi, fenmu;
	bool repeat = false;
	
	cout << "----------------欢迎！小学生四则运算答题系统:-D----------------"<<endl;
	/*选择题目范围和数量*/
	cout << "您想为孩子定制什么范围的题目呢？（可含有负数 && 上限≥下限）：" << endl;
	cout << "下限：";
	cin >> R1;
	cout << "上限：";
	cin >> R2;
	while (1)//是否输入合法
	{
		if (R2 < R1)
		{
			cout << "输入的范围不合理，请重新输入(上限≥下限):" << endl;
			cout << "下限：";
			cin >> R1;
			cout << "上限：";
			cin >> R2;
		}
		else
			break;
	}

	cout << "订制多少道题呢？请输入个数：" << endl;
	cout << "(友情提示：您不要为孩子出太多的题目(最多1000道)！谢谢合作！)" << endl;
	cin >> N;
	while (1)//是否输入合法
	{
		if (N<=0||N>1000)
		{
			cout << "输入的题目数量不合理，请重新输入:" << endl;
			cin >> N;
		}
		else
			break;
	}

	/*选择打印方式*/
	cout << "您是否需要保存文档？（0、不需要 1、需要）" << endl;
	cin >> SF;
	SF=Istrue_input(SF);//是否输入合法
	Output(SF);

	cout << "*********下面请按照孩子的学习程度选择题目的难度！！*********"<<endl;
	/*是否含有括号*/
	cout << "是否练习带有括号的难度运算？（0、不需要 1、需要）";
	cin >> KH;
	KH=Istrue_input(KH);//是否输入合法
	if (KH == 1)//含括号
	{
		for (i = 1; i <= N; i++)
		{
			string Formula = "";
			double Zhi;
			Have_kuohao(R1, R2,Formula,Zhi);  
		}
		

	}

    //不含括号
	else if (KH == 0)
	{
		/*加减运算或者四则运算*/
		cout << "请选择：0、只进行加减运算？ 1、进行四则运算？";
		cin >> Lei;
		Lei=Istrue_input(Lei);//是否输入合法

		cout << "加减运算中是否有负数？（0、没有 1、有）";
		cin >> JJ;
		JJ = Istrue_input(JJ);
	
		if (Lei == 1)//乘除
		{
			cout << "除法中是否出现余数？（0、没有 1、有）";
			cin >> CC;
			CC = Istrue_input(CC);
		}

		/*是否含有真分数*/
		cout << "题目中是否含有真分数？（0、不需要 1、需要）";
		cin >> FS;
		Istrue_input(FS);//是否输入合法

		cout << N << "道题目如下：" << endl;
		if (SF == 1)//文件输出
		{
			outfile << N << "道题目如下：" << endl;
		}
		string ku[10000] = {};
		
		for (i = 1; i <= N; i++)
		{
			if (FS == 0)//全整数
				Only_integer(Lei, R1, R2, question, Zhi, JJ, CC);
			else if (FS == 1)//含真分数
				Have_fenshu(Lei, R1, R2, question, Zhi, JJ);

			ku[i] = question;
			/*repeat = false;*/
			for (j = 0; j <i; j++)
			{
				if (ku[j] == ku[i])
				{
					i = i - 1;
					repeat = true;//重复
					break;
				}
			}
			/*if (repeat) ku[i+1] = "";*/
			if (!repeat)//不重复
			{
				/*Is_rept(i,str);*/
				cout << i << "、 " << question << " = " << endl;
				if (SF == 1)//文件输出
				{
					outfile << i << "、 " << question << " = " << Zhi << endl;
				}

				if ((Zhi - (int)Zhi)< 1E-7 && (Zhi - (int)Zhi)> -(1E-7))//可认为它是整数
				{
					cin >> answer;
				}
				else
				{
					cout << "    分子：";
					cin >> fenzi;
					cout << "    分母：";
					cin >> fenmu;
					answer = (double)fenzi / (double)fenmu;
				}
				
				if ((answer - Zhi) < 1E-7 && (answer - Zhi) > -(1E-7))
				{
					cout << "                        √" << endl;
					count++;
				}
				else
				{
					cout << "                        ×" << endl;
					cout << "答案是：" << Zhi << endl;
				}
			}
		}
		
		cout << "您的孩子一共答对了" << count << "道题目！！ 恭喜！！" << endl;
		if (SF == 1)//文件输出
		{
			outfile << "您的孩子一共答对了" << count << "道题目！！ 恭喜！！" << endl;
		}
		cout << "答错的" << N - count << "道题目请分析原因并改正~~  加油！！" << endl;
		if (SF == 1)//文件输出
		{
			outfile << "答错的" << N - count << "道题目请分析原因并改正~~  加油！！" << endl;
		}
	}
	outfile.close();

}
