#define _CRT_SECURE_NO_DEPRECATE

#include<iostream>
#include<string>

#include"Graph.h"
#include"Tourism.h"
using namespace std;

void menu()
{
	cout << "=====������Ϣ����ϵͳ=====" << endl;
	cout << "1.������������ͼ" << endl;
	cout << "2.��ѯ������Ϣ" << endl;
	cout << "3.���ξ��㵼��" << endl;
	cout << "4.��Ѱ���·��" << endl;
	cout << "5.�����·�滮" << endl;
	cout << "0.�˳�" << endl;
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
		cout << "������ѡ��>";
		cin >> input;
		if (input.length() == 1 && input[0]<='9' && input[0]>='0')
		{
			choice = input[0];
		}
		else
		{
			cout << "����ȷ����!" << endl;
			choice = 'a';
			continue;
		}	

		system("cls");
		switch (choice)
		{
			//1.������������ͼ
			//2.��ѯ������Ϣ
			//3.���ξ��㵼��
			//4.��Ѱ���·��
			//5.�����·�滮
			//0.�˳�
		case '1':	t.CreateGraph("Vex.txt", "Edge.txt"); break;
		case '2':	t.GetSpotInfo(); break;
		case '3':	t.TravelPath(); break;
		case '4':	t.FindShortPath(); break;
		case '5':	t.DesignPath(); break;

		default:
			cout << "û�и�ѡ�����������!" << endl;
			break;
		}
		
	} while (choice!='0');
	return 0;
}