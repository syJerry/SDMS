#include"Tourism.h"

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

	//判断输入是否合法
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
	cout << "*******旅游景点导航*******" << endl;
	if (!g.ShowGraph())
	{
		return;
	}
	//输入景点编号
	cout << "请输入景区编号>";
	int input;
	cin >> input;

	PathList pList = new Path;
	//遍历景区景点图
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
	cout << "*******搜寻最短路径*******" << endl;
	if (!g.ShowGraph())
	{
		return;
	}
	int origin = 0;
	int dest = 0;
	cout << "请输入起点>";
	cin >> origin;
	cout << "请输入终点>";
	cin >> dest;
	Edge* aPath = new Edge[g.GetNum()];
	g.FindShortPath(origin, dest, aPath);

	//for (int i = 0; i < 7; i++)
	//{
	//	cout << aPath[i].vex1 << "-" << aPath[i].vex2 << " ";
	//}
	//寻找终点的路径，从后往前输出
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
	cout << "*******铺设电路规划*******" << endl;
	if (!g.ShowGraph())
	{
		return;
	}
	int begin;
	cout << "请输入铺设起点>";
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