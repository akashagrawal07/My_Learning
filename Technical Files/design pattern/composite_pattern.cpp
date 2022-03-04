#ifndef COMPOSITE_H_
#define COMPOSITE_H_
#include <vector>
#include <algorithm>
/*
 * This library provide a reusable C++ template class which can be easily re used -
 * in place of implementing Composite design pattern.
 * Composite design pattern is one among the 23 popular design patterns -
 * identified by Gang of Four (GoF).
 * In a Composite pattern there will  be three type of classes like, component, 
 * composite and leaf.
 * Composite and leaf are derived from Component. Composite is a container class -
 * which can store many other Components.
 */
namespace GoFPatterns
{
using namespace std;
/*
 * This template class automatically inherits itself from the given Component type
 * and in addition it provides the containment features to the expanded template type.
 */
template<typename Component>
class Composite: public Component
{
protected:
	vector<Component*> children; //Child components list.
public:
	/*
	 * An iterator type is defined which can be used from Composite class
	 * To perform extensive operations on the Children list like Insert, Search etc.
	 * This is provided just for Ease of use for Composite class developers.
	 */
typedef	typename vector<Component*>::iterator ChildIterator;
	/*
	 * Add a Component to the child list.
	 * Check to avoid duplication of same child in the list.
	 */
	void AddChild(Component* child)
	{
		ChildIterator itr = find(children.begin(),children.end(),child);
		if( itr == children.end())
		{
			children.push_back(child);
		}
	}
	/*
	 * Remove a component from the child list if it exist there.
	 */
	void RemoveChild(Component* child)
	{
		ChildIterator itr = find(children.begin(),children.end(),child);
		if( itr != children.end())
		{
			children.erase(itr);
		}
	}
	/*
	 * Remove all child from the list.
	 */
	void Clear()
	{
		children.clear();
	}
	virtual ~Composite()
	{

	}
}; //End class Composite
}//End name space GoFPatterns
#endif /* COMPOSITE_H_ */ 


#include <iostream>
#include "Composite.h"
/*
 * This is program is an example use of Composite<> template class.
 * The program shows an Electronic system.
 * The system contains the following type of components.
 *   * Resistor
 *   * Capacitor
 *   * ICChip
 *   * PCB
 * All these components share the common features of 
 * "ElectronicComponet"-abstract class.  * In terms of Composite pattern, 
 * the class "ElectronicComponent" acts as the "Component"
 * The Resistor & Capacitor classes acts like Leafs since they don't have 
 * further sub division.
 * ICChip s contains many Resistors and Capacitors inside it, so it will be -
 *  a Composite of Electronic Components Composite<ElectronicComponent>.
 * Further more, the PCB ( Printed Circuit board ) can contains, Resistor, -
 * Capacitor and ICChips on it. So that also is a Composite Electronic Component.
 *
 * Simply, all Electronic Components has some common feature that it accept a Voltage
 * and Current as Input and generates a varied value of Voltage and current as Output.
 * So a function named DoFunction() is there which does the components actual processing.
 *
 * Also all Electronic components will have a specification.
 * For e.g. Resister has X number of Ohms, and Capacitor has X micro fared etc.
 * So a function named PrintSpec() is there which prints the component spec .
 */
namespace GoFExample
{
using namespace std;
using namespace GoFPatterns;
/*
 * The COMPONENT class which declares the common functionalities -
 * of all Electronic Components.
 */
class ElectronicComponent
{
public:
	virtual void PrintSpec(ostream& ostr, string prefix = "")= 0;
	virtual void DoFunction(float& voltage, float& current) = 0;
};
/*
 * Resistor is a LEAF class which is directly inherited from the -
 * ElectronicComponet class.
 */
class Resistor:public ElectronicComponent
{
	float resistance_Ohm; // Resistance value of resistor.
	Resistor(){}
public:
	/*
	 * Constructor - initialize the Resistance value.
	 */
	Resistor(float ohm)
	:resistance_Ohm(ohm)
	{}
	/*
	 * Prints the Resistor's specification.
	 */
	void PrintSpec(ostream& ostr, string prefix = "")
	{
		ostr<<prefix<<"Resistor ("<< resistance_Ohm <<" Ohm )"<<endl;
	}
	/*
	 * Performs the Resistor's real function of modifying  input Voltage & Current.
	 * Electrical engineers, please help :)
	 * Now I just put a printing of Voltage and current as place holder.
	 */
	void DoFunction(float& voltage, float& current)
	{
		cout<<endl<<"Resistor Input ("<<voltage<<" V ,"<<current<<" Amp) 
			Resistance = "<< resistance_Ohm <<endl;
	}
};
/*
 * Capacitor is a LEAF class which is directly inherited from the -
 * ElectronicComponet class.
 */
class Capacitor:public ElectronicComponent
{
	float capacitance_muF; //Capacitance value in micro fared.
	Capacitor(){}
public:
	/*
	 * Constructor - initialize the capacitance value.
	 */
	Capacitor(float muF)
	:capacitance_muF(muF)
	{

	}
	/*
	 * Prints the Capacitor's specification.
	 */
	void PrintSpec(ostream& ostr, string prefix = "")
	{
		ostr<<prefix<<"Capacitor ("<< capacitance_muF <<" muF )"<<endl;
	}
	/*
	 * Performs the Capacitor's real function of modifying  input Voltage & Current.
	 * Electrical engineers, please help :)
	 * Now I just put a printing of Voltage and current as place holder.
	 */
	void DoFunction(float& voltage, float& current)
	{
		cout<<endl<<"Capacitor Input ("<<voltage<<" V ,"<<current<<" Amp) 
			Capacitance ="<< capacitance_muF<<endl;
	}
};
/*
 * ICChip is a COMPOSITE class which consist of many ElectronicComponents -
 * such as Resistors & Capacitors.
 * So it can be said a Composite of ElectronicComponents. Thus it is inherited from -
 * Composite<ElectronicComponent>. This makes it a container class of -
 * other ElectronicComponents and at the same time it, it by itself -
 * an ElectronicComponent.
 */
class ICChip:public Composite<ElectronicComponent>
{
public:
	/*
	 * PrintSpec of ICChip prints no only the spec of the Chip itself
	 * but also the Spec of its Child components in a TAB ("\t") intended format.
	 */
	void PrintSpec(ostream& ostr, string prefix = "")
	{
		ostr<<prefix<<"ICChip With "<< children.size()<< 
						" Components " <<endl;
		for( unsigned int i = 0; i < children.size(); i++)
		{
			ostr<<prefix;
			children[i]->PrintSpec(ostr,"\t");
		}
	}
	/*
	 * Real functioning of ICChip is achieved by passing its input Voltage & Current
	 * To the sub components inside it.
	 * So the DoFunction - of ICChip passes its input Voltage & Current to all the
	 * child component's DoFunction .
	 */
	void DoFunction(float& voltage, float& current)
	{
		cout<<endl<<"ICChip Input ("<<voltage<<" V ,"<<current<<" Amp)";
		for( unsigned int i = 0; i < children.size(); i++)
		{
			children[i]->DoFunction(voltage,current);
		}
	}
};
/*
 * ICChip is a COMPOSITE class which consist of many ElectronicComponents -
 * such as Resistors, Capacitors or ICChips.
 * So it can be said a Composite of ElectronicComponents. Thus it is inherited from -
 * Composite<ElectronicComponent>. This makes it a container class of -
 * other ElectronicComponents and at the same time it, it by itself -
 * an ElectronicComponent.
 */
class PCB:public Composite<ElectronicComponent>
{
public:
	/*
	 * PrintSpec of PCB prints no only the spec of the PCB itself
	 * but also the Spec of its Child components in a TAB ("\t") intended format.
	 */
	void PrintSpec(ostream& ostr, string prefix = "")
	{
		ostr<<prefix<<"PCB With "<< children.size()<< " Components " <<endl;
		for( unsigned int i = 0; i < children.size(); i++)
		{
			ostr<<prefix;
			children[i]->PrintSpec(ostr,"\t");
		}
	}
	/*
	 * Real functioning of PCB is achieved by sending its input Voltage & Current
	 * To the sub components inside it.
	 * So the DoFunction - of PCB send its input Voltage & Current to all the
	 * child components inside it.
	 */
	void DoFunction(float& voltage, float& current)
	{
		cout<<endl<<"PCB Input ("<<voltage<<" V ,"<<current<<" Amp) ";
		for( unsigned int i = 0; i < children.size(); i++)
		{
			children[i]->DoFunction(voltage,current);
		}
	}
};
}//end name space GoFExample

using namespace GoFExample;
/*
 * Program entry point; main() function
 */
int main()
{
	Resistor r1(50), r2(70); //Define Resistors
	Capacitor c1(200),c2(300); //Define Capacitors

	ICChip ic1; //Create a Chip
	ic1.AddChild(new Resistor(2000)); // Add a Resistor inside the ICChip
	ic1.AddChild(new Capacitor(1000)); // Add a Capacitor inside the ICChip

	PCB pcb1; //Make  PCB Object and add the Resistor, Capacitors and ICChip on it
	pcb1.AddChild(&r1);
	pcb1.AddChild(&c1);
	pcb1.AddChild(&c2);
	pcb1.AddChild(&ic1);
	pcb1.AddChild(&ic1); // Duplicate child entries are ignored.

	cout<<"\n=========== Printing the PCB Spec =========="<<endl;
	pcb1.PrintSpec(cout);
	float v =110, i = 5;
	cout<<"\n=========== DoFunction(110,5) of PCB =========="<<endl;
	pcb1.DoFunction(v,i);
	cout<<"\n=========== Removing c2 from PCB =========="<<endl;
	pcb1.RemoveChild(&c2);
	cout<<"\n=========== Printing the PCB Spec =========="<<endl;
	pcb1.PrintSpec(cout);
	
	return 0;
} 