#include <iostream>
#include "Table.h"
#include "Tree.h"
#include "Strng.h"

using namespace std;

void method(Table table, T t, Strng s, int id)
{
	if (treeSearch(t.tree, id) != NULL)
	{
		for (int i = 0; i < table.size; i++)
		{
			int tmp = theNumberOfOccurrencesOfTheWord(s, i, table, id);
			if (tmp != 0)
				cout << i + 1 << " | " << table.words[id - 1] << " " << tmp << "\n";
		}
	}
}

int main()
{
	system("chcp 1251");
	system("cls");

	//
	Table table;
	createTable(table, "words.txt");

	T t;
	for (int i = 0; i < table.size; i++)
		t.tree = treeInsert(t, t.tree, table.id[i]);

	Strng s;
	createStrng(s, "strings.txt");
	//
	
	method(table, t, s, 2);

	treePrint(t.tree);
	cout << "\n";

	t.tree = treeRemove(t, t.tree, 2);

	method(table, t, s, 2);

	treePrint(t.tree);
	cout << "\n";

	deleteTable(table);
	t.tree = treeDel(t, t.tree);
	deleteStrng(s);

	//theNumberOfOccurrencesOfTheWord(s, 0, table, 0);
	//int id = 1;
	//if (treeSearch(t.tree, id) != NULL) cout << table.words[id - 1] << endl;

	/*t.tree = treeNew(t, 0);

	t.tree = treeInsert(t, t.tree, 30);
	t.tree = treeInsert(t, t.tree, 60);
	t.tree = treeInsert(t, t.tree, 65);
	t.tree = treeInsert(t, t.tree, 20);
	t.tree = treeInsert(t, t.tree, 70);

	if (treeSearch(t.tree, 100) != NULL) cout << "Found\n";
	else cout << "Not found\n";

	if (treeSearch(t.tree, 20) != NULL) cout << "Found\n";
	else cout << "Not found\n";

	treePrint(t.tree);
	cout << "\n";
	t.tree = treeRemove(t, t.tree, 65);
	treePrint(t.tree);
	cout << "\n";
	t.tree = treeRemove(t, t.tree, 60);
	treePrint(t.tree);
	cout << "\n";
	t.tree = treeRemove(t, t.tree, 20);
	treePrint(t.tree);
	cout << "\n";
	t.tree = treeRemove(t, t.tree, 70);
	treePrint(t.tree);
	cout << "\n";
	t.tree = treeRemove(t, t.tree, 30);
	treePrint(t.tree);
	cout << "\n";
	t.tree = treeRemove(t, t.tree, 0);
	treePrint(t.tree);
	cout << "\n";

	t.tree = treeDel(t, t.tree);*/

	return 0;
}

/*
 * Для хранения информации о ключевых словах некоторой программы имеется таблица перекрестных ссылок.
 * Для каждого слова задан список номеров строк, где оно встречается,
 * а для каждой строки - число образцов данного слова в строке.
 * Ключевые слова расположены по алфавиту. Построить бинарное дерево для быстрого поиска ключевых слов.
 * Составить программу определения общего количества вхождений заданного ключевого слова.
 * Обеспечить корректировку дерева поиска для случая удаления ключевого слова из некоторой строки.
 */