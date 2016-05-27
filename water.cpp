//Zhao Ziyin 2016/5/18  寻找水王

#include<iostream>
#include<fstream>
using namespace std;
#define MAX 50

void Find(int id[], int lenth, int &water)
{
	int i = 0, count = 0;               //count用来记录某id发帖次数
	for (i = 0; i<lenth; i++)
	{
		if (count == 0)                //次数为零
		{
			water = id[i];            //假设当前的id为水王
			count++;
		}
		else
		{
			if (water == id[i])        //若前后id相同，水王的id不变，次数加1
				count++;          
			else
				count--;
		}
	}
}
int main(int argc, char* argv[])
{
	int ID[MAX];                //发帖记录表
	int in[MAX+1];                //从文件中读出的数组
	int i , num, King;              //发帖数目、水王
	/*cout << "请输入帖子的数量:";
	cin >> num;
	cout << "请输入发帖ID:";
	for (int i = 0; i<num; i++)
	{
		cin >> ID[i];
	}*/

	//读取文件中的id号
	ifstream infile("id_form.txt", ios::in);
	if (infile.is_open() == false)
	{
		cerr << "open error!" << endl;
		exit(1);
	}
	infile >> in[0];//读取帖子总数
	num = in[0];
	cout << "帖子的总数为："<<in[0]<<endl;

	cout << "发帖的id号分别为：" << endl;
	for (i = 0; i < num; i++)
	{
		infile >> in[i+1];
		ID[i] = in[i+1];
		cout << ID[i]<<" ";
	}
	cout << endl;

	Find(ID, num, King);
	cout << endl << "找到水王！！！" << endl;
	cout << "发帖水王的id为：" << King << endl;
	infile.close();
	return 0;
}