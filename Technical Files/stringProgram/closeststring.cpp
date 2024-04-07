#include <iostream>

using namespace std;

int main()
{
	//string a[] = {"the","quick","brown","fox","qucik","geks"};
	string a[] = {"geeks","for","geeks","conribute","pratice"};
	cout <<"enter 2 words";
	string word1 ,word2;
	cin>>word1;
	cin>>word2;
	int len = sizeof(a)/sizeof(a[0]);
	int count = 0;
	bool flag = false;
	for (int i =0;i<len;i++)
	{
		if( a[i]== word1)
		{
			count = 0;
			flag = true;
		}
		if(a[i] == word2)
		{
			break;
		}
		if(flag)
			count++;		
	}
	cout << "Count-"<<count<<endl;
}
