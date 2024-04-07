#include <iostream>
#include <vector>
#include <map>
/*
I = 1
V = 5
X = 10
L = 50
C = 100
D = 500
M = 1000
*/


using namespace std;

int main()
{
	string roman;
	map<char,int> m;
	m['I'] = 1;
	m['V'] = 5;
	m['X'] = 10;
	m['L'] = 50;
	m['C'] = 100;
	m['D'] = 500;
	m['M'] = 1000;
	cout << "Enter Roman number-";
	cin>>roman;
	
	int len = roman.length();
	int convNumber = 0;
	
	for(int i = 0;i<len;i++)
	{
		char f = roman[i];

		map<char,int>::iterator it = m.find(f);
		
		cout << it->first <<endl;
		
		if(it == m.end())
		{
			cout << "Invalid Roman number\n";
			convNumber = 0;
			break;
		}
		else
		{
			cout << "found";
		}
		int nextSymbol = m[roman[i+1]];		
		if(it->second < nextSymbol)
		{
			convNumber = convNumber - it->second;
		}
		else
		{
			convNumber = convNumber + it->second;
		}
	}
	
	if(convNumber != 0)	
	{
		cout << roman << " roman number integer number is "<<convNumber<<endl;
	}
	return 0;
}
