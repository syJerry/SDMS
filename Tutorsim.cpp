#include"Tutorsim.h"

using namespace std;
void Tourism::CreateGraph(string Vfilename, string Efilename)
{
	if (g.CreatGraph(Vfilename, Efilename))
	{
		cout << "创建成功！" << endl;
	}
	else
	{
		cout<<"创建失败！" << endl;
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
	cout << "请输入要查询的景点编码>";
	cin >> input;

	if (input.length()>1 )
	{
		cout << "错误输入!" << endl;
		return;
		
	}
	else if(input[0]>'9' || input[0]<'0')
	{
		cout << "错误输入!" << endl;
		return;

	}
	else
	{
		v = input[0] - '0';
		if (v >= g.GetNum())
		{
			cout << "没有这个景点!" << endl;
			return;
		}
	}

	Edge* medge =new Edge[g.GetNum()];
	k = g.FindEdge(v, medge);

	if (k == -1)
	{
		cout << "请先创建图!" << endl;
		return;
	}
	Vex pos = g.GetVex(v);
	cout << pos.name << endl;
	cout << pos.desc << endl;

	Vex near;
	cout << "-----周边景点-----" << endl;
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
	//输入景点编号
	cout << "请输入景区编号>";
	int input;
	cin >> input;

	PathList pList;
	//遍历景区景点图
	g.DFSTraverse(input, pList);
	//输出遍历结果
}
