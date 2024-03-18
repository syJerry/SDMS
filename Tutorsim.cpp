#include"Tutorsim.h"

using namespace std;
void Tourism::CreateGraph(string Vfilename, string Efilename)
{
	if (g.CreatGraph(Vfilename, Efilename))
	{
		cout << "�����ɹ���" << endl;
	}
	else
	{
		cout<<"����ʧ�ܣ�" << endl;
	}
}

void Tourism::GetSpotInfo()
{
	string input;
	int v;
	int k = 0;
	if (!g.ShowGraph())
	{
		return;
	}
	cout << "������Ҫ��ѯ�ľ������>";
	cin >> input;

	if (input.length()>1 )
	{
		cout << "��������!" << endl;
		return;
		
	}
	else if(input[0]>'9' || input[0]<'0')
	{
		cout << "��������!" << endl;
		return;

	}
	else
	{
		v = input[0] - '0';
		if (v >= g.GetNum())
		{
			cout << "û���������!" << endl;
			return;
		}
	}

	Edge* medge =new Edge[g.GetNum()];
	k = g.FindEdge(v, medge);

	if (k == -1)
	{
		cout << "���ȴ���ͼ!" << endl;
		return;
	}
	Vex pos = g.GetVex(v);
	cout << pos.name << endl;
	cout << pos.desc << endl;

	Vex near;
	cout << "-----�ܱ߾���-----" << endl;
	for (int i = 0; i < k; i++)
	{
		near = g.GetVex(medge[i].vex2);
		cout << pos.name << "->" << near.name << " " << medge[i].weight << endl;
	}
	delete[] medge;
}


void Tourism::TravelPath(void)
{
	if (!g.ShowGraph())
	{
		return;
	}
	//���뾰����
	cout << "�����뾰�����>";
	int input;
	cin >> input;

	PathList pList;
	//������������ͼ
	g.DFSTraverse(input, pList);
	//����������
}
