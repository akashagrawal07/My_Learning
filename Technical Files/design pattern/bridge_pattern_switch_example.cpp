#include <iostream>
using namespace std;

class switchType
{
	public:
	virtual void On()=0;
	virtual void Off()=0;
};

class normalSwitch : public switchType
{
	public:
	void On()
	{
		cout<<"Normal Switch ON\n";
	}
	void Off()
	{
		cout<<"Normal Switch OFF\n";
	}
};

class clickSwitch : public switchType
{
	public:
	void On()
	{
		cout<<"Click Switch ON\n";
	}
	void Off()
	{
		cout<<"Click Switch OFF\n";
	}
};

class RopeSwitch : public switchType
{
	public:
	void On()
	{
		cout<<"Rope 1 Push ON\n";
	}
	void Off()
	{
		cout<<"Rope 2 Push OFF\n";
	}
};

class switchOperation
{
	protected:
		switchType *_st;
	public:
		switchOperation()
		{
			_st = new normalSwitch();
		}
		virtual void On()
		{
			_st->On();
		}
		virtual void Off()
		{
			_st->Off();
		}		
};


class Fan : public switchOperation
{
	public:
		Fan()
		{	
			cout<< "Fan Operation\n";
			_st = new RopeSwitch();
		}
};

class TV : public switchOperation
{
	public:
		TV()
		{
			cout<< "TV Operation\n";
		}
};

class Bell : public switchOperation
{
	public :
		Bell()
		{
			cout<< "Bell Operation\n";
			_st = new clickSwitch();
		}
};

int main()
{
	switchOperation *so = new TV();
	so->On();
	so->Off();
	cout<<endl;
	so = new Bell();
	so->On();
	so->Off();
	cout<<endl;
	so = new Fan();	
	so->On();
	so->Off();	
	
}
