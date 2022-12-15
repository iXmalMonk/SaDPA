#include "Graph.h"

void Graph::createPE(const char* _filenamePE)
{
	ifstream file;
	string temporaryString;

	file.open(_filenamePE);
	getline(file, temporaryString);
	sizePE = stoi(temporaryString);

	for (int i = 0; i < sizePE; i++)
	{
		DataPhysicalEffect temporaryDPE;

		getline(file, temporaryString, ' ');
		temporaryDPE.input = stoi(temporaryString);
		getline(file, temporaryString, ' ');
		temporaryDPE.output = stoi(temporaryString);
		getline(file, temporaryString, '\n');
		temporaryDPE.name = temporaryString;
		pe.push_back(temporaryDPE);
	}

	file.close();
}

void Graph::createPQ(const char* _filenamePQ)
{
	ifstream file;
	string temporaryStringFirst;
	string temporaryStringSecond;

	file.open(_filenamePQ);
	getline(file, temporaryStringFirst);
	sizePQ = stoi(temporaryStringFirst);

	for (int i = 0; i < sizePQ; i++)
	{
		getline(file, temporaryStringFirst, ' ');
		getline(file, temporaryStringSecond, '\n');
		pq[stoi(temporaryStringFirst)] = temporaryStringSecond;
	}

	file.close();
}

vector<vector<Graph::DataGraph>> Graph::createGraph()
{
	vector<vector<DataGraph>> temporaryGraph(pq.size(), vector<DataGraph>(pq.size()));

	for (int i = 0; i < pe.size(); i++)
		temporaryGraph[pe[i].input][pe[i].output].dataGraph.push_back(pe[i].name);

	return temporaryGraph;
}

void Graph::dfs(int _start, int _stop, string _path, vector<string>& _allPath, vector<int> _used)
{
	_used[_start] = 1;

	for (int i = 0; i < data.size(); i++)
		if ((_used[i] == 0) and (data[_start][i].dataGraph.size() != 0))
		{
			if (i == _stop)
			{
				regex r("[0-9]+$");

				_path += to_string(i);
				_allPath.push_back(_path);
				_path = regex_replace(_path, r, "");
				continue;
			}
			regex r("[0-9]+->$");

			_path += to_string(i) + "->";
			dfs(i, _stop, _path, _allPath, _used);
			_path = regex_replace(_path, r, "");
		}
}

void Graph::deleteAndSortChainsGreaterThanFour(vector<string>& _allPath)
{
	regex rArrow(">");
	vector<string> paths;
	int lenght = 1;

	for (int i = 0; i < _allPath.size(); i++)
	{
		auto wordsBegin = sregex_iterator(_allPath[i].begin(), _allPath[i].end(), rArrow);
		auto wordsEnd = sregex_iterator();

		if (distance(wordsBegin, wordsEnd) > 4)
		{
			_allPath.erase(_allPath.begin() + i);
			i = -1;
		}
	}

	for (int i = 0; i < _allPath.size(); i++)
	{
		auto wordsBegin = sregex_iterator(_allPath[i].begin(), _allPath[i].end(), rArrow);
		auto wordsEnd = sregex_iterator();

		if (distance(wordsBegin, wordsEnd) == lenght)
		{
			paths.push_back(_allPath[i]);
			_allPath.erase(_allPath.begin() + i);
			i = -1;
			continue;
		}
		if (i == _allPath.size() - 1)
		{
			i = -1;
			lenght++;
			continue;
		}
	}

	_allPath = paths;
}

void Graph::printChains(const vector<string>& _allPath)
{
	regex rId("[0-9]+");
	regex rArrow(">");

	for (int i = 0; i < _allPath.size(); i++)
	{
		auto wordsBeginArrow = sregex_iterator(_allPath[i].begin(), _allPath[i].end(), rArrow);
		auto wordsBeginId = sregex_iterator(_allPath[i].begin(), _allPath[i].end(), rId);
		auto wordsEnd = sregex_iterator();
		int lenght = distance(wordsBeginArrow, wordsEnd);
		sregex_iterator start = wordsBeginId;
		smatch in = *start;
		start++;
		smatch out = *start;

		cout << endl << _allPath[i] << ":" << endl;
		cout << "------------------------------" << endl;

		for (int j = 0; j < lenght; j++)
		{
			for (int k = 0; k < pe.size(); k++)
				if ((pe[k].input == stoi(in.str())) and (pe[k].output == stoi(out.str())))
					cout << pe[k].input << " " << pe[k].output << "\t" << pe[k].name << endl;

			if (j == lenght - 1)
				continue;
			else
			{
				in = out;
				start++;
				out = *start;
			}
		}

		cout << "------------------------------" << endl;
	}
	
	cout << endl;
}

Graph::Graph(const char* _filenamePE, const char* _filenamePQ)
{
	createPE(_filenamePE);
	createPQ(_filenamePQ);
	data = createGraph();
}

void Graph::printPhysicalQuantitiesThatAreNotInPhysicalEffects(bool _mode)
{
	vector<int> temporaryVector;

	for (int i = 0; i < sizePE; i++)
		if (_mode)
			temporaryVector.push_back(pe[i].input);
		else
			temporaryVector.push_back(pe[i].output);

	for (int i = 0; i < sizePQ; i++)
	{
		auto temporary = find(temporaryVector.begin(), temporaryVector.end(), i + 1);

		if (temporary == temporaryVector.end())
				cout << pq[i + 1] << endl;
	}

	cout << endl;
}

void Graph::chains(int _start, int _stop)
{
	string path = to_string(_start) + "->";
	vector<string> allPath;
	vector<int> used(data.size(), 0);
	dfs(_start, _stop, path, allPath, used);
	deleteAndSortChainsGreaterThanFour(allPath);
	if (allPath.size() == 0)
		cout << "Ничего не найдено" << endl;
	else
		printChains(allPath);
}
