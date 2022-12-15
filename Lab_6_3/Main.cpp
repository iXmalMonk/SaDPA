#include "Graph.h"

int main()
{
	system("chcp 1251");
	system("cls");

	Graph graph("pe.txt", "pq.txt");

	int start = 0;
	int stop = 0;

	graph.printPhysicalQuantitiesThatAreNotInPhysicalEffects(true);

	do
	{
		cout << "Start: ";
		cin >> start;
		cout << "Stop: ";
		cin >> stop;

		if (start == 0 and stop == 0)
			return 0;

		graph.chains(start, stop);
	} while (true);
}