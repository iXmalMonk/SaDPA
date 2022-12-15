#ifndef _GRAPH_H
#define _GRAPH_H

#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <string>
#include <vector>

using namespace std;

class Graph
{
private:
	struct DataPhysicalEffect
	{
		string name;
		int input;
		int output;
	};
	int sizePE;
	vector<DataPhysicalEffect> pe;

	int sizePQ;
	map<int, string> pq;

	struct DataGraph
	{
		vector<string> dataGraph;
	};

	vector<vector<DataGraph>> data;

	void createPE(const char* _filenamePE);
	void createPQ(const char* _filenamePQ);
	vector<vector<DataGraph>> createGraph();
	void dfs(int _start, int _stop, string _path, vector<string>& _allPath, vector<int> _used);
	void deleteAndSortChainsGreaterThanFour(vector<string>& _allPath);
	void printChains(const vector<string>& _allPath);

public:
	Graph(const char* _filenamePE, const char* _filenamePQ);
	void printPhysicalQuantitiesThatAreNotInPhysicalEffects(bool _mode);
	void chains(int _start, int _stop);
};

#endif // !_GRAPH_H


