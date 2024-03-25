
#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>

#define MAX_VERTEX_NUM 100


using namespace std;

//����
struct Vex
{
	int num;//�������
	char name[20];//��������
	char desc[50];//��������
};

struct Edge
{
	int vex1;//����1
	int vex2;//����2
	int weight;//Ȩ��
};

typedef struct Path
{
	int vexs[20]; //����һ��·��
	Path* next=NULL; //��һ��·��
};
typedef Path* PathList;

class Graph
{
public:
	Graph();
	int CreatGraph(string Vfilename, string Efilename);//����ͼ
	int ShowGraph();//չʾͼ
	Vex GetVex(int v);//��ȡ��
	int GetNum()//��ȡ������
	{
		return m_nVexNum;
	}
	int FindEdge(int v, Edge aEdge[]);//���ұ�

	void DFS(int nVex, bool bVisited[], int& nIndex, PathList pNow);
	void DFSTraverse(int nVex, PathList& pList);
	void PrintPath(const PathList pList);
	
	void FindShortPath(int origin, int dest, Edge*& aPath);
	void FindMinTree(int begin, Edge*& aPath);
private:
	int m_aAdjMatrix[20][20];//�ڽӾ���
	Vex m_aVexs[20];//������Ϣ����
	int m_nVexNum;//ͼ�Ķ�������

};


