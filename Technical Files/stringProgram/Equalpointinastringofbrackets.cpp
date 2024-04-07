#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a = "(())";
	char open = '(';
	char close = ')';
	int rev = a.length();
	cout << rev<< endl;
	int cOpen = 0;
	int cClose = 0;
	for (int i =0;i < a.length();i++,rev--)
	{
		if(a[i]== open)		
		{
			cOpen++;
		}
		if(a[rev] == close)
		{
			cClose++;
		}
		
		if(i)
		{
			cout << i;
		}
	}
	return 0;
}
