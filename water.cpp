//Zhao Ziyin 2016/5/18  Ѱ��ˮ��

#include<iostream>
#include<fstream>
using namespace std;
#define MAX 50

void Find(int id[], int lenth, int &water)
{
	int i = 0, count = 0;               //count������¼ĳid��������
	for (i = 0; i<lenth; i++)
	{
		if (count == 0)                //����Ϊ��
		{
			water = id[i];            //���赱ǰ��idΪˮ��
			count++;
		}
		else
		{
			if (water == id[i])        //��ǰ��id��ͬ��ˮ����id���䣬������1
				count++;          
			else
				count--;
		}
	}
}
int main(int argc, char* argv[])
{
	int ID[MAX];                //������¼��
	int in[MAX+1];                //���ļ��ж���������
	int i , num, King;              //������Ŀ��ˮ��
	/*cout << "���������ӵ�����:";
	cin >> num;
	cout << "�����뷢��ID:";
	for (int i = 0; i<num; i++)
	{
		cin >> ID[i];
	}*/

	//��ȡ�ļ��е�id��
	ifstream infile("id_form.txt", ios::in);
	if (infile.is_open() == false)
	{
		cerr << "open error!" << endl;
		exit(1);
	}
	infile >> in[0];//��ȡ��������
	num = in[0];
	cout << "���ӵ�����Ϊ��"<<in[0]<<endl;

	cout << "������id�ŷֱ�Ϊ��" << endl;
	for (i = 0; i < num; i++)
	{
		infile >> in[i+1];
		ID[i] = in[i+1];
		cout << ID[i]<<" ";
	}
	cout << endl;

	Find(ID, num, King);
	cout << endl << "�ҵ�ˮ��������" << endl;
	cout << "����ˮ����idΪ��" << King << endl;
	infile.close();
	return 0;
}