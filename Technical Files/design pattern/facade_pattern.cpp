// THIS HAVE 2 EXAMPLE PLEASE REFER DOWN ALSO

class Engine
{

public:
    void Start() { }

};

class Headlights
{

public:
    void TurnOn() { }

};

//  That's your facade.
class Car
{

private:
    Engine engine;
    Headlights headlights;

public:
    void TurnIgnitionKeyOn()
    {
        headlights.TurnOn();
        engine.Start();
    }

};

int Main(int argc, char *argv[])
{
    //  Consuming facade.
    Car car;
    car.TurnIgnitionKeyOn();

    return 0;
}

---------------------------------------------------------------------------------------------------------------------------------------------
// "Subsystem ClassA" 
#include <iostream>
class SubSystemOne
{
public:
    void MethodOne()
    {
        std::cout << " SubSystemOne Method" << std::endl;
    }
}

// Subsystem ClassB" 

class SubSystemTwo
{
public:
    void MethodTwo()
    {
        std::cout << " SubSystemTwo Method" << std::endl;
    }
}

// Subsystem ClassC" 

class SubSystemThree
{
public:
    void MethodThree()
    {
            std::cout << " SubSystemThree Method" << std::endl;
    }
}

// Subsystem ClassD" 

class SubSystemFour
{
public:
    void MethodFour()
    {
        std::cout << " SubSystemFour Method" << std::endl;
    }
}

// "Facade" 

class Facade
{
    SubSystemOne one;
    SubSystemTwo two;
    SubSystemThree three;
    SubSystemFour four;

public:
    Facade()
    {
    }

    void MethodA()
    {
        std::cout << "\nMethodA() ---- " << std::endl;
        one.MethodOne();
        two.MethodTwo();
        four.MethodFour();
    }
    void MethodB()
    {
        std::cout << "\nMethodB() ---- " << std::endl;
        two.MethodTwo();
        three.MethodThree();
    }
}

int Main()
{
    Facade facade = new Facade();

    facade.MethodA();
    facade.MethodB();

    return 0;
}

