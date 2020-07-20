#include "MedianHeap.h"


MedianHeap::MedianHeap()
{
}

MedianHeap::~MedianHeap()
{
}

void MedianHeap::insertElement(double value)
{

	if (leftHeap.size() == 0)leftHeap.push(value);
	else if (value < leftHeap.top())leftHeap.push(value);
	else rightHeap.push(value);

	if (leftHeap.size() > rightHeap.size() + 1)
	{
		rightHeap.push(leftHeap.top());
		leftHeap.pop();
	}
	else if (rightHeap.size() > leftHeap.size())
	{
		leftHeap.push(rightHeap.top());
		rightHeap.pop();
	}

}

double MedianHeap::getMedian()
{
	if (leftHeap.size() == 0) throw "No elements in this set!";
	if (leftHeap.size() > rightHeap.size())return leftHeap.top();
	else return (leftHeap.top() + rightHeap.top()) / 2;
}
