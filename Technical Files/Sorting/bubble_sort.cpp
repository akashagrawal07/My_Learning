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

void bubbleSort(int a[])
{
	cout << "------BUBBLE SORTING STARTED------\n\n";
	
	int outerLoopCount = 0;
	int innerLoopCount = 0;
	int sortedList = true;
	for(int i = 0 ; i < SIZE ; i++)
	{
		
		++outerLoopCount;
		for(int j = 0 ; j < SIZE-i-1 ; j++)
		{
			++innerLoopCount;	
			if(a[j] > a[j+1])
			{
				swapNode(a[j],a[j+1]);
				sortedList = false;
				
			}
			printdata(a);
		}
		if(sortedList)
		{
			cout << "List is sorted already\n";
			break;
		}
		sortedList = true;
	}
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
	bubbleSort(a);
	
	return 0;
}
