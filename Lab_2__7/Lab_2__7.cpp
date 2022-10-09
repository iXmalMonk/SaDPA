#include<iostream>
#include"Queue.h"

using namespace std;

int main()
{
	system("chcp 1251");
	system("cls");

	Queue Q1;
	Queue Q2;

	int index = 0;
	int data[7] = { 0 };
	double time1 = 8.00;
	double time2 = 8.00;

	pushQueue(&Q1, 1);
	pushQueue(&Q1, 3);
	pushQueue(&Q1, 2);
	pushQueue(&Q1, 5);
	pushQueue(&Q1, 6);
	pushQueue(&Q1, 4);
	pushQueue(&Q1, 7);

	pushQueue(&Q2, 2);
	pushQueue(&Q2, 4);
	pushQueue(&Q2, 5);
	pushQueue(&Q2, 3);
	pushQueue(&Q2, 1);
	pushQueue(&Q2, 7);
	pushQueue(&Q2, 6);

	while (index != 7)
	{
		for (int i = 0; i < index; i++)
		{
			if (peekQueue(&Q1) == data[i])
			{
				popQueue(&Q1);
				i = -1;
			}
			if (peekQueue(&Q2) == data[i])
			{
				popQueue(&Q2);
				i = -1;
			}
		}

		if (peekQueue(&Q1) != peekQueue(&Q2))
		{
			if (time1 >= int(time1) + 0.5) time1 = int(time1) + 1;
			if (time2 >= int(time2) + 0.5) time2 = int(time2) + 1;
			if (peekQueue(&Q1) != 0)
			{
				printf("Касса 1 - %i | %.2lf\n", peekQueue(&Q1), time1);
				data[index++] = popQueue(&Q1);
			}
			if (peekQueue(&Q2) != 0)
			{
				printf("Касса 2 - %i | %.2lf\n", peekQueue(&Q2), time2);
				data[index++] = popQueue(&Q2);
			}
			time1 += 0.15;
			time2 += 0.15;
		}

		if (peekQueue(&Q1) == peekQueue(&Q2))
		{
			if (time1 >= int(time1) + 0.5) time1 = int(time1) + 1;
			if (peekQueue(&Q1) != 0)
			{
				printf("Касса 1 - %i | %.2lf\n", peekQueue(&Q1), time1);
				data[index++] = popQueue(&Q1);
			}
			popQueue(&Q2);
			time1 += 0.15;
		}

	}

	return 0;
}