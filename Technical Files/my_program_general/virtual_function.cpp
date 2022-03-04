#include<iostream>

using namespace std;
///////////////////////////////////////////////////////////////////////
class A
{
	public:
	virtual void write()
	{
		cout<< "I'm write in Class A\n";
	}
	virtual void read()
	{
		cout<< "I'm read in class A\n";
	}
};

class B : public A
{
	public :
	void write()
	{
		cout<< "I'm write in Class B\n";
	}
	virtual void read()
	{
		cout<< "I'm read in class B\n";
	}
};
/////////////////////////////////////////////////////////////////////////////////////////
class Base
{
	public:
		virtual void print()=0;
};

class Der1 : virtual public Base
{
	public:
		void print()
		{
			cout << "Der-1"<<endl;
		}
};

class Der2 : virtual public Base
{
	public:
		void print()
		{
			cout << "Der-2"<<endl;
		}
};

class multiple : public Der1, Der2
{
	public:
		void print()
		{
			Der2::print();
		}
};
//////////////////////////////////////////////////////////////////////////////
class Base1
{
	public:
		void write()
		{
			cout<<"Base-write\n";
		}
};
class Der11 : public Base1
{
	public:
		void write()
		{
			cout<<"Derv11-write\n";
		}
};
class Der12 : public Base1
{
	public:
		void write()
		{
			cout<<"Derv12-write\n";
		}
};
//////////////////////////////////////////////////////////////////
/* -- Compilation error
class Base2
{
	private:
		int x;
	public:
		int x;
		void print()
		{
			cout<<x<<endl;
		}
};
//////////////////////////////////// */
int main()
{
	B b1;
	A a1;
	A *a = &a1;
	a-> read();
	a->write();
	
	
	multiple t;
	//t.print();
	Base *b = &t;
	b->print();
	
	Der11 d11;
	Der12 d12;
	Base1 *b12[2];
	b12[0] = &d11;
	b12[1] = &d12;
	for(int i = 0 ; i < 2;i++)
	{
		b12[i]->write();	
	}
}
