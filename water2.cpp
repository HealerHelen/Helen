//Zhao Ziyin 2016/5/27 寻找小水王

#include<iostream>
#include<fstream>
using namespace std;
#define MAX 50

void Find(int id[], int lenth, int water[])
{
	int i = 0;
	int count[3] = { 0, 0, 0 };             //count数组用来记录某id发帖次数
	water[0] = water[1] = water[2] = -1;    //初始化嫌疑人列表
	for (i = 0; i<lenth; i++)
	{
		if (count[0] == 0)            //初始化后先赋值
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

		else if (id[i] == water[0])    //如果count为0,重新赋值
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
		else //如果与三个嫌疑人的ID都不同，则三个计数数组的值都减1，直到count为0
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
	int ID[MAX];                //发帖记录表
	int in[MAX + 1];                //从文件中读出的数组
	int num, King[3];            //发帖数目、水桶
	
	//读取文件中的id号
	ifstream infile("id_form.txt", ios::in);
	if (infile.is_open() == false)
	{
		cerr << "open error!" << endl;
		exit(1);
	}
	infile >> in[0];//读取帖子总数
	num = in[0];
	cout << "帖子的总数为：" << in[0] << endl;

	cout << "发帖的id号分别为：" << endl;
	for (i = 0; i < num; i++)
	{
		infile >> in[i + 1];
		ID[i] = in[i + 1];
		cout << ID[i] << " ";
	}
	cout << endl;

	Find(ID, num, King);
	cout << endl << "找到小水王！！！" << endl;
	cout << "id为：";
	for (i = 0; i<3; i++)
	{
		cout << King[i] << " ";
	}
	cout << endl;
	infile.close();
	return 0;
}