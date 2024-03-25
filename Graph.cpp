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

bool IsAllVisted(const int nNum,const bool bVisited[])
{
	for (int i = 0; i < nNum; i++)
	{
		if (bVisited[i] == false)
		{
			return 0;
		}
	}
	return true;
}

void Graph::PrintPath(const PathList pList)
{
	PathList pNow = pList;
	int j = 1;
	while (pNow != NULL)
	{
		cout << "��·" << j++ << ": ";
		for (int i = 0; i < m_nVexNum; i++)
		{
			cout << m_aVexs[pNow->vexs[i]].name;
			if (i != m_nVexNum - 1)
				cout << "->";
			else
				cout << endl;
		}
		pNow = pNow->next;
	}
}

void Graph::DFS(int nVex, bool bVisited[], int& nIndex, PathList pNow)
{
	/*
	���ܣ������������
	������nVex��������ꣻ
		bVisted[]���ѷ��ʱ�־
		nIdex��·��λ������
		pList��·����Ϣ
	*/
	bVisited[nVex] = true; // ��Ϊ�ѷ���
	pNow->vexs[nIndex++] = nVex; //���ʶ��� nVex
	if (IsAllVisted(m_nVexNum, bVisited))
	{
		PathList pTem = new Path(*pNow);
		pNow->next = pTem;
		pNow = pTem;
	}
	else
	{
		for (int i = 0; i < m_nVexNum; i++) //���� v �������ڽӵ�
		{
			if (m_aAdjMatrix[nVex][i] != 0 && !bVisited[i])
			{
				DFS(i, bVisited, nIndex, pNow); //�ݹ���� DFS
				bVisited[i] = false;
				nIndex--;
			}
		}
	}

}

void Graph::DFSTraverse(int nVex, PathList& pList)
{
	int nIndex = 0;
	bool aVisited[MAX_VERTEX_NUM] = { false };
	PathList pNow=pList;
	DFS(nVex, aVisited, nIndex, pNow);
	pNow = pList;
	pList = pList->next;
	PrintPath(pList);

	delete pNow;
	pNow = NULL;
}

void Graph::FindShortPath(int origin, int dest, Edge* &aPath)
{
	int* path_dest = new int[m_nVexNum];//�洢����orgin�ľ���
	int* short_path_dest = new int[m_nVexNum];//���ҵ�����С����
	int* vex_visted = new int[m_nVexNum];
	if (vex_visted == NULL || path_dest == NULL || short_path_dest == NULL)
	{
		cout << "�ڴ濪��ʧ��" << endl;
		return;
	}
	for (int i = 0; i < m_nVexNum; i++)
	{
		path_dest[i] = INT_MAX;
		vex_visted[i] = false;
		short_path_dest[i] = 0;
	}


	int pos = origin;
	int min_dest = INT_MAX;
	int min_node=-1;
	int pre_dest = 0;

	vex_visted[origin] = true;
	for (int i = 0; i < m_nVexNum; i++)
	{
		min_dest = INT_MAX;
		min_node = -1;
		//�������ڵ�ľ��룬��С����path_dest[]����
		for (int j = 0; j < m_nVexNum; j++)
		{
			if (m_aAdjMatrix[pos][j] != 0 && vex_visted[j] == false)
			{
				if (path_dest[j] > m_aAdjMatrix[pos][j]+pre_dest)
				{
					aPath[j].vex1 = pos;
					path_dest[j] = m_aAdjMatrix[pos][j]+pre_dest;
				}
			}
		}
		//�ҵ�path_dest[]�о�����С�Ľڵ�
		for (int j = 0; j < m_nVexNum; j++)
		{
			if (path_dest[j] < min_dest && vex_visted[j] == false)
			{
				min_dest = path_dest[j];
				min_node = j;
			}
		}

		if (min_node == -1)
			break;


		short_path_dest[min_node] = min_dest;
		vex_visted[min_node] = true;

		aPath[min_node].vex2 = min_node;
		aPath[min_node].weight = min_dest;
		pre_dest = min_dest;
		pos = min_node;

	}

	/*for (int j = 0; j < m_nVexNum; j++)
		cout << short_path_dest[j] << " ";*/

	delete[] vex_visted;
	delete[] path_dest;
	delete[] short_path_dest;
	vex_visted = path_dest = short_path_dest = NULL;
}

void Graph::FindMinTree(int begin,Edge* &aPath)
{
	int* min_tree_node = new int[m_nVexNum];
	int* dest2tree = new int[m_nVexNum];
	for (int i = 0; i < m_nVexNum; i++)
	{
		min_tree_node[i] = 0;
		dest2tree[i] = INT_MAX;
	}

	min_tree_node[begin] = 1;
	dest2tree[begin] = 0;

	int node = begin;//���¼������Ľڵ�
	int minnode = begin;
	int mindest = 0;
	for (int i = 0; i < m_nVexNum - 1; i++)
	{
		minnode = -1;
		mindest = INT_MAX;
		//��������С�������ľ���
		for (int j = 0; j < m_nVexNum; j++)
		{
			if (min_tree_node[j] == 0 && m_aAdjMatrix[node][j] != 0)
			{
				if (m_aAdjMatrix[node][j] < dest2tree[j])
				{
					aPath[j].vex1 = node;
					dest2tree[j] = m_aAdjMatrix[node][j];
				}
			}
		}
		//�ҵ�����С�����������Ľڵ�
		for (int j = 0; j < m_nVexNum; j++)
		{
			if (min_tree_node[j] == 0 && mindest > dest2tree[j])
			{
				mindest = dest2tree[j];
				minnode = j;
			}
		}

		if (minnode != -1)
		{
			node = minnode;
			min_tree_node[minnode] = 1;
			aPath[minnode].vex2 = minnode;
			aPath[minnode].weight = mindest;
		}
	}
	delete[] min_tree_node;
	delete[] dest2tree;
	min_tree_node = dest2tree = NULL;
}