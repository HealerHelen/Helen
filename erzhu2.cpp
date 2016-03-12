//Zhao Ziyin��2016/3/11��Four arithmetics��2��

#include<iostream>
#include<time.h>
#include<string>
#include<fstream>
using namespace std;
//#define N 
#define random(x) (rand()%x)
int MM[10000][3];//��ʱ��¼��ʽ�Ķ�ά����

/*���صĺ���*/
int WheReap(int op1,int op2,int s_n,int c)
{
	//int MM[10000][3];//��ʱ��¼��ʽ�Ķ�ά����
	int i;
	bool flag=true;
	for (i = 0; i < c; i++)
	{
		if (MM[i][0] == op1 && MM[i][1] == s_n && MM[i][2] == op2)
		{
			flag = false;//�������ظ���ʽ
			break;
		}
	}
	if (flag)//���û�г����ظ�����������Ը�ֵ
	{
		MM[c][0] = op1;
		MM[c][1] = s_n;
		MM[c][2] = op2;
	}
	return flag;
}

/*�Ӽ�������*/
void AddSub(int n, int r1,int r2)
{
	/*srand((int)time(0));*/
	int r=r2-r1, one, two,three,four, sign_num,type, count = 0;//count��¼�����ĵڼ�����ʽ
	char sign;
	int choose1,choose2;
	bool flag_one = false, flag_two = false,flag_three=false,flag_four=false;
loop1:cout << "�Ƿ���д����������ϰ����ѡ��1���� 2����" << endl;
	cin >> choose1;
	if (choose1 != 1 && choose1 != 2)
	{
		cout << "û����ѡ��Ĺ��ܣ�������ѡ��" << endl;
		goto loop1;
	}
	else if (choose1 == 1)//�������������Ŀ
	{
	loop2: cout << "�Ӽ������������޸�������ѡ��1���� 2����" << endl;
		cin >> choose2;
		if (choose2 != 1 && choose2 != 2)
		{
			cout << "û����ѡ��Ĺ��ܣ�������ѡ��" << endl;
			goto loop2;
		}
		cout << "ϵͳ��Ϊ����" << n << "���Ӽ�����������Ŀ��" << endl;
		if (choose2 == 1)//���Ժ��и���
		{
			srand((int)time(0));
			while (count < n)
			{
				one = r1 + rand() % r;
				two = r1 + rand() % r;
				three = r1 + rand() % r;
				four = r1 + rand() % r;
				if (one < 0)//��¼��һ��������Ϊ������true��
					flag_one = true;
				if (two < 0)//��¼�ڶ���������Ϊ������true��
					flag_two = true;
				if (three < 0)//��¼������������Ϊ������true��
					flag_three = true;
				if (four < 0)//��¼���ĸ�������Ϊ������true��
					flag_four = true;
				//������������
				sign_num = rand() % 2;
				switch (sign_num)
				{
				case(0) : sign = '+'; break;
				case(1) : sign = '-'; break;
				}
				//�������������������
				type = rand() % 4;
				switch (type)
				{
				case(0) ://��������
				{
							 if (!WheReap(one, two, sign_num, count))//������ظ�
								 count--;
							 else//���û���ظ�
							 {
								 if (flag_one && !flag_two)//���op1Ϊ����op2Ϊ��
									 cout << count << "�� (" << one << ") " << sign << " " << two << endl;
								 if (!flag_one && flag_two)//���op1Ϊ����op2Ϊ��
									 cout << count << "�� " << one << " " << sign << " (" << two << ")" << endl;
								 if (flag_one && flag_two)//���op1��op2��Ϊ��
									 cout << count << "�� ��" << one << ") " << sign << " (" << two << ")" << endl;
							 }
							 break;
				}
				case(1) ://op1Ϊ�����
				{
							 if (one > two)//��һ��������ķ���ҪС�ڷ�ĸ
							 {
								 int tmp;
								 tmp = one;
								 one = two;
								 two = tmp;
							 }
							 bool flag_OT = false;
							 if ((one<0 && two>0) || (one > 0 && two < 0))//��¼��һ�������Ϊ������true��
								 flag_OT = true;
							 if (two!=0)//��ĸ��Ϊ0
							 {
								 if (flag_OT && !flag_three)//���op1Ϊ����op2Ϊ��
									 cout << count << "�� (" << one << "/" << two << ") " << sign << " " << three << endl;
								 if (!flag_OT && flag_three)//���op1Ϊ����op2Ϊ��
									 cout << count << "�� " << one << "/" << two << " " << sign << " (" << three << ")" << endl;
								 if (flag_OT && flag_three)//���op1��op2��Ϊ��
									 cout << count << "�� ��" << one << "/" << two << ") " << sign << " (" << three << ")" << endl;
							 }
							 break;

				}
				case(2) ://op2Ϊ�����
				{
							 if (three > four)//�ڶ�������ķ���ҪС�ڷ�ĸ
							 {
								 int tmp;
								 tmp = three;
								 three = four;
								 four = tmp;
							 }
							 bool flag_TF = false;
							 if ((three<0 && four>0) || (three > 0 && four < 0))//��¼�ڶ��������Ϊ������true��
								 flag_TF = true;
							 if (four!=0)//��ĸ��Ϊ0
							 {
								 if (flag_one && !flag_TF)//���op1Ϊ����op2Ϊ��
									 cout << count << "�� (" << one << ") " << sign << " " << three << "/" << four << endl;
								 if (!flag_one && flag_TF)//���op1Ϊ����op2Ϊ��
									 cout << count << "�� " << one << " " << sign << " (" << three << "/" << four << ")" << endl;
								 if (flag_one && flag_TF)//���op1��op2��Ϊ��
									 cout << count << "�� ��" << one << ") " << sign << " (" << three << "/" << four << ")" << endl;
							 }
							 break;
				}
				case(3) ://��������Ϊ�����
				{
							 if (one > two)//��һ��������ķ���ҪС�ڷ�ĸ
							 {
								 int tmp;
								 tmp = one;
								 one = two;
								 two = tmp;
							 }
							 if (three > four)//�ڶ�������ķ���ҪС�ڷ�ĸ
							 {
								 int tmp;
								 tmp = three;
								 three = four;
								 four = tmp;
							 }
							 bool flag_OT = false;
							 if ((one<0 && two>0) || (one > 0 && two < 0))//��¼��һ�������Ϊ������true��
								 flag_OT = true;

							 bool flag_TF = false;
							 if ((three<0 && four>0) || (three > 0 && four < 0))//��¼�ڶ��������Ϊ������true��
								 flag_TF = true;

							 if (two!=0 &&four!=0)//��ĸ��Ϊ0
							 {
								 if (flag_OT && !flag_TF)//���op1Ϊ����op2Ϊ��
									 cout << count << "�� (" << one << "/" << two << ") " << sign << " " << three << "/" << four << endl;
								 if (!flag_OT && flag_TF)//���op1Ϊ����op2Ϊ��
									 cout << count << "�� " << one << "/" << two << " " << sign << " (" << three << "/" << four << ")" << endl;
								 if (flag_OT && flag_TF)//���op1��op2��Ϊ��
									 cout << count << "�� (" << one << "/" << two << ") " << sign << " (" << three << "/" << four << ")" << endl;
							 }
							 break;
				}

				}
				count++;
			}
		}
		if (choose2 == 2)//�����Ժ��и���
		{
			srand((int)time(0));
			while (count < n)
			{
				one = r1 + rand() % r;
				two = r1 + rand() % r;
				three = r1 + rand() % r;
				four = r1 + rand() % r;
				//������Ϊ�෴��
				if (one < 0)
					one = -one;
				if (two < 0)
					two = -two;
				if (three < 0)
					three = -three;
				if (four < 0)
					four = -four;

				//������������
				sign_num = rand() % 2;
				switch (sign_num)
				{
				case(0) : sign = '+'; break;
				case(1) : sign = '-'; break;
				}
				
				//�������������������
				type = rand() % 4;
				switch (type)
				{
				case(0) ://��������
				{
							 if (sign == '-')
							 {
								 if (one < two)//���������ڼ���
								 {
									 int tmp;
									 tmp = one;
									 one = two;
									 two = tmp;
								 }
							 }
							 if (!WheReap(one, two, sign_num, count))//������ظ�
								 count--;
							 else//���û���ظ�
								 cout << count << "�� " << one << " " << sign << " " << two << endl;
							 break;
				}
				case(1) ://op1Ϊ�����
				{
								 if (sign != '-')
								 {
										 if (one > two)//��һ��������ķ���ҪС�ڷ�ĸ
										 {
											 int tmp;
											 tmp = one;
											 one = two;
											 two = tmp;
										 }
										 if (two != 0)//��ĸ��Ϊ0
										    cout << count << "�� " << one << "/" << two << " " << sign << " " << three << endl;
								 }
							 break;
				}
				case(2) ://op2Ϊ�����
				{
								 if (three > four)//�ڶ�������ķ���ҪС�ڷ�ĸ
								 {
									 int tmp;
									 tmp = three;
									 three = four;
									 four = tmp;
								 }
								 if (four != 0) //��ĸ��Ϊ0
								     cout << count << "�� " << one << " " << sign << " " << three << "/" << four << endl;
							 break;
				}
				case(3) ://��������Ϊ�����
				{
							 if (one > two)//��һ��������ķ���ҪС�ڷ�ĸ
							 {
								 int tmp;
								 tmp = one;
								 one = two;
								 two = tmp;
							 }
							 if (three > four)//�ڶ���������ķ���ҪС�ڷ�ĸ
							 {
								 int tmp;
								 tmp = three;
								 three = four;
								 four = tmp;
							 }
							 float OT, TF;
							 OT = one / two;
							 TF = three / four;
							 if (two != 0 && four != 0)//��ĸ��Ϊ0
							 {
								 if (sign == '-')//�������������ڼ���
								 {
									 if (OT<TF)
										 cout << count << "�� " << three << "/" << four << " " << sign << " " << one << "/" << two << endl;
									 else if (OT>TF)
										 cout << count << "�� " << one << "/" << two << " " << sign << " " << three << "/" << four << endl;
								 }
								 cout << count << "�� " << one << "/" << two << " " << sign << " " << three << "/" << four << endl;
							 }
							 break;
				}

				}
			     count++;
			}
		  }
		}
		else if (choose1 == 2)//���������������Ŀ
		{
			int choose3;
		loop3: cout << "�Ӽ������������޸�������ѡ��1���� 2����" << endl;
			cin >> choose3;
			if (choose3 != 1 && choose3 != 2)
			{
				cout << "û����ѡ��Ĺ��ܣ�������ѡ��" << endl;
				goto loop3;
			}
			cout << "ϵͳ��Ϊ����" << n << "���Ӽ�����������Ŀ��" << endl;
			if (choose3 == 1)//��������
			{
				srand((int)time(0));
				while (count < n)
				{
					one = r1 + rand() % r;
					two = r1 + rand() % r;
					if (one < 0)//��¼��һ��������Ϊ������true��
						flag_one = true;
					if (two < 0)//��¼�ڶ���������Ϊ������true��
						flag_two = true;
					//������������
					sign_num = rand() % 2;
					switch (sign_num)
					{
					case(0) : 
					{
								sign = '+';
								if (!WheReap(one, two, sign_num, count))//������ظ�
									count--;
								else//���û���ظ�
								{
									if (flag_one && !flag_two)//���op1Ϊ����op2Ϊ��
										cout << count << "�� (" << one << ") " << sign << " " << two << endl;
									if (!flag_one && flag_two)//���op1Ϊ����op2Ϊ��
										cout << count << "�� " << one << " " << sign << " (" << two << ")" << endl;
									if (flag_one && flag_two)//���op1��op2��Ϊ��
										cout << count << "�� ��" << one << ") " << sign << " (" << two << ")" << endl;
								}
								break;
					}
					case(1) :
					{
								sign = '-';
								if (!WheReap(one, two, sign_num, count))//������ظ�
									count--;
								else//���û���ظ�
								{
									if (flag_one && !flag_two)//���op1Ϊ����op2Ϊ��
										cout << count << "�� (" << one << ") " << sign << " " << two << endl;
									if (!flag_one && flag_two)//���op1Ϊ����op2Ϊ��
										cout << count << "�� " << one << " " << sign << " (" << two << ")" << endl;
									if (flag_one && flag_two)//���op1��op2��Ϊ��
										cout << count << "�� ��" << one << ") " << sign << " (" << two << ")" << endl;
								}
								break;
					}
					}
					count++;
				}
			}
			else if (choose3 == 2)//����������
			{
				srand((int)time(0));
				while (count < n)
				{
					one = r1 + rand() % r;
					two = r1 + rand() % r;
					//������Ϊ�෴��
					if (one < 0)
						one = -one;
					if (two < 0)
						two = -two;
					//������������
					sign_num = rand() % 2;
					switch (sign_num)
					{
					case(0) :
					{
								sign = '+';
								if (!WheReap(one, two, sign_num, count))//������ظ�
									count--;
								else//���û���ظ�
									cout << count << "�� " << one << " " << sign << " " << two << endl;
								break;		
					}
					case(1) : 
					{
								sign = '-';
								if (one < two)//���������ڼ���
								{
									int tmp;
									tmp = one;
									one = two;
									two = tmp;
								}
								if (!WheReap(one, two, sign_num, count))//������ظ�
									count--;
								else//���û���ظ�
									cout << count << "�� " << one << " " << sign << " " << two << endl;
								break;
					}
					}
					count++;
				}
			}

		}

}

/*�Ӽ��˳�����*/
void FourOper(int n, int r1, int r2)
{
	int r = r2 - r1, one, two, three, four, sign_num, type, count = 0;//count��¼�����ĵڼ�����ʽ
	char sign;
	int choose1, choose2;
	bool flag_one = false, flag_two = false, flag_three = false, flag_four = false;
loop1:cout << "�Ƿ���д����������ϰ����ѡ��1���� 2����" << endl;
	cin >> choose1;
	if (choose1 != 1 && choose1 != 2)
	{
		cout << "û����ѡ��Ĺ��ܣ�������ѡ��" << endl;
		goto loop1;
	}
	else if (choose1 == 1)//�������������Ŀ
	{
	loop2: cout << "����������������������ѡ��1���� 2����" << endl;
		cin >> choose2;
		if (choose2 != 1 && choose2 != 2)
		{
			cout << "û����ѡ��Ĺ��ܣ�������ѡ��" << endl;
			goto loop2;
		}
		cout << "ϵͳ��Ϊ����" << n << "���������Ƶ�����������Ŀ��" << endl;

		srand((int)time(0));
		while (count < n)
		{
			one = r1 + rand() % r;
			two = r1 + rand() % r;
			three = r1 + rand() % r;
			four = r1 + rand() % r;

			//������������
			sign_num = rand() % 4;
			switch (sign_num)//���������������������
			{
		    case(0) ://�ӷ�����
			{
						sign = '+';
				loop4:	type = rand() % 4;
						switch(type)
						{
			            case(0) ://��������
			            {
						 if (!WheReap(one, two, sign_num, count))//������ظ�
							 count--;
						 else//���û���ظ�
						 {
							 if (one < 0)//��¼��һ��������Ϊ������true��
								 flag_one = true;
							 if (two < 0)//��¼�ڶ���������Ϊ������true��
								 flag_two = true;

							 if (!flag_one && !flag_two)//���op1��op2��Ϊ��
								 cout << count << "�� " << one << " " << sign << " " << two << endl;
							 if (flag_one && !flag_two)//���op1Ϊ����op2Ϊ��
								 cout << count << "�� (" << one << ") " << sign << " " << two << endl;
							 if (!flag_one && flag_two)//���op1Ϊ����op2Ϊ��
								 cout << count << "�� " << one << " " << sign << " (" << two << ")" << endl;
							 if (flag_one && flag_two)//���op1��op2��Ϊ��
								 cout << count << "�� ��" << one << ") " << sign << " (" << two << ")" << endl;
						 }
						 break;
			            }
			           case(1) ://op1Ϊ�����
			          {
						 if (one > two)//��һ��������ķ���ҪС�ڷ�ĸ
						 {
							 int tmp;
							 tmp = one;
							 one = two;
							 two = tmp;
						 }
						 if (one < 0)//��¼��һ��������Ϊ������true��
							 flag_one = true;
						 if (two < 0)//��¼�ڶ���������Ϊ������true��
							 flag_two = true;
						 if (three < 0)//��¼������������Ϊ������true��
							 flag_three = true;
						 if (four < 0)//��¼���ĸ�������Ϊ������true��
							 flag_four = true;
						 bool flag_OT = false;
						 if ((one<0 && two>0) || (one > 0 && two < 0))//��¼��һ�������Ϊ������true��
							 flag_OT = true;
						 if (two != 0)//��ĸ��Ϊ0
						 {
							 if (!flag_OT && !flag_three)//���op1��op2��Ϊ��
								 cout << count << "�� " << one<<"/"<<two << " " << sign << " " << three << endl;
							 if (flag_OT && !flag_three)//���op1Ϊ����op2Ϊ��
								 cout << count << "�� (" << one << "/" << two << ") " << sign << " " << three << endl;
							 if (!flag_OT && flag_three)//���op1Ϊ����op2Ϊ��
								 cout << count << "�� " << one << "/" << two << " " << sign << " (" << three << ")" << endl;
							 if (flag_OT && flag_three)//���op1��op2��Ϊ��
								 cout << count << "�� ��" << one << "/" << two << ") " << sign << " (" << three << ")" << endl;
						 }
						 break;
			           }
			           case(2) ://op2Ϊ�����
			          {
						 if (three > four)//�ڶ�������ķ���ҪС�ڷ�ĸ
						 {
							 int tmp;
							 tmp = three;
							 three = four;
							 four = tmp;
						 }
						 if (one < 0)//��¼��һ��������Ϊ������true��
							 flag_one = true;
						 if (two < 0)//��¼�ڶ���������Ϊ������true��
							 flag_two = true;
						 if (three < 0)//��¼������������Ϊ������true��
							 flag_three = true;
						 if (four < 0)//��¼���ĸ�������Ϊ������true��
							 flag_four = true;
						 bool flag_TF = false;
						 if ((three<0 && four>0) || (three > 0 && four < 0))//��¼�ڶ��������Ϊ������true��
							 flag_TF = true;
						 if (four != 0)//��ĸ��Ϊ0
						 {
							 if (!flag_one && !flag_TF)//���op1��op2��Ϊ��
								 cout << count << "�� " << one << " " << sign << " " << three<<"/"<<four << endl;
							 if (flag_one && !flag_TF)//���op1Ϊ����op2Ϊ��
								 cout << count << "�� (" << one << ") " << sign << " " << three << "/" << four << endl;
							 if (!flag_one && flag_TF)//���op1Ϊ����op2Ϊ��
								 cout << count << "�� " << one << " " << sign << " (" << three << "/" << four << ")" << endl;
							 if (flag_one && flag_TF)//���op1��op2��Ϊ��
								 cout << count << "�� ��" << one << ") " << sign << " (" << three << "/" << four << ")" << endl;
						 }
						 break;
			           }
			          case(3) ://��������Ϊ�����
			         {
						 if (one > two)//��һ��������ķ���ҪС�ڷ�ĸ
						 {
							 int tmp;
							 tmp = one;
							 one = two;
							 two = tmp;
						 }
						 if (three > four)//�ڶ�������ķ���ҪС�ڷ�ĸ
						 {
							 int tmp;
							 tmp = three;
							 three = four;
							 four = tmp;
						 }
						 if (one < 0)//��¼��һ��������Ϊ������true��
							 flag_one = true;
						 if (two < 0)//��¼�ڶ���������Ϊ������true��
							 flag_two = true;
						 if (three < 0)//��¼������������Ϊ������true��
							 flag_three = true;
						 if (four < 0)//��¼���ĸ�������Ϊ������true��
							 flag_four = true;
						 bool flag_OT = false;
						 if ((one<0 && two>0) || (one > 0 && two < 0))//��¼��һ�������Ϊ������true��
							 flag_OT = true;

						 bool flag_TF = false;
						 if ((three<0 && four>0) || (three > 0 && four < 0))//��¼�ڶ��������Ϊ������true��
							 flag_TF = true;
						 if (two != 0 && four != 0)//��ĸ��Ϊ0
						 {
							 if (!flag_OT && !flag_TF)//���op1��op2��Ϊ��
								 cout << count << "�� " << one <<"/"<<two<< " " << sign << " " << three << "/" << four << endl;
							 if (flag_OT && !flag_TF)//���op1Ϊ����op2Ϊ��
								 cout << count << "�� (" << one << "/" << two << ") " << sign << " " << three << "/" << four << endl;
							 if (!flag_OT && flag_TF)//���op1Ϊ����op2Ϊ��
								 cout << count << "�� " << one << "/" << two << " " << sign << " (" << three << "/" << four << ")" << endl;
							 if (flag_OT && flag_TF)//���op1��op2��Ϊ��
								 cout << count << "�� (" << one << "/" << two << ") " << sign << " (" << three << "/" << four << ")" << endl;
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
						if (one < 0)//��¼��һ��������Ϊ������true��
							flag_one = true;
						if (two < 0)//��¼�ڶ���������Ϊ������true��
							flag_two = true;
			
						if (two != 0)
						{
							int yu = one%two;
							if (choose2 == 1)//�������㺬������
							{
								if (yu != 0)
								{
									if (!flag_one && !flag_two)//���op1��op2��Ϊ��
										cout << count << "�� " << one << " " << sign << " " << two << endl;
									if (flag_one && !flag_two)//���op1Ϊ����op2Ϊ��
										cout << count << "�� (" << one << ") " << sign << " " << two << endl;
									if (!flag_one && flag_two)//���op1Ϊ����op2Ϊ��
										cout << count << "�� " << one << " " << sign << " (" << two << ")" << endl;
									if (flag_one && flag_two)//���op1��op2��Ϊ��
										cout << count << "�� ��" << one << ") " << sign << " (" << two << ")" << endl;
								}
							}
							else if (choose2 == 2)//�������㲻������
							{
								if (yu == 0)
								{
									if (!flag_one && !flag_two)//���op1��op2��Ϊ��
										cout << count << "�� " << one << " " << sign << " " << two << endl;
									if (flag_one && !flag_two)//���op1Ϊ����op2Ϊ��
										cout << count << "�� (" << one << ") " << sign << " " << two << endl;
									if (!flag_one && flag_two)//���op1Ϊ����op2Ϊ��
										cout << count << "�� " << one << " " << sign << " (" << two << ")" << endl;
									if (flag_one && flag_two)//���op1��op2��Ϊ��
										cout << count << "�� ��" << one << ") " << sign << " (" << two << ")" << endl;
								}
							}
						}
						break; 
			}
			}
			count++;
		}
	}

	else if (choose1 == 2)//���������������Ŀ
	{
		int choose3;
	loop3: cout << "����������������������ѡ��1���� 2����" << endl;
		cin >> choose3;
		if (choose3 != 1 && choose3 != 2)
		{
			cout << "û����ѡ��Ĺ��ܣ�������ѡ��" << endl;
			goto loop3;
		}
		cout << "ϵͳ��Ϊ����" << n << "���������Ƶ�����������Ŀ��" << endl;

		srand((int)time(0));
		while (count < n)
		{
			one = r1 + rand() % r;
			two = r1 + rand() % r;
			if (one < 0)//��¼��һ��������Ϊ������true��
				flag_one = true;
			if (two < 0)//��¼�ڶ���������Ϊ������true��
				flag_two = true;
			//������������
			sign_num = rand() % 4;
			switch (sign_num)
			{
			case(0) :
			{
						sign = '+';
				loop5:	if (one < 0)//��¼��һ��������Ϊ������true��
						   flag_one = true;
						if (two < 0)//��¼�ڶ���������Ϊ������true��
						   flag_two = true;
						if (!WheReap(one, two, sign_num, count))//������ظ�
							count--;
						else//���û���ظ�
						{
							if (!flag_one && !flag_two)//���op1��op2��Ϊ��
								cout << count << "�� " << one << " " << sign << " " << two << endl;
							if (flag_one && !flag_two)//���op1Ϊ����op2Ϊ��
								cout << count << "�� (" << one << ") " << sign << " " << two << endl;
							if (!flag_one && flag_two)//���op1Ϊ����op2Ϊ��
								cout << count << "�� " << one << " " << sign << " (" << two << ")" << endl;
							if (flag_one && flag_two)//���op1��op2��Ϊ��
								cout << count << "�� ��" << one << ") " << sign << " (" << two << ")" << endl;
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
						if (one < 0)//��¼��һ��������Ϊ������true��
							flag_one = true;
						if (two < 0)//��¼�ڶ���������Ϊ������true��
							flag_two = true;
						if (two != 0)
						{
							int yu = one%two;
							if (choose3 == 1)//�������㺬������
							{
								if (yu != 0)
								{
									if (!flag_one && !flag_two)//���op1��op2��Ϊ��
										cout << count << "�� " << one << " " << sign << " " << two << endl;
									if (flag_one && !flag_two)//���op1Ϊ����op2Ϊ��
										cout << count << "�� (" << one << ") " << sign << " " << two << endl;
									if (!flag_one && flag_two)//���op1Ϊ����op2Ϊ��
										cout << count << "�� " << one << " " << sign << " (" << two << ")" << endl;
									if (flag_one && flag_two)//���op1��op2��Ϊ��
										cout << count << "�� ��" << one << ") " << sign << " (" << two << ")" << endl;
								}
							}
							else if (choose3 == 2)//�������㲻������
							{
								if (yu == 0)
								{
									if (!flag_one && !flag_two)//���op1��op2��Ϊ��
										cout << count << "�� " << one << " " << sign << " " << two << endl;
									if (flag_one && !flag_two)//���op1Ϊ����op2Ϊ��
										cout << count << "�� (" << one << ") " << sign << " " << two << endl;
									if (!flag_one && flag_two)//���op1Ϊ����op2Ϊ��
										cout << count << "�� " << one << " " << sign << " (" << two << ")" << endl;
									if (flag_one && flag_two)//���op1��op2��Ϊ��
										cout << count << "�� ��" << one << ") " << sign << " (" << two << ")" << endl;
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

/*�����ӡ��ʽ*/
int Output(int o)
{
	/*int o;
	cout << "ϵͳ�Ѿ���¼�����Ķ��Ʋ�������ѡ���ӡ�ķ�ʽ����1��ֱ����� 2�����浽�ļ���"<<endl;
	cin >> o;*/
	if (o == 1)
		cout << "�����������ϵͳ��ӭ������" << endl;
	else if (o == 2)
	{
		cout << "�����������ϵͳ��ӭ������" << endl;
		ofstream outfile("formula.txt", ios::out);
		if (!outfile)
		{
			cout << "Open error!!" << endl;
			exit(1);
		}
		outfile.close();
	}
	else
		cout << "�����������ѡ��" << endl;

	return 0;
}

void main()
{
	/*srand((int)time(0));*/
	int O, F;
	int N,R,R1,R2,count;
	cout << "��ѡ�����Ƿ���Ҫ�����ĵ�����1������Ҫ 2����Ҫ��" << endl;
	cin >> O;
	Output(O);
	cout << "����Ϊ���Ӷ���ʲô��Χ����Ŀ�أ����������ޣ����������ޣ��Իس�������ɺ��и��������ޡ����ޣ���"<<endl;
	cin >> R1;
	cin >> R2;
	while (1)//�ж��Ƿ�����Ϸ�
	{
		if (R2 < R1)
		{
			cout << "������ķ�Χ������Ӧ���� ���ޡ����ޣ�����������:" << endl;
			cin >> R1;
			cin >> R2;
		}
		else
			break;
	}
    cout << "�����ٵ����أ������������"<<endl;
	cout << "(������ʾ������ҪΪ���ӳ�̫�����Ŀ~1000��������ã�������100000����лл������)" << endl;
	cin >> N;
	cout << "�밴�պ��ӵ�ѧϰ�̶�ѡ����Ŀ���Ѷȣ��Ƿ�����˳����㣿��1���� 2����" << endl;
	cin >> F;
	while (1)//�ж��Ƿ�����Ϸ�
	{
		if (F!=1 && F!=2)
		{
			cout << "û�����붨�ƵĹ��ܣ����������루ֻ����1��2���ɣ�:" << endl;
			cin >> F;
		}
		else
			break;
	}
	if (F == 1)//�����˳���
		FourOper(N, R1, R2);
	if (F == 2)//�������˳���
	    AddSub(N, R1, R2);
	cout << "��л����ʹ�ã���ӭ�´�������ף���ĺ���ѧϰ��������<(�����)>" << endl;
	

}



