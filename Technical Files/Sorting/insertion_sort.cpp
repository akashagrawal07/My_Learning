#include <iostream>
#include <stdlib.h> 

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

void insertionSort(int a[])
{
	cout << "------INSERTION SORTING STARTED------\n\n";
	int outerLoopCount = 0;
	int innerLoopCount = 0;
	for(int i = 1 ; i < SIZE ; i++)
	{
		++outerLoopCount;
		int temp = a[i];
		int j = i;
		
		for(; j > 0 ;j--)
		{
			++innerLoopCount;
			if(temp < a[j-1])
				a[j] = a[j-1];
			else
				break;
			printdata(a);				
		}
		a[j] = temp;
	//	printdata(a);

		
	}

	cout << "Outer Loop Count ---" << outerLoopCount <<endl;
	cout << "Inner Loop Count ---" << innerLoopCount <<endl;
	
}

int main()
{
	int a[5];
	int count = 0;
	cout << "Enter Number : ";
	for(int i = 0;i<SIZE;i++)
	{
		int no = 0;
		/*while(1)
		{
			++count;
			no = rand();
			if(no < 100)
			{
				break;
			}
		}*/
		cin >> a[i];
	}
	printdata(a);
	insertionSort(a);
	return 0;
}
