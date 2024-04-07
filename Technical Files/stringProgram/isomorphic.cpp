#include <iostream>
#include <string>
#include <map>
#include <bits/stdc++.h>

using namespace std;

int main()
{
	string a = "aab";
	string b = "yyx";
	
	map<char,char> m;
	
	if(a.length() != b.length())
	{
		cout << "string is not isomorphic\n";
	}
	else
	{
		for(int i =0;i<a.length();i++)
		{
			if(m.find(a[i]) == m.end())
			{
				m[a[i]] = b[i];
			}
			else
			{
				if(m[a[i]] != b[i])
				{
					cout << "not isomorphic\n";
					break;
				}
			}			
		}
	}
	sort(b.begin(),b.end());
	
cout << b <<endl;	
	return 0;
}
