#include"Tourism.h"

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

	//�ж������Ƿ�Ϸ�
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
		if (medge[i].weight != 0)
		{
			near = g.GetVex(medge[i].vex2);
			cout << pos.name << "->" << near.name << " " << medge[i].weight << endl;
		}
	}
	delete[] medge;
	medge = NULL;
}


void Tourism::TravelPath()
{
	cout << "*******���ξ��㵼��*******" << endl;
	if (!g.ShowGraph())
	{
		return;
	}
	//���뾰����
	cout << "�����뾰�����>";
	int input;
	cin >> input;

	PathList pList = new Path;
	//������������ͼ
	g.DFSTraverse(input, pList);
	
	PathList tem;
	while (pList!=NULL)
	{
		tem = pList;
		pList = pList->next;
		delete tem;
		
	}
	pList = NULL;

}


void Tourism::FindShortPath(void)
{
	cout << "*******��Ѱ���·��*******" << endl;
	if (!g.ShowGraph())
	{
		return;
	}
	int origin = 0;
	int dest = 0;
	cout << "���������>";
	cin >> origin;
	cout << "�������յ�>";
	cin >> dest;
	Edge* aPath = new Edge[g.GetNum()];
	g.FindShortPath(origin, dest, aPath);

	//for (int i = 0; i < 7; i++)
	//{
	//	cout << aPath[i].vex1 << "-" << aPath[i].vex2 << " ";
	//}
	//Ѱ���յ��·�����Ӻ���ǰ���
	int index = dest;
	int count = 0;
	int* path=new int[g.GetNum()];
	path[count++] = dest;
	index = aPath[index].vex1;
	while (index != origin)
	{
		path[count++] = index;
		index = aPath[index].vex1;
	}
	path[count] = origin;
	for (int i = count; i >= 0; i--)
	{
		cout << g.GetVex(path[i]).name;
		if (i != 0)
			cout << "->";
		else
			cout << endl;
	}

	delete[] aPath;
	delete[] path;
	aPath =  NULL;
	path = NULL;
}

void Tourism::DesignPath()
{
	cout << "*******�����·�滮*******" << endl;
	if (!g.ShowGraph())
	{
		return;
	}
	int begin;
	cout << "�������������>";
	cin >> begin;
	Edge* aPath = new Edge[g.GetNum()];
	g.FindMinTree(begin, aPath);
	/*for (int i = 0; i < 6; i++)
	{
		cout << aPath[i].vex1 << "-" << aPath[i].vex2 << " ";
	}*/
	for (int i = 0; i < g.GetNum(); i++)
	{
		if (i == begin) continue;
		cout << g.GetVex(aPath[i].vex1).name << " - " << g.GetVex(aPath[i].vex2).name << "\t" << aPath[i].weight << "m" << endl;
	}

	delete[] aPath;
	aPath = NULL;
}