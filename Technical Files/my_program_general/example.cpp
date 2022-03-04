#ifndef SOMETHING_H
#define SOMETHING_H
#include <iostream>

using namespace std;

class  Base{
	// Private section
	public:
		// Public Declarations
	protected:
		// Protected Declarations
};
class Der : public Base
{
	public:
		void fun()
		{
			cout << "i'm in dervied class fun \n'";
		}
};
static int i = 0;
class AA
{
	int a;
};
class BB : public AA
{
	int b;
};
int main()
{
	/*Der d;
	//Base *b = dynamic_cast<Der *> &d;
	
	i++;
	cout << "Main - i"<< i <<endl;
	if(i < 2)
	{
		main();
	}
	//b->fun();*/
	AA a;
	BB b;
	cout << "Size OF BaseCLass-" <<  sizeof(a);
	cout << "Size OF BaseCLass-" <<  sizeof(b);
}

#endif
