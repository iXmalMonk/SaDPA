#include "Queue.h"

void pushQueue(Queue* queue, int number)
{
	Element* tmp = (Element*)malloc(sizeof(Element));

	if (!tmp) return;

	tmp->data = number;
	tmp->next = NULL;

	if (queue->head == NULL)
	{
		queue->head = tmp;
		queue->tail = tmp;
	}
	else
	{
		queue->tail->next = tmp;
		queue->tail = tmp;
	}
}

int popQueue(Queue* queue)
{
	if (queue->head == NULL) return 0;

	int number = queue->head->data;

	if (queue->head == queue->tail) queue->tail = NULL;

	Element* tmp = queue->head;
	queue->head = queue->head->next;
	free(tmp);

	return number;
}

int peekQueue(Queue* queue)
{
	if (queue->head == NULL) return 0;

	int number = queue->head->data;

	return number;
}

void printQueue(Queue const* queue)
{
	for (Element* current = queue->head; current != NULL; current = current->next)
		printf("%i ", current->data);
	printf("\n");
}

void clearQueue(Queue* queue)
{
	while (queue->head != NULL)
	{
		if (queue->head == queue->tail) queue->tail = NULL;

		Element* tmp = queue->head;
		queue->head = queue->head->next;
		free(tmp);
	}
}