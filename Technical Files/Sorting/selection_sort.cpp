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

void selectionSort(int a[])
{
	cout << "------SELECTION SORTING STARTED------\n\n";
	
	int outerLoopCount = 0;
	int innerLoopCount = 0;


	for(int i =0 ;i < SIZE ; i++)
	{
		int key = a[i];
		int smallest = i;
		++outerLoopCount;
		for(int j = i; j < SIZE ; j++)
		{
			++innerLoopCount;
			if(key > a[j])
			{
				key = a[j];
				smallest = j;
			}
		}
		//cout << "Smallest Element in array-" << a[smallest] << endl;
		swapNode(a[i],a[smallest]);
		printdata(a);
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
	selectionSort(a);
	
	return 0;
}
