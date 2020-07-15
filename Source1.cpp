#include <iostream>
#include "MedianList.h"
#include "MedianHeap.h"

using namespace std;

int main()
{
/*
	MedianList testList;

	cout << "number of elements to enter: \n";
	int n;
	cin >> n;

	cout << "enter the elements \n";
	double k;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		testList.insertElement(k);
	}

	testList.print();

	cout <<"median is "<< testList.getMedian()<<endl;
*/

//--------------------------------------------------
	
	MedianHeap test;

	cout << "number of elements to enter: \n";
	int n;
	cin >> n;

	cout << "enter the elements \n";
	double k;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		test.insertElement(k);
	}

	cout << "median is " << test.getMedian() << endl; 
	
	system("pause");
	return 0;
}



