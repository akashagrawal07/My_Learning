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
	int num;
	map<int,char> m;
	m[1000] = 'M';
	m[500] = 'D';
	m[100] = 'C';
	m[50] = 'L';
	m[10] = 'X';
	m[5] = 'V';
	m[1] = 'I';
	
	cout << "Enter number-";
	cin>>num;
	string roman = "";
	//IV
	int len = roman.length();
	int convNumber = 0;
	map<int,char>::iterator it = m.begin();
	map<int,char>::iterator itPre = m.begin();
	int pre = 0;
	while(1)
	{
			if(num <= it->first)
			{
				roman = roman + itPre->second;
				num = num - itPre->first;
				it = m.begin();
			}
			if(num <= 0)
			{
				break;
			}
			itPre = it;
			it++;
	}
	cout << "Roman Number "<<roman;
	return 0;
}
