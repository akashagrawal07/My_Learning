#include <iostream>

using namespace std;

int factorial(int no)
{
	cout<<"Enter number-"<<no<<endl;
	if(no >= 1)
	{
		cout<<"Factorial Number-"<<no<<endl;
		int t = no;
		return t * factorial(--no);
	}
	cout<<"return-------------1\n";
	return 1;
}
			
	
		
			
int sumOfFactorial(int num)
{
	int temp = 0;
	for(int i = 1 ; i <= num;i++)
	{
		temp = temp + factorial(i);
	}
	return temp;
}
int main()
{
	int num;
	cout<<"Input Number-";
	cin>> num;
	//cout << sumOfFactorial(num);
	cout<<factorial(num);
}
