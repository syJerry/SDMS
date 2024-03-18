#define _CRT_SECURE_NO_DEPRECATE

#include"Graph.h"
#include<vector>

Graph::Graph()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			m_aAdjMatrix[i][j] = 0;
		}
	}
	m_nVexNum = 0;
}
int Graph::CreatGraph(string Vfilename, string Efilename)
{
	cout << "=======������������ͼ=======" << endl;
	FILE* fs = fopen(Vfilename.c_str(), "r");
	if (fs == NULL)
	{
		cout << "�ļ���ʧ��!" << endl;
		return 0;
	}
	fscanf(fs, "%d", &m_nVexNum);
	cout << "������Ŀ��" << m_nVexNum << endl;
	cout << "------����------" << endl;
	for (int i = 0; i < m_nVexNum; i++)
	{
		int j = fscanf(fs, "%d%s%s", &m_aVexs[i].num, &m_aVexs[i].name, &m_aVexs[i].desc);
		cout << m_aVexs[i].num << "-" << m_aVexs[i].name << endl;
	}

	cout << "------��------" << endl;
	int v1 = 0;
	int v2 = 0;
	int w = 0;
	FILE* fs2 = fopen(Efilename.c_str(), "r");
	if (fs2 == NULL)
	{
		cout << "�ļ���ʧ��!" << endl;
		return 0;
	}
	while (!feof(fs2))
	{
		fscanf(fs2, "%d%d%d", &v1, &v2, &w);
		m_aAdjMatrix[v1][v2] = w;
		m_aAdjMatrix[v2][v1] = w;
		cout << "<v" << v1 << ",v" << v2 << ">" << " " << w << endl;
	}


	fclose(fs2);
	fclose(fs);
	fs = NULL;
	fs2 = NULL;
	return 1;
}

int Graph::ShowGraph()
{
	if (m_nVexNum == 0)
	{
		cout << "���ȳ�ʼ��!" << endl;
		return 0;
	}
	//cout << "��������:" << m_nVexNum << endl;
	//cout << "�ڽӾ���" << endl;
	//for (int i = 0; i < 20; i++)
	//{
	//	for (int j = 0; j < 20; j++)
	//	{
	//		cout << m_aAdjMatrix[i][j] << "\t";
	//	}
	//	cout << endl;
	//}
	for (int i = 0; i < m_nVexNum; i++)
	{
		cout << m_aVexs[i].num << "\t" << m_aVexs[i].name << endl;
	}
	return 1;
}

Vex Graph::GetVex(int v)
{
	return m_aVexs[v];
}

int Graph::FindEdge(int v, Edge aEdge[])
{
	if (m_nVexNum == 0)
	{
		return -1;
	}
	int k = 0;
	Edge tem;
	tem.vex1 = v;
	for (int i = 0; i < m_nVexNum; i++)
	{
		if (m_aAdjMatrix[v][i] != -1 && i != v)
		{
			tem.weight = m_aAdjMatrix[v][i];
			tem.vex2 = i;
			aEdge[k] = tem;
			k++;
		}

	}
	return k; // ���رߵ�����

}

void Graph::DFS(int nVex, bool bVisited[], int& nIndex, PathList& pList)
{
	bVisited[nVex] = true; // ��Ϊ�ѷ���
	pList->vexs[nIndex++] = nVex; //���ʶ��� nVex
	for (int i = 0; i < m_nVexNum;i++) //���� v �������ڽӵ�
	{
		if (m_aAdjMatrix[nVex][i]!=0 && !bVisited[i])
		{
			DFS(i, bVisited, nIndex, pList); //�ݹ���� DFS
		}
	}
}

void Graph::DFSTraverse(int nVex, PathList& pList)
{
	int nIndex = 0;
	bool aVisited[MAX_VERTEX_NUM] = { false };
	DFS(nVex, aVisited, nIndex, pList);
}
