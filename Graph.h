
#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>

#define MAX_VERTEX_NUM 100


using namespace std;

//顶点
struct Vex
{
	int num;//景区编号
	char name[20];//景区名字
	char desc[50];//景区描述
};

struct Edge
{
	int vex1;//顶点1
	int vex2;//顶点2
	int weight;//权重
};

typedef struct Path
{
	int vexs[20]; //保存一条路径
	Path* next=NULL; //下一条路径
};
typedef Path* PathList;

class Graph
{
public:
	Graph();
	int CreatGraph(string Vfilename, string Efilename);//创建图
	int ShowGraph();//展示图
	Vex GetVex(int v);//获取边
	int GetNum()//获取顶点数
	{
		return m_nVexNum;
	}
	int FindEdge(int v, Edge aEdge[]);//查找边

	void DFS(int nVex, bool bVisited[], int& nIndex, PathList pNow);
	void DFSTraverse(int nVex, PathList& pList);
	void PrintPath(const PathList pList);
	
	void FindShortPath(int origin, int dest, Edge*& aPath);
	void FindMinTree(int begin, Edge*& aPath);
private:
	int m_aAdjMatrix[20][20];//邻接矩阵
	Vex m_aVexs[20];//顶点信息矩阵
	int m_nVexNum;//图的顶点数量

};


