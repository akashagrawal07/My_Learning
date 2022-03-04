#ifndef SOMETHING_H
#define SOMETHING_H
#include <iostream>

using namespace std;
class  Base{
	// Private section
	int i ;
	void tfun0()
	{
		cout << "Base::private fun\n";
	}
	public:
		Base()
		{
			cout<< "Base::Constructor111\n";
		}
		void fun1()
		{
			cout << "Base::fun\n";
		}
		// Public Declarations
	protected:
		// Protected Declarations
};

class Derived : public Base {
	// Private section
	int y;
	public:
		Derived()
		{
			cout << "Derived::Constructor\n";
		}
		void fun()
		{
			Base::fun0();
			cout << "Derived:fun\n";
		}
		// Public Declarations
	protected:
		// Protected Declarations
};

#endif
int main()
{
//	Base b;
//	b.fun();
	Derived d;
	d.fun();
	
	return 0;
}
