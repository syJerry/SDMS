#pragma once
#include"Graph.h"
using namespace std;
class Tourism
{
public:
	void CreateGraph(string Vfilename, string Efilename);
	void GetSpotInfo();
	void TravelPath();
	void FindShortPath();
	void DesignPath();
private:
	Graph g;
};
