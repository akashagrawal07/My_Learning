// sort algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
using namespace std;
bool myfunction (int i,int j) 
{
cout<<"My function-"  << i << " and " << j <<endl;
return (i<j); 
}

struct myclass {
	int key;
  /*bool operator< (myclass &s) 
  { 
  cout<<"My function-"  << key << " and " << s.key <<endl;
  return (key<s.key);
  }*/
  bool operator() (int i,int j) 
  { 
  cout<<"My function-"  << i << " and " << j <<endl;
  return (i<j);
  }
} myobject;

int main () {
  int myints[] = {32,71,12,45,26,80,53};
  std::vector<int> myvector (myints, myints+7);               // 32 71 12 45 26 80 53 33
  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
  // using default comparison (operator <):
  //std::sort (myvector.begin(), myvector.begin()+4);           //(12 32 45 71)26 80 53 33

  // using function as comp
  //std::sort (myvector.begin()+4, myvector.end(), myfunction); // 12 32 45 71(26 33 53 80)

  // using object as comp
  std::sort (myvector.begin(), myvector.end(), myobject);     //(12 26 32 33 45 53 71 80)

  // print out content:
  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
