#ifndef _QUEUE_H
#define _QUEUE_H

#include<iostream>

struct Element
{
	int data = 0;
	double time = 0;
	Element* next = NULL;
};

struct Queue
{
	Element* head = NULL, * tail = NULL;
};

void pushQueue(Queue* queue, int number);

int popQueue(Queue* queue);

int peekQueue(Queue* queue);

void printQueue(Queue const* queue);

void clearQueue(Queue* queue);

#endif

