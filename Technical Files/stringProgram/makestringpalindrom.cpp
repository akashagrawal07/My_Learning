#include <iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;
 
int main()
{
	
	string a = "geeksforgeeks";
	sort(a.begin(),a.end());
	cout << a <<endl;
	vector<char> vec;
	int len = a.length();
	
	for(int i = 0;i<len;i++)
	{

		char *aa = &a[i];
		char *bb = &a[i+1];
		
	//	cout << *aa << " "<< *bb <<endl;
		
		if(a[i] == a[i+1])
		{
			i++;
		}
		else
		{
	//		cout << a[i] <<i<<endl;
			vec.push_back(a[i]);
		}
	}
	cout << "Sizeof Vector - "<< vec.size()<<endl;
	vector<char>::iterator it = vec.begin();
	for(;it != vec.end();it++)
	{
		cout << *it <<endl;
	}

	return 0;
}
