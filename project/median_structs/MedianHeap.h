#pragma once
#include <queue>
#include <functional>

using namespace std;

class MedianHeap
{
	priority_queue <double, vector<double>, greater<double> > rightHeap;
	priority_queue <double, vector<double> > leftHeap;

public:
	MedianHeap();
	~MedianHeap();

	void insertElement(double);
	double getMedian();

};

