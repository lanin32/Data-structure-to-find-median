#include <gtest/gtest.h>
#include <MedianHeap.h>
#include <MedianList.h>
#include <vector>



double randDouble(double fMin, double fMax)
{
	return fMin + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (fMax - fMin)));
}



TEST(ExampleTests, NoElementsTest)
{
	MedianHeap testHeap;
	MedianList testList;

	EXPECT_ANY_THROW(testHeap.getMedian());
	EXPECT_ANY_THROW(testList.getMedian());

}


TEST(ExampleTests, SingeElementTest)
{
	MedianHeap testHeap;
	MedianList testList;

	int k = randDouble(-200000, 200000);
	testHeap.insertElement(k);
	testList.insertElement(k);

	EXPECT_EQ(testHeap.getMedian(), k);
	EXPECT_EQ(testList.getMedian(), k);

}


TEST(ExampleTests, MultipleElementsTestOdd)
{
	MedianHeap testHeap;
	MedianList testList;
	vector<double> testVector;	//used for looking up the actual median
	
	srand(time(0));
	int k = rand() % 100 + 1;
	int n = 2 * k + 21; // random odd number between 23 and 221

	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		double k = randDouble(-200000, 200000);
		testHeap.insertElement(k);
		testList.insertElement(k);
		testVector.push_back(k);
	}
	//sort and take middle element
	sort(testVector.begin(), testVector.end());
	double median = testVector[testVector.size() / 2];

	EXPECT_EQ(testHeap.getMedian(), median);

}


TEST(ExampleTests, MultipleElementsTestEven)
{
	MedianHeap testHeap;
	MedianList testList;
	vector<double> testVector;	//used for looking up the actual median

	srand(time(0));
	int k = rand() % 100 + 1;
	int n = 2 * k +20; // random even number between 22 and 220
	

	//multiple elements test (even)
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		double k = randDouble(-200000, 200000);
		testHeap.insertElement(k);
		testList.insertElement(k);
		testVector.push_back(k);
	}

	//sort and take average of middle two elements
	sort(testVector.begin(), testVector.end());
	double median = (testVector[testVector.size() / 2 - 1] + testVector[testVector.size() / 2]) / 2;

	EXPECT_EQ(testHeap.getMedian(), median);

}
