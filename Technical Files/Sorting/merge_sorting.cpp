#include <iostream>

using namespace std;

#define SIZE 5

void printdata(int a[])
{
	cout << "\nPrinting Data-";
	for(int i = 0;i<SIZE;i++)
	{
		cout<< a[i] << " ";
	}
	cout << "\n";

}
void swapNode(int &a,int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void mergeSort(int a[])
{
	cout << "------MERGE SORTING STARTED------\n\n";
	
	int outerLoopCount = 0;
	int innerLoopCount = 0;
	int sortedList = true;

	cout << "Outer Loop Count ---" << outerLoopCount <<endl;
	cout << "Inner Loop Count ---" << innerLoopCount <<endl;
	
	
}

int main()
{
	int a[5];
	cout << "Enter Number:";
	for(int i = 0;i<SIZE;i++)
	{
		cin>> a[i];
	}
	printdata(a);
	mergeSort(a);

	
	return 0;
}
