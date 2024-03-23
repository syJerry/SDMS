#define _CRT_SECURE_NO_DEPRECATE

#include<iostream>
#include<string>

#include"Graph.h"
#include"Tourism.h"
using namespace std;

void menu()
{
	cout << "=====景区信息管理系统=====" << endl;
	cout << "1.创建景区景点图" << endl;
	cout << "2.查询景点信息" << endl;
	cout << "3.旅游景点导航" << endl;
	cout << "4.搜寻最短路径" << endl;
	cout << "5.铺设电路规划" << endl;
	cout << "0.退出" << endl;
}
//void test()
//{
//	//Graph g;
//	//g.CreatGraph("Vex.txt", "Edge.txt");
//	//cout << "***********************************" << endl;
//	//g.ShowGraph();
//	//cout << "***********************************" << endl;
//	//Edge* aPath = new Edge[g.GetNum()];
//	//g.FindShortPath(1, 4, aPath);
//	Tourism t;
//	t.CreateGraph("Vex.txt", "Edge.txt");
//	//t.GetSpotInfo();
//	//t.TravelPath();
//	//t.FindShortPath();
//	t.DesignPath();
//}


int main()
{
	
	Tourism t;
	string input;
	char choice;
	do
	{
		menu();
		cout << "请输入选择>";
		cin >> input;
		if (input.length() == 1 && input[0]<='9' && input[0]>='0')
		{
			choice = input[0];
		}
		else
		{
			cout << "请正确输入!" << endl;
			choice = 'a';
			continue;
		}	

		system("cls");
		switch (choice)
		{
			//1.创建景区景点图
			//2.查询景点信息
			//3.旅游景点导航
			//4.搜寻最短路径
			//5.铺设电路规划
			//0.退出
		case '1':	t.CreateGraph("Vex.txt", "Edge.txt"); break;
		case '2':	t.GetSpotInfo(); break;
		case '3':	t.TravelPath(); break;
		case '4':	t.FindShortPath(); break;
		case '5':	t.DesignPath(); break;

		default:
			cout << "没有该选项，请重新输入!" << endl;
			break;
		}
		
	} while (choice!='0');
	return 0;
}