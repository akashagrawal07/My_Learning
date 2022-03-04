#include <iostream>
#include<string>
using namespace std;
class Pizza 
{ 
    // it is an abstract pizza 
    protected:
    string description = "Unkknown Pizza"; 
  
    public:
		string virtual getDescription()
		{
			return description;
		}
		
    	int virtual getCost()=0;
		
};
  
// The decorator class :  It extends Pizza to be 
// interchangable with it topings decorator can 
// also be implemented as an interface 
class ToppingsDecorator : public Pizza 
{ 
    public:
	 string virtual getDescription() = 0; 
};
  
// Concrete pizza classes 
class PeppyPaneer : public Pizza 
{ 
    public :
	PeppyPaneer() { description = "PeppyPaneer"; } 
    int getCost() {  return 100; } 
}; 
class FarmHouse :public Pizza 
{ 
    public :
	FarmHouse() {  description = "FarmHouse"; } 
    int getCost() { return 200; } 
}; 
class Margherita : public Pizza 
{ 
    public:
    Margherita()  { description = "Margherita"; } 
    int getCost() { return 100;  } 
}; 
class ChickenFiesta :public Pizza 
{ 
    public :
	ChickenFiesta() { description = "ChickenFiesta";} 
    int getCost() { return 200; } 
}; 
class SimplePizza : public Pizza 
{ 
public:
 SimplePizza() { description = "SimplePizza"; } 
  int getCost() {  return 50;  } 
}; 
  
// Concrete toppings classes 
class FreshTomato : public ToppingsDecorator 
{ 
    // we need a reference to obj we are decorating 
    Pizza *pizza; 
  
    public :
	FreshTomato(Pizza *pizza) { this->pizza = pizza; } 
    string getDescription() { 
    	cout<< "tomato decorator----\n";
        return pizza->getDescription() + ", Fresh Tomato "; 
    } 
    int getCost() { 
	cout<<"Tomato cost\n";
	return 40 + pizza->getCost(); } 
}; 
class Barbeque : public ToppingsDecorator 
{ 
    Pizza *pizza; 
    public :
	Barbeque(Pizza *pizza) {  this->pizza = pizza;  } 
     string getDescription() { 
     
        return pizza->getDescription() + ", Barbeque "; 
    } 
    int getCost() { return 90 + pizza->getCost(); } 
}; 
class Paneer :public ToppingsDecorator 
{ 
    Pizza *pizza; 
    public:
	 Paneer(Pizza *pizza)  {  this->pizza = pizza; } 
    string getDescription() { 
    	cout<<"Paneer Decorator-------\n";
        return pizza->getDescription() + ", Paneer "; 
    } 
     int getCost()  {  
     cout<<"Paneer cost\n";
	 return 70 + pizza->getCost(); } 
}; 
  
// Other toppings can be coded in a similar way 
  
// Driver class and method 

    int main()
    { 
        // create new margherita pizza 
        Pizza *pizza = new Margherita(); 
      //  cout << "sizeOf--1" << sizeof(pizza) << endl;
        cout<< pizza->getDescription() ;
        cout<<" Cost :" << pizza->getCost() <<endl; 

        // create new FarmHouse pizza 
        Pizza *pizza2 = new FarmHouse(); 
	//	cout << "sizeOf--2" << sizeof(pizza2) << endl;
        // decorate it with freshtomato topping 
        pizza2 = new FreshTomato(pizza2); 
  //cout << "sizeOf--3" << sizeof(pizza2) << endl;
        //decorate it with paneer topping 
        pizza2 = new Paneer(pizza2); 
//  cout << "sizeOf--4" << sizeof(pizza2) << endl;
        cout<< pizza2->getDescription() ;
                         cout<<" Cost :" << pizza2->getCost() <<endl; 
        //Pizza *pizza3 = new Barbeque(0);    //no specific pizza 
        //cout<< pizza3->getDescription() ;
          //               cout<<" Cost :" << pizza3->getCost() <<endl; 
   } 
 

