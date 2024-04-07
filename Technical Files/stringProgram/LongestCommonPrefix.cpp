/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
/*

*/

string findLongestPrefix(string a[],int n)
{
	string result = a[0];
	int len = result.length();
	
	for (int i =1 ; i < n; i++)
	{
		while(a[i].find(result) != 0)
		{
			result = result.substr(0,len-1);
			len--;
		}
	}
	return result;
}

int main()
{
    string test[] = {"geeks","geet","geeet","ee"};
	int n =  sizeof(test)/sizeof(test[0]);
	cout << n <<endl;        
    cout << findLongestPrefix(test,n);

    return 0;
}

