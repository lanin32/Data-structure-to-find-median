#include "MedianList.h"
#include <iostream>


MedianList::MedianList()
{
	start = nullptr;
	middle = start;
	length = 0;
}

MedianList::~MedianList()
{
	Node* temp = start;
	while (temp)
	{
		temp = start->next;
		delete start;
		start = temp;
	}
}

void MedianList::print()
{
	Node* temp = start;
	while (temp)
	{
		std::cout << temp->value << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}

void MedianList::insertElement(double value)
{
	Node* newEl = new Node;
	newEl->value = value;
	newEl->next = nullptr;
	newEl->prev = nullptr;

	if (length == 0)
	{
		start = newEl;
		middle = start;
		length++;
		return;
	}

	Node* temp = start;
	Node* prev = nullptr;
	while (temp)
	{
		if (temp->value < value)
		{
			prev = temp;
			temp = temp->next;
		}
		else break;
	}

	newEl->prev = prev;
	if (temp == start)start = newEl;
	else prev->next = newEl;
	newEl->next = temp;
	if (temp)temp->prev = newEl;
	length++;

	if (length % 2 == 0)
	{
		if (middle->value >= value)middle = middle->prev;
	}
	else
	{
		if (middle->value < value)middle = middle->next;
	}

}

double MedianList::getMedian()
{
	//exception
	if (length == 0)return 0;
	if (length % 2 == 1)return middle->value;
	else return (middle->value + middle->next->value) / 2;
}
