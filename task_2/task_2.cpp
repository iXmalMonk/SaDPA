#include<iostream>

struct Node {
	int data;
	Node* next;
	Node* prev;
};

struct Ring {
	int size = 0;
	Node* current;
};

Ring* createRing()
{
	Ring* tmp = (Ring*)malloc(sizeof(Ring));

	tmp->size = 0;
	tmp->current = NULL;

	return tmp;
}

void addElement(Ring* ring, int value)
{
	Node* prev = NULL;
	Node* tmp = (Node*)malloc(sizeof(Node));

	tmp->data = value;

	if (ring->current == NULL)
	{
		ring->current = tmp;
		tmp->next = tmp->prev = tmp;
	}
	else
	{
		prev = ring->current->next->prev;
		tmp->next = ring->current->next;
		tmp->prev = ring->current;
		prev->prev = tmp;
		ring->current->next = tmp;
		ring->current = tmp;
	}

	ring->size++;
}

int removeElement(Ring* ring)
{
	Node* afterTarget = NULL;
	int value;

	if (ring->current == NULL) return 1e300;

	if (ring->current->next == ring->current)
	{
		value = ring->current->data;
		free(ring->current);
		ring->current = NULL;
	}
	else
	{
		afterTarget = ring->current->next;
		ring->current->prev->next = afterTarget;
		afterTarget->prev = ring->current->prev;
		value = ring->current->data;
		free(ring->current);
		ring->current = afterTarget;
	}

	ring->size--;

	return value;
}

Node* next(Ring* ring)
{
	Node* value = NULL;
	if (ring->current)
	{
		ring->current = ring->current->next;
		value = ring->current;
	}
	return value;
}

Node* prev(Ring* ring)
{
	Node* value = NULL;
	if (ring->current)
	{
		ring->current = ring->current->prev;
		value = ring->current;
	}
	return value;
}

void printCurrentElement(Ring* ring)
{
	printf("%i\n", ring->current->data);
}

void findElement(Ring* ring, int value)
{
	for (int i = 0; i < ring->size; i++)
	{
		if (ring->current->data != value) next(ring);
		else return;
	}

	printf("Ёлемент %i не найден", value);
}

int main()
{
	system("chcp 1251");
	system("cls	");

	Ring* ring;

	ring = createRing();

	addElement(ring, 1);
	addElement(ring, 2);
	addElement(ring, 3);

	prev(ring);

	printCurrentElement(ring);

	findElement(ring, 0);

	printCurrentElement(ring);
}