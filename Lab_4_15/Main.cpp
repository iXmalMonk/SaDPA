#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Data
{
	int size = 0;
	string* surname = NULL;
	string* phoneNumber = NULL;
};

void createData(Data& data, const char* filename)
{
	ifstream file; // ifstream file(filename)
	file.open(filename);
	string str;
	getline(file, str);
	data.size = stoi(str);
	data.surname = new string[data.size];
	data.phoneNumber = new string[data.size];
	for (int i = 0; i < data.size; i++)
	{
		getline(file, data.surname[i], ' ');
		getline(file, data.phoneNumber[i], '\n');
	}
	file.close();
}

void printData(const Data& data)
{
	for (int i = 0; i < data.size; i++)
		cout << data.surname[i] << " " << data.phoneNumber[i] << endl;
	cout << endl;
}

void destroyData(Data& data)
{
	delete[] data.surname;
	delete[] data.phoneNumber;
	data.surname = NULL;
	data.phoneNumber = NULL;
	data.size = 0;
}

void sortData(Data& data)
{
	for (int i = 0; i < data.size; i++)
	{
		int temporary = 0;
		for (int j = 0; j < data.size - 1; j++)
			if (data.surname[j][temporary] == data.surname[j + 1][temporary])
			{
				temporary++;
				j--;
			}
			else if (data.surname[j][temporary] > data.surname[j + 1][temporary])
			{
				swap(data.surname[j], data.surname[j + 1]);
				swap(data.phoneNumber[j], data.phoneNumber[j + 1]);
			}
	}
}

int main()
{
	system("chcp 1251");
	system("cls");

	Data data;
	createData(data, "data.txt");
	printData(data);
	sortData(data);
	printData(data);
	destroyData(data);

	return 0;
}