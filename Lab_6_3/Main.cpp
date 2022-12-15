#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <queue>

using namespace std;

#define CHAIN_SIZE 3

struct PhysicalQuantities
{
	int id = 0;
	string name;
};

struct PhysicalEffect
{
	int id = 0;
	string name;
	int input = 0;
	int output = 0;
};

struct GraphData
{
	int sizePQ = 0;
	int sizePE = 0;
	vector<PhysicalEffect> pe;
	PhysicalQuantities* pq = NULL;
};

void createGraph(GraphData& _graphData, const char* _filenamePQ, const char* _filenamePE)
{
	ifstream file;
	string temporaryString;
	// ----- PQ
	file.open(_filenamePQ);
	getline(file, temporaryString);
	_graphData.sizePQ = stoi(temporaryString);
	_graphData.pq = new PhysicalQuantities[_graphData.sizePQ];
	for (int i = 0; i < _graphData.sizePQ; i++)
	{
		getline(file, temporaryString, ' ');
		_graphData.pq[i].id = stoi(temporaryString);
		getline(file, temporaryString, '\n');
		_graphData.pq[i].name = temporaryString;
	}
	// ----- PQ
	file.close();
	// ----- PE
	file.open(_filenamePE);
	getline(file, temporaryString);
	_graphData.sizePE = stoi(temporaryString);
	for (int i = 0; i < _graphData.sizePE; i++)
	{
		PhysicalEffect temporaryPE;
		temporaryPE.id = i;
		getline(file, temporaryString, ' ');
		temporaryPE.input = stoi(temporaryString);
		getline(file, temporaryString, ' ');
		temporaryPE.output = stoi(temporaryString);
		getline(file, temporaryString, '\n');
		temporaryPE.name = temporaryString;
		_graphData.pe.push_back(temporaryPE);
	}
	// ----- PE
	file.close();
}

void printGraph(const GraphData& _graphData, bool textIO)
{
	for (int i = 0; i < _graphData.sizePE; i++)
		if (textIO)
			cout << "Name: " << _graphData.pe[i].name 
			<< " Input: " << _graphData.pq[_graphData.pe[i].input].name
			<< " Output: " << _graphData.pq[_graphData.pe[i].output].name
			<< endl;
		else
			cout << "Name: " << _graphData.pe[i].name << " Input: " << _graphData.pe[i].input << " Output: " << _graphData.pe[i].output << endl;
}

// inputs - true
// outputs - false
void printPhysicalQuantitiesThatAreNotInPhysicalEffects(const GraphData& _graphData, bool mode, bool text)
{
	vector<int> temporaryVector;

	for(int i = 0; i < _graphData.sizePE; i++)
		if (mode)
			temporaryVector.push_back(_graphData.pe[i].input);
		else
			temporaryVector.push_back(_graphData.pe[i].output);

	for (int i = 0; i < _graphData.sizePQ; i++)
	{
		auto temporary = find(temporaryVector.begin(), temporaryVector.end(), _graphData.pq[i].id);
		if (temporary == temporaryVector.end())
			if (text)
				cout << _graphData.pq[i].name << endl;
			else
				cout << _graphData.pq[i].id << endl;
	}
}

int main()
{
	system("chcp 1251");
	system("cls");
	GraphData graphData;
	createGraph(graphData, "pq.txt", "pe.txt");
	//printGraph(graphData, false);
	//printPhysicalQuantitiesThatAreNotInputsToPhysicalEffects(graphData, false);
	//printPhysicalQuantitiesThatAreNotOutputsToPhysicalEffects(graphData, false);
	//printPhysicalQuantitiesThatAreNotInPhysicalEffects(graphData, false, false);
	return 0;
}