#pragma once

struct Node
{
	Node* prev;
	Node* next;
	double value;
};

class MedianList
{
	Node* start;
	Node* middle;
	int length;

public:

	MedianList();
	~MedianList();

	void print();
	void insertElement(double value);
	double getMedian();

};
