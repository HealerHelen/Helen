//Zhao Ziyin 2016/5/27 Ѱ��Сˮ��

#include<iostream>
#include<fstream>
using namespace std;
#define MAX 50

void Find(int id[], int lenth, int water[])
{
	int i = 0;
	int count[3] = { 0, 0, 0 };             //count����������¼ĳid��������
	water[0] = water[1] = water[2] = -1;    //��ʼ���������б�
	for (i = 0; i<lenth; i++)
	{
		if (count[0] == 0)            //��ʼ�����ȸ�ֵ
		{
			count[0]++;
			water[0] = id[i];
		}
		else if (count[1] == 0)
		{
			count[1]++;
			water[1] = id[i];
		}
		else if (count[2] == 0)
		{
			count[2]++;
			water[2] = id[i];
		}

		else if (id[i] == water[0])    //���countΪ0,���¸�ֵ
		{
			count[0]++;
		}
		else if (id[i] == water[1])
		{
			count[1]++;
		}
		else if (id[i] == water[2])
		{
			count[2]++;
		}
		else //��������������˵�ID����ͬ�����������������ֵ����1��ֱ��countΪ0
		{
			count[0]--;
			count[1]--;
			count[2]--;
		}
	}
}

int main(int argc, char* argv[])
{
	int i;
	int ID[MAX];                //������¼��
	int in[MAX + 1];                //���ļ��ж���������
	int num, King[3];            //������Ŀ��ˮͰ
	
	//��ȡ�ļ��е�id��
	ifstream infile("id_form.txt", ios::in);
	if (infile.is_open() == false)
	{
		cerr << "open error!" << endl;
		exit(1);
	}
	infile >> in[0];//��ȡ��������
	num = in[0];
	cout << "���ӵ�����Ϊ��" << in[0] << endl;

	cout << "������id�ŷֱ�Ϊ��" << endl;
	for (i = 0; i < num; i++)
	{
		infile >> in[i + 1];
		ID[i] = in[i + 1];
		cout << ID[i] << " ";
	}
	cout << endl;

	Find(ID, num, King);
	cout << endl << "�ҵ�Сˮ��������" << endl;
	cout << "idΪ��";
	for (i = 0; i<3; i++)
	{
		cout << King[i] << " ";
	}
	cout << endl;
	infile.close();
	return 0;
}